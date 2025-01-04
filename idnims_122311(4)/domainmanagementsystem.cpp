#include "domainmanagementsystem.h"
#include "ui_domainmanagementsystem.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QDebug>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <fstream>
#include <sstream>
#include"domainmanagementsystem.h"
#include<QTreeWidget>
#include<set>
#include<QMessageBox>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include<QPieSeries>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QFont>
#include <QRandomGenerator>
#include <QRectF>
#include <QPointF>
#include <vector>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
domainmanagementsystem::domainmanagementsystem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::domainmanagementsystem)
{
    ui->setupUi(this);
    // 创建根节点
    root = new DomainNode("root", "根域", "域名系统根节点","无");
    nodeMap["root"] = root;

    // 打开数据库连接
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("jkomains.db");
    if (!db.open()) {
        qDebug() << "无法打开数据库:" << db.lastError().text();
        return;
    }

    // 创建表
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS jkomains ("
                    "full_path TEXT PRIMARY KEY,"
                    "parent_name TEXT,"
                    "domain_name TEXT,"
                    "type TEXT,"
                    "filed TEXT,"
                    "description TEXT);")) {
        qDebug() << "创建表失败:" << query.lastError().text();
    }
    // 从数据库加载域名
    loadFromDatabase();
}

domainmanagementsystem::~domainmanagementsystem()
{
    // 关闭数据库连接
    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());
    // 释放所有节点内存
    deleteSubtree(root);
    delete ui;
}
void domainmanagementsystem::loadFromDatabase() {
    QSqlQuery query("SELECT full_path, parent_name, domain_name, type,filed,description FROM jkomains ORDER BY length(full_path);");

    if (query.exec()) {
        while (query.next()) {
            QString full_path = query.value(0).toString();
            QString parent_name = query.value(1).toString();
            QString domain_name = query.value(2).toString();
            QString type = query.value(3).toString();
            QString description = query.value(5).toString();
            QString filed=query.value(4).toString();
            // 创建新节点
            DomainNode* newNode = new DomainNode(domain_name.toStdString(), type.toStdString(), description.toStdString(),filed.toStdString());

            // 找到父节点
            DomainNode* parentNode = nullptr;
            if (parent_name == "root") {
                parentNode = root;
            } else {
                parentNode = nodeMap[parent_name.toStdString()];
            }

            if (!parentNode) {
                qDebug() << "未找到父域名:" << parent_name;
                delete newNode;
                continue;
            }

            // 将新节点插入为第一个子节点或兄弟节点
            if (!parentNode->firstChild) {
                parentNode->firstChild = newNode;
            } else {
                DomainNode* sibling = parentNode->firstChild;
                while (sibling->nextSibling) {
                    sibling = sibling->nextSibling;
                }
                sibling->nextSibling = newNode;
            }

            newNode->parent = parentNode;

            // 更新节点映射表
            nodeMap[full_path.toStdString()] = newNode;
        }
    } else {
        qDebug() << "查询数据失败:" << query.lastError().text();
    }
}
 // 将域名数据保存到数据库
void  domainmanagementsystem::saveToDatabase() {
    // 确保数据库连接是打开的
    if (!db.isOpen()) {
        if (!db.open()) {
            qDebug() << "无法打开数据库:" << db.lastError().text();
            return;
        }
    }

    // 开始事务
    if (!db.transaction()) {
        qDebug() << "开始事务失败:" << db.lastError().text();
        return;
    }

    // 清空表
    QSqlQuery query;
    if (!query.exec("DELETE FROM jkomains;")) {
        qDebug() << "清空表失败:" << query.lastError().text();
        if (!db.rollback()) {
            qDebug() << "回滚事务失败:" << db.lastError().text();
        }
        return;
    }

    // 收集所有域名及其完整路径
    std::vector<std::pair<std::string, DomainNode*>> domainsToInsert;

    for (const auto& pair : nodeMap) {
        if (pair.first != "root") {
            domainsToInsert.push_back({ pair.first, pair.second });
        }
    }

    // 按路径长度升序排序
    std::sort(domainsToInsert.begin(), domainsToInsert.end(),
              [](const std::pair<std::string, DomainNode*>& a, const std::pair<std::string, DomainNode*>& b) {
                  return a.first.size() < b.first.size();
              });

    // 插入数据
    for (const auto& entry : domainsToInsert) {
        const std::string& full_path = entry.first;
        DomainNode* node = entry.second;

        // 获取父域名路径
        size_t lastSlash = full_path.find_last_of('/');
        std::string parent_name = (lastSlash != std::string::npos) ? full_path.substr(0, lastSlash) : "root";
        std::string domain_name = node->name;
        std::string type = node->type;
        std::string description = node->description;
        std::string filed=node->filed;
        QString sql = QString("INSERT INTO jkomains (full_path, parent_name, domain_name, type,filed,description) "
                              "VALUES ('%1', '%2', '%3', '%4', '%5','%6');")
                          .arg(QString::fromStdString(full_path))
                          .arg(QString::fromStdString(parent_name))
                          .arg(QString::fromStdString(domain_name))
                          .arg(QString::fromStdString(type))
                          .arg(QString::fromStdString(filed))
                          .arg(QString::fromStdString(description));

        if (!query.exec(sql)) {
            qDebug() << "插入数据失败:" << query.lastError().text();
            if (!db.rollback()) {
                qDebug() << "回滚事务失败:" << db.lastError().text();
            }
            return;
        }
    }

    // 提交事务
    if (!db.commit()) {
        qDebug() << "提交事务失败:" << db.lastError().text();
    }
}
// 计算子树节点数量
int  domainmanagementsystem::countSubtreeNodes(DomainNode* node) {
    if (!node) return 0;

    int count = 1;  // 当前节点

    // 加上子节点数量
    if (node->firstChild) {
        count += countSubtreeNodes(node->firstChild);
    }

    // 加上兄弟节点数量
    if (node->nextSibling) {
        count += countSubtreeNodes(node->nextSibling);
    }

    return count;
}
// 广度优先搜索查看指定路径下的子域名
void  domainmanagementsystem::viewSubdomains(DomainNode* node, int depth) {
    if (!node) return;

    // 缩进表示层次
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }

    // 打印当前节点信息
    std::cout << node->name
              << " (类型: " << node->type
              <<"领域:"<<node->filed
              << ", 描述: " << node->description << ")"
              << std::endl;

    // 递归打印子节点
    if (node->firstChild) {
        viewSubdomains(node->firstChild, depth + 1);
    }

    // 递归打印兄弟节点
    if (node->nextSibling) {
        viewSubdomains(node->nextSibling, depth);
    }
}

// 分割路径
std::vector<std::string>  domainmanagementsystem::splitPath(const std::string& path) {
    std::vector<std::string> result;
    std::istringstream iss(path);
    std::string segment;
    while (std::getline(iss, segment, '/')) {
        if (!segment.empty()) {
            result.push_back(segment);
        }
    }
    return result;
}
//test func
// 递归打印子树
void domainmanagementsystem::printSubtree(DomainNode* node, int depth) {
    if (!node) return;

    // 缩进表示层次
    for (int i = 0; i < depth; ++i) {
        std::cout<< "   ";
    }

    // 打印当前节点信息
    std::cout << node->name
              << " (类型: " << node->type
              <<"领域:"<<node->filed
              << ", 描述: " << node->description << ")"<<std::endl;

    // 递归打印子节点
    if (node->firstChild) {
        printSubtree(node->firstChild, depth + 1);
    }

    // 递归打印兄弟节点
    if (node->nextSibling) {
        printSubtree(node->nextSibling, depth);
    }
}
// 假设你有一个指针指向QTreeWidget，比如：QTreeWidget* treeWidget;

void  domainmanagementsystem::populateTreeWidget(QTreeWidget* treeWidget, DomainNode* node, QTreeWidgetItem* parent) {
    if (!node) return;

    // 创建一个新的QTreeWidgetItem
    QTreeWidgetItem* item = new QTreeWidgetItem(parent);

    // 设置当前节点信息
    item->setText(0, QString::fromStdString(node->name));
    item->setText(1, QString::fromStdString( std::string(node->type)));
    item->setText(2, QString::fromStdString( std::string(node->description)));
    item->setText(3,QString::fromStdString(std::string(node->filed)));
    // 设置项为可展开
    item->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
    // 如果parent为空，则添加顶级项
    if (!parent) {
        treeWidget->addTopLevelItem(item);
    }

    // 递归处理子节点
    if (node->firstChild) {
        populateTreeWidget(treeWidget, node->firstChild, item); // 子节点以当前项为父级
    }

    // 递归处理兄弟节点
    if (node->nextSibling) {
        populateTreeWidget(treeWidget, node->nextSibling, parent); // 兄弟节点与当前项同级
    }
}
//功能函数
// 检查祖先域名冲突
bool  domainmanagementsystem::checkAncestorConflict(DomainNode* node, const std::string& domainName) {
    while (node) {
        if (node->name == domainName) {
            return true;
        }
        node = node->parent;
    }
    return false;
}
// 检查域名是否存在
bool  domainmanagementsystem::checkDomainExists(const std::string& domainPath) {
    return nodeMap.find(domainPath) != nodeMap.end();
}
// 递归收集子树的所有节点路径
void  domainmanagementsystem::collectSubtreePaths(DomainNode* node, std::vector<std::string>& paths, std::string currentPath) {
    if (!node) return;
    // 当前节点的完整路径
    std::string fullPath = currentPath.empty() ? node->name : currentPath + "/" + node->name;
    paths.push_back(fullPath);

    // 递归收集子节点
    if (node->firstChild) {
        collectSubtreePaths(node->firstChild, paths, fullPath);
    }

    // 递归收集兄弟节点
    if (node->nextSibling) {
        collectSubtreePaths(node->nextSibling, paths, currentPath);
    }
}
// 递归查找节点
DomainNode*  domainmanagementsystem::findNode(DomainNode* startNode, const std::vector<std::string>& path, int index) {
    if (!startNode || index >= path.size()) return nullptr;

    // 检查当前节点
    if (startNode->name == path[index]) {
        if (index == path.size() - 1) return startNode; // 找到目标节点

        // 递归查找子节点
        return findNode(startNode->firstChild, path, index + 1);
    }

    // 递归查找兄弟节点
    return findNode(startNode->nextSibling, path, index);
}
// 递归删除子树
void domainmanagementsystem::deleteSubtree(DomainNode* node){
    if (!node) return;

    // 先删除所有子节点
    if (node->firstChild) {
        deleteSubtree(node->firstChild);
    }

    // 再删除兄弟节点
    if (node->nextSibling) {
        deleteSubtree(node->nextSibling);
    }

    // 最后删除当前节点
    delete node;
}
//增删改查
//插入函数
// 插入域名（增）
bool domainmanagementsystem::insertDomain(const std::string& parentPath,
                                          const std::string& domainName,
                                          const std::string& type,
                                          const std::string& description,
                                          const std::string& filed) {
    // 检查域名是否已经存在
    std::string fullPath = parentPath.empty() ? domainName : parentPath + "/" + domainName;
    if (checkDomainExists(fullPath)) {
        // 构造消息字符串
        //QString message = QString("域名已存在:" "%1").arg(fullPath.c_str());
        // 使用 QMessageBox 显示信息弹窗
        //QMessageBox::information(nullptr, "错误", message);
        qDebug() << "域名已存在:" << fullPath.c_str();
        return false;
    }
    // 找到父节点
    DomainNode* parentNode = nullptr;
    if (parentPath.empty()) {
        parentNode = root;

    } else {
        parentNode = findNode(root, splitPath(parentPath), 0);
    }

    if (!parentNode) {
        // 构造消息字符串
        //QString message = QString("未找到父域名" "%1").arg(parentPath.c_str());
        // 使用 QMessageBox 显示信息弹窗
        //QMessageBox::information(nullptr, "错误", message);
        qDebug() << "未找到父域名:" << parentPath.c_str();
        return false;
    }

    // 检查祖先域名冲突
    if (checkAncestorConflict(parentNode, domainName)) {
        // 构造消息字符串
        //QString message = QString("域名与祖先域名冲突:" "%1").arg(domainName.c_str());
        //// 使用 QMessageBox 显示信息弹窗
        //QMessageBox::information(nullptr, "错误", message);
        qDebug() << "域名与祖先域名冲突:" << domainName.c_str();
        return false;
    }

    // 创建新节点
    DomainNode* newNode = new DomainNode(domainName, type, description,filed);
    newNode->parent = parentNode;

    // 将新节点插入为第一个子节点或兄弟节点
    if (!parentNode->firstChild) {
        parentNode->firstChild = newNode;
    } else {
        DomainNode* sibling = parentNode->firstChild;
        while (sibling->nextSibling) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = newNode;
    }

    // 更新节点映射表
    nodeMap[fullPath] = newNode;
    // 实时保存到数据库
    // 插入数据到数据库
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "数据库连接已关闭";
        return false;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO jkomains (full_path, parent_name, domain_name, type,filed,description)"
                  "VALUES (?, ?, ?, ?, ?, ?);");
    query.addBindValue(fullPath.c_str());
    query.addBindValue(parentPath.empty() ? "" : parentPath.c_str());
    query.addBindValue(domainName.c_str());
    query.addBindValue(type.c_str());
    query.addBindValue(filed.c_str());
    query.addBindValue(description.c_str());

    if (!query.exec()) {
        // 构造消息字符串
        //QString message = QString("插入失败" "%1").arg(query.lastError().text());
        // 使用 QMessageBox 显示信息弹窗
        //QMessageBox::information(nullptr, "错误", message);
        qDebug() << "插入数据失败: " << query.lastError().text();
        return false;
    }

    return true;
}
//得到全路径地址
std::string domainmanagementsystem::getFullPath(DomainNode* node) {
    std::string fullPath = node->name;
    DomainNode* parentNode = node->parent;
    // 遍历父节点，拼接路径
    while (parentNode) {
        fullPath = parentNode->name + "/" + fullPath;
        parentNode = parentNode->parent;
    }
    return fullPath;
}
// 递归删除节点及其所有子节点
void  domainmanagementsystem::deleteNode(DomainNode* node) {
    if (!node) return;
    deleteNode(node->firstChild);
    deleteNode(node->nextSibling);
    // 从节点映射中删除
    nodeMap.erase(getFullPath(node));
    // 释放当前节点内存
    qDebug()<<"删除:"<<node->name;
    delete node;
}
// 从父节点的子节点链表中移除当前节点
void domainmanagementsystem::removeFromParent(DomainNode* node) {
    if (!node || !node->parent) return;
    DomainNode* sibling = node->parent->firstChild;
    DomainNode* prev = nullptr;

    while (sibling) {
        if (sibling == node) {
            if (prev) {
                prev->nextSibling = sibling->nextSibling; // 从链表中移除
            } else {
                node->parent->firstChild = sibling->nextSibling; // 更新第一个子节点
            }
            break;
        }
        prev = sibling;
        sibling = sibling->nextSibling;
    }
    delete node;
}
//删除域名
bool domainmanagementsystem::deleteDomain(const std::string& domainPath) {
    // 找到要删除的节点
    DomainNode* nodeToDelete = findNode(root, splitPath(domainPath), 0);
    if (!nodeToDelete) {
        // 构造消息字符串
        QString message = QString("未找到域名: %1").arg(domainPath.c_str());

        // 使用 QMessageBox 显示信息弹窗
        QMessageBox::information(nullptr, "错误", message);
        qDebug() << "未找到域名:" << domainPath.c_str();
        return false;
    }
    // 开始数据库事务
    if (!db.transaction()) {
        qDebug() << "开始事务失败:" << db.lastError().text();
        return false;
    }
    QSqlQuery query;
    try {
        // 删除数据库中所有以该域名开头的记录（包括所有子树）
        QString deleteSubtreeSql = QString("DELETE FROM jkomains WHERE full_path LIKE '%1%%'")
                                       .arg(QString::fromStdString(domainPath));

        qDebug() << "删除子树SQL:" << deleteSubtreeSql;
        if (!query.exec(deleteSubtreeSql)) {
            throw std::runtime_error(query.lastError().text().toStdString());
        }
        // 提交事务
        if (!db.commit()) {
            throw std::runtime_error(db.lastError().text().toStdString());
        }
        // 递归删除节点及其所有子节点
        DomainNode*kid=nodeToDelete->firstChild;
        nodeToDelete->firstChild=NULL;
        deleteNode(kid);
        nodeMap.erase(getFullPath(nodeToDelete));
        // 从父节点的子节点链表中移除当前节点
        removeFromParent(nodeToDelete);
        return true;
    } catch (const std::exception& e) {
        // 回滚事务
        db.rollback();
        qDebug() << "删除域名失败:" << e.what();
        return false;
    }
}
bool domainmanagementsystem::modifyDomain(const std::string& domainPath,
                                          const std::string& newType,
                                          const std::string& newDescription,
                                          const std::string& newFiled) {
    DomainNode* node = findNode(root, splitPath(domainPath), 0);
    if (!node) {
        qDebug() << "未找到域名:" << domainPath.c_str();
        return false;
    }

    std::map<std::string, std::string> updateFields;

    if (!newType.empty() && newType != node->type) {
        updateFields["type"] = newType;
    }
    if (!newDescription.empty() && newDescription != node->description) {
        updateFields["description"] = newDescription;
    }
    if (!newFiled.empty() && newFiled != node->filed) {
        updateFields["filed"] = newFiled;
    }

    if (updateFields.empty()) {
        qDebug() << "没有提供要更新的字段";
        return true;
    }

    QString sql = "UPDATE jkomains SET ";
    QString setClause = "";

    for (auto it = updateFields.begin(); it != updateFields.end(); ++it) {
        if (!setClause.isEmpty()) {
            setClause += ", ";
        }
        setClause += QString::fromStdString(it->first) + " = :" + QString::fromStdString(it->first);
    }

    sql += setClause + " WHERE full_path = :full_path;";

    QSqlQuery query;
    query.prepare(sql);

    for (auto it = updateFields.begin(); it != updateFields.end(); ++it) {
        query.bindValue(":" + QString::fromStdString(it->first), it->second.c_str());
    }
    query.bindValue(":full_path", domainPath.c_str());

    if (!query.exec()) {
        qDebug() << "更新数据失败: " << query.lastError().text();
        return false;
    }

    for (auto it = updateFields.begin(); it != updateFields.end(); ++it) {
        if (it->first == "type") {
            node->type = it->second;
        } else if (it->first == "description") {
            node->description = it->second;
        } else if (it->first == "filed") {
            node->filed = it->second;
        }
    }
    return true;
}
// 查询域名
DomainNode* domainmanagementsystem::queryDomain(const std::string& domainPath) {
    return findNode(root, splitPath(domainPath), 0);
}
// 深度优先搜索查找包含关键词（域名等级）的域名，并返回 DomainNode* 的 vector
void domainmanagementsystem::searchDomains(DomainNode* node, const std::string& keyword, std::vector<DomainNode*>& results, std::string currentPath) {
    if (!node) return;

    // 如果当前节点名称包含关键词，则将当前节点加入结果集
    if (node->type.find(keyword) != std::string::npos) {
        results.push_back(node);
    }

    // 递归搜索子节点
    if (node->firstChild) {
        searchDomains(node->firstChild, keyword, results, currentPath.empty() ? node->name : currentPath + "/" + node->name);
    }

    // 递归搜索兄弟节点
    if (node->nextSibling) {
        searchDomains(node->nextSibling, keyword, results, currentPath);
    }
}
// 深度优先搜索查找包含关键词（域名名字的关键字）的域名，并返回 DomainNode* 的 vector
void domainmanagementsystem::searchDomains_name(DomainNode* node, const std::string& keyword, std::vector<DomainNode*>& results, std::string currentPath) {
    if (!node) return;
    // 如果当前节点名称包含关键词，则将当前节点加入结果集
    if (node->name.find(keyword) != std::string::npos) {
        results.push_back(node);
    }
    // 递归搜索子节点
    if (node->firstChild) {
        searchDomains_name(node->firstChild, keyword, results, currentPath.empty() ? node->name : currentPath + "/" + node->name);
    }
    // 递归搜索兄弟节点
    if (node->nextSibling) {
        searchDomains_name(node->nextSibling, keyword, results, currentPath);
    }
}
// 深度优先搜索查找包含关键词（描述）的域名，并返回 DomainNode* 的 vector
void domainmanagementsystem::searchDomains_descritpion(DomainNode* node, const std::string& keyword, std::vector<DomainNode*>& results, std::string currentPath) {
    if (!node) return;
    // 如果当前节点名称包含关键词，则将当前节点加入结果集
    if (node->description.find(keyword) != std::string::npos) {
        results.push_back(node);
    }
    // 递归搜索子节点
    if (node->firstChild) {
        searchDomains_descritpion(node->firstChild, keyword, results, currentPath.empty() ? node->name : currentPath + "/" + node->name);
    }
    // 递归搜索兄弟节点
    if (node->nextSibling) {
        searchDomains_descritpion(node->nextSibling, keyword, results, currentPath);
    }
}
// 搜索包含关键词(域名等级)的域名，并返回包含 DomainNode* 的 vector
std::vector<DomainNode*> domainmanagementsystem::searchDomainKeyword(const std::string& keyword) {
    std::vector<DomainNode*> results;
    searchDomains(root, keyword, results, "");
    if (results.empty()) {
        std::cout << "未找到包含关键词 " << keyword << " 的域名" << std::endl;
    } else {
        std::cout << "包含关键词 " << keyword << " 的域名：" << std::endl;
        for (const auto& node : results) {
            std::cout << (node->parent ? (node->parent->name + "/") : "") + node->name << std::endl;
        }
    }
    return results;
}
// 搜索包含关键词(域名名字)的域名，并返回包含 DomainNode* 的 vector
std::vector<DomainNode*> domainmanagementsystem::searchDomainKeyword_name(const std::string& keyword) {
    std::vector<DomainNode*> results;
    searchDomains_name(root, keyword, results, "");
    if (results.empty()) {
        std::cout << "未找到包含关键词 " << keyword << " 的域名" << std::endl;
    } else {
        std::cout << "包含关键词 " << keyword << " 的域名：" << std::endl;
        for (const auto& node : results) {
            std::cout << (node->parent ? (node->parent->name + "/") : "") + node->name << std::endl;
        }
    }
    return results;
}
// 搜索包含关键词(域名描述)的域名，并返回包含 DomainNode* 的 vector
std::vector<DomainNode*> domainmanagementsystem::searchDomainKeyword_descritpion(const std::string& keyword) {
    std::vector<DomainNode*> results;
    searchDomains_descritpion(root, keyword, results, "");
    if (results.empty()) {
        std::cout << "未找到包含关键词 " << keyword << " 的域名" << std::endl;
    } else {
        std::cout << "包含关键词 " << keyword << " 的域名：" << std::endl;
        for (const auto& node : results) {
            std::cout << (node->parent ? (node->parent->name + "/") : "") + node->name << std::endl;
        }
    }
    return results;
}
// 查看指定路径下的子域名，并返回 DomainNode* 的 vector
std::vector<DomainNode*> domainmanagementsystem::viewSubdomainsAtPath(const std::string& path) {
    DomainNode* node = findNode(root, splitPath(path), 0);
    if (!node) {
        qDebug() << "未找到路径:" << path.c_str();
        return {};
    }

    std::vector<DomainNode*> subdomains;
    viewSubdomains(node->firstChild, subdomains);

    std::cout << "路径 " << path << " 下的子域名：" << std::endl;
    for (const auto& subdomain : subdomains) {
        std::cout << (subdomain->parent ? (subdomain->parent->name + "/") : "") + subdomain->name << std::endl;
    }

    return subdomains;
}

// 辅助函数：用于收集子域名的 DomainNode* 到 vector 中
void domainmanagementsystem::viewSubdomains(DomainNode* node, std::vector<DomainNode*>& subdomains) {
    if (!node) return;

    subdomains.push_back(node);

    if (node->firstChild) {
        viewSubdomains(node->firstChild, subdomains);
    }

    if (node->nextSibling) {
        viewSubdomains(node->nextSibling, subdomains);
    }
}

// 辅助函数：递归收集 DomainNode 及其所有子节点的信息到一个列表中
void domainmanagementsystem::collectDomainInfo(const DomainNode* node, std::vector<DomainNode*>& domains) {
    // if (!node) return;

    // // 将当前节点加入列表
    // domains.push_back(node);

    // // 递归收集子节点
    // if (node->firstChild) {
    //     collectDomainInfo(node->firstChild, domains);
    // }

    // // 继续收集兄弟节点
    // if (node->nextSibling) {
    //     collectDomainInfo(node->nextSibling, domains);
    // }
}
void domainmanagementsystem::visualize(const std::unordered_map<std::string, int>& levelCount) {
    // 创建柱状图数据
    QBarSeries* series = new QBarSeries();

    // 定义颜色数组
    QColor colors[] = { QColor(0, 204, 255), QColor(255, 105, 180), QColor(34, 193, 195), QColor(253, 187, 45),QColor(158, 62, 27) }; // 自定义颜色
    int colorIndex = 0;

    // 创建一个 QBarSet 对象并为其赋值
    for (const auto& pair : levelCount) {
        QBarSet* set = new QBarSet(QString::fromStdString(pair.first));  // 创建一个新的 QBarSet
        *set << pair.second;  // 将对应的数值添加到 QBarSet 中

        // 为每个柱子设置颜色
        set->setColor(colors[colorIndex % 5]);  // 循环设置不同颜色
        series->append(set);  // 将 QBarSet 添加到系列中
        colorIndex++;
    }

    // 创建图表
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("域名类型统计");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // 创建类别轴（X轴）
    QCategoryAxis* axisX = new QCategoryAxis();
    QList<QString> categories;
    int index = 0;

    // 将域名类型添加到列表，并生成对应的索引位置
    for (const auto& pair : levelCount) {
        categories.append(QString::fromStdString(pair.first));  // 获取域名类型名称作为标签
    }

    // 使用QString列表来添加类别标签
    for (int i = 0; i < categories.size(); ++i) {
        axisX->append(categories[i], i);  // 将标签与其位置绑定
    }
    // 创建数值轴（Y轴）
    QValueAxis* axisY = new QValueAxis();
    axisY->setRange(0, std::max_element(levelCount.begin(), levelCount.end(),
                                        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                                            return a.second < b.second;  // 比较second（计数值）
                                        })->second);  // 获取最大值并设置Y轴范围
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 显示柱子上的数值
    series->setLabelsVisible(true);  // 显示每个柱子的数值
    series->setLabelsPosition(QBarSeries::LabelsInsideEnd);  // 设置数值标签的位置

    // 创建视图
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRenderHint(QPainter::SmoothPixmapTransform);

    // 设置图表的样式
    chartView->setBackgroundBrush(QBrush(Qt::white));  // 背景为白色
    chart->setBackgroundBrush(QBrush(QColor(245, 245, 245)));  // 设置图表背景为浅灰色

    // 设置整体布局
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(chartView);

    QWidget* container = new QWidget();
    container->setLayout(layout);
    container->resize(800, 600);
    container->show();
}
 void domainmanagementsystem::visualizeFiled(const std::unordered_map<std::string, int>& filedCount) {
    // 创建柱状图数据
    QBarSeries* series = new QBarSeries();

    // 扩展颜色数组，增加更多颜色
    QColor colors[] = {
        QColor(0, 204, 255), QColor(255, 105, 180), QColor(34, 193, 195), QColor(253, 187, 45),
        QColor(158, 62, 27), QColor(123, 104, 238), QColor(255, 69, 0), QColor(124, 252, 0),
        QColor(255, 20, 147), QColor(75, 0, 130), QColor(255, 165, 0), QColor(0, 128, 128),
        QColor(255, 215, 0), QColor(0, 255, 127), QColor(238, 130, 238)
    }; // 自定义更多颜色
    int colorIndex = 0;

    // 创建一个 QBarSet 对象并为其赋值
    for (const auto& pair : filedCount) {
        QBarSet* set = new QBarSet(QString::fromStdString(pair.first));  // 创建一个新的 QBarSet
        *set << pair.second;  // 将对应的数值添加到 QBarSet 中

        // 为每个柱子设置颜色
        set->setColor(colors[colorIndex % (sizeof(colors) / sizeof(colors[0]))]);  // 循环设置不同颜色
        series->append(set);  // 将 QBarSet 添加到系列中
        colorIndex++;
    }

    // 创建图表
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("域名涉及领域统计");  // 设置图表标题
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // 添加 X 轴标签
    QCategoryAxis* axisX = new QCategoryAxis();
    QList<QString> categories;
    int index = 0;

    // 将域名涉及领域添加到列表，并生成对应的索引位置
    for (const auto& pair : filedCount) {
        categories.append(QString::fromStdString(pair.first));  // 获取领域名称作为标签
    }

    // 使用QString列表来添加类别标签
    for (int i = 0; i < categories.size(); ++i) {
        axisX->append(categories[i], i);  // 将标签与其位置绑定
    }

    // 添加 Y 轴标签
    QValueAxis* axisY = new QValueAxis();
    axisY->setRange(0, std::max_element(filedCount.begin(), filedCount.end(),
                                        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                                            return a.second < b.second;  // 比较second（计数值）
                                        })->second);  // 获取最大值并设置Y轴范围
    axisY->setTitleText("节点数量");  // 设置 Y 轴标题
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 添加 X 轴标题
    axisX->setTitleText("涉及领域");  // 设置 X 轴标题
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 显示柱子上的数值
    series->setLabelsVisible(true);  // 显示每个柱子的数值
    series->setLabelsPosition(QBarSeries::LabelsInsideEnd);  // 设置数值标签的位置
    QFont font = chart->font();
    font.setPointSize(10);  // 设置字体大小
    chart->setFont(font);   // 应用到图表
    //series->setLabelsColor(Qt::black);  // 设置标签颜色
    // 创建视图
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRenderHint(QPainter::SmoothPixmapTransform);

    // 设置图表的样式
    chartView->setBackgroundBrush(QBrush(Qt::white));  // 背景为白色
    chart->setBackgroundBrush(QBrush(QColor(245, 245, 245)));  // 设置图表背景为浅灰色

    // 设置整体布局
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(chartView);
    QWidget* container = new QWidget();
    container->setLayout(layout);
    container->resize(800, 600);
    container->show();
}
void domainmanagementsystem::visualizeLevelField(const std::unordered_map<std::string, std::unordered_map<std::string, int>>& levelFieldCount, const std::unordered_map<std::string, int>& levelCount) {
    QStackedBarSeries *series = new QStackedBarSeries();

    // 收集所有领域名称
    std::set<std::string> fields;
    for (const auto& levelPair : levelFieldCount) {
        for (const auto& fieldPair : levelPair.second) {
            fields.insert(fieldPair.first);
        }
    }

    QStringList categories;
    for (const std::string& field : fields) {
        categories << QString::fromStdString(field);
    }

    // 创建每个层级的BarSet
    for (const auto& levelPair : levelFieldCount) {
        QString level = QString::fromStdString(levelPair.first);
        QBarSet *set = new QBarSet(level);

        // 按照领域顺序填充数据
        for (const std::string& field : fields) {
            int count = 0;
            auto it = levelPair.second.find(field);
            if (it != levelPair.second.end()) {
                count = it->second;
            }
            *set << count;
        }

        series->append(set);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("域名层级及领域组成统计");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // 设置X轴
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 设置Y轴
    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow*window=new QMainWindow;
    window->setCentralWidget(chartView);
    window->resize(800, 600);
    window->show();
}
void domainmanagementsystem::visualizeLevelField_2(const std::unordered_map<std::string, std::unordered_map<std::string, int>>& levelFieldCount) {
    // 收集所有领域的名称
    std::set<std::string> fields;
    for (const auto& levelPair : levelFieldCount) {
        for (const auto& fieldPair : levelPair.second) {
            fields.insert(fieldPair.first);
        }
    }

    // 创建一个堆叠柱状图系列
    QStackedBarSeries *series = new QStackedBarSeries();

    // 为每个领域创建一个QBarSet
    std::unordered_map<std::string, QBarSet*> barSets;
    for (const std::string& field : fields) {
        barSets[field] = new QBarSet(QString::fromStdString(field));
    }

    // 收集所有层级的名称
    std::vector<std::string> levels;
    for (const auto& levelPair : levelFieldCount) {
        levels.push_back(levelPair.first);
    }

    // 填充数据
    for (size_t i = 0; i < levels.size(); ++i) {
        const std::string& level = levels[i];
        for (const std::string& field : fields) {
            int count = levelFieldCount.at(level).count(field) ? levelFieldCount.at(level).at(field) : 0;
            barSets[field]->append(count);
        }
    }

    // 将所有QBarSet添加到堆叠系列中
    for (const auto& fieldSet : barSets) {
        series->append(fieldSet.second);
    }

    // 创建图表和视图
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("域名层级及领域组成统计");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // 设置X轴
    QStringList categories;
    for (const std::string& level : levels) {
        categories << QString::fromStdString(level);
    }
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 设置Y轴
    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 设置图例
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow* window=new QMainWindow;
    window->setCentralWidget(chartView);
    window->resize(800, 600);
    window->show();
}
// 统计功能
void domainmanagementsystem::statistics(std::vector<std::string>& infor) {
    std::cout << "域名系统统计信息：" << std::endl;
    infor.push_back("域名系统统计信息：");
    std::cout << "总节点数：" << countSubtreeNodes(root) - 1 << std::endl;  // 减去根节点
    std::string str=std::to_string( countSubtreeNodes(root) - 1 );
    infor.push_back("总节点数："+str);
    // 层级统计
    std::unordered_map<std::string, int> levelCount;
    std::queue<DomainNode*> q;
    q.push(root);

    while (!q.empty()) {
        DomainNode* node = q.front();
        q.pop();

        if (node != root) {
            levelCount[node->type]++;
        }

        // 加入子节点和兄弟节点
        if (node->firstChild) {
            q.push(node->firstChild);
        }
        if (node->nextSibling) {
            q.push(node->nextSibling);
        }
    }

    std::cout << "域名类型统计：" << std::endl;
    infor.push_back( "域名类型统计：");
    for (const auto& pair : levelCount) {
        std::cout << pair.first << ": " << pair.second << " 个" << std::endl;
        infor.push_back(pair.first+":"+std::to_string(pair.second)+"个");
    }
    // 可视化
    visualize(levelCount);
}
 void domainmanagementsystem::statistics_2(std::vector<std::string>& infor) {
    std::cout << "域名系统统计信息：" << std::endl;
    infor.push_back("域名系统统计信息：");
    std::cout << "总节点数：" << countSubtreeNodes(root) - 1 << std::endl;  // 减去根节点
    std::string str=std::to_string( countSubtreeNodes(root) - 1 );
    infor.push_back("总节点数："+str);
    // 层级统计
    std::unordered_map<std::string, int> filedCount;  // 修改为统计 filed
    std::queue<DomainNode*> q;
    q.push(root);

    while (!q.empty()) {
        DomainNode* node = q.front();
        q.pop();

        if (node != root) {
            filedCount[node->filed]++;  // 统计 filed
        }

        // 加入子节点和兄弟节点
        if (node->firstChild) {
            q.push(node->firstChild);
        }
        if (node->nextSibling) {
            q.push(node->nextSibling);
        }
    }

    std::cout << "域名涉及领域统计：" << std::endl;
    infor.push_back( "域名涉及领域统计：");
    for (const auto& pair : filedCount) {
        std::cout << pair.first << ": " << pair.second << " 个" << std::endl;
        infor.push_back(pair.first+":"+std::to_string(pair.second)+"个");
    }

    // 可视化
  visualizeFiled(filedCount);
}
void domainmanagementsystem::statisticsAndVisualization(std::vector<std::string>& infor) {
    std::cout << "域名系统统计信息：" << std::endl;
    infor.push_back("域名系统统计信息：");
    std::cout << "总节点数：" << countSubtreeNodes(root) - 1 << std::endl;  // 减去根节点
     std::string str=std::to_string( countSubtreeNodes(root) - 1 );
    infor.push_back("总节点数："+str);
    // 统计每个层级下各个领域的节点数量
    std::unordered_map<std::string, std::unordered_map<std::string, int>> levelFieldCount;
    std::unordered_map<std::string, int> levelCount;
    std::queue<DomainNode*> q;
    q.push(root);

    while (!q.empty()) {
        DomainNode* node = q.front();
        q.pop();

        if (node != root) {
            levelFieldCount[node->type][node->filed]++;
            levelCount[node->type]++;
        }

        // 加入子节点和兄弟节点
        if (node->firstChild) {
            q.push(node->firstChild);
        }
        if (node->nextSibling) {
            q.push(node->nextSibling);
        }
    }

    // 输出统计结果
    std::cout << "域名类型统计：" << std::endl;
    infor.push_back( "域名涉及领域统计:");
    for (const auto& pair : levelCount) {
        std::cout << pair.first << ": " << pair.second << " 个" << std::endl;
    }

    std::cout << "域名涉及领域统计：" << std::endl;
    for (const auto& levelPair : levelFieldCount) {
        std::cout << "层级: " << levelPair.first << std::endl;
        infor.push_back("*层级*："+levelPair.first);
        for (const auto& fieldPair : levelPair.second) {
            std::cout << "  领域: " << fieldPair.first << ": " << fieldPair.second << " 个" << std::endl;
            infor.push_back("----"+fieldPair.first+":"+std::to_string(fieldPair.second)+"个");
        }
    }
    // 可视化统计结果
    return visualizeLevelField(levelFieldCount, levelCount);
}
void domainmanagementsystem::statisticsAndVisualization_2(std::vector<std::string>& infor) {
    std::cout << "域名系统统计信息：" << std::endl;
    infor.push_back("域名系统统计信息：");
    std::cout << "总节点数：" << countSubtreeNodes(root) - 1 << std::endl;  // 减去根节点
    std::string str=std::to_string( countSubtreeNodes(root) - 1 );
    infor.push_back("总节点数："+str);
    // 统计每个层级下各个领域的节点数量
    std::unordered_map<std::string, std::unordered_map<std::string, int>> levelFieldCount;
    std::unordered_map<std::string, int> levelCount;
    std::queue<DomainNode*> q;
    q.push(root);

    while (!q.empty()) {
        DomainNode* node = q.front();
        q.pop();

        if (node != root) {
            levelFieldCount[node->type][node->filed]++;
            levelCount[node->type]++;
        }

        // 加入子节点和兄弟节点
        if (node->firstChild) {
            q.push(node->firstChild);
        }
        if (node->nextSibling) {
            q.push(node->nextSibling);
        }
    }

    // 输出统计结果
    std::cout << "域名类型统计：" << std::endl;
    for (const auto& pair : levelCount) {
        std::cout << pair.first << ": " << pair.second << " 个" << std::endl;
    }

    std::cout << "域名涉及领域统计：" << std::endl;
    for (const auto& levelPair : levelFieldCount) {
        std::cout << "层级: " << levelPair.first << std::endl;
        infor.push_back("*层级*："+levelPair.first);
        for (const auto& fieldPair : levelPair.second) {
            std::cout << "  领域: " << fieldPair.first << ": " << fieldPair.second << " 个" << std::endl;
            infor.push_back("----"+fieldPair.first+":"+std::to_string(fieldPair.second)+"个");
        }
    }

    // 可视化统计结果
    visualizeLevelField_2(levelFieldCount);
}
// 打印整个域名树
void domainmanagementsystem::printDomainTree() {
    qDebug()<< "域名树结构：";
    printSubtree(root);
}
// 辅助函数：分割字符串
std::vector<std::string> domainmanagementsystem::splitString(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::string token;
    std::istringstream iss(str);
    while (std::getline(iss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}
// 读取TXT文件并插入域名数据
bool domainmanagementsystem::loadDomainDataFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        // 构造消息字符串
        QString message = QString("无法打开文件" "%1").arg(filePath.c_str());
        // 使用 QMessageBox 显示信息弹窗
        QMessageBox::information(nullptr, "错误", message);
        qDebug() << "无法打开文件:" << filePath.c_str();
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        // 分割每一行，提取字段
        std::vector<std::string> fields = splitString(line, ',');
        if (fields.size() < 4) {
            qDebug() << "无效的域名数据:" << line.c_str();
            continue;
        }

        std::string fullPath = fields[0];
        std::string type = fields[1];
        std::string description = fields[2];
        std::string filed=fields[3];
        // 分割路径
        std::vector<std::string> pathSegments = splitString(fullPath, '/');
        if (pathSegments.size() < 2) {
            qDebug() << "无效的域名路径:" << fullPath.c_str();
            continue;
        }

        // 构建父路径和域名名称
        std::string parentPath = "";
        if (pathSegments.size() > 2) {
            parentPath = fullPath.substr(0, fullPath.find_last_of('/'));
        } else if (pathSegments.size() == 2) {
            parentPath = "root";
        }

        std::string domainName = pathSegments.back();

        // 插入域名
        if (!insertDomain(parentPath, domainName, type, description,filed)) {
            qDebug() << "插入域名失败:" << fullPath.c_str();
        } else {
            qDebug() << "插入域名成功:" << fullPath.c_str();
        }
    }
    // 构造消息字符串
    QString message = QString("文件读取完成！");
    // 使用 QMessageBox 显示信息弹窗
    QMessageBox::information(nullptr, "成功", message);
    file.close();
    return true;
}
void domainmanagementsystem::keyword_shengchen(std::string str,std::vector<std::string>&res,int level){
    // 执行查询
    // 开始数据库事务
    QSqlQuery query;
    if (query.exec("SELECT full_path FROM jkomains")) {
        while (query.next()) {
            QString value = query.value(0).toString(); // 获取第一列的数据
            std::string value_std=value.toStdString();
            int index=0;
            for(int i=0;i<value_std.size();i++){
                if(value_std[i]=='/'){
                    index++;
                }
            }
            if(index==level){
                res.push_back(value_std);
                qDebug() << value;
            }
        }
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }
}
void domainmanagementsystem::on_pushButton_clicked()
{

}


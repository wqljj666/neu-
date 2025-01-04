#ifndef DOMAINMANAGEMENTSYSTEM_H
#define DOMAINMANAGEMENTSYSTEM_H

#include <QWidget>
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
#include "domainnode.h"
#include <fstream>
#include <sstream>
#include<QTreeWidget>
#include<stack>
#include <QtCharts>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QValueAxis>
#include <QCategoryAxis>
namespace Ui {
class domainmanagementsystem;
}

class domainmanagementsystem : public QWidget
{
    Q_OBJECT
private:
         //成员
    std::unordered_map<std::string, DomainNode*> nodeMap;  // 节点映射表
    //功能函数
    // 递归删除子树
    void deleteSubtree(DomainNode* node);
    void deleteNode(DomainNode* node);
    void removeFromParent(DomainNode* node);
    // 递归查找节点
    DomainNode* findNode(DomainNode* startNode, const std::vector<std::string>& path, int index);
    // 递归收集子树的所有节点路径
    void collectSubtreePaths(DomainNode* node, std::vector<std::string>& paths, std::string currentPath);
    // 检查域名是否存在
    bool checkDomainExists(const std::string& domainPath);
    // 检查祖先域名冲突
    bool checkAncestorConflict(DomainNode* node, const std::string& domainName);
    // 递归打印子树
    void printSubtree(DomainNode* node, int depth = 0);
    // // 深度优先搜索查找包含关键词的域名
    // void searchDomains(DomainNode* node, const std::string& keyword, std::vector<std::string>& results, std::string currentPath);
    // 深度优先搜索查找包含关键词的域名，并返回 DomainNode* 的 vector
    void searchDomains(DomainNode* node, const std::string& keyword, std::vector<DomainNode*>& results, std::string currentPath);
    void searchDomains_name(DomainNode* node, const std::string& keyword, std::vector<DomainNode*>& results, std::string currentPath);
     void searchDomains_descritpion(DomainNode* node, const std::string& keyword, std::vector<DomainNode*>& results, std::string currentPath);//根据描述
    // 广度优先搜索查看指定路径下的子域名
    void viewSubdomains(DomainNode* node, int depth = 0);
    // 分割路径
    std::vector<std::string> splitPath(const std::string& path);
    // 计算子树节点数量
    int countSubtreeNodes(DomainNode* node);
    // 将域名数据保存到数据库
    void saveToDatabase();
    //画图
    void visualize(const std::unordered_map<std::string, int>& levelCount);
    void visualizeFiled(const std::unordered_map<std::string, int>& filedCount);
    void visualizeLevelField(const std::unordered_map<std::string, std::unordered_map<std::string, int>>& levelFieldCount, const std::unordered_map<std::string, int>& levelCount);
    void visualizeLevelField_2(const std::unordered_map<std::string, std::unordered_map<std::string, int>>& levelFieldCount);
public:
    DomainNode* root;  // 根节点
    QSqlDatabase db;    // Qt数据库连接
    //加载数据库
    void loadFromDatabase();
    explicit domainmanagementsystem(QWidget *parent = nullptr);
    ~domainmanagementsystem();
    //增删改查函数
    // 插入域名
    bool insertDomain(const std::string& parentPath, const std::string& domainName,const std::string& type = "",const std::string& description = "",const std::string& filed="未知");
    //得到全域名
    std::string getFullPath(DomainNode* node);
    //删除域名
    bool deleteDomain(const std::string& domainPath);
    // 修改域名信息
    bool modifyDomain(const std::string& domainPath,const std::string& newType = "",const std::string& newDescription = "",const std::string&filed="");
    // 查询域名
    DomainNode* queryDomain(const std::string& domainPath);

    // 搜索包含关键词的域名，并返回包含 DomainNode* 的 vector
    std::vector<DomainNode*> searchDomainKeyword(const std::string& keyword);//域名等级
    std::vector<DomainNode*> searchDomainKeyword_name(const std::string& keyword);//域名名称的关键字
    std::vector<DomainNode*> searchDomainKeyword_descritpion(const std::string& keyword);//根据域名描述
    // 查看指定路径下的子域名，并返回 DomainNode* 的 vector
    std::vector<DomainNode*> viewSubdomainsAtPath(const std::string& path);

    // 辅助函数：用于收集子域名的 DomainNode* 到 vector 中
    void viewSubdomains(DomainNode* node, std::vector<DomainNode*>& subdomains);
    // 辅助函数：递归收集 DomainNode 及其所有子节点的信息到一个列表中
    void collectDomainInfo(const DomainNode* node, std::vector<DomainNode*>& domains);
    // 统计功能
    void statistics(std::vector<std::string>& infor);
    void statistics_2(std::vector<std::string>& infor);
    void statisticsAndVisualization(std::vector<std::string>& infor);
    void statisticsAndVisualization_2(std::vector<std::string>& infor);
    // 打印整个域名树
    void printDomainTree();
    // 辅助函数：分割字符串
    std::vector<std::string> splitString(const std::string& str, char delimiter);
    // 读取TXT文件并插入域名数据
    bool loadDomainDataFromFile(const std::string& filePath);
    //显示在树状图上
    void populateTreeWidget(QTreeWidget* treeWidget, DomainNode* node, QTreeWidgetItem* parent = nullptr);
    //输入关键字生成域名
    void keyword_shengchen(std::string str,std::vector<std::string>&res,int level);
    //输入转化全网址函数
    std::string reverseTransformDomain(const std::string& input) {
        std::stack<std::string> segments;
        std::istringstream iss(input);
        std::string segment;

        // 将所有段压入栈中
        while (std::getline(iss, segment, '.')) {
            segments.push(segment);
        }

        // 构建结果字符串
        std::string result = "root";
        while (!segments.empty()) {
            // 弹出并忽略 'www'
            if (segments.top() == "www") {
                segments.pop();
            }
            else {
                result += "/";
                result += segments.top();
                segments.pop();
            }
        }
        return result;
    }
private slots:
    void on_pushButton_clicked();

private:
    Ui::domainmanagementsystem *ui;
};

#endif // DOMAINMANAGEMENTSYSTEM_H

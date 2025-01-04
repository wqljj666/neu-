#ifndef DOMAINNODE_H
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
// 域名节点类
class DomainNode {
public:
    std::string name;           // 域名
    std::string type;           // 域名类型（如顶级域、二级域等）
    std::string description;    // 域名描述
    std::string filed;          //涉及领域
    DomainNode* firstChild;     // 第一个孩子节点
    DomainNode* nextSibling;    // 下一个兄弟节点
    DomainNode* parent;         // 父节点

    // 构造函数
    DomainNode(const std::string& _name = "",
               const std::string& _type = "",
               const std::string& _desc = "",
               const std::string& _filed= "");
};


#endif // DOMAINNODE_H

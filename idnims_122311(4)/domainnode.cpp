#include "domainnode.h"
#include <QTextStream>
DomainNode::    // 构造函数
    DomainNode(const std::string& _name,
               const std::string& _type,
               const std::string& _desc,
               const std::string&_filed) :
    name(_name),
    type(_type),
    description(_desc),
    filed(_filed),
    firstChild(nullptr),
    nextSibling(nullptr),
    parent(nullptr) {}

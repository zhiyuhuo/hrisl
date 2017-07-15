#ifndef PARTOFSPEECH_TAGGING_HPP_
#define PARTOFSPEECH_TAGGING_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

namespace hrisl{
    
class SLNode {
public:
    std::string mtag;
    std::string mtext;
    
    SLNode* parentNode;
    SLNode* firstChildNode;
    SLNode* leftSiblingNode;
    SLNode* rightSiblingNode;
    
public:
    SLNode () {   Init();   }
    ~SLNode () {  Init();   }
    
    SLNode (std::string tag, std::string text);
    
    void Init() ;
    std::string GetTag(); 
    std::string GetText();
    SLNode* GetParent();
    SLNode* GetFirstChild();
    SLNode* GetLeftSibling();
    SLNode* GetRightSibing();
    bool SetFirstChild(SLNode* nd);
    bool SetParent(SLNode* nd);  
    bool InsertNextChild(SLNode* nd);
    bool InsertLeftSibling(SLNode* nd);
    bool InsertRightSibling(SLNode* nd);
};
    
class POSTagging {
private:
    std::vector<std::string> pyStr;
    SLNode* rootNode;
public:
    POSTagging()  { rootNode = NULL; }
    ~POSTagging() { rootNode = NULL; }
    
    SLNode* BuildSLNode();
};

};

#endif
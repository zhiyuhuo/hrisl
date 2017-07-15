#include "hrisl/algorithm/partofspeech_tagging.hpp"

namespace hrisl {
    
    SLNode::SLNode (std::string _tag, std::string _text)
    {
        Init();
        tag = _tag;
        text = _text;
    }
    
    void SLNode::Init() 
    {
        tag = "";
        text = "";
        parentNode = NULL;
        firstChildNode = NULL;
        leftSiblingNode = NULL;
        rightSiblingNode = NULL;
    }
    
    std::string SLNode::GetTag() 
    {
        return tag;
    }
    
    std::string SLNode::GetText()
    {
        return text;
    }
    
    SLNode* SLNode::GetParent()
    {
        return parentNode;
    }
    
    SLNode* SLNode::GetFirstChild()
    {
        return firstChildNode;
    }
    
    SLNode* SLNode::GetLeftSibling()
    {
        return leftSiblingNode;
    }
    
    SLNode* SLNode::GetRightSibing()
    {
        return rightSiblingNode;
    }
    
    bool SLNode::SetFirstChild(SLNode* nd)
    {
        if (this->GetFirstChild() == NULL) {
            this->firstChildNode = nd;
            return true;
        } else {
            return false;
        }
    }
    
    bool SLNode::SetParent(SLNode* nd)
    {
        if (this->GetParent() == NULL) {
            parentNode = nd;
            return true;
        } else {
            return false;
        }
    }
    
    bool SLNode::InsertNextChild(SLNode* nd)
    {
        if (nd->GetParent() != NULL 
            || nd->GetLeftSibling() != NULL) {
            return false;
        }
        
        if (this->GetFirstChild() == NULL) {
            this->SetFirstChild(nd);
            nd->SetParent(this);
        } else {
            SLNode* p = this->GetFirstChild();
            while (p->GetRightSibing() != NULL) {
                p = p->GetRightSibing();
            }
            p->rightSiblingNode = nd;
            nd->leftSiblingNode = p;
            nd->SetParent(this);
        }
        
        return true;
    }
    
    bool SLNode::InsertLeftSibling(SLNode* nd)
    {
        if (nd->GetRightSibing() != NULL 
            || this->GetLeftSibling() != NULL) {
            return false;
        }

        nd->rightSiblingNode = this;
        this->leftSiblingNode = nd;
        return true;
    }
    
    bool SLNode::InsertRightSibling(SLNode* nd)
    {
        if (nd->GetLeftSibling() != NULL
            || this->GetRightSibing() != NULL) {
            return false;
        }
        
        nd->leftSiblingNode = this;
        this->rightSiblingNode = nd;
        return true;
    }
    
    SLNode* POSTagging::BuildSLNode()
    {
        //TODO this function will use the stack to build a SLNode pointer which head to a tree struture text.
        return rootNode;
    }
};
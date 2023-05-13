#include "interCheck.h"
BinSTreeNode* removeEmpty(BinSTreeNode* rootNode,BinSTreeNode* node){
  if(rootNode == NULL)return rootNode;
  if(node[0].left != NULL){
    removeEmpty(rootNode,node[0].left);
  }
  if(node[0].right != NULL){
    removeEmpty(rootNode,node[0].right);
  }
  if(node[0].word[0] =='\0') rootNode=myremoveNode(rootNode,node);
  return rootNode;
}

#include "interCheck.h"
void sortBinSTree(BinSTreeNode* rootNode){
  if(rootNode == NULL)return;
  BinSTreeNode* leftTree = rootNode[0].left;
  BinSTreeNode* rightTree = rootNode[0].right;
  rootNode[0].left=NULL;
  rootNode[0].right=NULL;
  
  if(leftTree != NULL){
    mysortBinSTree(rootNode,leftTree);
  }
  if(rightTree != NULL){
    mysortBinSTree(rootNode,rightTree);
  }
  return;
}

#include "interCheck.h"
void clearBinSTree(BinSTreeNode* rootNode){
  if(rootNode == NULL)return;
  if(rootNode[0].left != NULL){
    clearBinSTree(rootNode[0].left);
    rootNode[0].left=NULL;
  }
  if(rootNode[0].right != NULL){
    clearBinSTree(rootNode[0].right);
    rootNode[0].right=NULL;
  }

  free(rootNode[0].word);
  free(rootNode);
  return;
}

#include "interCheck.h"
void mysortBinSTree(BinSTreeNode* new_rootNode,BinSTreeNode* node){

  if(node[0].left != NULL){
    mysortBinSTree(new_rootNode,node[0].left);
    node[0].left = NULL;
  }
  if(node[0].right != NULL){
    mysortBinSTree(new_rootNode,node[0].right);
    node[0].right = NULL;
  }
  
  addNode(new_rootNode,createNode(node[0].word));//新しい木に追加

  //元の木のノードを解放
  free(node[0].word); 
  free(node);
  return;
}

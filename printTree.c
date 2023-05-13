#include "interCheck.h"
void printTree(BinSTreeNode* rootNode,int order){

  if( rootNode != NULL){
    switch (order){
    case 0://前順走査
      printf("%s\n",rootNode[0].word);
      if(rootNode[0].left != NULL){
        printTree(rootNode[0].left,order);
      }
      if(rootNode[0].right != NULL){
        printTree(rootNode[0].right,order);
      }
      break;
    case 1://間順走査 右の子だけいる時大丈夫？
      if(rootNode[0].left != NULL){
        printTree(rootNode[0].left,order);
      }
      printf("%s\n",rootNode->word);
      if(rootNode[0].right != NULL){
        printTree(rootNode[0].right,order);
      }
      break;
    case 2://後順走査
      if(rootNode[0].left != NULL){
        printTree(rootNode[0].left,order);
      }
      if(rootNode[0].right != NULL){
        printTree(rootNode[0].right,order);
      }
      printf("%s\n",rootNode[0].word);
      break;
    }
  }
  return;
}

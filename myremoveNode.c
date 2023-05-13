#include "interCheck.h"
BinSTreeNode* myremoveNode(BinSTreeNode* rootNode,BinSTreeNode* node){
  BinSTreeNode* tmp=NULL;;
  //置換されたノードを消したツリーに書き換え
  if(node[0].right ==NULL && node[0].left==NULL){ //子がいない場合
    if(node[0].pare == NULL){//rootNodeの場合
      free(node[0].word);
      free(node);
      rootNode=NULL;
    }
    else {
      if(node[0].pare ->left == node){//親にとっての右か左か
        node[0].pare -> left = NULL;
      }
      else{
        node[0].pare ->right = NULL;
      }
      free(node[0].word);
      free(node);
    }
  }
  else if(node[0].right == NULL){ //右に子がいない 
    node[0].left -> pare = node[0].pare;
    if(node[0].pare != NULL){//rootNodeではない場合
      if(node[0].pare ->left == node){//親にとっての右か左か
        node[0].pare -> left = node[0].left;
      }
      else{
        node[0].pare ->right = node[0].left;
      }
      free(node[0].word);
      free(node);
    }
    else{//rootNodeの場合
      tmp = node[0].left;
      free(node[0].word);
      free(node);
      rootNode = tmp;
    }
  }
  else if(node[0].left == NULL){ //左に子がいない
    node[0].right -> pare = node[0].pare;
    if(node[0].pare != NULL){//rootNodeではない場合
      if(node[0].pare ->left == node){//親にとっての右か左か
        node[0].pare -> left = node[0].right;
      }
      else{
        node[0].pare ->right = node[0].right;
      }
      free(node[0].word);
      free(node);
    }
    else {//rootNodeの場合
      tmp = node[0].right;
      free(node[0].word);
      free(node);
      rootNode = tmp;
    }
  }
  else{ //右も左も子がいる
    BinSTreeNode* tmpNode=node;
    free(node[0].word);
    while(tmpNode[0].right != NULL){//wordだけをひたすら左上に繰り上げ
      tmpNode[0].word = tmpNode[0].right->word;
      tmpNode = tmpNode[0].right;
    }
    if(tmpNode[0].left != NULL){//一番右下が左だけ子を持つ場合
      tmpNode[0].word = tmpNode[0].left->word;
      tmpNode = tmpNode[0].left;
      tmpNode[0].pare -> left =NULL;
     
      free(tmpNode);
    }
    else{
      tmpNode[0].pare->right =NULL;
      
      free(tmpNode);
    }
  }
  return rootNode;
}

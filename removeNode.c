#include "interCheck.h"
BinSTreeNode* removeNode(BinSTreeNode *rootNode,BinSTreeNode* node, const char *word, int delall){
  BinSTreeNode* tmp;
  switch (delall){
  case 0:
    if(node[0].left != NULL){
      rootNode = removeNode(rootNode,node[0].left,word,delall);
    }
    if(node[0].right != NULL){
      rootNode = removeNode(rootNode,node[0].right,word,delall);
    }
    if(mystrcmp(node[0].word,word) == 0){
      rootNode = myremoveNode(rootNode,node);
    }
    break;
  case 1:
    if(node[0].left != NULL){
      rootNode = removeNode(rootNode,node[0].left,word,delall);
    }
    if(node[0].right != NULL){
      rootNode = removeNode(rootNode,node[0].right,word,delall);
    }
    tmp = node;
    if(mystrcmp(tmp[0].word,word) == 0){
      while(tmp != NULL){
        if(tmp[0].pare == NULL) break;//rootNodeの削除
        if(mystrcmp(tmp[0].pare->word,word) == 0){//rootNodeに遡るうちで同じ文字があれば終了
          return rootNode;
        }
        tmp = tmp[0].pare;
      }
      rootNode = myremoveNode(rootNode,node);
    }
    break;
  }
  
  return rootNode;
}

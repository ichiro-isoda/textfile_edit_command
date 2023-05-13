#include "interCheck.h"
void addNode(BinSTreeNode* rootNode,BinSTreeNode* node){
  int cmp;
  BinSTreeNode* cmpNode = rootNode;
  BinSTreeNode* tmpNode = rootNode;//一つ前のノードを記憶しておく
  while(cmpNode != NULL){
    cmp =mystrcmp(cmpNode[0].word,node[0].word);
    switch (cmp){
    case -1:
      tmpNode = cmpNode;
      cmpNode = cmpNode[0].right;//node.wordの方が後ろならcmpNodeを右に進める
      break;
    case 1:
      tmpNode = cmpNode;
      cmpNode = cmpNode[0].left;//node.wordが前ならcmpNodeを左に進める
      break;
    case 0:
      tmpNode = cmpNode;
      cmpNode = cmpNode[0].right;
      break;
    }
  }
  
  switch(cmp){
  case -1:
    tmpNode[0].right = node;//親の右に追加
    node[0].pare = tmpNode;
    break;
  case 1:
    tmpNode[0].left = node;//親の左に追加
    node[0].pare = tmpNode;
    break;
  case 0: //親の右に追加
    tmpNode[0].right = node;
    node[0].pare = tmpNode;
    break;
  }
  return;
}
  

#include "interCheck.h"
BinSTreeNode* createNode(const char* word){
  
  BinSTreeNode* newNode;
  int len;
  len=mystrlen(word)+1;
  newNode = (BinSTreeNode*)malloc(sizeof(BinSTreeNode));
  newNode[0].word = (char*)malloc(sizeof(char)*len);
  newNode[0].word = mystrcpy(newNode[0].word,word);
 
  newNode[0].left = NULL;
  newNode[0].right = NULL;
  newNode[0].pare = NULL;
  return newNode;
}

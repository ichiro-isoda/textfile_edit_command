#include "interCheck.h"
void substString(BinSTreeNode* rootNode,const char*sstr,const char* rstr){
  char* tmp;

  if(rootNode[0].left != NULL){
    substString(rootNode[0].left,sstr,rstr);
  }
  if(rootNode[0].right != NULL){
    substString(rootNode[0].right,sstr,rstr);
  }
  
  tmp = (char*)malloc(sizeof(char) * (mystrlen(rootNode[0].word)+1) );
  tmp=mystrcpy(tmp,rootNode[0].word);//rootNode[0].wordをfreeするために一時保存
  free(rootNode[0].word);
  rootNode[0].word=mystrsubst(tmp,sstr,rstr);
  free(tmp);
  return;
}

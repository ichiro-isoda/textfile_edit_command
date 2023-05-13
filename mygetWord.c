#include "interCheck.h"
BinSTreeNode* mygetWord(char** index,char* input_word,BinSTreeNode* rootNode){
  int mode;//単語を読む状態0　空白を読み飛ばす状態1
  int j;
  int point=0;
  int row=0;
  j = 0;
  mode = 1;
  while(input_word[j] != '\n'){//行末まで１文字ずつ読み進める
    if(input_word[j] != ' ' && mode == 0){ //mode 0で文字にぶつかった場合
      index[row][point] = input_word[j];
      point++;
    }
    else if(input_word[j] == ' ' && mode == 0){ //mode 0 で空白にぶつかった場合
      index[row][point] = '\0';
      mode = 1;
      row++;
    }
    else if(input_word[j] != ' ' && mode == 1){ //mode 1 で文字にぶつかった場合
      mode = 0;
      point = 0;
      index[row][point] = input_word[j];
      point++;
    }
    j++;
  }
  if(mode == 0){//単語を読む状態で行末を迎えた場合
    index[row][point] = '\0';
    row++;
  }
  int k=0; //rootNodeがない時の対応
  if(rootNode == NULL){
    if(index[0][0] != '\0'){ //改行文字しかinputに無かった場合
      rootNode = createNode(index[0]);
      k++;
    }
  }
  
  for(j=k;j<row;j++){
    addNode(rootNode,createNode(index[j]));
  }
  
  return rootNode;
}

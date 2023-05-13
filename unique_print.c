#include "interCheck.h"
char** unique_print(BinSTreeNode* rootNode,int order,char* print_word[]){
  int i;
  static int word_count;
  switch (order){
  case 0://前順走査
    if(word_count == 0){
      printf("%s\n",rootNode[0].word);
      print_word[word_count]=rootNode[0].word;
      word_count++;
    }
      
    for(i=0;i<word_count;i++){
      if(mystrcmp(rootNode[0].word,print_word[i]) == 0){
        break;
      }
    }
    if(i == word_count){
      printf("%s\n",rootNode[0].word);
      print_word[word_count]=rootNode[0].word;
      word_count++;
    }
    if(rootNode[0].left != NULL){
      print_word = unique_print(rootNode[0].left,order,print_word);
    }
    if(rootNode[0].right != NULL){
      print_word = unique_print(rootNode[0].right,order,print_word);
    }
    break;
  case 1://間順走査 右の子だけいる時大丈夫？
    if(rootNode[0].left != NULL){
      print_word = unique_print(rootNode[0].left,order,print_word);
    }
    if(word_count == 0){
      printf("%s\n",rootNode[0].word);
      print_word[word_count]=rootNode[0].word;
      word_count++;
    }
    for(i=0;i<word_count;i++){
      if(mystrcmp(rootNode[0].word,print_word[i]) == 0){
        break;
      }
    }
    if(i == word_count){
      printf("%s\n",rootNode[0].word);
      print_word[word_count]=rootNode[0].word;
      word_count++;
    }
    if(rootNode[0].right != NULL){
      print_word = unique_print(rootNode[0].right,order,print_word);
    }
    break;
  case 2://後順走査
    if(rootNode[0].left != NULL){
      print_word = unique_print(rootNode[0].left,order,print_word);
    }
    if(rootNode[0].right != NULL){
      print_word = unique_print(rootNode[0].right,order,print_word);
    }
    if(word_count == 0){
      printf("%s\n",rootNode[0].word);
      print_word[word_count]=rootNode[0].word;
      word_count++;
    }
    for(i=0;i<word_count;i++){
      if(mystrcmp(rootNode[0].word,print_word[i]) == 0){
        break;
      }
    }
    if(i == word_count){
      printf("%s\n",rootNode[0].word);
      print_word[word_count]=rootNode[0].word;
      word_count++;
    }
      break;
    }
  return print_word;
}

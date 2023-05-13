#include "interCheck.h"
int match_replace(char* arg,char* match,char* replace){
  int i = 0,j=0;
  int count=0;
  while(arg[i] != '\0'){

    switch(arg[i]){
    case '/':
      if(count == 1)j=0;
      count++;
      break;

    default:
      if(count == 1)match[j]=arg[i];
      if(count == 2)replace[j]=arg[i];
      if(count == 3)return 1;//最後の/の後ろに文字列
      j++;
    }
    i++;
  }
  if(count!=3)return 1;//spaceがある
  if(j==0)replace[0]='\0';//replaceが空白の場合
  return 0;
}

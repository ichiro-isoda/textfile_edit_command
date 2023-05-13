#include "interCheck.h"

int rem_arg(char* arg,char* rem_char){
  int i=0,j=0,delall,count=0;
  while(arg[i] != '\0'){
    switch(arg[i]){
    case '/':
      if(count == 1)j=0;
      count++;
      break;
    case ' ':
      if(count == 2)return 1;
    default:
      if(count == 1){
        rem_char[j]=arg[i];
        j++;
      }
      if(count == 2){
        if(j==0){
          if(arg[i]=='0'){
            delall=0;
            j++;
          }
          else {//１文字目が0かその他か
            delall=1;
            j++;
          }
        }
        else{
          delall=1;
          j++;
        }
      }
    }
    i++;
  }
  if(j==0)delall=1;//delallが何も入力されていなかった場合
  if(count != 3)return -1;
  return delall;
}

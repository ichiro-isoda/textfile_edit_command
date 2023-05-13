#include "ex10.h"
char* mystrsubst(const char* s1,const char* s2,const char* s3){
  int i=0,j=0,k,point=0;
  int start_len,from_len,to_len;
  start_len = mystrlen(s1);
  from_len = mystrlen(s2);
  to_len = mystrlen(s3);
  int max_len;
  char* new_str;
  //置換によって考えられる最大長で動的確保
  if ( to_len > from_len){
    max_len = start_len + (start_len/from_len) * (to_len - from_len) ;
  }
  else{
    max_len = start_len ;
  }
  max_len++;
  new_str = (char*)malloc(sizeof(char) * max_len);

  if(from_len != 0){
    while(s1[i] != '\0'){
      if(s1[i] == s2[j]){ //一致した場合は次の文字を検証
        j++;
      }
      else{
        new_str[point] = s1[i-j];//先頭文字だけ代入
        point++;
        i-=j;//一致し始めた次の文字から再度チェック
        j=0;
      }
      if(j == from_len ){ //完全に一致した場合一致した文字をs３に置換 一致したときj++してる
        for(k=0;k<to_len;k++){
          new_str[point] = s3[k];
          point++;
        }
        j=0;
      }  
      i++;
    }
  }
  else {  //s2が空白ならそのままs１を返す
    new_str = mystrcpy(new_str,s1);
    return new_str;
  }
  if(j != 0){  //途中まで一致した状態でs１が\nを迎えた場合
    for(k=0;k<j;k++){
          new_str[point] = s1[i-j+k];
          point++;
        }
  }
  new_str[point]='\0';
  return new_str;
}

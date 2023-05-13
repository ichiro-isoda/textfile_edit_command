

#include "interCheck.h"

int main(int argc,char* argv[]){
  BinSTreeNode* rootNode=NULL;
  char* input_word;
  input_word = (char*)malloc(sizeof(char)*word_len);
  FILE* fp;
  int i,j,k;
  char** index;
  index = (char**)malloc(sizeof(char*)*word_num);
  for(i=0;i<word_num;i++){
    index[i]=(char*)malloc(sizeof(char)*word_len);
  }
  
  //引数のチェックと入力ファイルの確認
  char opt_pri[3]={'-','p','\0'};
  char opt_sub[3]={'-','s','\0'};
  char opt_uni[3]={'-','u','\0'};
  char opt_remove[3]={'-','r','\0'};
  char opt_help[3]={'-','h','\0'};
  int option[option_num];//optionを数字で示す　-s=1 ,-r=2
  int option_count=0;
  int p_count=0;
  int u_count=0;
  int print_option=1,unique=0;
  char* match[option_num],*replace[option_num];
  int s_count=0,arg;
  int delall[option_num],r_count=0;
  char* rem_char[option_num];
  int file_exist=0;
  for(i=0;i<option_num;i++){
    match[i]=(char*)malloc(sizeof(char)*word_len);
    replace[i]=(char*)malloc(sizeof(char)*word_len);
    rem_char[i]=(char*)malloc(sizeof(char)*word_len);
  }
  for(i=1;i<argc;i++){
    if(mystrcmp(argv[i],opt_pri) ==0){//-pオプション
      if(p_count != 0){
        printf("usage: ERROR(-p use only once)");//複数の-pオプションへのエラー
        for(i=0;i<option_num;i++){
          free(match[i]);
          free(replace[i]);
          free(rem_char[i]);
        }
        for(i=0;i<word_num;i++){
          free(index[i]);
        }
        free(index);
        free(input_word);
        return 1;
      }
      switch(argv[i+1][0]){
      case '0':
        print_option=0;
        i++;
        break;
      case '1':
        print_option=1;
        i++;
        break;
      case '2':
        print_option=2;
        i++;
        break;
      case '-'://引数なし、次がオプション
        break;
      default://引数なし、ファイル名か　不適切な引数
        break;
      }
      p_count++;
    }
    else if(mystrcmp(argv[i],opt_sub) == 0){//-sオプション
      option[option_count]=1;
      if(argv[i+1] == NULL){
        printf("usage:ERROR (incorrect -r format follow -r /rmvmatch/delall/)");
        for(i=0;i<option_num;i++){
          free(match[i]);
          free(replace[i]);
          free(rem_char[i]);
        }
        for(i=0;i<word_num;i++){
          free(index[i]);
        }
        free(index);
        free(input_word);
        return 1;
      }
      arg=match_replace(argv[i+1],match[s_count],replace[s_count]);//matchとreplaceの分割
      if(arg ==1){
        printf("usage: ERROR(incorrect -s format follow -s /match/replace/");
        for(i=0;i<option_num;i++){
          free(match[i]);
          free(replace[i]);
          free(rem_char[i]);
        }
        for(i=0;i<word_num;i++){
          free(index[i]);
        }
        free(index);
        free(input_word);
        return 1;
      }
      s_count++;
      option_count++;
      i++;
    }
    else if(mystrcmp(argv[i],opt_uni) == 0){
      if(u_count != 0){//複数の-uオプションへのエラー
        printf("usage: ERROR(-u use only once)");
        for(i=0;i<option_num;i++){
          free(match[i]);
          free(replace[i]);
          free(rem_char[i]);
        }
        for(i=0;i<word_num;i++){
          free(index[i]);
        }
        free(index);
        free(input_word);
        return 1;
      }
      unique=1;//-uオプション
      u_count++;
    }
    else if(mystrcmp(argv[i],opt_remove) == 0){//-rオプション
      option[option_count]=2;
      if(argv[i+1] == NULL){
        printf("usage:ERROR (incorrect -r format follow -r /rmvmatch/delall/)");
        for(i=0;i<option_num;i++){
          free(match[i]);
          free(replace[i]);
          free(rem_char[i]);
        }
        for(i=0;i<word_num;i++){
          free(index[i]);
        }
        free(index);
        free(input_word);
        return 1;
      }
      delall[r_count]=rem_arg(argv[i+1],rem_char[r_count]);
      if(delall[r_count] == -1){
        printf("usage:ERROR (incorrect -r format follow -r /rmvmatch/delall/)");
        for(i=0;i<option_num;i++){
          free(match[i]);
          free(replace[i]);
          free(rem_char[i]);
        }
        for(i=0;i<word_num;i++){
          free(index[i]);
        }
        free(index);
        free(input_word);
        return 1;
      }
      option_count++;
      r_count++;
      i++;
    }
    else if(mystrcmp(argv[i],opt_help) == 0){
      printf("usage: ");
      printf("./pjt [Options] [Files]\n If there are no input files, it gets words from standard input.\n");
      printf("Options\n-s option: -s /match/replace/ replaces all words of parts of match to replace.\n");
      printf("-r option: -r /word/delall/ When delall is 0, all word are removed. When delall is not 0, only one word is removed \n");
      printf("-u option: -u print word only once\n");
      printf("-p option: -p [num] \n");
      for(i=0;i<option_num;i++){
          free(match[i]);
          free(replace[i]);
          free(rem_char[i]);
        }
        for(i=0;i<word_num;i++){
          free(index[i]);
        }
        free(index);
        free(input_word);
      return 0;
    }
    else if(argv[i][0] == '-'){
      printf("usage: ERROR(options are invalid)");
      for(i=0;i<option_num;i++){
        free(match[i]);
        free(replace[i]);
        free(rem_char[i]);
      }
      for(i=0;i<word_num;i++){
        free(index[i]);
      }
      free(index);
      free(input_word);
      return 1;
    }
    else{//オプションではない引数が来たらそれ以降ファイルと想定
      file_exist=1;
      break;
    }
  }
  
  int file_count = i;
  //ツリーの作成
  switch (file_exist){
  case 0://入力ファイルなし
    while(fgets(input_word,word_len,stdin) != NULL){
      rootNode=mygetWord(index,input_word,rootNode);//標準入力から単語を抽出してaddNode
    }
    break;
    
  default://引数ファイルあり
    while(file_count <argc){
      fp = fopen(argv[file_count],"r");
      if(fp == NULL){
        printf("usage: ERROR(File is NULL(read file))\n");
        for(i=0;i<option_num;i++){
          free(match[i]);
          free(replace[i]);
          free(rem_char[i]);
        }
        for(i=0;i<word_num;i++){
          free(index[i]);
        }
        free(index);
        free(input_word);
        clearBinSTree(rootNode);
        return 1;
      }
      while(fgets(input_word,word_len,fp) != NULL){// '\0'まで行ごとに読んでいく
        rootNode=mygetWord(index,input_word,rootNode);//ファイルから単語を抽出してaddNode
      }
      file_count++;
    }
    break;
  }


  j=0;
  k=0;
  //オプションの実行
  for(i=0;i<option_count;i++){
    switch(option[i]){
    case 1://-s
      if(rootNode ==NULL)break;//空の木に対する-s
      substString(rootNode,match[j],replace[j]);
      rootNode=removeEmpty(rootNode,rootNode);
      sortBinSTree(rootNode);
      j++;
      break;
    case 2://-r
      if(rootNode ==NULL)break;//空の木に対する-r
      rootNode = removeNode(rootNode,rootNode,rem_char[k],delall[k]);
      rootNode=removeEmpty(rootNode,rootNode);
      sortBinSTree(rootNode);
      k++;
      break;
    }
  }
  
  
  //出力
  char* print_word[word_num];
  printf("---BinSTree---\n");

  if(rootNode == NULL){
    printf("There is no node\n");
    for(i=0;i<option_num;i++){
      free(match[i]);
      free(replace[i]);
      free(rem_char[i]);
    }
    for(i=0;i<word_num;i++){
      free(index[i]);
    }
    free(index);
    free(input_word);
    return 0;
  }
  switch(unique){
  case 0:
    printTree(rootNode,print_option);
    break;
  case 1://重複表示しないユニークオプションの実装 
    unique_print(rootNode,print_option,print_word);
    break;
  }

  //後処理
  for(i=0;i<option_num;i++){
    free(match[i]);
    free(replace[i]);
    free(rem_char[i]);
  }
  for(i=0;i<word_num;i++){
    free(index[i]);
  }
  free(index);
  free(input_word);
  clearBinSTree(rootNode);
  
  return 0;
}

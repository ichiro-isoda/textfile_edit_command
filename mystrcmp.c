int mystrcmp(const char *s1,const char* s2){
  int j=0;
  while(s1[j] == s2[j] && s1[j] != '\0' && s2[j] != '\0'){ //先頭から比較
    j++;
  }
  if (s1[j] == '\0' && s2[j] == '\0'){
    return 0; //同じなら０
  }
  else if (s1[j] < s2[j] || s1[j] == '\0'){ 
    return -1; //s１のが前なら−１ EOFはASCIIの先頭あたりにある
  }
  else {
    return 1;
  }
}
  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define word_len 256
#define word_num 256
#define option_num 256

//define BinSTreeNode
typedef struct _BinSTreeNode{
  char *word;
  struct _BinSTreeNode *left;
  struct _BinSTreeNode *right;
  struct _BinSTreeNode *pare;
}BinSTreeNode;

//required functions
BinSTreeNode* createNode(const char *word);
void addNode(BinSTreeNode *rootNode, BinSTreeNode *node);
void printTree(BinSTreeNode *rootNode, int order);
void substString(BinSTreeNode *rootNode, const char *sstr, const char *rstr);
void sortBinSTree(BinSTreeNode *rootNode);
void clearBinSTree(BinSTreeNode *rootNode);
BinSTreeNode* removeNode(BinSTreeNode *rootNode,BinSTreeNode* node, const char *word, int delall);

//your additional functions
int mystrlen(const char* str);
int mystrcmp(const char* s1,const char* s2);
char* mystrsubst(const char* s1,const char* s2,const char* s3);
void mysortBinSTree(BinSTreeNode* new_rootNode,BinSTreeNode* node);
char* mystrcpy(char* s1, const char* s2);

BinSTreeNode* myremoveNode(BinSTreeNode* rootNode,BinSTreeNode* node);
BinSTreeNode* mygetWord(char** index,char* input_word,BinSTreeNode* rootNode);
int match_replace(char* arg,char* match,char* replace);
int rem_arg(char* arg,char* rem_char);
BinSTreeNode* removeEmpty(BinSTreeNode* rootNode,BinSTreeNode* node);
char** unique_print(BinSTreeNode* rootNode,int print_option,char* print_word[]);

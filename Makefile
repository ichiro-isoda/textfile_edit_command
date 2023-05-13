PROG = pjt
# OBJSに実行に必要なオブジェクトファイルを追加
OBJS = main_pjt.o createNode.o addNode.o printTree.o substString.o sortBinSTree.o clearBinSTree.o mystrlen.o mystrcmp.o mystrsubst.o mysortBinSTree.o mystrcpy.o mygetWord.o removeNode.o myremoveNode.o match_replace.o rem_arg.o myremoveNode.o removeEmpty.o unique_print.o
CC = gcc
CFLAGS = -g -Wall -O0
LDFLAGS = -lm
.PHONY: all
all: $(PROG)

.SUFFIXES: .o.c
.c.o:
	$(CC) $(CFLAGS) -c $<
$(PROG): $(OBJS)
	$(CC) -g -o $@ $^ $(LDFLAGS)
.PHONY: clean
clean:
	rm -f $(PROG) $(OBJS)

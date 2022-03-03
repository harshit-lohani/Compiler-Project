all: 
	gcc -o stage1exe driverNew.c lexer.c hashTable.c stack.c NaryTree.c parser.c

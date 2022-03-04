/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary
*/

#ifndef PARSERDEF
#define PARSERDEF

#include <stdio.h>
#include <stdlib.h>
#include "lexerDef.h"
#include "NaryTreeDef.h"

#define TOTAL_NON_TERMINALS 53
#define TOTAL_TERMINALS 60
#define NO_OF_RULES 94

#define MAX_SYMBOL_SIZE 51

#define BIT_VECTOR_SIZE (sizeof(int)-1+ TOTAL_TERMINALS)/sizeof(int)

extern char syntax_error_text[100][200];
extern int error_index;

//2D array for first and follow sets
typedef struct {
	int** first;
	int** follow;
} FirstAndFollow; 

typedef int** parseTable;
parseTable parse_table;
struct parseTreeNode* rootNode;

#endif
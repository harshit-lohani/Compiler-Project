/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary


*/

#ifndef STACKDEF
#define STACKDEF

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parserDef.h"
#include "NaryTreeDef.h"

typedef parseTreeNode stackData;
struct StackNode{
	stackData* stack_data;
	struct StackNode* next;
};

typedef struct StackNode StackNode;

typedef struct {
	StackNode* bottom;
	StackNode* top;
	int size;
} Stack;

#endif
/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stackDef.h"

Stack* initializeStack();
StackNode* createStackNode(stackData* stack_data);
StackNode* pop(Stack* stack);
StackNode* top(Stack* stack);
void push(Stack* stack, stackData* stack_data);
void pushAllChildrenOnStack(Stack* stack, stackData* stack_data);
void printStack(Stack* stack);
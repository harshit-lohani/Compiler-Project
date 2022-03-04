/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary


*/

#include "stack.h"
#include "parser.h"

Stack* initializeStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack -> bottom = NULL;
    stack -> top = NULL;
    stack -> size = 0;
    return stack;
}

StackNode* createStackNode(stackData* stack_data) {
    StackNode* stack_node = (StackNode*)malloc(sizeof(StackNode));
    stack_node -> stack_data = stack_data;
    stack_node -> next = NULL;
    return stack_node;
}

StackNode* pop(Stack* stack) {
    if (stack -> size == 0) {
        return NULL;
    }
    StackNode* temp = stack -> top;
    stack -> top = stack -> top -> next;
    stack -> size --;
    return temp;
}

StackNode* top(Stack* stack) {
    if(stack->size == 0) return NULL;
    return stack -> top;
}

void push(Stack* stack, stackData* stack_data) {
    StackNode* new_node = createStackNode(stack_data);
    if (stack -> size == 0) {
        stack -> top = new_node;
        stack -> bottom = new_node;
        stack -> size++;
    } else {
        new_node -> next = stack -> top;
        stack -> top = new_node;
        stack -> size++;
    }
}

void pushAllChildrenOnStack(Stack* stack, stackData* stack_data) {
    if (stack_data->nextSibling!=NULL)
    {
        pushAllChildrenOnStack(stack,stack_data->nextSibling);
    }
    push(stack,stack_data);
}


void printStack(Stack* stack) {
    StackNode* temp = stack->top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->stack_data->isTerminal);
        temp = temp->next;
    }
}
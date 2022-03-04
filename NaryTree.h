/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary
*/

#ifndef NARYTREE
#define NARYTREE

#include "NaryTreeDef.h"

parseTreeNode* createNode(int isTerminal, int type, parseTreeNode* parent, Token* token, int rule_no);
parseTreeNode* initializeParseTree();
parseTreeNode* addChildren(char* rule, parseTreeNode* parent);
void printParseTreeUtility(parseTreeNode* root, char** tokenMap, char** nonterminals, FILE* outputfile);
void printNode(parseTreeNode* root, char** tokenMap, char** non_terminals, FILE* outputfile);

void printParseTreeUtility2(parseTreeNode* root, char** tokenMap, char** nonterminals);
void printNode2(parseTreeNode* root, char** tokenMap, char** non_terminals);

#endif
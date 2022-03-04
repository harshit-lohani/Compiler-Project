/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary
*/

#ifndef AST
#define AST

#include "lexerDef.h"
#include "astDef.h"
#include "NaryTreeDef.h"
#include "parserDef.h"


astNode* createAST(parseTreeNode* tree);
void print_ast(astNode* ast);
float return_mul(int number);
astNode* get_last_node(astNode* node);
void manage_term_values(astNode** main, astNode** ptr1_temporary, astNode** ptr2_temporary);
void manage_term_prime(astNode** main, astNode** ptr1_temporary, astNode** ptr2_temporary);
astNode* make_ast_node(astNode* temp,Label label, astNode* parent, astNode* first_kid, astNode* next, Token* token);

#endif
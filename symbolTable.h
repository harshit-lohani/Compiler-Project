/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary


*/

#ifndef SYMBOLTABLE
#define SYMBOLTABLE

#include "symbolTableDef.h"


void semantic_analysis(astNode* root);
N_Rec* generateRNode(field_list* fields,Token* token);
N_Id* generateINode(Token* varTok,Token* funTok,Token* typeToken,Type type,int isGlobal,int* offset);
N_Func* generateFNode(Token* token);
int measure_r_node_similarity(int similarity_quo,void* node1, void* node2);
int measure_f_node_similarity(int similarity_quotient, void* node1, void* node2);
int measure_i_node_similarity(void* node1, void* node2, int symbol_table_or_type_check);
void generate_I_table(astNode* root, astNode* parent);
void generate_R_table(astNode* root, astNode* parent);
void generate_F_table(astNode* root, astNode* parent);
void initialize_symbol_tables(astNode* ast);
void remove_node(SymbolTable* st, void* node);
void* retrieve(field_list* f_list, SymbolTable* st1, void* node, int node_type, int symbol_table_or_type_check);
void insert(int to_insert, SymbolTable** st2,void* node, int node_type);

void printSymbolTable(SymbolTable* htPtr);
void printGlobalSymbolTable(SymbolTable* htPtr);
void printFunctionTable(SymbolTable* htPtr);
void printRecordTable(SymbolTable* htPtr);
funList* generate_function_list(Token* Tk_f, N_Id* identifier);
funIDNode* generate_function_id(N_Id* identifier);
char* printType(N_Rec* ptr_to_rec);

#endif

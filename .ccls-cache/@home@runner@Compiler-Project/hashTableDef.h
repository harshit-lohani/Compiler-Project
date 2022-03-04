/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary


*/

#ifndef HASHTABLEDEF
#define HASHTABLEDEF

#include "lexerDef.h"

#define NUMBER_OF_SLOTS 500

struct node{
    Tokentype tType;
    char* lexeme;
    struct node* next;
};

typedef struct node Node;

typedef struct {
    struct node* head;
} Entry;



typedef struct {
    int m; // no of slots in hash table
    Entry* entries; 
} Table;

Table* lookUpTable;

struct pNode{
    int tType;
    char* lexeme;
    struct pNode* next;
};

typedef struct pNode pNode;

typedef struct {
    struct pNode* head;
} pEntry;

typedef struct {
    int m; // no of slots in hash table
    pEntry* entries; 
} pTable;

pTable* plookupTable;

#endif
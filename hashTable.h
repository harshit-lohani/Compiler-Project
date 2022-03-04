/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary
*/
#ifndef HASHTABLE
#define HASHTABLE

#include "hashTableDef.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hashValue(char* str, int m);
Table* createAndPopulateLookUpTable(char** tokens, int no_of_tokens, int no_of_slots);
int lookUp(char* lex);
pTable* createLookUpTable(int no_of_slots);
pTable* PopulateLookUpTable(pTable* table,char** tokens,int no_of_tokens, int no_of_slots);
int pLookUp(pTable* lookupTable,char* lex);

#endif


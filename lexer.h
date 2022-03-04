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

#include "lexerDef.h"

//Function Declarations

void appendNewLine(FILE* fp);
Token* getNextToken(FILE** file_ptr);
FILE* getStream(FILE* file_ptr);
void addToken(Token* token, Tokentype type, char* lexeme, int valueType, Value* value);
void initializeLexer();
void unSetOverFlag();
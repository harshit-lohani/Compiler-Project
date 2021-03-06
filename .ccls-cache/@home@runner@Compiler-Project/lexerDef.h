/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary
*/

#ifndef LEXERDEF
#define LEXERDEF

#define TOTAL_TERMINALS_INCLUDING_ERROR 60
#define NO_SLOTS 200

typedef enum{
    TK_ASSIGNOP,
    TK_COMMENT,
    TK_FIELDID,
    TK_ID,
    TK_NUM,
    TK_RNUM,//CC  pattern changed little bit doubt in this
    TK_FUNID,
    TK_RUID, //CC  changed purpose changed little bit
    TK_WITH,
    TK_PARAMETERS,
    TK_END,
    TK_WHILE, // pattern changed little bit capital W
    TK_UNION,//CC  added
    TK_ENDUNION,//CC  added
    TK_DEFINETYPE,//CC  added
    TK_AS,//CC  added
    TK_TYPE, // pattern changed little bit capital T
    TK_MAIN,
    TK_GLOBAL, // pattern changed little bit capital G
    TK_PARAMETER,
    TK_LIST, // pattern changed little bit capital L
    TK_SQL,
    TK_SQR,
    TK_INPUT,//changed pattern capital I
    TK_OUTPUT, // changed pattern capital O
    TK_INT, // changed pattern capital I
    TK_REAL, // changed pattern capital R
    TK_COMMA,
    TK_SEM,
    TK_COLON,
    TK_DOT,
    TK_ENDWHILE,
    TK_OP,
    TK_CL,
    TK_IF, //
    TK_THEN, //
    TK_ENDIF, //cahnged pattern starting letter capital
    TK_READ, //
    TK_WRITE, //
    TK_RETURN, //
    TK_PLUS,
    TK_MINUS,
    TK_MUL,
    TK_DIV,
    TK_CALL,// cahnged pattern starting letter capital
    TK_RECORD,// cahnged pattern starting letter capital
    TK_ENDRECORD,
    TK_ELSE,//cahnged pattern starting letter capital
    TK_AND,
    TK_OR,
    TK_NOT,
    TK_LT,
    TK_LE,
    TK_EQ,
    TK_GT,
    TK_GE,
    TK_NE,
    EPSILON,
    DOLLAR,
    TK_ERROR
} Tokentype;

typedef struct {
	int num;
	float r_num;
} Value;

typedef struct{
    
    Tokentype type; // enum    
    int line_no; // line number
    char* lexeme; // actual lexeme
    Value* value; // resulting value
    int vtype; // 0 for int, 1 for real, -1 for other, -2 for ERROR

} Token;

#include "hashTable.h"

#endif
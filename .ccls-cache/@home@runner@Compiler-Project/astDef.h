/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary
*/

#ifndef ASTDEF
#define ASTDEF

#include "lexerDef.h"

typedef enum{
    PROGRAM_NODE,
	OTHERFUNCTIONS_NODE,
	MAINFUNCTION_NODE,
	FUNCTIONDEF_NODE,
	INPUTPAR_NODE,
	OUTPUTPAR_NODE,
	ID_NODE,
	INT_NODE,
	REAL_NODE,
	RECORDID_NODE,
	TYPEDEFINITIONS_NODE,
	DECLARATIONS_NODE,
	OTHERSTATEMENTS_NODE,
	FIELDID_NODE,
	GLOBALID_NODE,
	ASSIGNOP_NODE,
	CALL_NODE,
	FUNCTIONCALL_NODE,
	OUTPUTPARAMETERS_NODE,
	INPUTPARAMETERS_NODE,
	WHILE_NODE,
	IF_NODE,
	ELSE_NODE,
	IOREAD_NODE,
	IOWRITE_NODE, 
	NUM_NODE,
	RNUM_NODE,
	MULOP_NODE,
	DIVOP_NODE,
	PLUSOP_NODE,
	MINUSOP_NODE,
	NOTOP_NODE,
	LTOP_NODE,
	GTOP_NODE,
	LEOP_NODE,
	GEOP_NODE,
	EQOP_NODE,
	NEOP_NODE,
	ANDOP_NODE,
	OROP_NODE,
	RETURN_NODE
}Label;


struct astlist{
	struct astNode* head;
	int size;
	struct astNode* tail;
};
typedef struct astlist astChildren;


struct astNode{


	Label label;

	struct astNode* parent;

	
	struct astNode* first_kid;

	
	struct astNode* next; 

	
	Token* token; 

	
	int line_no;


};

typedef struct astNode astNode;

extern int AST_SIZE;

#endif
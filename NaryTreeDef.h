/*
Group:38
2019A7PS0048P Dhairya Rikul Shah
2019A7PS0061P Harshit Raj Lohani
2019A7PS0124P Kshitij Banka
2019A7PS0014P Rohini Prakash
2019A7PS0082P Raghav Chaudhary
*/

#ifndef NARYTREEDEF
#define NARYTREEDEF

#include "lexerDef.h"
#include "parserDef.h"
#include "hashTableDef.h"
#include "astDef.h"

typedef enum{
	program,
	mainFunction,
	otherFunctions,
	function,
	input_par,
	output_par,
	parameter_list,
	dataType,
	primitiveDatatype,
	constructedDatatype,
	remaining_list,
	stmts,
	typeDefinitions,
	actualOrRedefined,
	typeDefinition,
	fieldDefinitions,
	fieldDefinition,
	fieldType,
	moreFields,
	declarations,
	declaration,
	global_or_not,
	otherStmts,
	stmt,
	assignmentStmt,
	singleOrRecId,
	option_single_constructed,
	oneExpansion,
	moreExpansions,
	funCallStmt,
	outputParameters,
	inputParameters,
	iterativeStmt,
	conditionalStmt,
	elsePart,
	ioStmt,
	arithmeticExpression,
	expPrime,
	term,
	termPrime,
	factor,
	highPrecedenceOperators,
	lowPrecedenceOperators,
	booleanExpression ,
	var ,  
	logicalOp ,  
	relationalOp ,  
	returnStmt ,  
	optionalReturn ,  
	idList ,  
	more_ids ,  
	definetypestmt ,  
	A
} NonTerminal;

typedef union {
	Tokentype terminalType;
	NonTerminal nonTerminalType;
} symbolType;

struct parseTreeNode{
    int isTerminal;
    symbolType symType;
    struct parseTreeNode* nextSibling;
    Token* token;
    struct parseTreeNode* parent;
    int no_children;
    struct parseTreeNode* first_kid;
	int rule_no;
	
	// astNode* addr;
	// astNode* inh_addr;
};

typedef struct parseTreeNode parseTreeNode;

extern int PARSER_SIZE;

#endif
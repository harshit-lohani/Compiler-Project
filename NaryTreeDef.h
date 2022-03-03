/*
Group:33
2016A7PS0036P Megh Thakkar
2016A7PS0103P Sahil Singla
2016A7PS0110P Sankalp Sangle
2016A7PS0150P Patel Parth
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
	operator,
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
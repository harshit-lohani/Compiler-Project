/*
Group:33
2016A7PS0036P Megh Thakkar
2016A7PS0103P Sahil Singla
2016A7PS0110P Sankalp Sangle
2016A7PS0150P Patel Parth
*/

/*
Todo
1.Name errrors appropriately
2.Remove comments and don't tokenize them
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "NaryTree.h"
#include "hashTable.h"
#include "lexer.h"
#include "parser.h"
#include "stack.h"
// #include "ast.h"
// #include "symbolTable.h"
// #include "typeChecker.h"
// #include "codeGeneration.h"

char *tokenMap2[] = {
    "TK_ASSIGNOP", "TK_COMMENT",   "TK_FIELDID", "TK_ID",       "TK_NUM",
    "TK_RNUM",     "TK_FUNID",     "TK_RUID",    "TK_WITH",     "TK_PARAMETERS",
    "TK_END",      "TK_WHILE",     "TK_UNION",   "TK_ENDUNION", "TK_DEFINETYPE",
    "TK_AS",       "TK_TYPE",      "TK_MAIN",    "TK_GLOBAL",   "TK_PARAMETER",
    "TK_LIST",     "TK_SQL",       "TK_SQR",     "TK_INPUT",    "TK_OUTPUT",
    "TK_INT",      "TK_REAL",      "TK_COMMA",   "TK_SEM",      "TK_COLON",
    "TK_DOT",      "TK_ENDWHILE",  "TK_OP",      "TK_CL",       "TK_IF",
    "TK_THEN",     "TK_ENDIF",     "TK_READ",    "TK_WRITE",    "TK_RETURN",
    "TK_PLUS",     "TK_MINUS",     "TK_MUL",     "TK_DIV",      "TK_CALL",
    "TK_RECORD",   "TK_ENDRECORD", "TK_ELSE",    "TK_AND",      "TK_OR",
    "TK_NOT",      "TK_LT",        "TK_LE",      "TK_EQ",       "TK_GT",
    "TK_GE",       "TK_NE",        "EPSILON",    "DOLLAR",      "TK_ERROR"};
char *keywords2[] = {
    NULL,     NULL,        NULL,         NULL,         NULL,        NULL,
    NULL,     NULL,        "with",       "parameters", "end",       "while",
    "union",  "endunion",  "definetype", "as",         "type",      "_main",
    "global", "parameter", "list",       NULL,         NULL,        "input",
    "output", "int",       "real",       NULL,         NULL,        NULL,
    NULL,     "endwhile",  NULL,         NULL,         "if",        "then",
    "endif",  "read",      "write",      "return",     NULL,        NULL,
    NULL,     NULL,        "call",       "record",     "endrecord", "else",
    NULL,     NULL,        NULL,         NULL,         NULL,        NULL,
    NULL,     NULL,        NULL,         NULL,         NULL,        NULL};

char *non_terminals2[] = {"program",
                         "mainFunction",
                         "otherFunctions",
                         "function",
                         "input_par",
                         "output_par",
                         "parameter_list",
                         "dataType",
                         "primitiveDatatype",
                         "constructedDatatype",
                         "remaining_list",
                         "stmts",
                         "typeDefinitions",
                         "actualOrRedefined",
                         "typeDefinition",
                         "fieldDefinitions",
                         "fieldDefinition",
                         "fieldType",
                         "moreFields",
                         "declarations",
                         "declaration",
                         "global_or_not",
                         "otherStmts",
                         "stmt",
                         "assignmentStmt",
                         "singleOrRecId",
                         "option_single_constructed",
                         "oneExpansion",
                         "moreExpansions",
                         "funCallStmt",
                         "outputParameters",
                         "inputParameters",
                         "iterativeStmt",
                         "conditionalStmt",
                         "elsePart",
                         "ioStmt",
                         "arithmeticExpression",
                         "expPrime",
                         "term",
                         "termPrime",
                         "factor",
                         "highPrecedenceOperators",
                         "lowPrecedenceOperators",
                         "operator",
                         "booleanExpression",
                         "var",
                         "logicalOp",
                         "relationalOp",
                         "returnStmt",
                         "optionalReturn",
                         "idList",
                         "more_ids",
                         "definetypestmt",
                         "A"};
// char* keywords2[] = {NULL,    NULL,    NULL,    NULL,    NULL,    NULL, NULL,
// NULL,  "with",    "parameters",    "end",    "while",    "type",    "_main",
// "global",    "parameter",    "list",    NULL,    NULL,    "input", "output",
// "int",    "real",    NULL,    NULL,    NULL,    NULL,    "endwhile",    NULL,
// NULL,    "if",    "then",    "endif",    "read",    "write",    "return",
// NULL,    NULL,    NULL,    NULL,    "call",    "record",    "endrecord",
// "else",    NULL,    NULL,    NULL,    NULL,    NULL,    NULL,    NULL, NULL,
// NULL,    NULL,   NULL,   NULL};
char symbol_table_errors[20][200];
int initialized_plook_up = 0;
int initialized_look_up = 0;
int created_parse_table = 0;
int root_node_created = 0;
int initialized_lexer = 0;
int grammar_file_closed = 0;
int ast_created = 0;
int symbol_tables_created = 0;

#define SIZE 1.3

// void getMemory(int * p1, int * p2) {
// 	*p1  = PARSER_SIZE*(sizeof(parseTreeNode));
// 	AST_SIZE *= SIZE;
// 	*p2= AST_SIZE*(sizeof(astNode));
// }

int main(int argc, char *argv[]) {

  if (argc != 3) {
    printf("Check command: ./compiler testcase(x).txt outputParseTree.txt\n");
    return 0;
  }
  clock_t start_time1, end_time1, start_time2, end_time2;

  int syntax_errors = 0;

  printf("***************************Information of implementation "
         "details:***************************\n\n");
  printf("LEVEL 4 : AST / Symbol Table / Type Checker / Semantic Module work "
         "correctly\n");

  printf("***************************End of implementation "
         "details***************************\n\n");

  double total_CPU_time1, total_CPU_time_in_seconds1, total_CPU_time2,
      total_CPU_time_in_seconds2, total_CPU_time3, total_CPU_time_in_seconds3;
  FILE *fp1 = fopen(argv[1], "r");
  // appendNewLine(fp1);

  printf("----------------------------- Execution started "
         "-----------------------------\n");

  if (initialized_lexer == 0) {
    initializeLexer();
    initialized_lexer = 1;
  }
  int break_loop = 0;
  char test_file_name[100];
  strcpy(test_file_name, argv[1]);
  // astNode* ast = NULL;
  while (1) {

    printf("\nEnter the number corresponding to the functionality:\n\n");
    printf("0: Exit the interface\n");
    printf("1: For removal of comments\n");
    printf("2: For printing the token list generated by the lexer");
    printf("3: To verify the syntactic correctness of the input source code "
           "and print the parse tree\n");
    printf("4: For printing the total time taken\n");
    printf("\n\nYour Input: ");

    int choice;
    int x = scanf("%d", &choice);
    printf("Choice : %d\n", choice);
    switch (choice) {

    case 0: {
      break_loop = 1;
    } break;

    case 1: {
      removeComments(test_file_name, "out.txt");
    } break;

    case 2: {
      // FILE* f = freopen("out1.txt", "w", stdout);
      if (initialized_lexer == 0) {
        initializeLexer();
        initialized_lexer = 1;
      }
      char temp_file_name[100];
      strcpy(temp_file_name, test_file_name);
      FILE *fp = fopen(temp_file_name, "r");
      unSetOverFlag();
      Token *token;
      while ((token = getNextToken(&fp)) != NULL) {
        printf("Line No : %d\t Lexeme : %s\t Token type : %s\n", token->line_no,
               token->lexeme, tokenMap2[token->type]);
        if (fp == NULL) {
          printf("File pointer null\n");
        }
      }
      if (fp != NULL)
        fclose(fp);
      strcpy(test_file_name, temp_file_name);
    } break;

    case 3: {
      char temp_file_name[100];
      strcpy(temp_file_name, test_file_name);
      printf("Syntax analysis of %s\n", test_file_name);
      unSetOverFlag();
      start_time1 = clock();
      if (initialized_lexer == 0) {
        initializeLexer();
        initialized_lexer = 1;
        printf("Stage 1");
      }
      if (initialized_plook_up == 0) {
          printf("1\n");
        plookupTable = createLookUpTable(NUMBER_OF_SLOTS);
          printf("2\n");
        plookupTable = PopulateLookUpTable(plookupTable, tokenMap2,
                                           TOTAL_TERMINALS, NUMBER_OF_SLOTS);
          printf("3\n");
          printf("%lu", sizeof(non_terminals2)/sizeof(non_terminals2[0]));
        plookupTable = PopulateLookUpTable(
            plookupTable, non_terminals2, TOTAL_NON_TERMINALS, NUMBER_OF_SLOTS);
          printf("4\n");
        initialized_plook_up = 1;
        printf("Stage 2");
      }
      FirstAndFollow *first_and_follow = ComputeFirstAndFollowSets(NUMBER_OF_SLOTS);
        

      printf("wgesrdver");
      printFirstAndFollow(first_and_follow);
      if (created_parse_table == 0) {
        parse_table = createParseTable(first_and_follow);
        created_parse_table = 1;
      }
      // printParseTable(parse_table);

      if (root_node_created == 0) {
        rootNode =
            parseInputSourceCode(temp_file_name, parse_table, &syntax_errors);
        root_node_created = 1;
      }

      FILE *outputfile = fopen("out.txt", "w");
      fprintf(outputfile, "%-25s %-10s %-15s %-15s %-10s %-5s %s\n\n\n",
              "LEXEME", "LINE", "TOKEN", "VALUE", "PARENT", "IS LEAF?",
              "NODE SYMBOL");

      printParseTreeUtility(rootNode, tokenMap2, non_terminals2, outputfile);
      if (syntax_errors == 0)
        printf("Input source code is syntactically correct.\n");
      else
        printf("Input source code is syntactically incorrect\n");

      FILE *fp = fopen("out.txt", "r");
      char ch;
      while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);
      end_time1 = clock();
      total_CPU_time1 = (double)(end_time1 - start_time1);
      total_CPU_time_in_seconds1 = total_CPU_time1 / CLOCKS_PER_SEC;
    } break;

      // case 3:{
      // 	if(created_parse_table == 1 && syntax_errors == 0 &&
      // root_node_created == 1) { 		start_time2 = clock();
      // ast = createAST(rootNode); 		printf("%-25s %-25s %-25s %-25s
      // %-25s\n","Label","Lexeme","Parent","First Child","Sibling");
      // 		print_ast(ast);
      // 		ast_created = 1;
      // 		initialize_symbol_tables(ast);
      // 		symbol_tables_created = 1;
      // 		end_time2 = clock();
      // 		total_CPU_time2 = (double) (end_time2 - start_time2);
      // 		total_CPU_time_in_seconds2 = total_CPU_time2 /
      // CLOCKS_PER_SEC;
      // 	}
      // 	else {
      // 		if(syntax_errors == 1) {
      // 			printf("Input source code is syntactically
      // incorrect. Hence, AST not being created.\n");
      // 		}
      // 		if(root_node_created == 0) {
      // 			printf("Parse tree not yet created. Press 2
      // first to generate it.\n");
      // 		}
      // 	}
      // } break;

      // case 4:{
      // 	int parse_tree_memory;
      // 	int ast_memory;
      // 	getMemory( &parse_tree_memory, &ast_memory);
      // 	printf("Parse Tree Number of Nodes : %d     Allocated Memory :
      // %d\n", PARSER_SIZE, parse_tree_memory); 	printf("AST Number of
      // Nodes : %d            Allocated Memory : %d\n", AST_SIZE, ast_memory);
      // 	if(ast_created == 1)
      // 		printf("Compression Ratio =
      // %f\n",(1.0*(parse_tree_memory-return_mul(ast_memory))/parse_tree_memory*100.0));
      // 	else {
      // 		if(syntax_errors == 1) {
      // 			printf("Input source code is syntactically
      // incorrect. Hence, AST not being created.\n"); 		}else{
      // 			if(root_node_created == 0) {
      // 				printf("Parse tree not yet created.
      // Press 2 first to generate it.\n");
      // 			}
      // 			else {
      // 				printf("AST not yet created. Press 3
      // first to generate it.\n");
      // 			}
      // 		}
      // 	}
      // }break;

      // case 5:{
      // 	if(ast_created == 1) {
      // 		printf("-----------------------Identifier
      // Table-----------------------------\n");
      // 		printSymbolTable(IdentifierTable);
      // 	}
      // 	else {
      // 		printf("AST not yet created. Please press 3\n");
      // 	}
      // }break;

      // case 6:{
      // 	if(symbol_tables_created == 1) {
      // 		printf("%-30s %-30s %-30s %-30s\n",
      // 					"Lexeme",
      // 					"Type",
      // 					"Offset",
      // 					"-----"
      // 					);
      // 		printGlobalSymbolTable(IdentifierTable);
      // 	} else {
      // 		printf("AST not yet created. Please press 3\n");
      // 	}
      // }break;

      // case 7:{
      // 	if(symbol_tables_created == 1) {
      // 		printf("-------------------------Function
      // Table----------------------------\n"); 		printf("%-30s
      // %s\n","Lexeme", "Width");
      // printFunctionTable(FunctionTable); 	} else {
      // printf("AST not yet created. Please press 3\n");
      // 	}

      // }break;

      // case 8:{
      // 	if(symbol_tables_created == 1) {
      // 		printf("------------------------Record
      // Table----------------------------\n");
      // printRecordTable(RecordTable);

      // 	} else {
      // 		printf("AST not yet created. Please press 3\n");
      // 	}	break;
      // }
      // case 9:{
      // 	if(ast_created==0)
      // 	{
      // 			if(syntax_errors==1)
      // 			{
      // 				printf("Syntax errors exist.\n");
      // 				for(int i = 0; i < error_index; i++) {
      // 					printf("%s",
      // syntax_error_text[i]);
      // 				}
      // 				continue;
      // 			}
      // 			printf("AST not created. Press 3 for creating
      // AST\n"); 			continue;
      // 	}
      // 	if(syntax_errors==1)
      // 	{
      // 		printf("Syntax errors exist.\n");
      // 		for(int i = 0; i < error_index; i++) {
      // 					printf("%s",
      // syntax_error_text[i]);
      // 		}
      // 	}
      // 	else
      // 	{
      // 		printf("No syntax errors exist\n");
      // 		if(ast_created==0)
      // 		{
      // 			if(syntax_errors==1)
      // 			{
      // 				printf("Syntax errors exist. Refer to
      // case 2 for all syntax errors\n");
      // 			}
      // 			else
      // 			{
      // 				printf("AST not created. Press 3 for
      // creating AST\n");
      // 			}

      // 		}
      // 		else
      // 		{
      // 			for(int i = 0; i < symbol_table_error_index;
      // i++) { 					printf("%s",
      // symbol_table_errors_text[i]);
      // 			}
      // 			semantic_analysis(ast);
      // 			if(semantic_errors_detected == 0)
      // 			{
      // 				printf("No semantic errors exist\n");
      // 			}
      // 		}
      // 	}
      // 	printf("Total CPU time : %lf\n", total_CPU_time1 +
      // total_CPU_time2); 	printf("Total CPU time in seconds : %lf\n",
      // total_CPU_time_in_seconds1 + total_CPU_time_in_seconds2);

      // }break;

      // case 10:{
      // 	//start_code_generation(ast);
      // 	//generate_asm(argv[2]);
      // 	printf("Code Generation module not implemented\n");
      // }break;
    }

    if (break_loop)
      break;
  }
  printf("----------------------------- Execution complete "
         "-----------------------------\n");

  return 0;
}

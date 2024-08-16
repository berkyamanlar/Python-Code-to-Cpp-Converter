/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220114

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "project.y"

	#include <stdio.h>
	#include <iostream>
	#include <string>
	#include <map>
	using namespace std;
	#include "y.tab.h"
	extern FILE *yyin;
	extern int yylex();
	void yyerror(string s);
	
	extern int linenum;
	bool errorFlag=false;
	int isTab=-1;
	#include <vector>
	#include <algorithm>
	vector<int> ss;
	vector<bool> ssCond;
	vector<int> ssWhat; /* 1=if, 2=elif, 3=else*/
	map<string,int>varType; /* 1=int 2=float 3=string*/
	map<string,string>stringVars;
	map<string,string>intVars;
	map<string,string>floatVars;
	
	int lastSt;
	


	
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 32 "project.y"
typedef union YYSTYPE
{
	int number;
	char * str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 67 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define PRINTF 257
#define PERCENTINT 258
#define IFST 259
#define ELIFST 260
#define ELSEST 261
#define COMMA 262
#define EQUAL 263
#define SEMICOLON 264
#define COLON 265
#define OPS 266
#define CPS 267
#define COMPARISON 268
#define MATH 269
#define OP 270
#define CP 271
#define IDENTIFIER 272
#define TAB 273
#define QUOTE 274
#define INT 275
#define FLOAT 276
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    3,    3,    4,
    4,    5,    5,    6,    6,    9,    9,    9,    9,    9,
    7,    7,    8,    8,    8,    8,   10,   10,   11,   11,
   11,   11,   12,   12,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    1,    1,    1,    6,    7,    6,
    7,    2,    3,    1,    2,    3,    3,    3,    3,    5,
    1,    3,    1,    1,    1,    3,    1,    3,    1,    1,
    1,    3,    1,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,   33,    0,    1,    0,    4,    5,
    6,    7,   14,    0,    0,    0,   12,    0,    3,    0,
    0,    0,   34,   15,    0,   25,   23,   24,    0,   21,
    0,    0,    0,    0,    0,    0,    0,    0,   13,    0,
    0,    0,    0,    0,   31,   29,   30,    0,   27,    0,
    0,   26,    0,   22,    0,    0,    0,   20,    0,    0,
    8,   10,   32,   28,    0,    0,    9,   11,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  259,  260,  261,  272,  273,  278,  279,  280,  281,  282,
  283,  284,  287,  290,  273,  273,  265,  263,  279,  259,
  260,  261,  273,  287,  270,  272,  275,  276,  285,  286,
  285,  272,  274,  275,  276,  285,  273,  273,  265,  285,
  268,  269,  268,  270,  272,  275,  276,  288,  289,  285,
  285,  271,  285,  286,  285,  288,  269,  274,  268,  268,
  265,  265,  271,  289,  285,  285,  265,  265,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          6,
    7,    8,    9,   10,   11,   12,   29,   30,   13,   48,
   49,   14,
};
static const YYINT yysindex[] = {                      -257,
 -273, -248, -253, -235,    0,    0,    0, -257,    0,    0,
    0,    0,    0, -250, -234, -234,    0, -241,    0, -236,
 -233, -221,    0,    0, -234,    0,    0,    0, -209,    0,
 -207,    0, -225,    0,    0, -223, -234, -234,    0, -252,
 -234, -234, -234, -225,    0,    0,    0, -261,    0, -205,
 -203,    0, -226,    0, -213, -251, -225,    0, -234, -234,
    0,    0,    0,    0, -212, -211,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,   55,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    0,    6,   21,   24,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
   59,    0,    0,    0,    0,    0,  -11,   26,   56,   25,
   14,    0,
};
#define YYTABLESIZE 297
static const YYINT yytable[] = {                         15,
   18,    1,    2,    3,   31,   16,   36,   57,   20,   21,
   22,   17,   58,   40,    4,    5,   42,   57,   52,   63,
   17,    4,   23,   19,   16,   50,   51,   18,   25,   53,
   32,   55,   33,   34,   35,   25,   37,   26,   61,   38,
   27,   28,   42,   39,   44,   42,   45,   65,   66,   46,
   47,   62,   67,   68,    2,   42,   42,   42,   41,   42,
   43,   42,   59,   42,   60,   42,   19,   54,   56,   24,
   64,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   18,
   18,   18,    0,    0,   16,   16,   16,    0,    0,   25,
    0,    0,   18,   18,   23,    0,    0,   16,   16,   17,
   17,   17,   19,   19,   19,    0,    0,    0,    0,   24,
    0,    0,   17,   17,    0,   19,   19,
};
static const YYINT yycheck[] = {                        273,
    0,  259,  260,  261,   16,    0,   18,  269,  259,  260,
  261,  265,  274,   25,  272,  273,  269,  269,  271,  271,
    0,  272,  273,    0,  273,   37,   38,  263,  270,   41,
  272,   43,  274,  275,  276,  270,  273,  272,  265,  273,
  275,  276,  269,  265,  270,  269,  272,   59,   60,  275,
  276,  265,  265,  265,    0,  269,  269,  269,  268,  269,
  268,  269,  268,  269,  268,  269,    8,   42,   44,   14,
   57,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,
  260,  261,   -1,   -1,  259,  260,  261,   -1,   -1,  269,
   -1,   -1,  272,  273,  269,   -1,   -1,  272,  273,  259,
  260,  261,  259,  260,  261,   -1,   -1,   -1,   -1,  269,
   -1,   -1,  272,  273,   -1,  272,  273,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#define YYUNDFTOKEN 291
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","PRINTF","PERCENTINT","IFST",
"ELIFST","ELSEST","COMMA","EQUAL","SEMICOLON","COLON","OPS","CPS","COMPARISON",
"MATH","OP","CP","IDENTIFIER","TAB","QUOTE","INT","FLOAT","$accept","start",
"program","statement","if_block","elif_block","else_block","assignment_block",
"expression","value","assignment","expquote","valuequote","tab_block",
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : program",
"program : statement",
"program : statement program",
"statement : if_block",
"statement : elif_block",
"statement : else_block",
"statement : assignment_block",
"if_block : IFST TAB expression COMPARISON expression COLON",
"if_block : tab_block IFST TAB expression COMPARISON expression COLON",
"elif_block : ELIFST TAB expression COMPARISON expression COLON",
"elif_block : tab_block ELIFST TAB expression COMPARISON expression COLON",
"else_block : ELSEST COLON",
"else_block : tab_block ELSEST COLON",
"assignment_block : assignment",
"assignment_block : tab_block assignment",
"assignment : IDENTIFIER EQUAL INT",
"assignment : IDENTIFIER EQUAL FLOAT",
"assignment : IDENTIFIER EQUAL IDENTIFIER",
"assignment : IDENTIFIER EQUAL expression",
"assignment : IDENTIFIER EQUAL QUOTE expquote QUOTE",
"expression : value",
"expression : expression MATH value",
"value : INT",
"value : FLOAT",
"value : IDENTIFIER",
"value : OP expression CP",
"expquote : valuequote",
"expquote : expquote MATH valuequote",
"valuequote : INT",
"valuequote : FLOAT",
"valuequote : IDENTIFIER",
"valuequote : OP expquote CP",
"tab_block : TAB",
"tab_block : tab_block TAB",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 1152 "project.y"

void yyerror(string s){
	cerr<<"Syntax Error at line: "<<linenum<<endl;
	errorFlag=true;
}


int yywrap(){
	return 1;
}
int main(int argc, char *argv[])
{
    /* Call the lexer, then quit. */
    yyin=fopen(argv[1],"r");
    yyparse();
    fclose(yyin);
	

    return 0;
}
#line 505 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 47 "project.y"
	{
		
		cout << "void main()\n{"<<endl;
		
		map<string, string>::iterator it;
		
		if(!intVars.empty())
		{
			cout<<"\tint ";
			for ( it = intVars.begin(); it != prev(intVars.end()); it++ )
			{
				cout << it->first << "_int,";
			}
			cout << it->first << "_int";
			cout << ";" << endl;
		}
		
		if(!floatVars.empty())
		{
			cout<<"\tfloat ";
			for ( it = floatVars.begin(); it != prev(floatVars.end()); it++ )
			{
				cout << it->first << "_flt,";
			}
			cout << it->first << "_flt";
			cout << ";" << endl;
		}
		
		if(!stringVars.empty())
		{
			cout<<"\tstring ";
			for ( it = stringVars.begin(); it != prev(stringVars.end()); it++ )
			{
				cout << it->first << "_str,";
			}
			cout << it->first << "_str";
			cout << ";" << endl;
		}
		cout<<endl;
		
		cout<<yystack.l_mark[0].str;
		cout <<"}"<<endl;
		cout << endl;
	}
#line 1221 "y.tab.c"
break;
case 2:
#line 94 "project.y"
	{
		if(lastSt==1 | lastSt==2 | lastSt==3)
		{
			cout << "error in line " << linenum-1 << ": at least one line should be inside if/elif/else block" << endl;
			exit(1);
		}
		yyval.str=strdup(yystack.l_mark[0].str);
	}
#line 1233 "y.tab.c"
break;
case 3:
#line 104 "project.y"
	{
		string combined=string(yystack.l_mark[-1].str)+string(yystack.l_mark[0].str);
		yyval.str=strdup(combined.c_str());
	}
#line 1241 "y.tab.c"
break;
case 4:
#line 111 "project.y"
	{ yyval.str=strdup(yystack.l_mark[0].str); linenum++; lastSt=1;}
#line 1246 "y.tab.c"
break;
case 5:
#line 113 "project.y"
	{ yyval.str=strdup(yystack.l_mark[0].str); linenum++; lastSt=2;}
#line 1251 "y.tab.c"
break;
case 6:
#line 115 "project.y"
	{ yyval.str=strdup(yystack.l_mark[0].str); linenum++; lastSt=3; }
#line 1256 "y.tab.c"
break;
case 7:
#line 117 "project.y"
	{yyval.str=strdup(yystack.l_mark[0].str); linenum++; lastSt=4; }
#line 1261 "y.tab.c"
break;
case 8:
#line 122 "project.y"
	{
		
		string tempp=yystack.l_mark[-3].str;
		char tempChar=tempp[0];
		string tempStr(1, tempChar);
		int tempType=varType[ tempStr ];  
		
		for(int i=1; i<tempp.length(); i++)
		{
			if(tempp[i]!='*' && tempp[i]!='/' && tempp[i]!='-' && tempp[i]!='+')
			{
				char tempChar=tempp[i];
				string tempStr(1, tempChar);
				int tempType2=varType[ tempStr ];
				
				if(tempType==1 && tempType2==2)
				{
					tempType=2;
				}
				else if( (tempType==1 && tempType2==3) | (tempType==2 && tempType2==3) | (tempType==3 && tempType2==1) | (tempType==3 && tempType2==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		string tempp2=yystack.l_mark[-1].str;
		char tempChar2=tempp2[0];
		string tempStr2(1, tempChar2);
		int tempTypeB=varType[ tempStr2 ];  
		
		for(int i=1; i<tempp2.length(); i++)
		{
			if(tempp2[i]!='*' && tempp2[i]!='/' && tempp2[i]!='-' && tempp2[i]!='+')
			{
				char tempChar2=tempp2[i];
				string tempStr2(1, tempChar2);
				int tempType3=varType[ tempStr2 ];
				
				if(tempTypeB==1 && tempType3==2)
				{
					tempTypeB=2;
				}
				else if( (tempTypeB==1 && tempType3==3) | (tempTypeB==2 && tempType3==3) | (tempTypeB==3 && tempType3==1) | (tempTypeB==3 && tempType3==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		if( (tempType==3 && tempTypeB==1) | (tempType==3 && tempTypeB==2) | (tempType==1 && tempTypeB==3) | (tempType==2 && tempTypeB==3) )
		{
			cout << "comparison type mismatch in line " << linenum << endl;
			exit(1);
		}

		if(ss.empty())
		{		
		
			isTab=1;
			string combined = "\t" + string(yystack.l_mark[-5].str) + "(" + " " + string(yystack.l_mark[-3].str) + " " + string(yystack.l_mark[-2].str) + " " + string(yystack.l_mark[-1].str) + " " + ")" + "\n" + "\t" + "{" + "\n";
			yyval.str=strdup(combined.c_str());
	
			ss.push_back(0);
			ssCond.push_back(false);
			ssWhat.push_back(1);
		}
		else if(ss.size()>=1 && ssCond.back()==true)
		{
			string ssCurl;
			
			while(!ss.empty())
			{
				string ssNumCurl(ss.back(), '\t');
				ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
				
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
			}
			
			isTab=1;
			string combined = ssCurl + "\t" + string(yystack.l_mark[-5].str) + "(" + " " + string(yystack.l_mark[-3].str) + " " + string(yystack.l_mark[-2].str) + " " + string(yystack.l_mark[-1].str) + " " + ")" + "\n" + "\t" + "{" + "\n";
			yyval.str=strdup(combined.c_str());
		
			ss.push_back(0);
			ssCond.push_back(false);
			ssWhat.push_back(1);
		}
		else if(ss.size()>=1 && ssCond.back()==false)
		{
			cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
			exit(1);
		}
		else
		{
			cout << "if/else inconsistency at line: "<< linenum << endl;
			exit(1);
		}

	}
#line 1368 "y.tab.c"
break;
case 9:
#line 227 "project.y"
	{
		
		string tempp=yystack.l_mark[-3].str;
		char tempChar=tempp[0];
		string tempStr(1, tempChar);
		int tempType=varType[ tempStr ];  
		
		for(int i=1; i<tempp.length(); i++)
		{
			if(tempp[i]!='*' && tempp[i]!='/' && tempp[i]!='-' && tempp[i]!='+')
			{
				char tempChar=tempp[i];
				string tempStr(1, tempChar);
				int tempType2=varType[ tempStr ];
				
				if(tempType==1 && tempType2==2)
				{
					tempType=2;
				}
				else if( (tempType==1 && tempType2==3) | (tempType==2 && tempType2==3) | (tempType==3 && tempType2==1) | (tempType==3 && tempType2==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		string tempp2=yystack.l_mark[-1].str;
		char tempChar2=tempp2[0];
		string tempStr2(1, tempChar2);
		int tempTypeB=varType[ tempStr2 ];  
		
		for(int i=1; i<tempp2.length(); i++)
		{
			if(tempp2[i]!='*' && tempp2[i]!='/' && tempp2[i]!='-' && tempp2[i]!='+')
			{
				char tempChar2=tempp2[i];
				string tempStr2(1, tempChar2);
				int tempType3=varType[ tempStr2 ];
				
				if(tempTypeB==1 && tempType3==2)
				{
					tempTypeB=2;
				}
				else if( (tempTypeB==1 && tempType3==3) | (tempTypeB==2 && tempType3==3) | (tempTypeB==3 && tempType3==1) | (tempTypeB==3 && tempType3==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		if( (tempType==3 && tempTypeB==1) | (tempType==3 && tempTypeB==2) | (tempType==1 && tempTypeB==3) | (tempType==2 && tempTypeB==3) )
		{
			cout << "comparison type mismatch in line " << linenum << endl;
			exit(1);
		}
			
		if (isTab == -1 || yystack.l_mark[-6].number > isTab)
		{
			cout << "tab inconsistency in line "<< linenum << endl;
			exit(1);
		}
		else
		{

			
			if( (ss.size()!=0) && ssCond.back()==false && yystack.l_mark[-6].number==ss.back()+1 )
			{
				ssCond.back()=true;
				
				ss.push_back(yystack.l_mark[-6].number);
				ssCond.push_back(false);
				ssWhat.push_back(1);
				
				isTab=yystack.l_mark[-6].number+1; 
				string stuff(yystack.l_mark[-6].number, '\t');
				string combined = "\t" + stuff + string(yystack.l_mark[-5].str) + "(" + " " +string(yystack.l_mark[-3].str)  +" " + string(yystack.l_mark[-2].str) + " " + string(yystack.l_mark[-1].str) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
				yyval.str=strdup(combined.c_str());
			}
			else if( (ss.size()!=0) && ssCond.back()==true && yystack.l_mark[-6].number==ss.back()+1 )
			{
				ss.push_back(yystack.l_mark[-6].number);
				ssCond.push_back(false);
				ssWhat.push_back(1);
				
				isTab=yystack.l_mark[-6].number+1;
				string stuff(yystack.l_mark[-6].number, '\t');
				string combined = "\t" + stuff + string(yystack.l_mark[-5].str) + "(" + " " +string(yystack.l_mark[-3].str)  +" " + string(yystack.l_mark[-2].str) + " " + string(yystack.l_mark[-1].str) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
				yyval.str=strdup(combined.c_str());
				
			}
			else if( (ss.size()!=0) && ssCond.back()==true && yystack.l_mark[-6].number==ss.back() )
			{	
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				ss.push_back(yystack.l_mark[-6].number);
				ssCond.push_back(false);
				ssWhat.push_back(1);
				
				isTab=yystack.l_mark[-6].number+1;
				string stuff(yystack.l_mark[-6].number, '\t');
				string combined = "\t" + stuff + string(yystack.l_mark[-5].str) + "(" + " " +string(yystack.l_mark[-3].str)  +" " + string(yystack.l_mark[-2].str) + " " + string(yystack.l_mark[-1].str) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
				yyval.str=strdup(combined.c_str());
			}
			else if( (ss.size()!=0) && ssCond.back()==true && yystack.l_mark[-6].number<ss.back() )
			{
				
				while( yystack.l_mark[-6].number!=ss.back() ) 
				{
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
				}
				
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				ss.push_back(yystack.l_mark[-6].number);
				ssCond.push_back(false);
				ssWhat.push_back(1);
				
				isTab=yystack.l_mark[-6].number+1;
				string stuff(yystack.l_mark[-6].number, '\t');
				string combined  = "\t" + stuff + string(yystack.l_mark[-5].str) + "(" + " " +string(yystack.l_mark[-3].str) + " " + string(yystack.l_mark[-2].str) + " " + string(yystack.l_mark[-1].str) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
				yyval.str=strdup(combined.c_str());
				
			}
			else if( ss.size()!=0 && ssCond.back()==false )
			{
				cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
				exit(1);
			}
			else
			{
				cout << "if/else inconsistency at line: "<< linenum << endl;
				exit(1);
			}
		}
	}
#line 1515 "y.tab.c"
break;
case 10:
#line 374 "project.y"
	{	
	
		string tempp=yystack.l_mark[-3].str;
		char tempChar=tempp[0];
		string tempStr(1, tempChar);
		int tempType=varType[ tempStr ];  
		
		for(int i=1; i<tempp.length(); i++)
		{
			if(tempp[i]!='*' && tempp[i]!='/' && tempp[i]!='-' && tempp[i]!='+')
			{
				char tempChar=tempp[i];
				string tempStr(1, tempChar);
				int tempType2=varType[ tempStr ];
				
				if(tempType==1 && tempType2==2)
				{
					tempType=2;
				}
				else if( (tempType==1 && tempType2==3) | (tempType==2 && tempType2==3) | (tempType==3 && tempType2==1) | (tempType==3 && tempType2==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		string tempp2=yystack.l_mark[-1].str;
		char tempChar2=tempp2[0];
		string tempStr2(1, tempChar2);
		int tempTypeB=varType[ tempStr2 ];  
		
		for(int i=1; i<tempp2.length(); i++)
		{
			if(tempp2[i]!='*' && tempp2[i]!='/' && tempp2[i]!='-' && tempp2[i]!='+')
			{
				char tempChar2=tempp2[i];
				string tempStr2(1, tempChar2);
				int tempType3=varType[ tempStr2 ];
				
				if(tempTypeB==1 && tempType3==2)
				{
					tempTypeB=2;
				}
				else if( (tempTypeB==1 && tempType3==3) | (tempTypeB==2 && tempType3==3) | (tempTypeB==3 && tempType3==1) | (tempTypeB==3 && tempType3==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		if( (tempType==3 && tempTypeB==1) | (tempType==3 && tempTypeB==2) | (tempType==1 && tempTypeB==3) | (tempType==2 && tempTypeB==3) )
		{
			cout << "comparison type mismatch in line " << linenum << endl;
			exit(1);
		}
			
		if( ss.size()>=1 && ssWhat.front()==1 && ssCond.back()==true )
		{
			string ssCurl;
			
			while(!ss.empty())
			{
				string ssNumCurl(ss.back(), '\t');
				ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
				
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
			}
			
			isTab=1;
			string combined = ssCurl  + "\t" + string("else if") + " " + "(" + " " + string(yystack.l_mark[-3].str) + " " + string(yystack.l_mark[-2].str) + " " + string(yystack.l_mark[-1].str) + " " + ")" + "\n" + "\t" + "{" + "\n";
			yyval.str=strdup(combined.c_str());
			
			ss.push_back(0);
			ssCond.push_back(false);
			ssWhat.push_back(2);
		}
		else if( ss.size()==0 )
		{
			cout << "elif without if in line " << linenum << endl;
			exit(1);
		}
		else if( ss.size()>=1 && ssWhat.back()==3 )
		{
			cout << "elif after else in line " << linenum << endl;
			exit(1);
		}
		else if( ss.size()>=1 && ssCond.back()==false )
		{
			cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
			exit(1);
		}
		else
		{
			cout << "if/else inconsistency at line: "<< linenum << endl;
			exit(1);
		}
	}
#line 1620 "y.tab.c"
break;
case 11:
#line 477 "project.y"
	{
		
		string tempp=yystack.l_mark[-3].str;
		char tempChar=tempp[0];
		string tempStr(1, tempChar);
		int tempType=varType[ tempStr ];  
		
		for(int i=1; i<tempp.length(); i++)
		{
			if(tempp[i]!='*' && tempp[i]!='/' && tempp[i]!='-' && tempp[i]!='+')
			{
				char tempChar=tempp[i];
				string tempStr(1, tempChar);
				int tempType2=varType[ tempStr ];
				
				if(tempType==1 && tempType2==2)
				{
					tempType=2;
				}
				else if( (tempType==1 && tempType2==3) | (tempType==2 && tempType2==3) | (tempType==3 && tempType2==1) | (tempType==3 && tempType2==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		string tempp2=yystack.l_mark[-1].str;
		char tempChar2=tempp2[0];
		string tempStr2(1, tempChar2);
		int tempTypeB=varType[ tempStr2 ];  
		
		for(int i=1; i<tempp2.length(); i++)
		{
			if(tempp2[i]!='*' && tempp2[i]!='/' && tempp2[i]!='-' && tempp2[i]!='+')
			{
				char tempChar2=tempp2[i];
				string tempStr2(1, tempChar2);
				int tempType3=varType[ tempStr2 ];
				
				if(tempTypeB==1 && tempType3==2)
				{
					tempTypeB=2;
				}
				else if( (tempTypeB==1 && tempType3==3) | (tempTypeB==2 && tempType3==3) | (tempTypeB==3 && tempType3==1) | (tempTypeB==3 && tempType3==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		if( (tempType==3 && tempTypeB==1) | (tempType==3 && tempTypeB==2) | (tempType==1 && tempTypeB==3) | (tempType==2 && tempTypeB==3) )
		{
			cout << "comparison type mismatch in line " << linenum << endl;
			exit(1);
		}
	
		if (isTab == -1 || yystack.l_mark[-6].number > isTab)
		{
			cout << "tab inconsistency in line "<< linenum << endl;
			exit(1);
		}
		else
		{
			if( (ss.size()!=0) && ssCond.back()==true && yystack.l_mark[-6].number==ss.back() )
			{
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				ss.push_back(yystack.l_mark[-6].number);
				ssCond.push_back(false);
				ssWhat.push_back(2);
				
				isTab=yystack.l_mark[-6].number+1;
				string stuff(yystack.l_mark[-6].number, '\t');
				string combined = stuff + "\t" +  string("}") + "\n" + "\t" + stuff + string("else if") + " " + "(" + " " +string(yystack.l_mark[-3].str) + " " + string(yystack.l_mark[-2].str) + " " + string(yystack.l_mark[-1].str) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
				yyval.str=strdup(combined.c_str());
			}
			else if( (ss.size()!=0) && ssCond.back()==true && yystack.l_mark[-6].number<ss.back() )
			{
				while(yystack.l_mark[-6].number!=ss.back())
				{
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
				}
				if(ssWhat.back()==1)
				{
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
					
					ss.push_back(yystack.l_mark[-6].number);
					ssCond.push_back(false);
					ssWhat.push_back(2);
					
					isTab=yystack.l_mark[-6].number+1;
					string stuff(yystack.l_mark[-6].number, '\t');
					string combined=stuff + "\t" +  string("}") + "\n" + "\t" + stuff + string("else if") + " " + "(" + " " +string(yystack.l_mark[-3].str) + " " + string(yystack.l_mark[-2].str) + " " + string(yystack.l_mark[-1].str) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
					yyval.str=strdup(combined.c_str());
				}
				else
				{
					cout << "if/else inconsistency at line: "<< linenum << endl;
					exit(1);
				}
				
				
			}
			else if( ss.size()==0 )
			{
				cout << "elif without if in line " << linenum << endl;
				exit(1);
			}
			else if( ss.size()!=0 && ssWhat.back()==3 )
			{
				cout << "elif after else in line " << linenum << endl;
				exit(1);
			}
			else if(ss.size()!=0 && ssCond.back()==false)
			{
				cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
				exit(1);
			}
			else if( ss.size()!=0 && yystack.l_mark[-6].number>ss.back() )
			{
				cout << "elif without if in line " << linenum << endl;
				exit(1);
			}
			else
			{
				cout << "if/else inconsistency at line: "<< linenum << endl;
				exit(1);
			}
		}
	}
#line 1762 "y.tab.c"
break;
case 12:
#line 620 "project.y"
	{
		if( ss.size()>=1 && (ssWhat.front()==1 || ssWhat.front()==2 ) && ssCond.back()==true )
		{
			string ssCurl;
			
			while(!ss.empty())
			{
				string ssNumCurl(ss.back(), '\t');
				ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
				
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
			}
			
			isTab=1;
			string combined= ssCurl + "\t"  + string(yystack.l_mark[-1].str) + "\n" + "\t" + "{" + "\n";
			yyval.str=strdup(combined.c_str());
			
			ss.push_back(0);
			ssCond.push_back(false);
			ssWhat.push_back(3);
		}
		else if( ss.size()==0 )
		{
			cout << "else without if in line " << linenum << endl;
			exit(1);
		}
		else if( ss.size()>=1 && ssCond.back()==false )
		{
			cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
			exit(1);
		}
		else
		{
			cout << "if/else inconsistency at line: "<< linenum << endl;
			exit(1);
		}
	}
#line 1805 "y.tab.c"
break;
case 13:
#line 661 "project.y"
	{
		if (isTab == -1 || yystack.l_mark[-2].number > isTab)
		{
			cout << "tab inconsistency in line "<< linenum << endl;
			exit(1);
		}
		else
		{
			if( (ss.size()!=0) && ssCond.back()==true && yystack.l_mark[-2].number==ss.back() )
			{
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				ss.push_back(yystack.l_mark[-2].number);
				ssCond.push_back(false);
				ssWhat.push_back(3);
				
				isTab=yystack.l_mark[-2].number+1;
				string stuff(yystack.l_mark[-2].number, '\t');
				string combined= stuff+ "\t" + string("}") + "\n" + "\t" + stuff + string(yystack.l_mark[-1].str) + "\n" + stuff + "\t" + "{" + "\n";
				yyval.str=strdup(combined.c_str());
			}
			else if( (ss.size()!=0) && ssCond.back()==true && yystack.l_mark[-2].number<ss.back() )
			{
				while(yystack.l_mark[-2].number!=ss.back())
				{
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
				}
				if(ssWhat.back()==1)
				{
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
					
					ss.push_back(yystack.l_mark[-2].number);
					ssCond.push_back(false);
					ssWhat.push_back(3);
					
					isTab=yystack.l_mark[-2].number+1;
					string stuff(yystack.l_mark[-2].number, '\t');
					string combined=stuff+ "\t" + string("}") + "\n" + "\t" + stuff + string(yystack.l_mark[-1].str) + "\n" + stuff + "\t" + "{" + "\n";
					yyval.str=strdup(combined.c_str());
				}
				else
				{
					cout << "if/else inconsistency at line: "<< linenum << endl;
					exit(1);
				}
				
				
			}
			else if(ss.size()==0)
			{
				cout << "else without if in line " << linenum << endl;
				exit(1);
			}
			else if( ss.size()!=0 && ssCond.back()==false )
			{
				cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
				exit(1);
			}
			else if( ss.size()!=0 && yystack.l_mark[-2].number>ss.back() )
			{
				cout << "else without if in line " << linenum << endl;
				exit(1);
			}
			else
			{
				cout << "if/else inconsistency at line: "<< linenum << endl;
				exit(1);
			}
		}
	}
#line 1885 "y.tab.c"
break;
case 14:
#line 741 "project.y"
	{
		if(ss.empty())
		{
			isTab=0;
			string combined= "\t" + string(yystack.l_mark[0].str) + "\n";
			yyval.str=strdup(combined.c_str());
		}
		else if( !ss.empty() && ssCond.back()==true )
		{
			string ssCurl;
			
			while( !ss.empty() ) 
			{
				string ssNumCurl(ss.back(), '\t');
				ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
			
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
			}
			
			ss.pop_back();
			ssCond.pop_back();
			ssWhat.pop_back();
			
			isTab=0;
			string combined = ssCurl + "\t" + string(yystack.l_mark[0].str) + "\n";
			yyval.str=strdup(combined.c_str());
		}
		else if( !ss.empty() && ssCond.back()==false )
		{
			cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
			exit(1);
		}
		else
		{
			cout << "if/else inconsistency at line: "<< linenum << endl;
			exit(1);
		}

	}
#line 1930 "y.tab.c"
break;
case 15:
#line 784 "project.y"
	{
		if (isTab == -1 || yystack.l_mark[-1].number > isTab)
		{
			cout << "tab inconsistency in line "<< linenum << endl;
			exit(1);
		}
		else
		{
			if( (ss.size()!=0) && ssCond.back()==false && yystack.l_mark[-1].number==ss.back()+1 )
			{
				ssCond.back()=true;
				
				string stuff(yystack.l_mark[-1].number, '\t');
				string combined= "\t" + stuff + string(yystack.l_mark[0].str) + "\n";
				yyval.str=strdup(combined.c_str());
				
			}
			else if( (ss.size()!=0) && ssCond.back()==true && yystack.l_mark[-1].number==ss.back()+1 )
			{
				string stuff(yystack.l_mark[-1].number, '\t');
				string combined= "\t" + stuff + string(yystack.l_mark[0].str) + "\n";
				yyval.str=strdup(combined.c_str());
			}
			else if( (ss.size()!=0) && ssCond.back()==true && yystack.l_mark[-1].number==ss.back() ) 
			{
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				string stuff(yystack.l_mark[-1].number, '\t');
				string combined = stuff+ "\t" + string("}") + "\n"+ "\t" + stuff + string(yystack.l_mark[0].str) + "\n";
				yyval.str=strdup(combined.c_str());
				
			}
			else if( (ss.size()!=0) && ssCond.back()==true && yystack.l_mark[-1].number<ss.back() )
			{	
				string ssCurl;
				
				while( yystack.l_mark[-1].number!=ss.back() ) 
				{
					string ssNumCurl(ss.back(), '\t');
					ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
				
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
				}
				string ssNumCurl(ss.back(), '\t');
				ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
				
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				string stuff(yystack.l_mark[-1].number, '\t');
				string combined = ssCurl + "\t" + stuff + string(yystack.l_mark[0].str) + "\n";
				yyval.str=strdup(combined.c_str());
				
			}
			else if( ss.size()!=0 && ssCond.back()==false )
			{
				cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
				exit(1);
			}
			else
			{
				cout << "if/else inconsistency at line: "<< linenum << endl;
				exit(1);
			}
		}
	}
#line 2005 "y.tab.c"
break;
case 16:
#line 859 "project.y"
	{
		varType[string(yystack.l_mark[-2].str)]=1;
		intVars[string(yystack.l_mark[-2].str)]=yystack.l_mark[0].str;
		
		string combined= string(yystack.l_mark[-2].str)+string("_int")+" "+string(yystack.l_mark[-1].str)+" "+string(yystack.l_mark[0].str)+";";
		yyval.str=strdup(combined.c_str());
	}
#line 2016 "y.tab.c"
break;
case 17:
#line 868 "project.y"
	{
		varType[string(yystack.l_mark[-2].str)]=2;
		floatVars[string(yystack.l_mark[-2].str)]=yystack.l_mark[0].str;
		
		string combined=string(yystack.l_mark[-2].str)+string("_flt")+" "+string(yystack.l_mark[-1].str)+" "+string(yystack.l_mark[0].str)+";";
		yyval.str=strdup(combined.c_str());
	}
#line 2027 "y.tab.c"
break;
case 18:
#line 877 "project.y"
	{
		
		if( varType.find(string(yystack.l_mark[0].str))==varType.end() )
		{
			cout<<"Line "<<linenum<<": variable "<<yystack.l_mark[0].str<<" is not declared\n";
			exit(1);
		}
			
		if( varType[string(yystack.l_mark[0].str)]==1 )
		{
			varType[string(yystack.l_mark[-2].str)]=1;
			intVars[string(yystack.l_mark[-2].str)]=yystack.l_mark[0].str;
			
			string combined=string(yystack.l_mark[-2].str)+string("_int")+" "+string(yystack.l_mark[-1].str)+" "+string(yystack.l_mark[0].str)+string("_int")+";";
			yyval.str=strdup(combined.c_str());
		}
		else if( varType[string(yystack.l_mark[0].str)]==2 )
		{
			varType[string(yystack.l_mark[-2].str)]=2;
			floatVars[string(yystack.l_mark[-2].str)]=yystack.l_mark[0].str;
			
			string combined=string(yystack.l_mark[-2].str)+string("_flt")+" "+string(yystack.l_mark[-1].str)+" "+string(yystack.l_mark[0].str)+string("_flt")+";";
			yyval.str=strdup(combined.c_str());
		}
		else if( varType[string(yystack.l_mark[0].str)]==3 )
		{
			varType[string(yystack.l_mark[-2].str)]=3;
			stringVars[string(yystack.l_mark[-2].str)]=yystack.l_mark[0].str;
			
			string combined=string(yystack.l_mark[-2].str)+string("_str")+" "+string(yystack.l_mark[-1].str)+" "+string(yystack.l_mark[0].str)+string("_str")+";";
			yyval.str=strdup(combined.c_str());
		}

	}
#line 2065 "y.tab.c"
break;
case 19:
#line 913 "project.y"
	{
		string tempp=yystack.l_mark[0].str;
		string tempStr;
		int i=0;
		if(tempp[0]=='-')
		{
			i=1;
			while( i<tempp.length() && tempp[i]!='+' && tempp[i]!='-' && tempp[i]!='/' && tempp[i]!='*' )
			{
				tempStr=tempStr+tempp[i];
				i++;
			}
		}
		else
		{
			i=0;
			while( i<tempp.length() && tempp[i]!='+' && tempp[i]!='-' && tempp[i]!='/' && tempp[i]!='*' )
			{
				tempStr=tempStr+tempp[i];
				i++;
			}
		}	
		
		int tempType=0;
		if( isalpha(tempStr[0]) )
		{	
			tempStr=tempStr.erase(tempStr.size()-5);
			tempType = varType[ string(tempStr) ];
		}
		else if( isdigit(tempStr[0]) )
		{
			float num=stof(tempStr);
			if( int(num)-num < 0 )
			{
				tempType=2;
			}
			else if( int(num)-num == 0 )
			{
				tempType=1;
			}
		}
	
		for(int j=i+1; j<tempp.length(); j++)
		{
			int k=j;
			string tempStr2;
			while( k<tempp.length() && tempp[k]!='+' && tempp[k]!='-' && tempp[k]!='/' && tempp[k]!='*')
			{
				tempStr2=tempStr2+tempp[k];
				k++;
			}
			j=k;
			
			int tempType2=0;
			if( isalpha(tempStr2[1]) )
			{
				if(tempStr2.find("_int") != string::npos) {tempType2=1;}
				if(tempStr2.find("_flt") != string::npos) {tempType2=2;}
				if(tempStr2.find("_str") != string::npos) {tempType2=3;}
			}
			else if( isdigit(tempStr2[1]) )
			{
				float num=stof(tempStr2);
				if( int(num)-num < 0 )
				{
					tempType2=2;
				}
				else if( int(num)-num == 0 )
				{
					tempType2=1;
				}
			}
			
			if( (tempType==1 && tempType2==3) | (tempType==2 && tempType2==3) | (tempType==3 && tempType2==1) | (tempType==3 && tempType2==2) )
			{
				cout << "type mismatch in line " << linenum << endl;
				exit(1);
			}
			else if( tempType==2 && (tempType2==1 | tempType2==2) )
			{
				tempType=2;
			}
			else if( tempType==1 && tempType2==2 )
			{
				tempType=2;
			}
			else if( tempType==1 && tempType2==1 )
			{
				tempType=1;
			}
		}

		
		varType[ string(yystack.l_mark[-2].str) ] = tempType;
		if(tempType==1)
		{	
			intVars[string(yystack.l_mark[-2].str)]=yystack.l_mark[0].str;
			string combined = string(yystack.l_mark[-2].str)+string("_int") + " " + string(yystack.l_mark[-1].str) + " " + string(yystack.l_mark[0].str) + ";";
			yyval.str=strdup(combined.c_str());
		}
		else if(tempType==2)
		{
			floatVars[string(yystack.l_mark[-2].str)]=yystack.l_mark[0].str;
			string combined = string(yystack.l_mark[-2].str)+string("_flt") + " " + string(yystack.l_mark[-1].str) + " " + string(yystack.l_mark[0].str) + ";";
			yyval.str=strdup(combined.c_str());
		}
		else if(tempType==3)
		{
			stringVars[string(yystack.l_mark[-2].str)]=yystack.l_mark[0].str;
			string combined = string(yystack.l_mark[-2].str)+string("_str") + " " + string(yystack.l_mark[-1].str) + " " + string(yystack.l_mark[0].str) + ";";
			yyval.str=strdup(combined.c_str());
		}
		
		
		
	}
#line 2185 "y.tab.c"
break;
case 20:
#line 1031 "project.y"
	{
		varType[string(yystack.l_mark[-4].str)]=3;
		string cmbd = string(yystack.l_mark[-2].str)+string(yystack.l_mark[-1].str)+string(yystack.l_mark[0].str);
		stringVars[string(yystack.l_mark[-4].str)]=cmbd;
		
		string combined=string(yystack.l_mark[-4].str)+ "_flt" +" "+string(yystack.l_mark[-3].str)+" "+string(yystack.l_mark[-2].str)+string(yystack.l_mark[-1].str)+string(yystack.l_mark[0].str)+";";
		yyval.str=strdup(combined.c_str());
	}
#line 2197 "y.tab.c"
break;
case 21:
#line 1043 "project.y"
	{
		yyval.str=yystack.l_mark[0].str;
	}
#line 2204 "y.tab.c"
break;
case 22:
#line 1048 "project.y"
	{		
		string combined=string(yystack.l_mark[-2].str)+" "+string(yystack.l_mark[-1].str)+" "+string(yystack.l_mark[0].str);
		yyval.str=strdup(combined.c_str());
	}
#line 2212 "y.tab.c"
break;
case 23:
#line 1056 "project.y"
	{
		yyval.str=strdup(yystack.l_mark[0].str);
	}
#line 2219 "y.tab.c"
break;
case 24:
#line 1061 "project.y"
	{

		yyval.str=strdup(yystack.l_mark[0].str);
	}
#line 2227 "y.tab.c"
break;
case 25:
#line 1067 "project.y"
	{

		if( varType.find(string(yystack.l_mark[0].str))==varType.end() )
		{
			cout<<"Line "<<linenum<<": variable "<<yystack.l_mark[0].str<<" is not declared\n";
			exit(1);
		}
		
		if( varType[string(yystack.l_mark[0].str)]==1 )
		{

			string combined=string(yystack.l_mark[0].str)+string("_int");
			yyval.str=strdup(combined.c_str());
		}
		else if( varType[string(yystack.l_mark[0].str)]==2 )
		{

			string combined=string(yystack.l_mark[0].str)+string("_flt");
			yyval.str=strdup(combined.c_str());
		}
		else if( varType[string(yystack.l_mark[0].str)]==3 )
		{

			string combined=string(yystack.l_mark[0].str)+string("_str");
			yyval.str=strdup(combined.c_str());
		}
	}
#line 2258 "y.tab.c"
break;
case 26:
#line 1096 "project.y"
	{
		string combined="("+string(yystack.l_mark[-1].str)+")";
		yyval.str=strdup(combined.c_str());
	}
#line 2266 "y.tab.c"
break;
case 27:
#line 1106 "project.y"
	{
		yyval.str=yystack.l_mark[0].str;
	}
#line 2273 "y.tab.c"
break;
case 28:
#line 1111 "project.y"
	{
		string combined=string(yystack.l_mark[-2].str)+string(yystack.l_mark[-1].str)+string(yystack.l_mark[0].str);
		yyval.str=strdup(combined.c_str());
	}
#line 2281 "y.tab.c"
break;
case 29:
#line 1119 "project.y"
	{
		yyval.str=strdup(yystack.l_mark[0].str);
	}
#line 2288 "y.tab.c"
break;
case 30:
#line 1124 "project.y"
	{
		yyval.str=strdup(yystack.l_mark[0].str);
	}
#line 2295 "y.tab.c"
break;
case 31:
#line 1129 "project.y"
	{
		yyval.str=strdup(yystack.l_mark[0].str);
	}
#line 2302 "y.tab.c"
break;
case 32:
#line 1134 "project.y"
	{
		string combined="("+string(yystack.l_mark[-1].str)+")";
		yyval.str=strdup(combined.c_str());
	}
#line 2310 "y.tab.c"
break;
case 33:
#line 1143 "project.y"
	{yyval.number=1;}
#line 2315 "y.tab.c"
break;
case 34:
#line 1145 "project.y"
	{yyval.number=yystack.l_mark[-1].number+1;}
#line 2320 "y.tab.c"
break;
#line 2322 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}

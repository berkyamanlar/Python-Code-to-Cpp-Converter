#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE
{
	int number;
	char * str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */

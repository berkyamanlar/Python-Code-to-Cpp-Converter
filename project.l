digit [0-9]
letter	[A-Za-z]


%{
  #include <stdio.h>
  #include <string.h>
  #include "y.tab.h"
  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <map>
  using namespace std;
  
  int lineCount=0;
  int linenum=1;
  int tcounter=-1;
  
%}

%%

"if" {yylval.str=strdup(yytext); return IFST;}
"elif" {yylval.str=strdup(yytext); return ELIFST;}
"else" {yylval.str=strdup(yytext); return ELSEST;}
"printf" {yylval.str=strdup(yytext); return PRINTF;}
"%d" {yylval.str=strdup(yytext); return PERCENTINT;}
\"	{yylval.str=strdup(yytext); return QUOTE;}
"-"([0-9]+"."[0-9]+|"."[0-9]+|[0-9]+".")|[0-9]+"."[0-9]+|"."[0-9]+|[0-9]+"." {yylval.str=strdup(yytext); return FLOAT;}
[0-9]+|"-"[0-9]+ {yylval.str = strdup(yytext); return INT;}
"," {yylval.str=strdup(yytext); return COMMA;}
"=" {yylval.str=strdup(yytext); return EQUAL;}
";" {yylval.str=strdup(yytext); return SEMICOLON;}
":" {yylval.str=strdup(yytext); return COLON;}
"[" {yylval.str=strdup(yytext); return OPS;}
"]" {yylval.str=strdup(yytext); return CPS;}
"=="|"!="|"<"|"<="|">"|">=" {yylval.str=strdup(yytext); return COMPARISON;}
"+"|"-"|"*"|"/"  {yylval.str=strdup(yytext); return MATH;}
"(" {yylval.str=strdup(yytext); return OP;}
")" {yylval.str=strdup(yytext); return CP;}
{letter}({letter}|{digit})*	{yylval.str=strdup(yytext); return IDENTIFIER;}
\n	{linenum;}
[  \t] {yylval.str=strdup(yytext); return TAB;}

 

%%


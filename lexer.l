%{
using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include "parser.tab.h"

extern int yylex();
extern int yyline;
extern void yyerror(string);

unsigned yycol = 0;
string yybuffer;

#define YY_USER_ACTION yycol += yyleng;
%}

%option yylineno nounput
%x C_COMMENT

TYPE    int|char
COMMAND   print
BR_START    "{"
BR_END      "}"
ARRAY       array
STRING      string
ARRAY_LEFT "["
ARRAY_RIGHT "]"
COMPARE     "=="|"!="|"<"|">"|"<="|">="
STATIC_CHAR    '.'|'\\n'|'\\\\'|'\\''|'\\t'
STATIC_STRING \"([^"]|\\[nt\\"])*\"
FAIL_STRING \"([^"\\\n]|\\[nt\\"])*
ID    _*[a-zA-Z][a-zA-Z0-9_]*
STATIC_INT  [0-9]+
STATIC_FLOAT  [0-9]*"."[0-9]+
SUB   "-"
AND     "&&"
OR      "||"
NOT     "!"
ADD           "+"
MULT          "*"
DIV           "/"
MOD           "%"
CARET         "^"
OPENP   "("
CLOSEP    ")"
ASSIGN    =
WHILE_LOOP  while
FOR_LOOP    for
SEPARATOR ,
ENDLINE   ;
COASSIGN  [\+\/\*\-\%]=
WHITESPACE  [ \t]+
COMMENT   #.*
NEWLINE   \n
CC_START  "/*"
CC_END    "*/"
RESERVED  "tmp____"[0-9a-zA-Z]*

%%
<INITIAL>{
{TYPE}    { yylval.istr=strdup(yytext);return TYPE; }
"."         { return METHOD_OP;}
break       { return BREAK;}
{COMMAND} { return PRINT; }
if          { return IF;}
else        { return ELSE;}
{BR_START}  { return BR_START;}
{BR_END}    { return BR_END;}
{ARRAY}     { return ARRAY;}
{STRING}    { return STRING; }
{ARRAY_LEFT} {return ARRAY_LEFT;}
{ARRAY_RIGHT} {return ARRAY_RIGHT;}
{WHILE_LOOP} { return WHILE_LOOP;}
{FOR_LOOP}  { return FOR_LOOP;}
{COMPARE}   { yylval.istr=strdup(yytext); return COMPARE;}
{STATIC_STRING}     { yylval.istr=strdup(yytext); return STATIC_STRING;}
{STATIC_CHAR}      { yylval.istr=strdup(yytext); return STATIC_CHAR;}
{FAIL_STRING}     { cerr << "ERROR(line " << yylineno << "): Unterminated string." << endl;exit(EXIT_FAILURE);}
"define"    {return DEFINE;}
"declare" 	{return DECLARE;}
"return"    { return RETURN;}
{ID}    { yylval.istr = strdup(yytext); return ID; }
{STATIC_INT}  { yylval.iint=atoi(yytext); return STATIC_INT; }
{STATIC_FLOAT}  { yylval.ifloat=atof(yytext); return STATIC_FLOAT;}
{AND}       { return AND;}
{OR}        { return OR;}
{NOT}       { return NOT;}
{SUB}   { return SUB;}
{ADD}   { return ADD;}
{MULT}    { return MULT;}
{DIV}       { return DIV;}
{MOD}       { return MOD;}
{CARET}     { return CARET;}
{OPENP}   { return OPENP;}
{CLOSEP}  { return CLOSEP;}
{ASSIGN}  { return ASSIGN; }
{SEPARATOR} { return SEPARATOR; }
{ENDLINE} { return ENDLINE; }
{COASSIGN}  { yylval.istr=strdup(yytext);return COASSIGN; }
{WHITESPACE}  {}
{NEWLINE}.*  { yycol=0; yybuffer = yytext; yyless(1); }
. { cerr << "ERROR(line " << yylineno << "): Unknown Token '" <<  yytext << "'."<< endl;exit(EXIT_FAILURE); }

{COMMENT} {}
{CC_START}  { BEGIN(C_COMMENT); }
}
<C_COMMENT>{
{CC_END}  { BEGIN(INITIAL); }
{NEWLINE} {}
}

%%


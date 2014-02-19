/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 2068 of yacc.c  */
#line 17 "parser.y"
#include "ast.h" 


/* Line 2068 of yacc.c  */
#line 42 "parser.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COMMAND = 258,
     ASSIGN = 259,
     ENDLINE = 260,
     PRINT = 261,
     SEPARATOR = 262,
     ARRAY_LEFT = 263,
     ARRAY_RIGHT = 264,
     METHOD_OP = 265,
     DEFINE = 266,
     DECLARE = 267,
     BR_START = 268,
     BR_END = 269,
     AND = 270,
     NOT = 271,
     OR = 272,
     ARRAYINDEX = 273,
     IF = 274,
     ELSE = 275,
     BREAK = 276,
     RETURN = 277,
     WHILE_LOOP = 278,
     FOR_LOOP = 279,
     ARRAY = 280,
     STRING = 281,
     OPENP = 282,
     CLOSEP = 283,
     NEGATIVE = 284,
     SUB = 285,
     ADD = 286,
     MULT = 287,
     DIV = 288,
     MOD = 289,
     CARET = 290,
     TYPE = 291,
     COMPARE = 292,
     STATIC_STRING = 293,
     ID = 294,
     COASSIGN = 295,
     BUILT_IN_FUNC = 296,
     STATIC_INT = 297,
     STATIC_FLOAT = 298,
     STATIC_CHAR = 299,
     UMINUS = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 18 "parser.y"

    char * istr;
    int iint;
    float ifloat;
    ASTNode_Base *inode;
    Addr *iaddr;
    vector<ASTNode_Base*> *multi_expr;
    vector<ASTNode_Assignment*> *multi_decl;
    vector<ASTNode_Val*> *multi_val;
	vector<Addr*> *multi_addr;
    ArrayIndex  *index;
    Array_Type *arraytype;
    ASTNode_Function *func;
    Scope* scope;
    Ctype* cast;



/* Line 2068 of yacc.c  */
#line 123 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



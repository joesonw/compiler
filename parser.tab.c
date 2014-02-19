/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

using namespace std;

#include <string>
// global temp fix for outfile
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "driver.h"
#include "icstruct.h"



/* Line 268 of yacc.c  */
#line 88 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 288 of yacc.c  */
#line 17 "parser.y"
#include "ast.h" 


/* Line 288 of yacc.c  */
#line 116 "parser.tab.c"

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

/* Line 293 of yacc.c  */
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



/* Line 293 of yacc.c  */
#line 197 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 209 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    14,    15,    17,    19,
      22,    24,    26,    28,    30,    32,    34,    38,    40,    43,
      45,    50,    52,    56,    57,    58,    68,    69,    70,    71,
      82,    84,    85,    90,    93,    94,   101,   102,   103,   115,
     117,   118,   120,   121,   127,   135,   137,   139,   140,   145,
     146,   149,   153,   154,   159,   162,   165,   166,   170,   174,
     177,   181,   184,   188,   192,   196,   200,   204,   208,   212,
     216,   220,   222,   224,   226,   228,   233,   240,   247,   254,
     259,   263,   265
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    47,    49,    -1,    47,    57,    -1,    47,
      54,    -1,     5,    -1,    -1,    49,    -1,    57,    -1,    51,
       5,    -1,    50,    -1,    71,    -1,    69,    -1,    63,    -1,
      53,    -1,    77,    -1,     6,    77,    74,    -1,    21,    -1,
      22,    77,    -1,    36,    -1,    25,    27,    36,    28,    -1,
      26,    -1,    52,    75,     5,    -1,    -1,    -1,    12,    52,
      39,    27,    55,    61,    56,    28,     5,    -1,    -1,    -1,
      -1,    11,    52,    39,    27,    58,    61,    59,    28,    60,
      70,    -1,    62,    -1,    -1,    62,     7,    52,    39,    -1,
      52,    39,    -1,    -1,    23,    27,    77,    28,    64,    49,
      -1,    -1,    -1,    24,    27,    65,    67,     5,    68,     5,
      67,    66,    28,    70,    -1,    51,    -1,    -1,    77,    -1,
      -1,    19,    27,    77,    28,    70,    -1,    19,    27,    77,
      28,    70,    20,    70,    -1,    49,    -1,     5,    -1,    -1,
      13,    72,    73,    14,    -1,    -1,    73,    48,    -1,     7,
      77,    74,    -1,    -1,    75,     7,    39,    76,    -1,    39,
      76,    -1,     4,    77,    -1,    -1,    77,    37,    77,    -1,
      77,    15,    77,    -1,    16,    77,    -1,    77,    17,    77,
      -1,    30,    77,    -1,    27,    77,    28,    -1,    77,    30,
      77,    -1,    77,    31,    77,    -1,    77,    32,    77,    -1,
      77,    33,    77,    -1,    77,    34,    77,    -1,    77,    35,
      77,    -1,    39,    40,    77,    -1,    39,     4,    77,    -1,
      39,    -1,    42,    -1,    44,    -1,    38,    -1,    39,     8,
      77,     9,    -1,    39,     8,    77,     9,     4,    77,    -1,
      39,     8,    77,     9,    40,    77,    -1,    39,    10,    39,
      27,    78,    28,    -1,    39,    27,    78,    28,    -1,    78,
       7,    77,    -1,    77,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    74,    81,    88,    89,    92,    93,    96,
      99,   104,   105,   106,   107,   110,   113,   118,   120,   125,
     134,   143,   148,   173,   192,   173,   212,   232,   272,   212,
     284,   285,   287,   304,   323,   323,   333,   338,   333,   345,
     346,   348,   349,   352,   355,   361,   362,   366,   366,   379,
     380,   387,   388,   391,   398,   408,   409,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   428,
     433,   434,   435,   438,   441,   444,   449,   453,   459,   463,
     475,   479,   484
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMAND", "ASSIGN", "ENDLINE", "PRINT",
  "SEPARATOR", "ARRAY_LEFT", "ARRAY_RIGHT", "METHOD_OP", "DEFINE",
  "DECLARE", "BR_START", "BR_END", "AND", "NOT", "OR", "ARRAYINDEX", "IF",
  "ELSE", "BREAK", "RETURN", "WHILE_LOOP", "FOR_LOOP", "ARRAY", "STRING",
  "OPENP", "CLOSEP", "NEGATIVE", "SUB", "ADD", "MULT", "DIV", "MOD",
  "CARET", "TYPE", "COMPARE", "STATIC_STRING", "ID", "COASSIGN",
  "BUILT_IN_FUNC", "STATIC_INT", "STATIC_FLOAT", "STATIC_CHAR", "UMINUS",
  "$accept", "start", "block_stmt", "true_stmt", "non_end_stmt", "stmt",
  "type_cast", "declarations", "fun_declaration", "@1", "$@2",
  "fun_definition", "@3", "$@4", "$@5", "function_para", "function_paras",
  "loop", "@6", "@7", "$@8", "null_stmt", "null_expr", "selection",
  "open_stmt", "block", "@9", "multi_stmt", "multi_expr", "multi_decl",
  "decl", "expr", "function_args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    47,    48,    48,    49,
      49,    50,    50,    50,    50,    51,    51,    51,    51,    52,
      52,    52,    53,    55,    56,    54,    58,    59,    60,    57,
      61,    61,    62,    62,    64,    63,    65,    66,    63,    67,
      67,    68,    68,    69,    69,    70,    70,    72,    71,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     1,
       4,     1,     3,     0,     0,     9,     0,     0,     0,    10,
       1,     0,     4,     2,     0,     6,     0,     0,    11,     1,
       0,     1,     0,     5,     7,     1,     1,     0,     4,     0,
       2,     3,     0,     4,     2,     2,     0,     3,     3,     2,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     4,     6,     6,     6,     4,
       3,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     5,     0,     1,     0,     0,     0,    47,     0,     0,
      17,     0,     0,     0,     0,    21,     0,     0,    19,    74,
      71,    72,    73,     2,    10,     0,     0,    14,     4,     3,
      13,    12,    11,    15,    52,     0,     0,    49,    59,     0,
      18,     0,    36,     0,     0,    61,     0,     0,     0,    82,
       0,     9,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
      40,     0,    62,    70,     0,     0,    81,     0,    69,     0,
      54,    22,     0,    58,    60,    63,    64,    65,    66,    67,
      68,    57,    52,    26,    23,    48,    50,     7,     8,     0,
      34,    39,     0,    20,    75,    82,     0,    79,    55,    56,
      51,    31,    31,    46,    45,    43,     0,    42,     0,     0,
       0,    80,    53,     0,    27,    30,    24,     0,    35,     0,
      41,    76,    77,    78,    33,     0,     0,     0,    44,    40,
      28,     0,     0,    37,     0,    32,    25,     0,    29,     0,
      38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    96,   114,    24,    25,    26,    27,    28,   112,
     137,    29,   111,   135,   144,   124,   125,    30,   116,    70,
     147,   102,   129,    31,   115,    32,    37,    67,    64,    53,
      80,    33,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -116
static const yytype_int16 yypact[] =
{
      17,  -116,   113,  -116,    -6,    -9,    -9,  -116,    -6,   -19,
    -116,    -6,    -4,    -1,     4,  -116,    -6,    -6,  -116,  -116,
       3,  -116,  -116,  -116,  -116,    23,    10,  -116,  -116,  -116,
    -116,  -116,  -116,   275,   215,    11,    29,  -116,  -116,    -6,
     275,    -6,  -116,     6,   236,  -116,    -6,    -6,    35,    -6,
      -6,  -116,    31,    13,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,  -116,    24,    44,   147,   246,   267,
     199,    47,  -116,   275,   225,    58,   275,    12,   275,    -6,
    -116,  -116,    49,   296,   288,    32,    32,    51,    51,    51,
      51,   304,   215,  -116,  -116,  -116,  -116,  -116,  -116,    57,
    -116,  -116,    84,  -116,     1,    -6,    -6,  -116,   275,    31,
    -116,    -9,    -9,  -116,  -116,    70,   174,    -6,    -6,    -6,
      18,   275,  -116,    52,  -116,    85,  -116,    57,  -116,    89,
     275,   275,   275,  -116,  -116,    69,    -9,    72,  -116,   199,
    -116,    59,    97,  -116,    57,  -116,  -116,    77,  -116,    57,
    -116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -116,  -116,  -116,     2,  -116,   -67,    -5,  -116,  -116,  -116,
    -116,    41,  -116,  -116,  -116,    -3,  -116,  -116,  -116,  -116,
    -116,   -29,  -116,  -116,  -115,  -116,  -116,  -116,    19,  -116,
       5,    -2,     7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      35,    36,    34,   101,    23,   118,    38,    46,    39,    40,
       8,    47,   138,    48,    44,    45,    14,    15,    81,   106,
      82,    16,     1,    41,    17,   106,    42,    18,    51,   148,
      49,    43,    19,    20,   150,    79,    21,    68,    22,    69,
     107,   119,    71,    50,    73,    74,   133,    76,    78,    52,
      65,    93,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   113,     4,    58,    59,    60,    61,    66,    97,
       7,    94,   101,     8,    75,   103,     9,   108,    10,    11,
      12,    13,    14,    15,    16,   105,    61,    17,   109,   117,
     127,   134,   136,    18,   139,    19,    20,   140,   145,    21,
     142,    22,   146,    76,   121,   149,   123,   123,    98,   126,
     143,   110,   120,     3,   122,   130,   131,   132,   128,     4,
       0,     0,     0,     0,     5,     6,     7,     0,     0,     8,
       0,   141,     9,     0,    10,    11,    12,    13,    14,    15,
      16,     0,     0,    17,     0,     0,     0,     0,     0,    18,
       0,    19,    20,     4,     0,    21,     0,    22,     5,     0,
       7,    95,     0,     8,     0,     0,     9,     0,    10,    11,
      12,    13,    14,    15,    16,     0,     0,    17,     0,     0,
       4,     0,     0,    18,     0,    19,    20,     7,     0,    21,
       8,    22,     0,     9,     0,    10,    11,    12,    13,    14,
      15,    16,     0,     0,    17,     4,     0,     0,     0,     0,
      18,     0,    19,    20,     0,     8,    21,     0,    22,     0,
      10,    11,    63,     0,     0,     0,    16,     0,     0,    17,
      54,     0,    55,     0,   104,     0,     0,    19,    20,     0,
      54,    21,    55,    22,     0,    56,    57,    58,    59,    60,
      61,    54,    62,    55,     0,    56,    57,    58,    59,    60,
      61,    54,    62,    55,    72,     0,    56,    57,    58,    59,
      60,    61,     0,    62,    99,     0,    56,    57,    58,    59,
      60,    61,    54,    62,    55,     0,     0,     0,     0,     0,
      54,     0,    55,     0,     0,   100,     0,    56,    57,    58,
      59,    60,    61,    54,    62,    56,    57,    58,    59,    60,
      61,     0,    62,     0,     0,     0,     0,     0,    56,    57,
      58,    59,    60,    61,     0,    62,    56,    57,    58,    59,
      60,    61,     0,    62,    56,    57,    58,    59,    60,    61,
       0,    -1
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-116))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
       5,     6,     4,    70,     2,     4,     8,     4,    27,    11,
      16,     8,   127,    10,    16,    17,    25,    26,     5,     7,
       7,    27,     5,    27,    30,     7,    27,    36,     5,   144,
      27,    27,    38,    39,   149,     4,    42,    39,    44,    41,
      28,    40,    36,    40,    46,    47,    28,    49,    50,    39,
      39,    27,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     5,     6,    32,    33,    34,    35,    39,    67,
      13,    27,   139,    16,    39,    28,    19,    79,    21,    22,
      23,    24,    25,    26,    27,    27,    35,    30,    39,     5,
      20,    39,     7,    36,     5,    38,    39,    28,    39,    42,
      28,    44,     5,   105,   106,    28,   111,   112,    67,   112,
     139,    92,   105,     0,   109,   117,   118,   119,   116,     6,
      -1,    -1,    -1,    -1,    11,    12,    13,    -1,    -1,    16,
      -1,   136,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    39,     6,    -1,    42,    -1,    44,    11,    -1,
      13,    14,    -1,    16,    -1,    -1,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,
       6,    -1,    -1,    36,    -1,    38,    39,    13,    -1,    42,
      16,    44,    -1,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,     6,    -1,    -1,    -1,    -1,
      36,    -1,    38,    39,    -1,    16,    42,    -1,    44,    -1,
      21,    22,     7,    -1,    -1,    -1,    27,    -1,    -1,    30,
      15,    -1,    17,    -1,     9,    -1,    -1,    38,    39,    -1,
      15,    42,    17,    44,    -1,    30,    31,    32,    33,    34,
      35,    15,    37,    17,    -1,    30,    31,    32,    33,    34,
      35,    15,    37,    17,    28,    -1,    30,    31,    32,    33,
      34,    35,    -1,    37,    28,    -1,    30,    31,    32,    33,
      34,    35,    15,    37,    17,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    17,    -1,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,    15,    37,    30,    31,    32,    33,    34,
      35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    -1,    37,    30,    31,    32,    33,
      34,    35,    -1,    37,    30,    31,    32,    33,    34,    35,
      -1,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    47,     0,     6,    11,    12,    13,    16,    19,
      21,    22,    23,    24,    25,    26,    27,    30,    36,    38,
      39,    42,    44,    49,    50,    51,    52,    53,    54,    57,
      63,    69,    71,    77,    77,    52,    52,    72,    77,    27,
      77,    27,    27,    27,    77,    77,     4,     8,    10,    27,
      40,     5,    39,    75,    15,    17,    30,    31,    32,    33,
      34,    35,    37,     7,    74,    39,    39,    73,    77,    77,
      65,    36,    28,    77,    77,    39,    77,    78,    77,     4,
      76,     5,     7,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    27,    27,    14,    48,    49,    57,    28,
      28,    51,    67,    28,     9,    27,     7,    28,    77,    39,
      74,    58,    55,     5,    49,    70,    64,     5,     4,    40,
      78,    77,    76,    52,    61,    62,    61,    20,    49,    68,
      77,    77,    77,    28,    39,    59,     7,    56,    70,     5,
      28,    52,    28,    67,    60,    39,     5,    66,    70,    28,
      70
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 67 "parser.y"
    {
        try {
            (yyvsp[(2) - (2)].inode)->toIC();
        } catch (const char* e) {
            yyerror(e);
        }
    }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 74 "parser.y"
    {
        try {
            (yyvsp[(2) - (2)].inode)->toIC();
        } catch (const char* e) {
            yyerror(e);
        }
  }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 81 "parser.y"
    {
        try {
            (yyvsp[(2) - (2)].inode)->toIC();
        } catch (const char* e) {
            yyerror(e);
        }
  }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 88 "parser.y"
    {}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 89 "parser.y"
    {}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 92 "parser.y"
    { (yyval.inode)=(yyvsp[(1) - (1)].inode); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 93 "parser.y"
    { (yyval.inode)=(yyvsp[(1) - (1)].inode); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 96 "parser.y"
    {
        (yyval.inode)=(yyvsp[(1) - (2)].inode);
    }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 99 "parser.y"
    {
        (yyval.inode)=(yyvsp[(1) - (1)].inode);
    }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 104 "parser.y"
    {(yyval.inode)=(yyvsp[(1) - (1)].inode);}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 105 "parser.y"
    {(yyval.inode)=(yyvsp[(1) - (1)].inode);}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 106 "parser.y"
    {(yyval.inode)=(yyvsp[(1) - (1)].inode);}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 107 "parser.y"
    {(yyval.inode)=(yyvsp[(1) - (1)].inode);}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 110 "parser.y"
    {
        (yyval.inode)=(yyvsp[(1) - (1)].inode);
    }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 113 "parser.y"
    {
    (yyvsp[(3) - (3)].multi_expr)->push_back((yyvsp[(2) - (3)].inode));
        ASTNode_Base* a=new ASTNode_Print((yyvsp[(3) - (3)].multi_expr));
        (yyval.inode)=a;
  }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 118 "parser.y"
    {
    (yyval.inode)=new ASTNode_Break(currScopes);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 120 "parser.y"
    {
        (yyval.inode)=new ASTNode_Return((yyvsp[(2) - (2)].inode),currScopes);
    }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 125 "parser.y"
    {
        Ctype *t=new Ctype();
        t->d=0;
        if (string((yyvsp[(1) - (1)].istr))=="int")
            t->t=VINT;
        else if (string((yyvsp[(1) - (1)].istr))=="char")
            t->t=VCHAR;
        (yyval.cast)=t;
    }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 134 "parser.y"
    {
        Ctype *t=new Ctype();
        t->d=1;
        if (string((yyvsp[(3) - (4)].istr))=="int")
            t->t=VINT;
        else if (string((yyvsp[(3) - (4)].istr))=="char")
            t->t=VCHAR;
        (yyval.cast)=t;
    }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 143 "parser.y"
    {
        (yyval.cast)=new Ctype(VCHAR,1);
    }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 148 "parser.y"
    {
        for (unsigned i=0;i<(yyvsp[(2) - (3)].multi_decl)->size();) {
            ASTNode_Val *j=(*(yyvsp[(2) - (3)].multi_decl))[i]->val();
            if (j->addr()==0) {
                Addr* a;
                if ((yyvsp[(1) - (3)].cast)->d==0) {
                    a=new Addr(getID());
                } else {
                    a=new Addr(getArrayID());
                    cout<<"ar_set_siz "<<a->value<<" 0\n";
                }
                a->d=(yyvsp[(1) - (3)].cast)->d;
                a->type=(yyvsp[(1) - (3)].cast)->t;
                j->setAddr(a);

            }
            if ((yyvsp[(2) - (3)].multi_decl)->at(i)->source()==0) {
                (yyvsp[(2) - (3)].multi_decl)->erase((yyvsp[(2) - (3)].multi_decl)->begin()+i);
            } else {
                i++;
            }
        }
        (yyval.inode)=new ASTNode_Multi_Assignment((yyvsp[(2) - (3)].multi_decl));
    }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 173 "parser.y"
    {
		if(currScopes->back() != globalScope) {
				yyerror("Attempting to declare function '" + string((yyvsp[(3) - (4)].istr)) + "' outside of global scope!");
		}
		Scope* newScope=new Scope(getScopeID());
        currScopes->push_back(newScope);
		Addr* a;
		if ((yyvsp[(2) - (4)].cast)->d==0) {
			a=new Addr(getID());
		} else {
			a=new Addr(getArrayID());
		}
        a->type=(yyvsp[(2) - (4)].cast)->t;
        a->d=(yyvsp[(2) - (4)].cast)->d;
        ASTNode_Function* func=new ASTNode_Function((yyvsp[(3) - (4)].istr),0,a,0,newScope,currScopes);
		functions.push_back(func);
        newScope->assoc_func=func;
		(yyval.func)=func;
	}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 192 "parser.y"
    {
		for (unsigned i=0;i<functions.size();i++) {
			if (functions[i]->getName()==(yyvsp[(3) - (6)].istr)) {
				vector<ASTNode_Val*> args= *(functions[i]->Args());
				if (args.size()!=(yyvsp[(6) - (6)].multi_val)->size())
					continue;
				for (unsigned j=0;j<args.size();j++) {
					if (args[j]->addr()->type != (yyvsp[(6) - (6)].multi_val)->at(j)->addr()->type || args[j]->addr()->d != (yyvsp[(6) - (6)].multi_val)->at(j)->addr()->d || !functions[i]->defined)
						continue;
                	yyerror("re-declaring function");
				}
            }
		}
		(yyvsp[(5) - (6)].func)->setArgs((yyvsp[(6) - (6)].multi_val));	
	}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 207 "parser.y"
    {
        removeScope(currScopes,(yyvsp[(5) - (9)].func)->getScope());
		(yyval.inode)=new ASTNode_Dummy();
	}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 212 "parser.y"
    {
			if(currScopes->back() != globalScope) {
				yyerror("Attempting to define function '" + string((yyvsp[(3) - (4)].istr)) + "' outside of global scope!");
			}
        Scope* newScope=new Scope(getScopeID());
        currScopes->push_back(newScope);

        
		Addr* a;
		if ((yyvsp[(2) - (4)].cast)->d==0) {
			a=new Addr(getID());
		} else {
			a=new Addr(getArrayID());
		}
        a->type=(yyvsp[(2) - (4)].cast)->t;
        a->d=(yyvsp[(2) - (4)].cast)->d;
        ASTNode_Function* func=new ASTNode_Function((yyvsp[(3) - (4)].istr),0,a,0,newScope,currScopes);
        newScope->assoc_func=func;
        (yyval.func)=func;
    }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 232 "parser.y"
    {
		bool exist=false;
		ASTNode_Function* f;
		for (unsigned i=0;i<functions.size();i++) {
            if (functions[i]->getName()==(yyvsp[(3) - (6)].istr)) {
				vector<ASTNode_Val*> args= *(functions[i]->Args());
				unsigned count=0;
				if (args.size()!=(yyvsp[(6) - (6)].multi_val)->size())
					continue;
				for (unsigned j=0;j<args.size();j++) {
					if (args[j]->addr()->type == (yyvsp[(6) - (6)].multi_val)->at(j)->addr()->type &&
						args[j]->addr()->d == (yyvsp[(6) - (6)].multi_val)->at(j)->addr()->d)
							count++;
					if (args[j]->addr()->type != (yyvsp[(6) - (6)].multi_val)->at(j)->addr()->type || args[j]->addr()->d != (yyvsp[(6) - (6)].multi_val)->at(j)->addr()->d || !functions[i]->defined)
						continue;
                	yyerror("re-definning function");
				}
				if (count==args.size()) {
					if (functions[i]->addr()->type!=(yyvsp[(2) - (6)].cast)->t ||
						functions[i]->addr()->d!=(yyvsp[(2) - (6)].cast)->d) {
						yyerror("Attempting to define function '"+functions[i]->getName()+"', with return type '"+findType((yyvsp[(5) - (6)].func)->addr())+"' but previously declared as type '"+findType(functions[i]->addr())+"'.");
					}
					exist=true;
					functions[i]->defined=true;
					f=functions[i];
				}
            }
        }
		if (exist) {
			removeScope(currScopes,(yyvsp[(5) - (6)].func)->getScope());
			currScopes->push_back(f->getScope());
			(yyvsp[(5) - (6)].func)=f;
		} else {
        	(yyvsp[(5) - (6)].func)->setArgs((yyvsp[(6) - (6)].multi_val));
			(yyvsp[(5) - (6)].func)->defined=true;
        	functions.push_back((yyvsp[(5) - (6)].func));
		}
		cout<<"jump end_function_"<<(yyvsp[(5) - (6)].func)->getScope()->id<<(yyvsp[(3) - (6)].istr)<<endl;
        cout<<"function_"<<(yyvsp[(5) - (6)].func)->getScope()->id<<(yyvsp[(3) - (6)].istr)<<":"<<endl;
    }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 272 "parser.y"
    {}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 273 "parser.y"
    {
        (yyvsp[(10) - (10)].inode)->toIC();
        removeScope(currScopes,(yyvsp[(5) - (10)].func)->getScope());
        (yyvsp[(5) - (10)].func)->setBlock((yyvsp[(10) - (10)].inode));
		printMessage("WARNING: there is no return value for function:"+string((yyvsp[(3) - (10)].istr)));
		cout<<"ret"<<endl;
        cout<<"end_function_"<<(yyvsp[(5) - (10)].func)->getScope()->id<<(yyvsp[(3) - (10)].istr)<<":"<<endl;
        (yyval.inode)=new ASTNode_Dummy();
    }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 284 "parser.y"
    {(yyval.multi_val)=(yyvsp[(1) - (1)].multi_val);}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 285 "parser.y"
    {(yyval.multi_val)=new vector<ASTNode_Val*>();}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 287 "parser.y"
    {
        checkRedefine((yyvsp[(4) - (4)].istr));
		Addr* a;
		if ((yyvsp[(3) - (4)].cast)->d!=0) {
			a=new Addr(getArrayID());
		} else {
			a=new Addr(getID());
		}
        a->d=(yyvsp[(3) - (4)].cast)->d;
        a->type=(yyvsp[(3) - (4)].cast)->t;
        ASTNode_Val* v=new ASTNode_Val((yyvsp[(4) - (4)].istr));
        v->setAddr(a);
        v->setScope(currScopes->back());
        vtable->add(v);
        (yyvsp[(1) - (4)].multi_val)->push_back(v);
        (yyval.multi_val)=(yyvsp[(1) - (4)].multi_val);
    }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 304 "parser.y"
    {
        checkRedefine((yyvsp[(2) - (2)].istr));
		Addr *a;
		if ((yyvsp[(1) - (2)].cast)->d!=0) {
			a=new Addr(getArrayID());
		} else {
			a=new Addr(getID());
		}
        a->d=(yyvsp[(1) - (2)].cast)->d;
        a->type=(yyvsp[(1) - (2)].cast)->t;
        vector<ASTNode_Val*> *args=new vector<ASTNode_Val*>();
        ASTNode_Val* v=new ASTNode_Val((yyvsp[(2) - (2)].istr));
        v->setAddr(a);
        v->setScope(currScopes->back());
        args->push_back(v);
        vtable->add(v);
        (yyval.multi_val)=args;
    }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 323 "parser.y"
    {
        Scope* newScope=new Scope(getScopeID());
        currScopes->push_back(newScope);
        (yyval.scope)=newScope;

    }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 329 "parser.y"
    {
        removeScope(currScopes,(yyvsp[(5) - (6)].scope));
        (yyval.inode)=new ASTNode_While((yyvsp[(3) - (6)].inode),(yyvsp[(6) - (6)].inode),currScopes,(yyvsp[(5) - (6)].scope));
    }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 333 "parser.y"
    {
        Scope* newScope=new Scope(getScopeID());
        currScopes->push_back(newScope);
        (yyval.scope)=newScope;
    }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 338 "parser.y"
    {}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 339 "parser.y"
    {
        removeScope(currScopes,(yyvsp[(3) - (11)].scope));
        (yyval.inode)=new ASTNode_For((yyvsp[(4) - (11)].inode),(yyvsp[(6) - (11)].inode),(yyvsp[(8) - (11)].inode),(yyvsp[(11) - (11)].inode),currScopes,(yyvsp[(3) - (11)].scope));
    }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 345 "parser.y"
    {(yyval.inode)=(yyvsp[(1) - (1)].inode);}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 346 "parser.y"
    {(yyval.inode)=0;}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 348 "parser.y"
    {(yyval.inode)=(yyvsp[(1) - (1)].inode);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 349 "parser.y"
    {(yyval.inode)=0;}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 352 "parser.y"
    {
        (yyval.inode)=new ASTNode_If_Else((yyvsp[(3) - (5)].inode),(yyvsp[(5) - (5)].inode),0);
    }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 355 "parser.y"
    {
        (yyval.inode)=new ASTNode_If_Else((yyvsp[(3) - (7)].inode),(yyvsp[(5) - (7)].inode),(yyvsp[(7) - (7)].inode));
    }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 361 "parser.y"
    {(yyval.inode)=(yyvsp[(1) - (1)].inode);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 362 "parser.y"
    {(yyval.inode)=0;}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 366 "parser.y"
    {
        Scope* newScope=new Scope(getScopeID());
        (yyval.scope) = newScope;
        currScopes->push_back(newScope);
    }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 371 "parser.y"
    {
        removeScope(currScopes,(yyvsp[(2) - (4)].scope));
        ASTNode_Block* b=new ASTNode_Block((yyvsp[(3) - (4)].multi_expr),(yyvsp[(2) - (4)].scope),currScopes);
        (yyval.inode)=b;
    }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 379 "parser.y"
    {(yyval.multi_expr)=new vector<ASTNode_Base*>();}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 380 "parser.y"
    {
        (yyvsp[(1) - (2)].multi_expr)->push_back((yyvsp[(2) - (2)].inode));
        (yyval.multi_expr)=(yyvsp[(1) - (2)].multi_expr);
    }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 387 "parser.y"
    { (yyvsp[(3) - (3)].multi_expr)->push_back((yyvsp[(2) - (3)].inode));(yyval.multi_expr)=(yyvsp[(3) - (3)].multi_expr); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 388 "parser.y"
    { (yyval.multi_expr) = new vector<ASTNode_Base*>(); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 391 "parser.y"
    {
        checkRedefine((yyvsp[(3) - (4)].istr));
        ASTNode_Val* a=vtable->add(new ASTNode_Val(string((yyvsp[(3) - (4)].istr))));
        a->setScope(currScopes->back());
        (yyvsp[(1) - (4)].multi_decl)->push_back(new ASTNode_Assignment(a,(yyvsp[(4) - (4)].inode)));
        (yyval.multi_decl)=(yyvsp[(1) - (4)].multi_decl);
  }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 398 "parser.y"
    {
    checkRedefine((yyvsp[(1) - (2)].istr));
    ASTNode_Val* a=vtable->add(new ASTNode_Val(string((yyvsp[(1) - (2)].istr))));
        a->setScope(currScopes->back());
        vector<ASTNode_Assignment*> *r=new vector<ASTNode_Assignment*>();
        r->push_back(new ASTNode_Assignment(a,(yyvsp[(2) - (2)].inode)));
        (yyval.multi_decl)=r;
  }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 408 "parser.y"
    { (yyval.inode)=(yyvsp[(2) - (2)].inode); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 409 "parser.y"
    {(yyval.inode)=0; }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 414 "parser.y"
    {(yyval.inode)=new ASTNode_Math((yyvsp[(1) - (3)].inode),(yyvsp[(3) - (3)].inode),string((yyvsp[(2) - (3)].istr)));}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 415 "parser.y"
    {(yyval.inode)=new ASTNode_And((yyvsp[(1) - (3)].inode),(yyvsp[(3) - (3)].inode));}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 416 "parser.y"
    {(yyval.inode)=new ASTNode_Not((yyvsp[(2) - (2)].inode));}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 417 "parser.y"
    {(yyval.inode)=new ASTNode_Or((yyvsp[(1) - (3)].inode),(yyvsp[(3) - (3)].inode));}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 418 "parser.y"
    {(yyval.inode)=new ASTNode_Neg((yyvsp[(2) - (2)].inode));}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 419 "parser.y"
    {(yyval.inode)=(yyvsp[(2) - (3)].inode);}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 420 "parser.y"
    {(yyval.inode)=new ASTNode_Math((yyvsp[(1) - (3)].inode),(yyvsp[(3) - (3)].inode),'-');}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 421 "parser.y"
    {(yyval.inode)=new ASTNode_Math((yyvsp[(1) - (3)].inode),(yyvsp[(3) - (3)].inode),'+');}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 422 "parser.y"
    {(yyval.inode)=new ASTNode_Math((yyvsp[(1) - (3)].inode),(yyvsp[(3) - (3)].inode),'*');}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 423 "parser.y"
    {(yyval.inode)=new ASTNode_Math((yyvsp[(1) - (3)].inode),(yyvsp[(3) - (3)].inode),'/');}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 424 "parser.y"
    {(yyval.inode)=new ASTNode_Math((yyvsp[(1) - (3)].inode),(yyvsp[(3) - (3)].inode),'%');}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 425 "parser.y"
    {
        (yyval.inode)=new ASTNode_Exponent((yyvsp[(1) - (3)].inode), (yyvsp[(3) - (3)].inode));
    }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 428 "parser.y"
    {
    checkUnknown((yyvsp[(1) - (3)].istr));
    ASTNode_Math *result = new ASTNode_Math(retrieve((yyvsp[(1) - (3)].istr)),(yyvsp[(3) - (3)].inode),(yyvsp[(2) - (3)].istr)[0]);
    (yyval.inode)=new ASTNode_Assignment(retrieve((yyvsp[(1) - (3)].istr)),result);
  }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 433 "parser.y"
    {checkUnknown((yyvsp[(1) - (3)].istr));(yyval.inode)=new ASTNode_Assignment(retrieve((yyvsp[(1) - (3)].istr)),(yyvsp[(3) - (3)].inode));}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 434 "parser.y"
    {checkUnknown((yyvsp[(1) - (1)].istr));(yyval.inode)=retrieve((yyvsp[(1) - (1)].istr));}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 435 "parser.y"
    {
    (yyval.inode)=new ASTNode_Int((yyvsp[(1) - (1)].iint));
  }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 438 "parser.y"
    {
        (yyval.inode)=new ASTNode_Char((yyvsp[(1) - (1)].istr));
    }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 441 "parser.y"
    {
        (yyval.inode)=new ASTNode_String((yyvsp[(1) - (1)].istr));
    }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 444 "parser.y"
    {
        checkUnknown((yyvsp[(1) - (4)].istr));
        (yyval.inode)=new ASTNode_ArrayItem(retrieve((yyvsp[(1) - (4)].istr)),(yyvsp[(3) - (4)].inode));

    }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 449 "parser.y"
    {
       checkUnknown((yyvsp[(1) - (6)].istr));
        (yyval.inode)=new ASTNode_ArrayAssignment(retrieve((yyvsp[(1) - (6)].istr)),(yyvsp[(3) - (6)].inode),(yyvsp[(6) - (6)].inode));
    }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 453 "parser.y"
    {
       checkUnknown((yyvsp[(1) - (6)].istr));
        ASTNode_ArrayItem *v = new ASTNode_ArrayItem(retrieve((yyvsp[(1) - (6)].istr)),(yyvsp[(3) - (6)].inode));
        ASTNode_Math *result = new ASTNode_Math(v,(yyvsp[(6) - (6)].inode),(yyvsp[(5) - (6)].istr)[0]);
        (yyval.inode)=new ASTNode_ArrayAssignment(retrieve((yyvsp[(1) - (6)].istr)),(yyvsp[(3) - (6)].inode),result);
    }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 459 "parser.y"
    {
        checkUnknown((yyvsp[(1) - (6)].istr));
        (yyval.inode)=new ASTNode_BuiltIn(retrieve((yyvsp[(1) - (6)].istr)),(yyvsp[(3) - (6)].istr),(yyvsp[(5) - (6)].multi_expr));
    }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 463 "parser.y"
    {
       ASTNode_BuiltIn *result;
       if ( string((yyvsp[(1) - (4)].istr))!="random" &&
            string((yyvsp[(1) - (4)].istr))!="print_mem") {
            result=new ASTNode_BuiltIn((yyvsp[(1) - (4)].istr),(yyvsp[(3) - (4)].multi_expr),currScopes,vtable,&functions);
        } else {
            result=new ASTNode_BuiltIn(0,(yyvsp[(1) - (4)].istr),(yyvsp[(3) - (4)].multi_expr));
        }
        (yyval.inode)=result;
    }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 475 "parser.y"
    {
        (yyvsp[(1) - (3)].multi_expr)->push_back((yyvsp[(3) - (3)].inode));
        (yyval.multi_expr)=(yyvsp[(1) - (3)].multi_expr);
    }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 479 "parser.y"
    {
        vector<ASTNode_Base*>* args=new vector<ASTNode_Base*>();
        args->push_back((yyvsp[(1) - (1)].inode));
        (yyval.multi_expr)=args;
    }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 484 "parser.y"
    {(yyval.multi_expr)= new vector<ASTNode_Base*>();}
    break;



/* Line 1806 of yacc.c  */
#line 2474 "parser.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 487 "parser.y"

int main(int argc, char* argv[]) {
    currScopes->push_back(globalScope);
  int argument;
  bool interpreter=false,debug=false,memory=false;


  while((argument = getopt(argc, argv, "hidm")) != -1) {
    switch(argument) {
      case 'h': help(); break;
      case 'i': interpreter=true; yyparse();break;
      case 'd': debug=true; break;
      case 'm': memory=true;break;
      case '?': exit(EXIT_FAILURE); break;
    }
  }

  vector<string> files;
  for(; optind < argc; optind++) {
    files.push_back(argv[optind]);
  }

  if(argc <= 1 && !interpreter) {
    error("Format: ./tube-ic[flags] [filename]\nType 'tube-ic -h' for help.");
  } else if(!(yyin = fopen(files[0].c_str(), "r"))) {
    error("Error opening " + files[0]);
  } else if(files.size() == 2) {
    ofstream out,tmp;
    tmp.open("compiler.tmp");
    out.open(files[1].c_str());
    if (out.fail()) {
      error("Error opening outfile " + files[1]);
    }
    // this will redirect all output directed at cout to our output
    // file
    streambuf * old = cout.rdbuf(tmp.rdbuf());
    cout<<"StartProgram:"<<endl;
    yyparse();
	for (unsigned i=0;i<functions.size();i++) {
		if (!functions[i]->defined)
			yyerror("function '"+functions[i]->getName()+"' never fully defined!");
	}
    cout.rdbuf(old);
    old=cout.rdbuf(out.rdbuf());
    IcLineTable l("compiler.tmp",debug, memory);
    l.compile();
    cout.rdbuf(old);
    cout << "Parse Successful!" << endl;
    exit(EXIT_SUCCESS);
  } else {
    ofstream out;
    out.open("compiler.tmp");
    if (out.fail()) {
        error("Error creating temp files");
    }
    streambuf* old=cout.rdbuf(out.rdbuf());
    yyparse();
    cout.rdbuf(old);
    IcLineTable l("compiler.tmp",debug,memory);
    l.compile();
    //cout << "Parse Successful!" << endl;
    exit(EXIT_SUCCESS);
  }
}



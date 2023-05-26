
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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

/* Line 189 of yacc.c  */
#line 1 "lrparser.y"


#include <stdio.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);
extern int type;
//FuncParam还需要修改
//需要修改VarDef、ConstExps、ConstDef、ConstInitVal、InitVal、ConstInitVals、InitVals



/* Line 189 of yacc.c  */
#line 86 "lrparser.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     num_INT = 258,
     Y_INT = 259,
     Y_VOID = 260,
     Y_CONST = 261,
     Y_IF = 262,
     Y_ELSE = 263,
     Y_WHILE = 264,
     Y_BREAK = 265,
     Y_CONTINUE = 266,
     Y_FLOAT = 267,
     Y_RETURN = 268,
     Y_ADD = 269,
     Y_COMMA = 270,
     Y_DIV = 271,
     Y_LPAR = 272,
     Y_SUB = 273,
     Y_LSQUARE = 274,
     Y_MODULO = 275,
     Y_MUL = 276,
     Y_NOT = 277,
     Y_RPAR = 278,
     Y_RSQUARE = 279,
     Y_RBRACKET = 280,
     Y_LESS = 281,
     Y_LESSEQ = 282,
     Y_GREAT = 283,
     Y_GREATEQ = 284,
     Y_NOTEQ = 285,
     Y_EQ = 286,
     Y_AND = 287,
     Y_OR = 288,
     Y_ASSIGN = 289,
     Y_LBRACKET = 290,
     Y_SEMICOLON = 291,
     num_FLOAT = 292,
     Y_ID = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 13 "lrparser.y"

     int		token;
	int		int_value;
	float     float_value;
	char*	id_name;
	past		pAst;



/* Line 214 of yacc.c  */
#line 170 "lrparser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 182 "lrparser.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    14,    16,    18,    20,
      25,    30,    34,    38,    42,    47,    51,    56,    58,    61,
      65,    70,    72,    75,    79,    83,    88,    91,    95,    97,
     101,   104,   109,   111,   114,   118,   123,   126,   130,   136,
     143,   145,   149,   152,   157,   161,   167,   169,   171,   173,
     178,   180,   183,   185,   191,   197,   205,   208,   211,   215,
     218,   222,   225,   227,   230,   232,   234,   236,   240,   244,
     248,   252,   254,   258,   262,   264,   268,   270,   274,   276,
     278,   282,   286,   288,   292,   296,   300,   302,   306,   311,
     314,   317,   320,   322,   326,   330,   332,   334,   336,   338,
     341,   345
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    39,    -1,    43,    42,    -1,    56,
      42,    -1,    43,    -1,    56,    -1,    44,    -1,    51,    -1,
       6,    59,    46,    36,    -1,     6,    59,    45,    36,    -1,
      46,    15,    46,    -1,    45,    15,    46,    -1,    38,    34,
      48,    -1,    38,    47,    34,    48,    -1,    19,    49,    24,
      -1,    19,    49,    24,    47,    -1,    49,    -1,    35,    25,
      -1,    35,    48,    25,    -1,    35,    48,    50,    25,    -1,
      69,    -1,    15,    48,    -1,    15,    48,    50,    -1,    59,
      53,    36,    -1,    59,    53,    52,    36,    -1,    15,    53,
      -1,    15,    53,    52,    -1,    38,    -1,    38,    34,    54,
      -1,    38,    47,    -1,    38,    47,    34,    54,    -1,    68,
      -1,    35,    25,    -1,    35,    54,    25,    -1,    35,    54,
      55,    25,    -1,    15,    54,    -1,    15,    54,    55,    -1,
      59,    38,    17,    23,    61,    -1,    59,    38,    17,    57,
      23,    61,    -1,    58,    -1,    57,    15,    58,    -1,    59,
      38,    -1,    59,    38,    19,    24,    -1,    59,    38,    75,
      -1,    59,    38,    19,    24,    75,    -1,     4,    -1,    12,
      -1,     5,    -1,    74,    34,    68,    36,    -1,    36,    -1,
      68,    36,    -1,    61,    -1,     9,    17,    67,    23,    60,
      -1,     7,    17,    67,    23,    60,    -1,     7,    17,    67,
      23,    60,     8,    60,    -1,    10,    36,    -1,    11,    36,
      -1,    13,    68,    36,    -1,    13,    36,    -1,    35,    62,
      25,    -1,    35,    25,    -1,    63,    -1,    63,    62,    -1,
      43,    -1,    60,    -1,    69,    -1,    69,    26,    64,    -1,
      69,    28,    64,    -1,    69,    27,    64,    -1,    69,    29,
      64,    -1,    64,    -1,    64,    31,    65,    -1,    64,    30,
      65,    -1,    65,    -1,    65,    32,    66,    -1,    66,    -1,
      66,    33,    67,    -1,    69,    -1,    70,    -1,    69,    14,
      70,    -1,    69,    18,    70,    -1,    71,    -1,    70,    21,
      71,    -1,    70,    16,    71,    -1,    70,    20,    71,    -1,
      73,    -1,    38,    17,    23,    -1,    38,    17,    72,    23,
      -1,    14,    71,    -1,    18,    71,    -1,    22,    71,    -1,
      68,    -1,    68,    15,    72,    -1,    17,    68,    23,    -1,
      74,    -1,     3,    -1,    37,    -1,    38,    -1,    38,    75,
      -1,    19,    68,    24,    -1,    19,    68,    24,    75,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    39,    40,    41,    42,    45,    46,    49,
      50,    53,    54,    57,    58,    61,    62,    65,    66,    67,
      68,    71,    74,    75,    78,    79,    82,    83,    86,    87,
      88,    89,    92,    93,    94,    95,    98,    99,   103,   104,
     107,   108,   111,   112,   113,   114,   117,   118,   119,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     135,   136,   139,   140,   143,   144,   147,   148,   149,   150,
     151,   154,   155,   156,   159,   160,   163,   164,   167,   171,
     172,   173,   176,   177,   178,   179,   182,   183,   184,   185,
     186,   187,   190,   191,   194,   195,   196,   197,   200,   201,
     204,   205
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "num_INT", "Y_INT", "Y_VOID", "Y_CONST",
  "Y_IF", "Y_ELSE", "Y_WHILE", "Y_BREAK", "Y_CONTINUE", "Y_FLOAT",
  "Y_RETURN", "Y_ADD", "Y_COMMA", "Y_DIV", "Y_LPAR", "Y_SUB", "Y_LSQUARE",
  "Y_MODULO", "Y_MUL", "Y_NOT", "Y_RPAR", "Y_RSQUARE", "Y_RBRACKET",
  "Y_LESS", "Y_LESSEQ", "Y_GREAT", "Y_GREATEQ", "Y_NOTEQ", "Y_EQ", "Y_AND",
  "Y_OR", "Y_ASSIGN", "Y_LBRACKET", "Y_SEMICOLON", "num_FLOAT", "Y_ID",
  "'\\n'", "$accept", "program", "CompUnit", "Decl", "ConstDecl",
  "ConstDefs", "ConstDef", "ConstExps", "ConstInitVal", "ConstExp",
  "ConstInitVals", "VarDecl", "VarDecls", "VarDef", "InitVal", "InitVals",
  "FuncDef", "FuncParams", "FuncParam", "Type", "Stmt", "Block",
  "BlockItems", "BlockItem", "RelExp", "EqExp", "LAndExp", "LOrExp", "Exp",
  "AddExp", "MulExp", "UnaryExp", "CallParams", "PrimaryExp", "LVal",
  "ArraySubscripts", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    42,    43,    43,    44,
      44,    45,    45,    46,    46,    47,    47,    48,    48,    48,
      48,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    53,    54,    54,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    58,    58,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    65,    65,    65,    66,    66,    67,    67,    68,    69,
      69,    69,    70,    70,    70,    70,    71,    71,    71,    71,
      71,    71,    72,    72,    73,    73,    73,    73,    74,    74,
      75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     1,     1,     1,     4,
       4,     3,     3,     3,     4,     3,     4,     1,     2,     3,
       4,     1,     2,     3,     3,     4,     2,     3,     1,     3,
       2,     4,     1,     2,     3,     4,     2,     3,     5,     6,
       1,     3,     2,     4,     3,     5,     1,     1,     1,     4,
       1,     2,     1,     5,     5,     7,     2,     2,     3,     2,
       3,     2,     1,     2,     1,     1,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     4,     2,
       2,     2,     1,     3,     3,     1,     1,     1,     1,     2,
       3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    46,    48,     0,    47,     0,     0,     5,     7,     8,
       6,     0,     0,     1,     2,     3,     4,    28,     0,     0,
       0,     0,     0,     0,     0,    30,     0,    24,     0,     0,
       0,     0,    10,     0,     9,     0,     0,    40,     0,    96,
       0,     0,     0,     0,    97,    98,     0,    21,    79,    82,
      86,    95,     0,    29,    32,    78,     0,    28,    26,    25,
       0,    13,    17,     0,    12,    11,     0,    38,     0,     0,
      42,    89,     0,    90,    91,     0,     0,    99,    15,     0,
       0,     0,     0,     0,    33,     0,    31,    27,    18,     0,
      14,     0,     0,     0,     0,     0,    61,    50,    64,     0,
      65,    52,     0,    62,     0,    95,    41,    39,     0,    44,
      94,    87,    92,     0,     0,    16,    80,    81,    84,    85,
      83,     0,    34,     0,     0,    19,     0,     0,     0,    56,
      57,    59,     0,    60,    63,    51,     0,    43,     0,    88,
     100,    36,    35,    22,    20,    71,    74,    76,     0,    66,
       0,    58,     0,    45,    93,   101,    37,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    73,
      72,    75,    77,    54,    67,    69,    68,    70,    53,     0,
      55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    20,    21,    25,    61,    62,
     126,     9,    28,    18,    53,   123,    10,    36,    37,    11,
     100,   101,   102,   103,   145,   146,   147,   148,   104,    55,
      48,    49,   113,    50,    51,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -147
static const yytype_int16 yypact[] =
{
     127,  -147,  -147,    83,  -147,    29,    10,   127,  -147,  -147,
     127,    32,    38,  -147,  -147,  -147,  -147,    62,    11,     1,
      12,    23,    79,   296,    28,    21,    47,  -147,    98,   249,
      64,    38,  -147,    38,  -147,   114,    37,  -147,   118,  -147,
     296,   296,   296,   296,  -147,    50,   133,    76,   101,  -147,
    -147,  -147,    75,  -147,  -147,    76,    28,    17,   145,  -147,
     222,  -147,  -147,   249,  -147,  -147,   141,  -147,    83,   114,
     142,  -147,   139,  -147,  -147,   251,   296,  -147,   146,   296,
     296,   296,   296,   296,  -147,    -2,  -147,  -147,  -147,     7,
    -147,   147,   150,   132,   134,   258,  -147,  -147,  -147,    47,
    -147,  -147,   144,   177,   135,   138,  -147,  -147,   287,  -147,
    -147,  -147,   158,   151,   161,  -147,   101,   101,  -147,  -147,
    -147,    28,  -147,   167,   249,  -147,   168,   296,   296,  -147,
    -147,  -147,   160,  -147,  -147,  -147,   296,   156,   296,  -147,
     156,   182,  -147,   183,  -147,    -6,   169,   170,   179,    97,
     181,  -147,   164,  -147,  -147,  -147,  -147,  -147,   296,   296,
     296,   296,   213,   296,   296,   296,   296,   213,  -147,  -147,
    -147,  -147,  -147,   197,  -147,  -147,  -147,  -147,  -147,   213,
    -147
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,    54,   -62,  -147,  -147,    49,   -16,   -49,   184,
      63,  -147,   152,   185,   -44,    67,  -147,  -147,   149,     6,
    -146,   -30,   106,  -147,   -36,   -52,    58,  -118,   -22,   -23,
      39,   -25,    81,  -147,   -59,   -69
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      47,   109,    54,    30,    98,    67,    47,   105,    85,    12,
     150,    89,    86,   121,    90,    71,   173,    73,    74,    72,
      23,   178,   124,   122,   158,   159,    26,    31,    38,    13,
      54,    39,   125,   180,    54,    29,    23,    47,    33,   107,
      47,    98,    40,   172,   105,    41,    42,    27,    32,    14,
      43,    24,    68,   112,   114,    56,   118,   119,   120,    34,
      69,    15,   115,    52,    16,    44,    45,    75,   153,    76,
      17,   155,    99,   132,    38,   143,    19,   141,    39,    22,
      64,    23,    65,     1,     2,    57,   114,     1,     2,    40,
      79,     4,    41,    42,    80,     4,    24,    43,    63,    54,
      84,    47,    35,   105,   149,   149,   169,   170,   105,    99,
      52,    79,    44,    45,   152,    80,   112,    81,   116,   117,
     105,    82,    83,   163,   164,   165,   166,   174,   175,   176,
     177,     1,     2,     3,    59,   149,   149,   149,   149,     4,
     149,   149,   149,   149,    39,     1,     2,     3,    91,    66,
      92,    93,    94,     4,    95,    40,    70,    78,    41,    42,
      26,   108,   110,    43,   127,    23,    96,   128,   129,   133,
     130,   135,   136,   138,   139,    76,    66,    97,    44,    45,
      39,     1,     2,     3,    91,   140,    92,    93,    94,     4,
      95,    40,   142,   144,    41,    42,   151,   121,   124,    43,
     168,   160,   162,   161,   167,   179,   157,    46,   156,   134,
      87,    58,    66,    97,    44,    45,    39,   106,   171,   154,
      91,     0,    92,    93,    94,    39,    95,    40,     0,     0,
      41,    42,     0,     0,     0,    43,    40,     0,     0,    41,
      42,     0,     0,     0,    43,     0,     0,    88,    66,    97,
      44,    45,    39,     0,    39,     0,     0,    60,     0,    44,
      45,    39,     0,    40,     0,    40,    41,    42,    41,    42,
       0,    43,    40,    43,   111,    41,    42,     0,     0,     0,
      43,     0,     0,     0,    60,     0,    44,    45,    44,    45,
      39,     0,     0,     0,   131,    44,    45,     0,     0,    39,
       0,    40,     0,     0,    41,    42,     0,     0,     0,    43,
      40,   137,     0,    41,    42,     0,     0,     0,    43,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,     0,
       0,     0,     0,    44,    45
};

static const yytype_int16 yycheck[] =
{
      23,    70,    24,    19,    66,    35,    29,    66,    52,     3,
     128,    60,    56,    15,    63,    40,   162,    42,    43,    41,
      19,   167,    15,    25,    30,    31,    15,    15,    22,     0,
      52,     3,    25,   179,    56,    34,    19,    60,    15,    69,
      63,   103,    14,   161,   103,    17,    18,    36,    36,    39,
      22,    34,    15,    75,    76,    34,    81,    82,    83,    36,
      23,     7,    78,    35,    10,    37,    38,    17,   137,    19,
      38,   140,    66,    95,    68,   124,    38,   121,     3,    17,
      31,    19,    33,     4,     5,    38,   108,     4,     5,    14,
      14,    12,    17,    18,    18,    12,    34,    22,    34,   121,
      25,   124,    23,   162,   127,   128,   158,   159,   167,   103,
      35,    14,    37,    38,   136,    18,   138,    16,    79,    80,
     179,    20,    21,    26,    27,    28,    29,   163,   164,   165,
     166,     4,     5,     6,    36,   158,   159,   160,   161,    12,
     163,   164,   165,   166,     3,     4,     5,     6,     7,    35,
       9,    10,    11,    12,    13,    14,    38,    24,    17,    18,
      15,    19,    23,    22,    17,    19,    25,    17,    36,    25,
      36,    36,    34,    15,    23,    19,    35,    36,    37,    38,
       3,     4,     5,     6,     7,    24,     9,    10,    11,    12,
      13,    14,    25,    25,    17,    18,    36,    15,    15,    22,
      36,    32,    23,    33,    23,     8,   143,    23,   141,   103,
      58,    26,    35,    36,    37,    38,     3,    68,   160,   138,
       7,    -1,     9,    10,    11,     3,    13,    14,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    14,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    35,    36,
      37,    38,     3,    -1,     3,    -1,    -1,    35,    -1,    37,
      38,     3,    -1,    14,    -1,    14,    17,    18,    17,    18,
      -1,    22,    14,    22,    23,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    35,    -1,    37,    38,    37,    38,
       3,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,     3,
      -1,    14,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      14,    24,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,    12,    41,    42,    43,    44,    51,
      56,    59,    59,     0,    39,    42,    42,    38,    53,    38,
      45,    46,    17,    19,    34,    47,    15,    36,    52,    34,
      47,    15,    36,    15,    36,    23,    57,    58,    59,     3,
      14,    17,    18,    22,    37,    38,    49,    69,    70,    71,
      73,    74,    35,    54,    68,    69,    34,    38,    53,    36,
      35,    48,    49,    34,    46,    46,    35,    61,    15,    23,
      38,    71,    68,    71,    71,    17,    19,    75,    24,    14,
      18,    16,    20,    21,    25,    54,    54,    52,    25,    48,
      48,     7,     9,    10,    11,    13,    25,    36,    43,    59,
      60,    61,    62,    63,    68,    74,    58,    61,    19,    75,
      23,    23,    68,    72,    68,    47,    70,    70,    71,    71,
      71,    15,    25,    55,    15,    25,    50,    17,    17,    36,
      36,    36,    68,    25,    62,    36,    34,    24,    15,    23,
      24,    54,    25,    48,    25,    64,    65,    66,    67,    69,
      67,    36,    68,    75,    72,    75,    55,    50,    30,    31,
      32,    33,    23,    26,    27,    28,    29,    23,    36,    65,
      65,    66,    67,    60,    64,    64,    64,    64,    60,     8,
      60
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 36 "lrparser.y"
    {showAst("|", (yyvsp[(1) - (2)].pAst), 0); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 39 "lrparser.y"
    {past l = newCompUnit((yyvsp[(1) - (2)].pAst), NULL); l->right = (yyvsp[(2) - (2)].pAst); (yyval.pAst) = l;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 40 "lrparser.y"
    {past l = newCompUnit((yyvsp[(1) - (2)].pAst), NULL); l->right = (yyvsp[(2) - (2)].pAst); (yyval.pAst) = l;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 41 "lrparser.y"
    {(yyval.pAst) = newCompUnit((yyvsp[(1) - (1)].pAst), NULL);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 42 "lrparser.y"
    {(yyval.pAst) = newCompUnit((yyvsp[(1) - (1)].pAst), NULL);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 49 "lrparser.y"
    {(yyval.pAst) = newDeclStmt(NULL, (yyvsp[(3) - (4)].pAst));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 50 "lrparser.y"
    {(yyval.pAst) = newDeclStmt(NULL, (yyvsp[(3) - (4)].pAst));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 53 "lrparser.y"
    {(yyval.pAst) = newDeclStmt((yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 54 "lrparser.y"
    {(yyval.pAst) = newDeclStmt((yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 57 "lrparser.y"
    {(yyval.pAst) = newVarDecl(get_conststype(type), type, 1, (yyvsp[(1) - (3)].id_name), NULL, (yyvsp[(3) - (3)].pAst));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 58 "lrparser.y"
    {(yyval.pAst) = newVarDecl(get_conststype(type), type, 1, (yyvsp[(1) - (4)].id_name), NULL, (yyvsp[(4) - (4)].pAst)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 61 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (3)].pAst);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 62 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (4)].pAst); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 66 "lrparser.y"
    {(yyval.pAst) = NULL; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 67 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (3)].pAst);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 68 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (4)].pAst); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 74 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (2)].pAst);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 75 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (3)].pAst); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 78 "lrparser.y"
    {(yyval.pAst) = newDeclStmt(NULL, (yyvsp[(2) - (3)].pAst));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 79 "lrparser.y"
    {(yyval.pAst) = newDeclStmt((yyvsp[(2) - (4)].pAst), (yyvsp[(3) - (4)].pAst));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 82 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (2)].pAst);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 83 "lrparser.y"
    {(yyval.pAst) = newDeclStmt((yyvsp[(2) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 86 "lrparser.y"
    {(yyval.pAst) = newVarDecl(get_stype(type), type, 0, (yyvsp[(1) - (1)].id_name), NULL, NULL);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 87 "lrparser.y"
    {(yyval.pAst) = newVarDecl(get_stype(type), type, 0, (yyvsp[(1) - (3)].id_name), NULL, (yyvsp[(3) - (3)].pAst));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 88 "lrparser.y"
    {(yyval.pAst) = newVarDecl(get_stype(type), type, 0, (yyvsp[(1) - (2)].id_name), NULL, NULL); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 89 "lrparser.y"
    {(yyval.pAst) = newVarDecl(get_stype(type), type, 0, (yyvsp[(1) - (4)].id_name), NULL, (yyvsp[(4) - (4)].pAst)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 93 "lrparser.y"
    {(yyval.pAst) = NULL;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 94 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (3)].pAst);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 95 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (4)].pAst); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 98 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (2)].pAst); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 99 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (3)].pAst); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 103 "lrparser.y"
    {(yyval.pAst) = newFuncDecl(get_stype((yyvsp[(1) - (5)].pAst)->ivalue), (yyvsp[(1) - (5)].pAst)->ivalue,(yyvsp[(2) - (5)].id_name), NULL, newCompoundStmt(NULL, (yyvsp[(5) - (5)].pAst)));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 104 "lrparser.y"
    {(yyval.pAst) = newFuncDecl(get_stype((yyvsp[(1) - (6)].pAst)->ivalue), (yyvsp[(1) - (6)].pAst)->ivalue, (yyvsp[(2) - (6)].id_name), (yyvsp[(4) - (6)].pAst), newCompoundStmt(NULL, (yyvsp[(6) - (6)].pAst)));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 108 "lrparser.y"
    {(yyvsp[(3) - (3)].pAst)->left = (yyvsp[(1) - (3)].pAst); (yyval.pAst) = (yyvsp[(3) - (3)].pAst);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 111 "lrparser.y"
    {(yyval.pAst) = newParaDecl(get_stype((yyvsp[(1) - (2)].pAst)->ivalue), (yyvsp[(2) - (2)].id_name), NULL, NULL);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 112 "lrparser.y"
    {(yyval.pAst) = newParaDecl(get_stype((yyvsp[(1) - (4)].pAst)->ivalue), (yyvsp[(2) - (4)].id_name), NULL, NULL);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 113 "lrparser.y"
    {(yyval.pAst) = newParaDecl(get_stype((yyvsp[(1) - (3)].pAst)->ivalue), (yyvsp[(2) - (3)].id_name), NULL, NULL);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 114 "lrparser.y"
    {(yyval.pAst) = newParaDecl(get_stype((yyvsp[(1) - (5)].pAst)->ivalue), (yyvsp[(2) - (5)].id_name), NULL, NULL);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 117 "lrparser.y"
    {yylval.int_value = Y_INT;(yyval.pAst) = newType(Y_INT);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 118 "lrparser.y"
    {yylval.int_value = Y_FLOAT;(yyval.pAst) = newType(Y_FLOAT);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 119 "lrparser.y"
    {yylval.int_value = Y_VOID;(yyval.pAst) = newType(Y_VOID);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 122 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("=", Y_ASSIGN, (yyvsp[(1) - (4)].pAst), (yyvsp[(3) - (4)].pAst));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 123 "lrparser.y"
    {(yyval.pAst) = NULL;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 124 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(1) - (2)].pAst);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 126 "lrparser.y"
    {(yyval.pAst) = newWhileStmt((yyvsp[(3) - (5)].pAst), newCompoundStmt(NULL,(yyvsp[(5) - (5)].pAst)));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 127 "lrparser.y"
    {(yyval.pAst) = newIfStmt((yyvsp[(3) - (5)].pAst), newCompoundStmt(NULL,(yyvsp[(5) - (5)].pAst)), NULL);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 128 "lrparser.y"
    {(yyval.pAst) = newIfStmt((yyvsp[(3) - (7)].pAst), newCompoundStmt(NULL,(yyvsp[(5) - (7)].pAst)), newCompoundStmt(NULL,(yyvsp[(7) - (7)].pAst)));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 129 "lrparser.y"
    {(yyval.pAst) = newBreakStmt();;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 130 "lrparser.y"
    {(yyval.pAst) = newContinueStmt();;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 131 "lrparser.y"
    {(yyval.pAst) = newReturnStmt((yyvsp[(2) - (3)].pAst), NULL);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 132 "lrparser.y"
    {(yyval.pAst) = newReturnStmt(NULL, NULL);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 135 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (3)].pAst);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 136 "lrparser.y"
    {(yyval.pAst) = NULL;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 139 "lrparser.y"
    {(yyval.pAst) = newCompoundStmt((yyvsp[(1) - (1)].pAst), NULL);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 140 "lrparser.y"
    {past l = newCompoundStmt((yyvsp[(1) - (2)].pAst), NULL); l->right = (yyvsp[(2) - (2)].pAst); (yyval.pAst) = l;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 148 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("<", Y_LESS, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 149 "lrparser.y"
    {(yyval.pAst) = newBinaryOper(">", Y_GREAT, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 150 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("<=", Y_LESSEQ, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 151 "lrparser.y"
    {(yyval.pAst) = newBinaryOper(">=", Y_GREATEQ, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 155 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("==", Y_EQ, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 156 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("!=", Y_NOTEQ, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 160 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("&&", Y_AND, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 164 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("||", Y_OR, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 172 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("+", Y_ADD, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 173 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("-", Y_SUB, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 177 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("*", Y_MUL, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 178 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("/", Y_DIV, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 179 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("%", Y_MODULO, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 183 "lrparser.y"
    {(yyval.pAst) = newCallExp(NULL, 0, (yyvsp[(1) - (3)].id_name), NULL, NULL);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 184 "lrparser.y"
    {(yyval.pAst) = newCallExp(NULL, 0, (yyvsp[(1) - (4)].id_name), (yyvsp[(3) - (4)].pAst), NULL);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 185 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("+", Y_ADD, NULL, (yyvsp[(2) - (2)].pAst));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 186 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("-", Y_SUB, NULL, (yyvsp[(2) - (2)].pAst));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 187 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("!", Y_NOT, NULL, (yyvsp[(2) - (2)].pAst));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 191 "lrparser.y"
    {(yyval.pAst) = newBinaryOper("-", Y_SUB, (yyvsp[(1) - (3)].pAst), (yyvsp[(3) - (3)].pAst));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 194 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (3)].pAst);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 196 "lrparser.y"
    {(yyval.pAst) = newIntVal((yyvsp[(1) - (1)].int_value));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 197 "lrparser.y"
    {(yyval.pAst) = newFloatVal((yyvsp[(1) - (1)].float_value));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 200 "lrparser.y"
    {(yyval.pAst) = newDeclRefExp((yyvsp[(1) - (1)].id_name), NULL, NULL);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 201 "lrparser.y"
    {(yyval.pAst) = newDeclRefExp((yyvsp[(1) - (2)].id_name), NULL, NULL);;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 204 "lrparser.y"
    {(yyval.pAst) = (yyvsp[(2) - (3)].pAst);}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 205 "lrparser.y"
    {(yyval.pAst) = newArraySubscriptsExp((yyvsp[(2) - (4)].pAst), (yyvsp[(4) - (4)].pAst));;}
    break;



/* Line 1455 of yacc.c  */
#line 2144 "lrparser.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 208 "lrparser.y"



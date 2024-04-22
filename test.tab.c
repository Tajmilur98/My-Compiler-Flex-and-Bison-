
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
#line 1 "test.y"

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
extern int yylineno;


    char variable[1000][1000];
    int store[1000];
    char store_char[1000];
	char store_str[1000][1000];  
	float store_float[1000]; 
	int type_of_id[1000];

	int tot_var = 1,f=1;
	int casedefault=0,casevar=0;

      int isdeclared(char *s){
        int i;
        for(i=1; i<tot_var; i++){
            if(strcmp(variable[i],s) == 0)return 1;
        }return 0;
      }
    
      int assign(char *s)
      {
        if(isdeclared(s)==1)
            return 0;
        strcpy(variable[tot_var],s); 
        store[tot_var]=0;
        tot_var++;
        return 1;
      }

      int setval(char *s,int val)
    {
        if(isdeclared(s) == 0)
            return 0;
        int ok=0, i;
        for( i=1; i<tot_var; i++)
        {
            if(strcmp(variable[i],s) == 0)
            {
                ok=i;
                break;
            }
        }
        store[ok]=val;
        return 1;
    }

      int getval(char *s)
    {

        int pos=-1;
        int i;
        for( i=1; i<tot_var; i++)
        {
            if(strcmp(variable[i],s) == 0)
            {
                pos=i;
                break;
            }
        }
        return pos;
    }

    char parameters[100][100];
	int cnt_func = 1;
    int func_here(char *s){
 		int i;
        for(i=1; i<cnt_func; i++){
            if(strcmp(parameters[i],s) == 0)return 1;
        }return 0;
	}

    int assign_func(char *s)
    {
        strcpy(parameters[cnt_func],s); cnt_func++;return 1;
    }

    




/* Line 189 of yacc.c  */
#line 161 "test.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     NUMBER = 258,
     VARIABLE = 259,
     STR = 260,
     INCLUDE = 261,
     HFSTD = 262,
     HFSTR = 263,
     HFMATH = 264,
     HFLIB = 265,
     INT = 266,
     FLOAT = 267,
     CHAR = 268,
     STRING = 269,
     VOID = 270,
     UDFUNC = 271,
     COLON = 272,
     MAIN = 273,
     PRINT = 274,
     SCAN = 275,
     RETURN = 276,
     AT = 277,
     FSINT = 278,
     FSCRT = 279,
     FSFLT = 280,
     FSSRT = 281,
     ASSIGN = 282,
     EOI = 283,
     ADD1 = 284,
     SUB1 = 285,
     INCBY = 286,
     DECBY = 287,
     SWITCH = 288,
     DEFAULT = 289,
     CASE = 290,
     BREAK = 291,
     FOR = 292,
     WHILE = 293,
     SIN = 294,
     COS = 295,
     TAN = 296,
     LOG10 = 297,
     LOGE = 298,
     ODDEVEN = 299,
     FACT = 300,
     SLCOM = 301,
     MLCOM = 302,
     DOUBLE = 303,
     IF = 304,
     ELIF = 305,
     IFX = 306,
     ELSE = 307,
     NE = 308,
     GTE = 309,
     LTE = 310,
     EQ = 311,
     GT = 312,
     LT = 313
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 89 "test.y"

    char *ch;
    char c;
    int dim;
    int me;
    double floating;



/* Line 214 of yacc.c  */
#line 265 "test.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 277 "test.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNRULES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    63,     2,     2,
      65,    66,    61,    59,    69,    60,     2,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,    68,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     8,    14,    19,    21,    23,    25,
      27,    29,    31,    32,    42,    46,    48,    56,    57,    59,
      61,    63,    65,    67,    70,    73,    74,    78,    82,    84,
      90,    96,   101,   103,   105,   107,   112,   118,   126,   130,
     148,   166,   180,   194,   202,   214,   233,   235,   237,   239,
     241,   245,   249,   253,   257,   261,   265,   269,   273,   277,
     281,   285,   289,   294,   299,   304,   309,   314,   319
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      71,     0,    -1,    72,    74,    77,    -1,    -1,    72,     6,
      58,    73,    57,    -1,     6,    58,    73,    57,    -1,     7,
      -1,     8,    -1,     9,    -1,    10,    -1,    80,    -1,    75,
      -1,    -1,    16,    78,     4,    65,    76,    66,    67,    79,
      68,    -1,    76,    69,     4,    -1,     4,    -1,    78,    18,
      65,    66,    67,    79,    68,    -1,    -1,    11,    -1,    12,
      -1,    15,    -1,    13,    -1,    14,    -1,    80,    79,    -1,
      82,    79,    -1,    -1,    78,    81,    28,    -1,    81,    69,
       4,    -1,     4,    -1,    19,    65,    87,    66,    28,    -1,
      20,    65,     4,    66,    28,    -1,     4,    27,    88,    28,
      -1,    86,    -1,    85,    -1,    83,    -1,    82,    21,     3,
      28,    -1,    33,     4,    67,    84,    68,    -1,    35,    88,
      17,    82,    36,    28,    84,    -1,    34,    17,    82,    -1,
      37,    65,     4,    27,     3,    28,     4,    55,     3,    28,
       4,    31,     3,    66,    67,    82,    68,    -1,    37,    65,
       4,    27,     3,    28,     4,    54,     3,    28,     4,    32,
       3,    66,    67,    82,    68,    -1,    38,    65,     4,    55,
       3,    66,    67,    82,     4,    31,     3,    28,    68,    -1,
      38,    65,     4,    54,     3,    66,    67,    82,     4,    32,
       3,    28,    68,    -1,    49,    65,    88,    66,    67,    79,
      68,    -1,    49,    65,    88,    66,    67,    79,    68,    52,
      67,    79,    68,    -1,    49,    65,    88,    66,    67,    79,
      68,    50,    65,    88,    66,    67,    79,    68,    52,    67,
      79,    68,    -1,     4,    -1,     5,    -1,     3,    -1,     4,
      -1,    88,    59,    88,    -1,    88,    60,    88,    -1,    88,
      61,    88,    -1,    88,    62,    88,    -1,    88,    64,    88,
      -1,    88,    63,    88,    -1,    65,    88,    66,    -1,    88,
      56,    88,    -1,    88,    58,    88,    -1,    88,    57,    88,
      -1,    88,    55,    88,    -1,    88,    54,    88,    -1,    39,
      65,    88,    66,    -1,    40,    65,    88,    66,    -1,    41,
      65,    88,    66,    -1,    42,    65,    88,    66,    -1,    43,
      65,    88,    66,    -1,    44,    65,    88,    66,    -1,    45,
      65,    88,    66,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   126,   129,   130,   132,   132,   132,   132,
     136,   137,   138,   140,   147,   157,   172,   173,   176,   176,
     176,   176,   176,   180,   180,   181,   186,   190,   198,   209,
     211,   217,   230,   232,   234,   236,   242,   252,   263,   277,
     285,   293,   302,   316,   320,   324,   332,   343,   349,   350,
     360,   364,   369,   374,   386,   388,   390,   393,   396,   399,
     402,   405,   407,   409,   411,   413,   415,   417,   419
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "VARIABLE", "STR", "INCLUDE",
  "HFSTD", "HFSTR", "HFMATH", "HFLIB", "INT", "FLOAT", "CHAR", "STRING",
  "VOID", "UDFUNC", "COLON", "MAIN", "PRINT", "SCAN", "RETURN", "AT",
  "FSINT", "FSCRT", "FSFLT", "FSSRT", "ASSIGN", "EOI", "ADD1", "SUB1",
  "INCBY", "DECBY", "SWITCH", "DEFAULT", "CASE", "BREAK", "FOR", "WHILE",
  "SIN", "COS", "TAN", "LOG10", "LOGE", "ODDEVEN", "FACT", "SLCOM",
  "MLCOM", "DOUBLE", "IF", "ELIF", "IFX", "ELSE", "NE", "GTE", "LTE", "EQ",
  "GT", "LT", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'('", "')'",
  "'{'", "'}'", "','", "$accept", "program", "include", "hf", "before",
  "func", "parameters", "start", "type", "lines", "declare", "id", "stmt",
  "switch_case", "casecode", "loops", "condstmt", "pcontent", "expr", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,    43,
      45,    42,    47,    37,    94,    40,    41,   123,   125,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    79,    79,    79,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    83,    84,    84,    85,
      85,    85,    85,    86,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     5,     4,     1,     1,     1,     1,
       1,     1,     0,     9,     3,     1,     7,     0,     1,     1,
       1,     1,     1,     2,     2,     0,     3,     3,     1,     5,
       5,     4,     1,     1,     1,     4,     5,     7,     3,    17,
      17,    13,    13,     7,    11,    18,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,    12,     0,     1,     0,    18,    19,    21,
      22,    20,     0,    17,    11,     0,    10,     6,     7,     8,
       9,     0,     0,     0,     2,     0,    28,     0,     5,     0,
       0,     0,    26,     0,     4,     0,     0,    27,    15,     0,
       0,     0,     0,    25,    25,    14,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    25,    34,    33,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    23,     0,
      24,    13,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,     0,     0,     0,     0,     0,     0,     0,    56,
      61,    60,    57,    59,    58,    50,    51,    52,    53,    55,
      54,    29,    30,     0,     0,    36,     0,     0,     0,    25,
      62,    63,    64,    65,    66,    67,    68,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,    25,
       0,     0,    42,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    40,    39,     0,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    21,    13,    14,    39,    24,    15,    53,
      54,    27,    55,    56,   116,    57,    58,    85,    82
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -142
static const yytype_int16 yypact[] =
{
      20,   -23,    53,   292,     5,  -142,    45,  -142,  -142,  -142,
    -142,  -142,    50,    50,  -142,   106,  -142,  -142,  -142,  -142,
    -142,    55,     5,   109,  -142,    96,  -142,   -21,  -142,    66,
      61,    63,  -142,   123,  -142,   125,    64,  -142,  -142,    32,
      65,    67,   132,   105,   105,  -142,   114,    68,    87,   146,
      88,    91,   235,   100,   105,    62,  -142,  -142,  -142,   113,
      15,     4,   190,   140,   216,   229,    15,  -142,  -142,   243,
    -142,  -142,  -142,  -142,   236,   237,   244,   245,   246,   247,
     248,    15,   103,  -142,  -142,   193,   206,   -13,   258,    24,
     116,   286,    15,    15,    15,    15,    15,    15,    15,   129,
    -142,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,   287,   288,   300,    15,   250,   316,   317,   318,
     255,  -142,   142,   155,   168,   181,   194,   207,   220,  -142,
      85,    85,    85,    85,    85,     8,     8,   259,   259,   259,
     259,  -142,  -142,   102,    30,  -142,   296,   260,   261,   105,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,   304,   102,   324,
     262,   263,   264,    13,    42,   102,   102,    52,   303,   330,
     331,    -1,     2,   270,   269,   -13,   309,   310,   307,   311,
      15,   105,  -142,   336,   337,   340,   341,   233,   277,   314,
     319,   320,   321,   280,  -142,   348,   349,   285,   289,   105,
     290,   293,  -142,  -142,   294,   291,   297,   302,   102,   102,
     298,   -17,   -16,   105,  -142,  -142,   295,  -142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,  -142,   333,  -142,  -142,  -142,  -142,    95,   -44,
     357,  -142,  -141,  -142,   186,  -142,  -142,  -142,   -65
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      59,    90,   157,   178,    69,    69,   179,    32,    83,    84,
      68,    70,    17,    18,    19,    20,    99,   163,    72,    73,
      69,   114,   115,    69,   171,   172,     1,   122,   123,   124,
     125,   126,   127,   128,    69,     4,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   158,    33,   168,
     144,   214,   215,     5,    74,    75,    76,    77,    78,    79,
      80,     7,     8,     9,    10,    11,    46,   211,   212,   108,
     109,   110,   111,     7,     8,     9,    10,    11,   118,   119,
      81,    47,    48,    69,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    49,   169,   170,    41,    50,
      51,    42,   173,    22,   174,   162,    46,    23,    25,    46,
      26,    52,    28,    30,    31,   187,     7,     8,     9,    10,
      11,    47,    48,    34,    47,    48,    35,    37,    36,    38,
      40,   100,    43,    61,    44,    49,    45,   188,    49,    50,
      51,    60,    50,    51,   106,   107,   108,   109,   110,   111,
      63,    52,    62,    64,    52,   204,    65,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    67,   216,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,    71,   120,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    86,   129,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    87,   150,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      88,   151,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    89,   152,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    91,   153,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     154,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   113,   155,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   117,   156,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     6,   193,
      66,    92,    93,     7,     8,     9,    10,    11,    12,    94,
      95,    96,    97,    98,   121,   141,   142,   143,   145,   146,
     147,   148,   149,   111,   159,    69,   160,   161,   164,   165,
     166,   175,   167,   176,   177,   180,   181,   183,   184,   185,
     189,   190,   186,   191,   192,   194,   195,   199,   197,   198,
     196,   200,   201,   202,   210,    29,   205,   203,   208,   206,
      16,   182,   207,   217,   209,   213
};

static const yytype_uint8 yycheck[] =
{
      44,    66,   143,     4,    21,    21,     4,    28,     4,     5,
      54,    55,     7,     8,     9,    10,    81,   158,     3,     4,
      21,    34,    35,    21,   165,   166,     6,    92,    93,    94,
      95,    96,    97,    98,    21,    58,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    17,    69,    36,
     115,    68,    68,     0,    39,    40,    41,    42,    43,    44,
      45,    11,    12,    13,    14,    15,     4,   208,   209,    61,
      62,    63,    64,    11,    12,    13,    14,    15,    54,    55,
      65,    19,    20,    21,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    33,    54,    55,    66,    37,
      38,    69,    50,    58,    52,   149,     4,    12,    13,     4,
       4,    49,    57,     4,    18,   180,    11,    12,    13,    14,
      15,    19,    20,    57,    19,    20,    65,     4,    65,     4,
      66,    28,    67,    65,    67,    33,     4,   181,    33,    37,
      38,    27,    37,    38,    59,    60,    61,    62,    63,    64,
       4,    49,    65,    65,    49,   199,    65,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    68,   213,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    68,    66,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     4,    66,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    67,    66,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       4,    66,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     4,    66,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     3,    66,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    66,
      66,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    66,    66,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    27,    66,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     6,    66,
      65,    65,    65,    11,    12,    13,    14,    15,    16,    65,
      65,    65,    65,    65,    28,    28,    28,    17,    68,     3,
       3,     3,    67,    64,    28,    21,    66,    66,     4,    67,
      67,    28,    68,     3,     3,    65,    67,    28,    28,    32,
       4,     4,    31,     3,     3,    68,    32,    67,    28,    28,
      31,     3,     3,    68,    52,    22,    66,    68,    67,    66,
       3,   175,    68,    68,    67,    67
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    71,    72,    58,     0,     6,    11,    12,    13,
      14,    15,    16,    74,    75,    78,    80,     7,     8,     9,
      10,    73,    58,    78,    77,    78,     4,    81,    57,    73,
       4,    18,    28,    69,    57,    65,    65,     4,     4,    76,
      66,    66,    69,    67,    67,     4,     4,    19,    20,    33,
      37,    38,    49,    79,    80,    82,    83,    85,    86,    79,
      27,    65,    65,     4,    65,    65,    65,    68,    79,    21,
      79,    68,     3,     4,    39,    40,    41,    42,    43,    44,
      45,    65,    88,     4,     5,    87,     4,    67,     4,     4,
      88,     3,    65,    65,    65,    65,    65,    65,    65,    88,
      28,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    66,    66,    34,    35,    84,    27,    54,    55,
      66,    28,    88,    88,    88,    88,    88,    88,    88,    66,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    28,    28,    17,    88,    68,     3,     3,     3,    67,
      66,    66,    66,    66,    66,    66,    66,    82,    17,    28,
      66,    66,    79,    82,     4,    67,    67,    68,    36,    54,
      55,    82,    82,    50,    52,    28,     3,     3,     4,     4,
      65,    67,    84,    28,    28,    32,    31,    88,    79,     4,
       4,     3,     3,    66,    68,    32,    31,    28,    28,    67,
       3,     3,    68,    68,    79,    66,    66,    68,    67,    67,
      52,    82,    82,    67,    68,    68,    79,    68
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
#line 125 "test.y"
    {printf("program compiled successfully.\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 129 "test.y"
    {printf("header files included.\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 141 "test.y"
    {
		printf("FUNC Declared!\n\n");		
	;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 148 "test.y"
    {
   		 if(func_here((yyvsp[(3) - (3)].ch))==1)
      			  printf("\nparameters already exists!");
   		 else
    			    assign_func((yyvsp[(3) - (3)].ch));
                     assign((yyvsp[(3) - (3)].ch));

		;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 158 "test.y"
    {
		   if(func_here((yyvsp[(1) - (1)].ch))==1)
      			 printf("\nparameters already exists!");
   		 else
      				  assign_func((yyvsp[(1) - (1)].ch));
                       assign((yyvsp[(1) - (1)].ch));
		;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 172 "test.y"
    {printf("main function compiled successfully.\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 181 "test.y"
    {(yyval.dim)=1;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 186 "test.y"
    { printf("\nValid declaration!\n"); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 191 "test.y"
    {
   		 if(isdeclared((yyvsp[(3) - (3)].ch))==1)
      			  printf("\nDouble Declaration!");
   		 else
    			    assign((yyvsp[(3) - (3)].ch));
		;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 199 "test.y"
    {
		   if(isdeclared((yyvsp[(1) - (1)].ch))==1)
      			  printf("\nDouble Declaration! \n");
   		 else
      				  assign((yyvsp[(1) - (1)].ch));
		;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 209 "test.y"
    {printf("Print successful.\n");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 211 "test.y"
    {
      if(isdeclared((yyvsp[(3) - (5)].ch))==1)
            {
			printf("Scan is successful.\n");
		}
      ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 218 "test.y"
    {
 		    if(setval((yyvsp[(1) - (4)].ch),(yyvsp[(3) - (4)].dim))==0)
  		 	{
  		    	(yyval.dim)=0;
				printf("\nNot declared\n");
   			}
    		else
    		{
                store[getval((yyvsp[(1) - (4)].ch))]= (yyvsp[(3) - (4)].dim);
      			(yyval.dim)=(yyvsp[(3) - (4)].dim);
   			}
		;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 230 "test.y"
    {printf("Conditional statement successfully complied.\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 243 "test.y"
    {
    		casedefault = 0;
    		casevar = (yyvsp[(2) - (5)].ch);
           
		;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 253 "test.y"
    {
             printf("switch VAL:   %d\n", casevar);
             printf("case VAL:   %d\n", (yyvsp[(2) - (7)].dim));
    		if((yyvsp[(2) - (7)].dim) == casevar)
    			{
        			printf("\nExecuted case %d\n",(yyvsp[(2) - (7)].dim));
        			casedefault = 0;
   			 }
		;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 264 "test.y"
    {
  		  if(casedefault == 1)
   			 {
    			   casedefault = 1;
     			   printf("\nDefault Block executed\n");
    		 }
		;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 278 "test.y"
    {
 		    int i;
			for(i= (yyvsp[(5) - (17)].dim) ; i<= (yyvsp[(9) - (17)].dim) ; i+=(yyvsp[(13) - (17)].dim))
			{
				printf("expr in for loop increasing %d\n",i);
			} printf("\n");	 			    
		;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 286 "test.y"
    {
 		    int i;
			for(i= (yyvsp[(5) - (17)].dim) ; i >= (yyvsp[(9) - (17)].dim) ; i-=(yyvsp[(13) - (17)].dim))
			{
				printf("expr in for loop increasing %d\n",i);
			} printf("\n");	 			    
		;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 294 "test.y"
    {
        int a = store[getval((yyvsp[(3) - (13)].ch))], inc = (yyvsp[(11) - (13)].dim);
        while((a+=inc)< (yyvsp[(5) - (13)].dim))
			{
                store[getval((yyvsp[(3) - (13)].ch))]=a;
				printf("While loop is executing value of variable %s : %d\n", (yyvsp[(3) - (13)].ch), a);
			}
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 303 "test.y"
    {
        int a = store[getval((yyvsp[(3) - (13)].ch))], inc = (yyvsp[(11) - (13)].dim);
        while((a-=inc)> (yyvsp[(5) - (13)].dim))
			{
                store[getval((yyvsp[(3) - (13)].ch))]=a;
				printf("While loop is executing value of variable %s : %d\n", (yyvsp[(3) - (13)].ch), a);
			}
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 316 "test.y"
    {
                                          if((yyvsp[(3) - (7)].dim)) { (yyval.dim) = (yyvsp[(6) - (7)].dim); }
						      else   { (yyval.dim) = 0; }
                                        ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 320 "test.y"
    {
							if((yyvsp[(3) - (11)].dim)) { (yyval.dim) =(yyvsp[(6) - (11)].dim);}	
							else   { (yyval.dim) =(yyvsp[(10) - (11)].dim);}
						;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 324 "test.y"
    {
							if((yyvsp[(3) - (18)].dim)){ (yyval.dim) = (yyvsp[(6) - (18)].dim);}
                                          else if((yyvsp[(10) - (18)].dim)) {(yyval.dim) = (yyvsp[(13) - (18)].dim);}
                                          else {(yyval.dim) = (yyvsp[(17) - (18)].dim);}
                                           ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 332 "test.y"
    {
			if(isdeclared((yyvsp[(1) - (1)].ch))==0)
			{
				printf("Can't print, Value is not declared.\n");
			}
			else 
			{
				printf("\nValue of the variable %s:  %d\t",(yyvsp[(1) - (1)].ch), store[getval((yyvsp[(1) - (1)].ch))]);
			}
 		   
     ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 343 "test.y"
    { 
            printf("\nPrinting the string %s",(yyvsp[(1) - (1)].ch));
      ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 349 "test.y"
    { (yyval.dim) = (yyvsp[(1) - (1)].dim);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 351 "test.y"
    {
  		  if( isdeclared((yyvsp[(1) - (1)].ch)) == 0)
   			 {
    			    (yyval.dim)=0;
     			   printf("\nNot declaredd!\n");
   			 }
    		else
       			 (yyval.dim)= store[getval((yyvsp[(1) - (1)].ch))];
		;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 361 "test.y"
    {
  			(yyval.dim) = (yyvsp[(1) - (3)].dim) + (yyvsp[(3) - (3)].dim); 
		;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 365 "test.y"
    {
  			(yyval.dim) = (yyvsp[(1) - (3)].dim) - (yyvsp[(3) - (3)].dim); 
		;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 370 "test.y"
    {
 			   (yyval.dim) = (yyvsp[(1) - (3)].dim) * (yyvsp[(3) - (3)].dim);
 			   
		;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 375 "test.y"
    { 	if((yyvsp[(3) - (3)].dim))
 			   {
  			      (yyval.dim) = (yyvsp[(1) - (3)].dim) / (yyvsp[(3) - (3)].dim);
  			  }
   			 else
    			{
      				 (yyval.dim) = 0;
       				 printf("\nDivision by zero\t");
    			}
		;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 387 "test.y"
    { 	(yyval.dim)=pow((yyvsp[(1) - (3)].dim),(yyvsp[(3) - (3)].dim)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 389 "test.y"
    {	 (yyval.dim)= (yyvsp[(1) - (3)].dim)% (yyvsp[(3) - (3)].dim); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 391 "test.y"
    { (yyval.dim) = (yyvsp[(2) - (3)].dim) ;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 394 "test.y"
    { (yyval.dim) = ((yyvsp[(1) - (3)].dim) == (yyvsp[(3) - (3)].dim)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 397 "test.y"
    { (yyval.dim) = (yyvsp[(1) - (3)].dim) < (yyvsp[(3) - (3)].dim); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 400 "test.y"
    { (yyval.dim) = (yyvsp[(1) - (3)].dim) > (yyvsp[(3) - (3)].dim); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 403 "test.y"
    { (yyval.dim) = (yyvsp[(1) - (3)].dim) <= (yyvsp[(3) - (3)].dim); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 406 "test.y"
    { (yyval.dim) = (yyvsp[(1) - (3)].dim) >= (yyvsp[(3) - (3)].dim); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 407 "test.y"
    {printf("Value of Sin(%d) is %lf\n",(yyvsp[(3) - (4)].dim),sin((yyvsp[(3) - (4)].dim)*3.1416/180)); (yyval.dim)=sin((yyvsp[(3) - (4)].dim)*3.1416/180);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 409 "test.y"
    {printf("Value of Cos(%d) is %lf\n",(yyvsp[(3) - (4)].dim),cos((yyvsp[(3) - (4)].dim)*3.1416/180)); (yyval.dim)=cos((yyvsp[(3) - (4)].dim)*3.1416/180);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 411 "test.y"
    {printf("Value of Tan(%d) is %lf\n",(yyvsp[(3) - (4)].dim),tan((yyvsp[(3) - (4)].dim)*3.1416/180)); (yyval.dim)=tan((yyvsp[(3) - (4)].dim)*3.1416/180);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 413 "test.y"
    {printf("Value of Log10(%d) is %lf\n",(yyvsp[(3) - (4)].dim),(log((yyvsp[(3) - (4)].dim)*1.0)/log(10.0))); (yyval.dim)=(log((yyvsp[(3) - (4)].dim)*1.0)/log(10.0));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 415 "test.y"
    {printf("Value of ln(%d) is %lf\n",(yyvsp[(3) - (4)].dim),(log((yyvsp[(3) - (4)].dim)))); (yyval.dim)=(log((yyvsp[(3) - (4)].dim)));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 417 "test.y"
    {if((yyvsp[(3) - (4)].dim)%2==0) printf("value provided for OddEven function is %d which is even\n",(yyvsp[(3) - (4)].dim));else printf("value provided for OddEven function is %d which is odd\n",(yyvsp[(3) - (4)].dim));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 419 "test.y"
    {int ans = 1; for(int i=1; i<=(yyvsp[(3) - (4)].dim); i++){ans*=i;}printf("Factorial of %d is %d\n",(yyvsp[(3) - (4)].dim),ans);;}
    break;



/* Line 1455 of yacc.c  */
#line 2128 "test.tab.c"
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
#line 423 "test.y"


int yyerror(char *s)
{
    printf( "%s\n %d", s, yylineno);
}



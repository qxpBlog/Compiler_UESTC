
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 12 "threeaddress.y"

     int		token;
	int		int_value;
	float     float_value;
	char*	id_name;
	past		pAst;



/* Line 1676 of yacc.c  */
#line 100 "threeaddress.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



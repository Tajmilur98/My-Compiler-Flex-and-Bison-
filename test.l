%{
#include "test.tab.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int varindex(char *var);
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
yylineno=1;
%}


/*Definitions*/

ID [a-zA-Z][a-zA-Z0-9]*[_]?[a-zA-Z0-9]*
DIGIT [0-9]
single_line_comment [/][/].*
multi_line_comment [/][*](.*|\n)*[*][/]
 


%%

"headerfile" {return INCLUDE;}
"mycode's_IO.h" {return HFSTD;}
"mycode's_String.h" {return HFSTR;}
"mycode's_Math.h" {return HFMATH;}
"mycode's_Lib.h" {return HFLIB;}


"int"         { return INT; }
"flt"         { return FLOAT; }
"crt"		  { return CHAR; }
"String_of_mycode"  { return STRING;}
"nothing_to_ret" {return VOID;}



"Function_of_mycode" {return UDFUNC;}


"begin_with"     {return MAIN;}
"show"       {return PRINT;}
"scan"       {return SCAN;}
"close_with"   {return RETURN;}
"@"          {return AT;}

"type_int"    {return FSINT;}
"type_crt"    {return FSCRT;}
"type_flt"    {return FSFLT;}
"type_srt"    {return FSSRT;}



[[]          {return '[';}
[]]          {return ']';}        
[{]          {return '{';}        
[}]          {return '}';}       
[(]          {return '(';}        
[)]          {return ')';}    
","          {return ',';}    
"#"          {return EOI;}  
[\n]         {yylineno++;}      


"<-"         { return ASSIGN; }
"+"          { return '+'; }
"-"          { return '-'; }
"*"          { return '*'; }
"/"          { return '/'; }
"^"          { return '^'; }
"%"          { return '%'; }


"="          { return EQ; }
"<"          { return LT; }
">"          { return GT; }
"<="         { return LTE; }
">="         { return GTE; }
"!="         { return NE; }

"++"         { return ADD1; }
"--"         { return SUB1; }   
"IncBy"      { return INCBY; }
"DecBy"      { return DECBY; }


"if"    	  { return IF; }
"else"    	  { return ELSE;}
"elif"        { return ELIF;}

"button_of_mycode"      { return SWITCH; }
"key_of_mycode"         { return CASE; }
"short_ckt"     { return DEFAULT; }
"cut_it"        { return BREAK;}
":"               { return COLON;}


"simple_iteration"  { return FOR; }
"as_long_as"       { return WHILE; }


"sin_of_mycode"        {return SIN;}
"cos_of_mycode"        {return COS;}
"tan_of_mycode"        {return TAN;}
"log_of_10"         {return LOG10;}
"log_of_e"          {return LOGE;}
"OddEven"           {return ODDEVEN;} 	      
"fact"              {return FACT;} 	


{single_line_comment} {return SLCOM;}
{multi_line_comment}  {return MLCOM;}
[ \t]*  	;

\"(\\.|[^"\\])*\" {yylval.ch = strdup(yytext);return STR;}

[+-]?[0-9]*[.][0-9]+([eE][+-]?[0-9]+)? {yylval.floating = atof(yytext); return DOUBLE;}

"-"?{DIGIT}+ {
	yylval.dim=atoi(yytext);
	return NUMBER;
	}

{ID} {
		yylval.ch = strdup(yytext);
 		return VARIABLE;
 	 }


%%

int yywrap() {
    return 1;
}

int main()
{
	yyin  = freopen("input.txt","r",stdin);
	yyout = freopen("output.txt","w",stdout);
	yyparse();
	
    return 0;
}
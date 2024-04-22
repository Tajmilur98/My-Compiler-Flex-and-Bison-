%{
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

    


%}

%union
{
    char *ch;
    char c;
    int dim;
    int me;
    double floating;
}
%error-verbose
%token <dim>  NUMBER
%token <ch>  VARIABLE
%token <ch>  STR
%type  <dim>  expr
%type  <dim>  stmt
%type  <dim>  loops
%type  <dim>  pcontent
%type  <dim>  condstmt
%type  <dim>  lines
%type  <dim>  declare
%type  <dim>  casecode
%type  <dim>  switch_case



%token INCLUDE HFSTD HFSTR HFMATH HFLIB INT FLOAT CHAR STRING VOID UDFUNC COLON MAIN PRINT SCAN RETURN AT FSINT FSCRT FSFLT FSSRT ASSIGN EOI ADD1 SUB1 INCBY DECBY SWITCH DEFAULT CASE BREAK FOR WHILE SIN COS TAN LOG10 LOGE ODDEVEN FACT SLCOM MLCOM DOUBLE IF ELIF

%nonassoc IFX
%nonassoc ELSE 
%left LT GT EQ  LTE GTE NE
%left '+' '-'
%left '*' '/' '%'
%right  '^'

%%

/*start*/
program:
        include before start    {printf("program compiled successfully.\n");}
      |
   	;

include: include INCLUDE LT hf GT     {printf("header files included.\n");}
         | INCLUDE LT hf GT
         ;
hf: HFSTD | HFSTR | HFMATH | HFLIB 
   ;
/* header include ended*/

before: declare 
        |func
        |
        ;
func: UDFUNC type VARIABLE '(' parameters ')' '{' lines '}'
	{
		printf("FUNC Declared!\n\n");		
	}
	;

parameters	:
	parameters ',' VARIABLE
		{
   		 if(func_here($3)==1)
      			  printf("\nparameters already exists!");
   		 else
    			    assign_func($3);
                     assign($3);

		}

	| VARIABLE
		{
		   if(func_here($1)==1)
      			 printf("\nparameters already exists!");
   		 else
      				  assign_func($1);
                       assign($1);
		}
	;




/* Main function stared here */
start:
      type MAIN '(' ')' '{' lines '}' {printf("main function compiled successfully.\n");}
      |
	;

type: INT | FLOAT | VOID | CHAR | STRING 
	;

lines: 
      declare lines | stmt lines 
      | {$$=1;}
	;

//declaration
declare:
	type id EOI      	{ printf("\nValid declaration!\n"); } 
	;

id	:
	id ',' VARIABLE
		{
   		 if(isdeclared($3)==1)
      			  printf("\nDouble Declaration!");
   		 else
    			    assign($3);
		}

	| VARIABLE
		{
		   if(isdeclared($1)==1)
      			  printf("\nDouble Declaration! \n");
   		 else
      				  assign($1);
		}
	;
//declaration ended

stmt: 
      PRINT '(' pcontent ')' EOI {printf("Print successful.\n");}
      |
      SCAN '(' VARIABLE ')' EOI {
      if(isdeclared($3)==1)
            {
			printf("Scan is successful.\n");
		}
      }
      | VARIABLE ASSIGN expr EOI
		{
 		    if(setval($1,$3)==0)
  		 	{
  		    	$$=0;
				printf("\nNot declared\n");
   			}
    		else
    		{
                store[getval($1)]= $3;
      			$$=$3;
   			}
		}
      |condstmt {printf("Conditional statement successfully complied.\n");}

      |loops

      |switch_case

      | stmt  RETURN NUMBER EOI 
      ;


//switch case
switch_case: 
        SWITCH  VARIABLE  '{' casecode '}'
		{
    		casedefault = 0;
    		casevar = $2;
           
		}
	;

casecode:

	 CASE expr COLON stmt BREAK EOI casecode
		{
             printf("switch VAL:   %d\n", casevar);
             printf("case VAL:   %d\n", $2);
    		if($2 == casevar)
    			{
        			printf("\nExecuted case %d\n",$2);
        			casedefault = 0;
   			 }
		}

	| DEFAULT COLON  stmt
		{
  		  if(casedefault == 1)
   			 {
    			   casedefault = 1;
     			   printf("\nDefault Block executed\n");
    		 }
		}
	;


//loops

loops:
    FOR '(' VARIABLE ASSIGN NUMBER EOI VARIABLE LTE NUMBER EOI VARIABLE INCBY NUMBER')' '{' stmt '}'
		{
 		    int i;
			for(i= $5 ; i<= $9 ; i+=$13)
			{
				printf("expr in for loop increasing %d\n",i);
			} printf("\n");	 			    
		}
    |FOR '(' VARIABLE ASSIGN NUMBER EOI VARIABLE GTE NUMBER EOI VARIABLE DECBY NUMBER')' '{' stmt '}'
		{
 		    int i;
			for(i= $5 ; i >= $9 ; i-=$13)
			{
				printf("expr in for loop increasing %d\n",i);
			} printf("\n");	 			    
		}
    |WHILE '('VARIABLE LTE NUMBER ')' '{' stmt VARIABLE INCBY NUMBER EOI'}'
    {
        int a = store[getval($3)], inc = $11;
        while((a+=inc)< $5)
			{
                store[getval($3)]=a;
				printf("While loop is executing value of variable %s : %d\n", $3, a);
			}
    }
    |WHILE '('VARIABLE GTE NUMBER ')' '{' stmt VARIABLE DECBY NUMBER EOI'}'
    {
        int a = store[getval($3)], inc = $11;
        while((a-=inc)> $5)
			{
                store[getval($3)]=a;
				printf("While loop is executing value of variable %s : %d\n", $3, a);
			}
    }
	;	


//conditioanls
condstmt:
      IF '(' expr ')' '{'lines'}' %prec IFX {
                                          if($3) { $$ = $6; }
						      else   { $$ = 0; }
                                        }
      |IF '(' expr ')' '{'lines'}' ELSE '{'lines'}' %prec IFX {
							if($3) { $$ =$6;}	
							else   { $$ =$10;}
						}
	 |IF '(' expr ')' '{'lines'}' ELIF '(' expr ')' '{'lines'}' ELSE '{'lines'}' %prec IFX {
							if($3){ $$ = $6;}
                                          else if($10) {$$ = $13;}
                                          else {$$ = $17;}
                                           }
      ;

pcontent:
      VARIABLE {
			if(isdeclared($1)==0)
			{
				printf("Can't print, Value is not declared.\n");
			}
			else 
			{
				printf("\nValue of the variable %s:  %d\t",$1, store[getval($1)]);
			}
 		   
     }
      | STR { 
            printf("\nPrinting the string %s",$1);
      }
      ;

expr:
      NUMBER  { $$ = $1;}
      | VARIABLE
		{
  		  if( isdeclared($1) == 0)
   			 {
    			    $$=0;
     			   printf("\nNot declaredd!\n");
   			 }
    		else
       			 $$= store[getval($1)];
		}
        | expr '+' expr	 	  
		{
  			$$ = $1 + $3; 
		}
	| expr '-' expr	 	  
		{
  			$$ = $1 - $3; 
		}

	| expr '*' expr
		{
 			   $$ = $1 * $3;
 			   
		}
      | expr '/' expr	 	  
		{ 	if($3)
 			   {
  			      $$ = $1 / $3;
  			  }
   			 else
    			{
      				 $$ = 0;
       				 printf("\nDivision by zero\t");
    			}
		}
      
	| expr '^' expr 		
		{ 	$$=pow($1,$3); }
      | expr '%' expr 		
		{	 $$= $1% $3; }
      | '(' expr ')'		  
    		 { $$ = $2 ;}
    
    | expr EQ expr	
		{ $$ = ($1 == $3); }

      | expr LT expr	
		{ $$ = $1 < $3; }

	| expr GT expr	
		{ $$ = $1 > $3; }

	| expr LTE expr  
		{ $$ = $1 <= $3; }

	| expr GTE expr   
 		 { $$ = $1 >= $3; }
      | SIN '('expr ')'			      {printf("Value of Sin(%d) is %lf\n",$3,sin($3*3.1416/180)); $$=sin($3*3.1416/180);}

      | COS '('expr ')' 			{printf("Value of Cos(%d) is %lf\n",$3,cos($3*3.1416/180)); $$=cos($3*3.1416/180);}

      | TAN '('expr ')' 			{printf("Value of Tan(%d) is %lf\n",$3,tan($3*3.1416/180)); $$=tan($3*3.1416/180);}

      | LOG10 '('expr ')' 			{printf("Value of Log10(%d) is %lf\n",$3,(log($3*1.0)/log(10.0))); $$=(log($3*1.0)/log(10.0));}

	| LOGE '('expr ')' 			{printf("Value of ln(%d) is %lf\n",$3,(log($3))); $$=(log($3));}

	|ODDEVEN '('expr ')'         {if($3%2==0) printf("value provided for OddEven function is %d which is even\n",$3);else printf("value provided for OddEven function is %d which is odd\n",$3);}

	|FACT '('expr ')'           {int ans = 1; for(int i=1; i<=$3; i++){ans*=i;}printf("Factorial of %d is %d\n",$3,ans);}
      ;


%%

int yyerror(char *s)
{
    printf( "%s\n %d", s, yylineno);
}


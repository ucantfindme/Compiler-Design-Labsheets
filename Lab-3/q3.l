%option noyywrap 
%{ 
    #include<stdio.h> 
%}
%%
"<"[^>]*> {printf("%s",yytext);}
\n {printf("\n");}
.     ;
%% 
int main() { 
    FILE * f; 
    f=fopen("inp1.html","r"); 
    yyin=f; 
    yylex();
    return 0; 
}
%option noyywrap 
%{ 
    #include <stdio.h> 
    #include <string.h>
    int letters=0;
    int words=0;
    int digits=0;
    int symbols=0;
%}
%%
[0-9] {digits++;}
[a-zA-Z] {letters++;}
([ ])+ {words++;}
\n {words++;}
. {symbols++;}
%% 
int main() { 
    FILE * f; 
    f=fopen("inp.txt","r"); 
    yyin=f; 
    yylex(); 
    printf("Number of Letters: %d\n",letters);
    printf("Number of Words: %d\n",words);
    printf("Number of Digits: %d\n",digits);
    printf("Number of Symbols: %d\n",symbols);
    return 0; 
}
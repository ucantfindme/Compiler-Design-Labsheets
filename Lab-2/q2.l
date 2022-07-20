%option noyywrap
%{
    #include <stdlib.h>
    #include <stdio.h>
%}
number [0-9]+
op [+|-|*|%|=]
keyword If|While|Else|For|Return|Then|Int|Float|Switch|Case|Break|Continue
id [a-z][a-z A-Z 0-9]*
symbol [!|@|#|$|%|^|&]
semi [;]
%%
{number} {printf(" <number> ");}
{op} {printf(" <operator> ");}
{id} {printf(" <identifier> ");}
{symbol} {printf(" <symbol> ");} 
{semi} {printf(" <semicolon> ");}
{keyword} {printf(" <keyword> ");}
%%
int main(){
    yylex();
    return 0;
}
%option noyywrap 
%{ 
    #include <stdlib.h> 
    #include <stdio.h> 
%} 
number [0-9]+ 
for for
while while
int int
include #include<[a-z . A-Z]+>
identifier [a-z]([a-z]|[0-9])* 
string ["](.)+["]
le (\<=)
eq [=]
semi [;]
lb [(]
rb [)]
inc (\+\+)
lp [{]
rp [}]
mul [*]
comma [,]
%% 
{for} {printf("<FOR>");}
{while} {printf("<WHILE>");}
{int} {printf("<int>");}
{number} {printf("<NUM,%s>",yytext);} 
{include} {printf("<INCLUDE,%s>",yytext);} 
{identifier} {printf("<ID,%s>",yytext);} 
{string} {printf("<STRING>");}
{eq} {printf("<ASSIGN>");}
{semi} {printf("<SEMI>");}
{lb} {printf("<LBRACKET>");}
{rb} {printf("<RBRACKET>");}
{le} {printf("<LE>");}
{inc} {printf("<INC>");}
{lp} {printf("<LPAREN>");}
{rp} {printf("<RPAREN>");}
{mul} {printf("<MULT>");}
{comma} {printf("<COMMA>");}
%% 
int main() { 
    FILE * f; 
    f=fopen("inp.txt","r"); 
    yyin=f; 
    yylex(); 
    return 1; 
}
%{
#include <string>    
%}

DIGITO [0-9]
LETRA [A-Za-z_]
DECIMAL [0-9]*\.[0-9]+|[0-9]+\.[0-9]* 

NUM {DIGITO}+
ID {LETRA}({LETRA}|{NUM})*
FLUTUANTE {DECIMAL}
BOOLEANO (true)|(false)
CARACTER('{ID}')
RELACIONAL (==)|(!=)|(<=)|(>=)|>|<
%%

"int"   {yylval.tipo = "int"; return TK_TIPO;}
"float" {yylval.tipo = "float";return TK_TIPO;}
"char"    {yylval.tipo = "char";return TK_TIPO;}
"bool"  {yylval.tipo = "bool";return TK_TIPO;}


"main" {return TK_MAIN;}

[(){}[\];,=*/]    { return *yytext; }
[\*/+-]        { return *yytext; }

{RELACIONAL} {yylval.traducao = yytext;return TK_RELACIONAL;}  
[&|!]		{yylval.traducao = yytext;return TK_LOGICO;} 

{NUM} {yylval.valor = yytext;        yylval.tipo = "int"; return TK_TERMINAL;}
{FLUTUANTE} {yylval.valor = yytext; yylval.tipo = "float"; return TK_TERMINAL;}
{BOOLEANO} {yylval.valor = yytext;  yylval.tipo = "bool";return TK_TERMINAL;}
{CARACTER} {yylval.valor = yytext;  yylval.tipo = "char";return TK_TERMINAL;}
{ID} {yylval.label = yytext; return TK_ID;}

%%

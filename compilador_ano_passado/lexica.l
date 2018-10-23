%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM (-)?{DIGITO}+
REAL (-)?{NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*
STRING	\"[^\"]*\"

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"var"		{return TK_TIPO_VAR;}

"int"		{return TK_TIPO_INT;}

"float"		{return TK_TIPO_FLOAT;}

"char"		{return TK_TIPO_CHAR;}

"bool"		{return TK_TIPO_BOOL;}

"string"	{return TK_TIPO_STRING;}

"void"	{return TK_TIPO_VOID;}

"global"	{return TK_GLOBAL;}

[(){}[\];,]	{ return *yytext; }

[+\-*/=]		{ return *yytext; }

">"         { return *yytext;}

"<"         { return *yytext;}

">="        { return TK_GTE;}

"<="        { return TK_LTE; }

"=="        { return TK_EQUAL;  }

"!="        { return TK_NEQUAL;  }

"and"       { return TK_AND;  }

"or"        { return TK_OR;  }

"not"       { return TK_NOT; }

"if"		{ return TK_IF; }

"else"		{ return TK_ELSE; }

"do" 		{ return TK_DO; }

"while" 	{ return TK_WHILE; }

"for" 		{ return TK_FOR; }

"break"		{ return TK_BREAK; }

"continue"	{ return TK_CONTINUE; }


"cout"		{ return TK_PRINT; }

"cin"		{ return TK_READ; }




"true"		{ yylval.label = yytext; return TK_BOOL; }

"false"		{ yylval.label = yytext; return TK_BOOL; }

{NUM}		{ yylval.label = yytext; return TK_NUM; }
{REAL}		{ yylval.label = yytext; return TK_REAL;}
{ID}		{ yylval.label = yytext; return TK_ID; }
{CHAR}	{ yylval.label = yytext; return TK_CHAR; }
{STRING}    { yylval.label = yytext; return TK_STRING; }


.			{ *yytext; }

%%

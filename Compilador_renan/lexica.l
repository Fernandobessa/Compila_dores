%{
	#include <string>
	#include <iostream>
	using namespace std;
%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
BOOL [true|false]

DELIM {ESPACO}+
NUM [-]?{DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
STRING \"([^\"\n]|\\\")*\"
ID {LETRA}({LETRA}|{NUM})*
VAR ({CHAR}|{REAL})*

%%

"\n"		{lines++;}

{DELIM} 	{}

"main"		{main_called = 1;
			return TK_MAIN;}

"begin"		{return TK_BEGIN;}

"end"		{return TK_END;}

"functions"	{
				return TK_FUNCTIONS;
			}

"procedure"		{FUN function;
					if(pilha.empty()){
 						function.next = NULL;
						pilha.push(function);
					} else{
						function.next = &pilha.top();
						pilha.push(function);
					}
				return TK_PROCEDURE;}

"function"		{FUN function;
					if(pilha.empty()){
 						function.next = NULL;
						pilha.push(function);
						first_exestack = &pilha.top();
					} else{
						function.next = &pilha.top();
						pilha.push(function);
					}
				return TK_FUNCTION;}

"int"|"float"|"char"|"bool"|"var"|"string"		{yylval.var_tipo = yytext;
												return TK_TYPES;}

"while"		{
					if(pilha.top().name != "do"){
						yylval.label = create_loop_names();
						FUN function;
						function.next = &pilha.top();
						pilha.push(function);
						return TK_WHILE;
						}
					}

"do"		{yylval.label = create_loop_names();
				FUN function;
				function.name = "do";
				function.next = &pilha.top();
				pilha.push(function);
				return TK_DO;}

"for"		{yylval.label = create_loop_names();
				FUN function;
				function.next = &pilha.top();
				pilha.push(function);
				return TK_FOR;}

"foreach"	{yylval.label = create_loop_names();
				FUN function;
				function.next = &pilha.top();
				pilha.push(function);
				return TK_FOREACH;}

"in"		{return TK_IN;}

"not"		{return TK_NOT;}

"as"		{return TK_AS;}

"until"		{yylval.label = create_loop_names();
			FUN function;
			function.next = &pilha.top();
			pilha.push(function);
			return TK_UNTIL;}

"if"		{FUN function;
				function.next = &pilha.top();
				pilha.push(function);
				return TK_IF;}

"else"		{FUN function;
					function.next = &pilha.top();
					pilha.push(function);
					return TK_ELSE;}

"elif"		{FUN function;
					function.next = &pilha.top();
					pilha.push(function);
					return TK_ELIF;}

"switch"	{yylval.label = create_switch_names();
			FUN function;
			function.name = "switch";
			function.next = &pilha.top();
			pilha.push(function);
			return TK_SWITCH;}

"case"		{return TK_CASE;}

"return"	{return TK_RETURN;}

"default"	{return TK_DEFAULT;}

"break"		{return TK_BREAK;}

"continue"	{return TK_CONTINUE;}

"readln"	{return TK_READLN;}

"writeln"		{return TK_WRITELN;}

"true"		{yylval.valor = "1";
					yylval.label = create_temp_names();
					yylval.var_tipo = "bool";
					return TK_TRUE;}

"false"		{yylval.valor = "0";
					yylval.label = create_temp_names();
					yylval.var_tipo = "bool";
					return TK_FALSE;}

"global"	{return TK_GLOBAL;}

"%"			{yylval.op = yytext;
			return TK_MOD;}

".^"		{return TK_POW;}

"!"			{return TK_FACTORIAL;}

"<"|">"|"<="|">="|"!="|"=="|"||"|"&&"	{yylval.op = yytext;
										yylval.var_tipo = "bool";
										return TK_OPL;}

[(){}[\];,:]	{ return *yytext; }

[+\-*/]		{ return *yytext; }

"++"				{yylval.op = yytext;
					return TK_ADD1;}

"--"				{yylval.op = yytext;
					return TK_SUB1;}

"+="				{yylval.op = "+";
					return TK_ADDI;}

"-="				{yylval.op = "-";
					return TK_SUBI;}

"*="				{yylval.op = "*";
					return TK_MULTI;}

"/="				{yylval.op = "/";
					return TK_DIVI;}

"%="				{yylval.op = "%";
					return TK_MODI;}
				
"<->"				{yylval.op = yytext;
					return TK_INVERT;}

{NUM}		{ yylval.valor = yytext;
				yylval.label = create_temp_names();
				yylval.var_tipo = "int";
				return TK_INT; }

{CHAR}		{yylval.valor = yytext;
					yylval.label = create_temp_names();
					yylval.var_tipo = "char";
					return TK_CHAR;}

{STRING}	{yylval.valor = yytext;
					yylval.label = create_temp_names();
					yylval.var_tipo = "string";
					return TK_STRING;}

{REAL}		{yylval.valor = yytext;
					yylval.label = create_temp_names();
					yylval.var_tipo = "float";
					return TK_FLOAT;}

{VAR}		{yylval.valor = yytext;
				yylval.label = yytext;
				yylval.var_tipo = "?";
				return TK_VAR;}

{ID}		{yylval.nome = yytext;
				return TK_ID; }


"(int)"|"(float)"|"(char)"	{yylval.cast = yytext;
														yylval.label = create_temp_names();
														return TK_CAST;}

.			{ *yytext; }

%%

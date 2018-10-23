%{
#include <iostream>
#include <string>
#include <sstream>
#include "variaveis.h"
#include "loop.h"

#define YYSTYPE atributos

using namespace std;


struct atributos
{
	string label;
	string traducao;
	int tipo;

	int tamanho;
};

struct Funcoes
{
	string name;
	string new_name;

	string tipo;

	int qtd_params;

};

vector<Funcoes> funcoes_lista;

// Funcoes *funcoes_lista;

// Variaveis Planistas
string error_msg = "Wubba Lubba Dub Dub";

// roubando pra fazer else if, gambiarra demais
string else_if_string = "";

// roubando para fazer declaracao de funcao gambiarra demais
string funcao_declaracoes = "";

maps* tack = criarMaps();
varsDeclaradas varsDec;

Loop_stack* loop_tack = criarLoopStack();


// Functions
int yylex(void);
void yyerror(string);
string exibirVarsDeclaradas();
variavel criadorDeVariavel(string, string, string, int);
void deletadorDeVariavel(string);
string geradoraDeNomeDeVariaveis();
int getTipoToken(string);
string getTipoString(int);
atributos tratadoraLogic(int, string, int, string, string);
atributos tratarArithComCast(int, string, int, string, string);
atributos concatenarStrings(atributos, atributos);
int tipoResult(int, int);
atributos tratadoraArith(atributos, atributos, string);
variavel getVarPorNome(string);
string geradorTextGoto(int);


const vector<string> explode(const string& s, const char& c);
%}

%token TK_NUM TK_REAL TK_CHAR TK_BOOL TK_STRING
%token TK_MAIN TK_ID TK_TIPO_VAR TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_TIPO_STRING TK_TIPO_VOID
%token TK_EQUAL TK_GTE TK_LTE TK_NEQUAL
%token TK_AND TK_OR TK_NOT
%token TK_IF TK_ELSE
%token TK_DO TK_WHILE TK_FOR TK_BREAK TK_CONTINUE
%token TK_PRINT TK_READ
%token TK_FIM TK_ERROR
%token TK_MM TK_PP
%token TK_GLOBAL


// ordem das operacoes?! bottom -> up	
%start S
%left '+' '-'
%left '*' '/'
%right '='

%%

S 			: DECLARATION_GLOBAL FUNCAO_DECLARADA TK_TIPO_INT TK_MAIN '(' ')' BLOCO 
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\n" << exibirVarsDeclaradas() << "\n" << funcao_declaracoes << "\n" << "\nint main(void)\n{\n" << else_if_string << $7.traducao << "\n\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: PUSH_SCOPE '{' COMANDOS '}' POP_SCOPE
			{
				$$.traducao = $3.traducao;
				$$.tamanho = $3.tamanho;

				cout << "taamnaho aqui 33" << endl;
				cout << $$.tamanho << endl;
			}
			;

PUSH_SCOPE: {
				Var_table escopo;
				pushEsc(tack,escopo);
				
				$$.traducao = "";
				$$.label = "";
			}
			;
POP_SCOPE:	{
				popEsc(tack);
				
				$$.traducao = "";
				$$.label = "";
			}
			;

COMANDOS	: COMANDO COMANDOS
			{

				cout << "taamnaho aqui 22" << endl;
				cout << $$.tamanho << endl;

				$$.traducao = $1.traducao + $2.traducao;

				$$.tamanho = $1.tamanho;




			}
			| // vazio
			{
				$$.traducao = "";
			}
			;

COMANDO 	: TK_IF '(' E ')' BLOCO
			{

				int tipo_atual = tipoResult($3.tipo, $3.tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), $3.tamanho);
				string gotoText = geradorTextGoto(TK_IF); //$1.tipo

				string line = $3.traducao; 
				line += "\t" +nome+ " = !" +$3.label+ ";\n";

				$$.traducao = line + "\tif(" +nome+ ") goto " +gotoText+ ";\n";
				$$.traducao += $5.traducao+ "\n";
				$$.traducao += "\t" +gotoText+ ":\n";

			} 
			| TK_IF '(' E ')' BLOCO ELSE
			{
				int tipo_atual = tipoResult($3.tipo, $3.tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), $3.tamanho);
				string gotoText_ir_para_else = geradorTextGoto(TK_IF); //$1.tipo

				string line = $3.traducao;
				line += "\t" +nome+ " = !" +$3.label+ ";\n";


				// $$.traducao = line + "\tif(" +$3.label+ "){\n" +$5.traducao+ "\t}\n";
				// $$.traducao += $6.traducao;

				$$.traducao = line + "\tif(" +nome+ ") goto " +gotoText_ir_para_else+ ";\n";
				$$.traducao += $5.traducao+ "\n";
				$$.traducao += "\tgoto " +$6.label+ ";\n";
				$$.traducao += "\t" +gotoText_ir_para_else+ ":\n";
				$$.traducao += $6.traducao;


				

			}
			| PUSH_LOOP LOOP POP_LOOP
			{
				$$.traducao = $2.traducao;
			}
			| DECLARATION ';'
			{
				$$ = $1;

				// cout << "AQUIII ________ \n" << "Label: " << $1.label << "\nTrad: " << $1.traducao << "\n ACABOUU ---" <<endl; 
			}
			| ATRIB ';'
			{
				$$ = $1;
			}
			| PRINT ';'
			{
				$$ = $1;

			}
			| READ ';'
			{
				$$ = $1;

			}
			| TK_BREAK ';'
			{
				if(loop_tack->loops.empty()){
			 		cout << "erro compilação. break deve estar em um loop ";
			 		exit(0);
			 	}else{
			 		Loop loopAtual = getLoop(loop_tack);
			 		$$.traducao = "\tgoto " + loopAtual.fimL + ";\n";
			 	}
			}
			| TK_CONTINUE ';'
			{
				if(loop_tack->loops.empty()){
			 		cout << "erro compilação. continue deve estar em um loop ";
			 		exit(0);
			 	}else{
			 		Loop loopAtual = getLoop(loop_tack);
			 		$$.traducao = "\tgoto " + loopAtual.contL + ";\n";
			 	}

			}
			| OPERADOR_UNARIO ';'
			{
				$$ = $1;
			}

			| GLOBAL ';'
			{
				$$ = $1;
			}

			| FUNCAO_CHAMADA ';'
			{
				$$ = $1;
			}

			// | E ';'
			;

OPERADOR_UNARIO:TK_ID TK_PP 
			{
				
				variavel v = getVarPorNome($1.label);
				if(v.tipo != getTipoString(TK_TIPO_INT)){
					cout << "operador ++ não é permitido para o tipo " << v.tipo << endl;
					exit(0);
				}
				
				string nome = geradoraDeNomeDeVariaveis();
				variavel var = criadorDeVariavel(nome, nome, v.tipo, 0);
				
				string linha = "\t" + nome + " =  1;\n";
				string linha2 = "\t" + var.temp_name + " = "+ nome +" + " + v.temp_name + ";\n";
				
				$$.traducao = linha + linha2;


			}
			| TK_PP TK_ID 
			{
				variavel v = getVarPorNome($1.label);
				if(v.tipo != getTipoString(TK_TIPO_INT)){
					cout << "operador ++ não é permitido para o tipo " << v.tipo << endl;
					exit(0);
				}
				
				addVarEsc(tack, v);
				varsDec.push_back(v);
				
				string linha2 = "\t" + v.temp_name + " = " + v.temp_name + " + "+ "1" + ";\n";
				
				$$.traducao = linha2;
			}
			| TK_ID TK_MM
			{
				
				variavel v = getVarPorNome($1.label);
				if(v.tipo != getTipoString(TK_TIPO_INT)){
					cout << "operador -- não é permitido para o tipo " << v.tipo << endl;
					exit(0);
				}
				
				string nome = geradoraDeNomeDeVariaveis();
				variavel var = criadorDeVariavel(nome, nome, v.tipo, 0);
				
				string linha = "\t" + nome + " =  1;\n";
				string linha2 = "\t" + var.temp_name + " = " + v.temp_name + " - " + nome + ";\n";
				
				$$.traducao = linha + linha2;


			}
			| TK_MM TK_ID
			{
				
				variavel v = getVarPorNome($1.label);
				if(v.tipo != getTipoString(TK_TIPO_INT)){
					cout << "operador -- não é permitido para o tipo " << v.tipo << endl;
					exit(0);
				}
				
				addVarEsc(tack, v);
				varsDec.push_back(v);

				
				//string linha = "\t" + nome + " =  1;\n";
				string linha2 = "\t" + v.temp_name + " = " + v.temp_name + " - " + "1" + ";\n";
				
				$$.traducao = linha2;
			}
			;
GLOBAL: 	TK_GLOBAL TIPO TK_ID 
			{
			

				//nao existe no escopo global
				if ( tack->variaveis_map[0][$3.label].var_name == ""  ){
					
					string nome = geradoraDeNomeDeVariaveis();

					variavel v;
					if (getTipoString($2.tipo) == "string")
					{
						// criando sting com tamanho predeterminado, deve melhorar [to-do]
						v = criarVar(nome, nome, getTipoString($2.tipo), 10);
						
					}else{
						v = criarVar(nome, nome, getTipoString($2.tipo), 0);
					}

					addVarEscGlobal(tack, v);
					varsDec.push_back(v);

				}else{
					cout << "Variavel " << $3.label << " ja foi declarada no escopo global" <<endl;
					exit(0);
				}
	
			}
			|
			TK_GLOBAL TIPO TK_ID '=' E
			{
			
				//nao existe no escopo global
				if ( tack->variaveis_map[0][$3.label].var_name == ""  ){

					string nome = geradoraDeNomeDeVariaveis();

					variavel v;
					if (getTipoString($2.tipo) == "string")
					{
						// criando sting com tamanho predeterminado, deve melhorar [to-do]
						v = criarVar(nome, nome, getTipoString($2.tipo), 10);
						
					}else{
						v = criarVar(nome, nome, getTipoString($2.tipo), 0);
					}

					addVarEscGlobal(tack, v);
					varsDec.push_back(v);
					
					// Cast na atribuição
					if( v.tipo != getTipoString($5.tipo) ) {
						string store = geradoraDeNomeDeVariaveis();
						string linha =  store + " = (" +v.tipo+") " + $5.label + ";\n";
						string linha2 = "\t"  + nome + " = " + store + ";\n";
						
						$$.traducao = $3.traducao + $5.traducao + "\t"  + linha + linha2;
	
						variavel v;
						if (getTipoString($2.tipo) == "string")
						{
							// criando sting com tamanho predeterminado, deve melhorar [to-do]
							v = criarVar(nome, nome, getTipoString($2.tipo), 10);
							
						}else{
							v = criarVar(nome, nome, getTipoString($2.tipo), 0);
						}

						addVarEscGlobal(tack, v);
						varsDec.push_back(v);
				
					}
					else
					{
						// tipo igual, inferido?

						if (getTipoString($5.tipo) == "char*"){
							$$.traducao = $3.traducao + $5.traducao + "\tstrcpy(" + nome  + ", " + $5.label +");\n";
						}
						else
							$$.traducao = $3.traducao + $5.traducao + "\t" + nome  + " = " + $5.label +";\n";
						
					}
				
				}	
			}
			;
FUNCAO_CHAMADA: TK_ID '(' PARAMS_FUNCAO_CHAMADA ')'
			{
				cout << "ASDSAD " << $1.label << " " << $3.tamanho << endl;

				

				for (int i = 0; i < funcoes_lista.size(); ++i)
				{
					// checar se ja existe uma funcao com mesmo nome
					if (funcoes_lista.at(i).name == $1.label && funcoes_lista.at(i).qtd_params != $3.tamanho)
					{
						cout << "Funcao com o mesmo nome mas nao com esse numero de parametros -> " << funcoes_lista.at(i).name << endl;
						exit(0);
					}
					else if (funcoes_lista.at(i).name == $1.label && funcoes_lista.at(i).qtd_params == $3.tamanho)
					{
						// string params = $3.traducao;
						// string call = "\tcall " + $1.label + ", " + to_string($3.tamanho); 


						// VOLTAR AQUI
						string var_parametros = "";
						cout << "nome das variaveis buscada " << $3.traducao << endl;
						string tradu = $3.traducao;
						vector<string> nome_vars = explode(tradu, ',');
						for (int j = 0; j < $3.tamanho; ++j)
						{

							cout << "nome da variavel buscada " << nome_vars.at(j) << endl;
							variavel var = getVarPorNome(nome_vars.at(j));

							// variavel nao existe
							if (var.var_name == "")
							{
								cout << "essa variavel nao existe " << endl;
								exit(0);
							}

							var_parametros += var.temp_name;

							if (j < $3.tamanho - 1)
							{
								var_parametros += ", ";
							}

						}


						$$.traducao = "\t" + $1.label + "(" + var_parametros + ");\n";

						cout << $$.traducao << endl;
					}

					cout << "nome da funcao: " << funcoes_lista.at(i).name << " parametros " << $3.traducao << endl;
				}	

			}
			| TK_ID '=' TK_ID '(' PARAMS_FUNCAO_CHAMADA ')'
			{
				cout << "ASDSAD " << $3.label << " " << $5.tamanho << endl;

				

				for (int i = 0; i < funcoes_lista.size(); ++i)
				{
					// checar se ja existe uma funcao com mesmo nome
					if (funcoes_lista.at(i).name == $3.label && funcoes_lista.at(i).qtd_params != $5.tamanho)
					{
						cout << "Funcao com o mesmo nome mas nao com esse numero de parametros -> " << funcoes_lista.at(i).name << endl;
						exit(0);
					}
					else if (funcoes_lista.at(i).name == $3.label && funcoes_lista.at(i).qtd_params == $5.tamanho)
					{
						// string params = $3.traducao;
						// string call = "\tcall " + $1.label + ", " + to_string($3.tamanho); 


						// VOLTAR AQUI
						string var_parametros = "";
						cout << "nome das variaveis buscada " << $5.traducao << endl;
						string tradu = $5.traducao;
						vector<string> nome_vars = explode(tradu, ',');
						for (int j = 0; j < $5.tamanho; ++j)
						{

							cout << "nome da variavel buscada " << nome_vars.at(j) << endl;
							variavel var = getVarPorNome(nome_vars.at(j));

							// variavel nao existe
							if (var.var_name == "")
							{
								cout << "essa variavel nao existe " << endl;
								exit(0);
							}

							var_parametros += var.temp_name;

							if (j < $5.tamanho - 1)
							{
								var_parametros += ", ";
							}

						}

						variavel v = getVarPorNome($1.label);

						if (v.var_name == "")
						{
							cout << "Nao existe variavel que a funcao vai ser atribuida" << endl;
							exit(0);
						}
						else if(v.tipo != funcoes_lista.at(i).tipo){
							cout << "Tipo de variavel que a funcao vai ser atribuida diferente do tipo da cuncao" << endl;
							cout << v.tipo << " " << funcoes_lista.at(i).tipo << endl;
							exit(0);
						}
						else{
							$$.traducao = "\t" + v.temp_name + " = " + $3.label + "(" + var_parametros + ");\n";

						}



						cout << $$.traducao << endl;
					}

					cout << "nome da funcao: " << funcoes_lista.at(i).name << " parametros " << $5.traducao << endl;
				}	

			}
			;

PARAMS_FUNCAO_CHAMADA: TK_ID
			{
				$$.traducao = $1.label;
				$$.tamanho = 1;
				$$.tipo = $1.tipo;

			}
			| TK_ID ',' PARAMS_FUNCAO_CHAMADA
			{
				$$.traducao = $1.label + "," + $3.traducao;
				$$.tamanho = $3.tamanho + 1;
			}
			| FUNCAO_CHAMADA
			{
				$$.traducao = $1.traducao;
			}
			;

FUNCAO_DECLARADA: TIPO TK_ID '(' PARAMS_FUNCAO ')' BLOCO
			{
				cout << "Declrando func " << $2.label << endl;

				for (int i = 0; i < funcoes_lista.size(); ++i)
				{
					// checar se ja existe uma funcoes_lista com mesmo nome
					if (funcoes_lista.at(i).name == $2.label && funcoes_lista.at(i).qtd_params == $4.tamanho)
					{
						cout << "Funcao com o mesmo nome e tamanho de parametros ja declarada -> " << funcoes_lista.at(i).name << endl;
						exit(0);
					}
				}

				Funcoes funcao = {.name = $2.label, .qtd_params = $4.tamanho, .tipo = getTipoString($1.tipo)};
				funcoes_lista.push_back(funcao);

				// funcoes_lista = (Funcoes*) malloc(sizeof(struct Funcoes));
				// funcoes_lista.at(i).name = $2.label;
				// funcoes_lista.at(i).qtd_params = $4.tamanho;

				cout << "QTD PARAMS_1 " << funcao.qtd_params << " " << endl;


				// funcoes_lista.at(i).new_name por questao de debug :)
				funcao_declaracoes += getTipoString($1.tipo) + " " + funcao.name + "(" + $4.traducao + ") {\n" + $6.traducao + "\n}";
			}
			| FUNCAO_DECLARADA TIPO TK_ID '(' PARAMS_FUNCAO ')' BLOCO
			{

				cout << "Declrando func " << $3.label << endl;

				for (int i = 0; i < funcoes_lista.size(); ++i)
				{
					// checar se ja existe uma funcoes_lista com mesmo nome
					if (funcoes_lista.at(i).name == $3.label && funcoes_lista.at(i).qtd_params == $5.tamanho)
					{
						cout << "Funcao com o mesmo nome e tamanho de parametros ja declarada -> " << funcoes_lista.at(i).name << endl;
						exit(0);
					}
				}

				Funcoes funcao = {.name = $3.label, .qtd_params = $5.tamanho, .tipo = getTipoString($1.tipo)};
				funcoes_lista.push_back(funcao);

				cout << "QTD PARAMS_2 " << funcao.qtd_params << " " << endl;

				// funcoes_lista.at(i).new_name por questao de debug :)
				funcao_declaracoes += "\n" + getTipoString($2.tipo) + " " + funcao.name + "(" + $5.traducao + ") {\n" + $7.traducao + "\n}";
				

			}
			| // vazio
			{
				$$.traducao = "";
			}
			;
PARAMS_FUNCAO: TIPO TK_ID
			{
				$$.traducao = getTipoString($1.tipo) + " " + $2.label;
				$$.tamanho = 1;
				// cout << "TAAAMNHOooooooo " << $$.tamanho << endl;


			}
			| TIPO TK_ID ',' PARAMS_FUNCAO
			{
				$$.traducao = getTipoString($1.tipo) + " " + $2.label + "," + $4.traducao;
				$$.tamanho = $4.tamanho + 1;

				// cout << "TAAAMNHO " << $$.tamanho << " " << $4.tamanho << endl;

			}

			;
ELSE 		: TK_ELSE BLOCO
			{
				string gotoText_final_if = geradorTextGoto(TK_IF); // ou $1.tipo e mudar a func

				$$.traducao += $2.traducao+ "\n";
				$$.traducao += "\t" +gotoText_final_if+ ":\n";

				$$.label = gotoText_final_if;


			}
			| TK_ELSE TK_IF '(' E ')' BLOCO
			{

				int tipo_atual = tipoResult($4.tipo, $4.tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), $4.tamanho);
				string gotoText_final_if = geradorTextGoto(TK_IF); //$1.tipo

				string line = $4.traducao; 
				line += "\t" +nome+ " = !" +$4.label+ ";\n";

				$$.traducao = line + "\tif(" +nome+ ") goto " +gotoText_final_if+ ";\n";
				$$.traducao += $6.traducao+ "\n";
				$$.traducao += "\t" +gotoText_final_if+ ":\n";


				$$.label = gotoText_final_if;


				// // string line = $4.traducao;
				// else_if_string += $4.traducao;
				// // deletadorDeVariavel($4.label);


				// $$.traducao = "\telse if(" +$4.label+ "){\n" +$6.traducao+ "\t}\n";

			} 
			| TK_ELSE TK_IF '(' E ')' BLOCO ELSE
			{
				int tipo_atual = tipoResult($4.tipo, $4.tipo);

				// IF aceita bool e int
				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT )
				{
					cout << "nao aceita esse tipo no if" << endl;
					exit(0);
				}

				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), $4.tamanho);
				string gotoText_ir_para_else = geradorTextGoto(TK_IF); //$1.tipo

				string line = $4.traducao;
				line += "\t" +nome+ " = !" +$4.label+ ";\n";

				$$.traducao = line + "\tif(" +nome+ ") goto " +gotoText_ir_para_else+ ";\n";
				$$.traducao += $6.traducao+ "\n";
				$$.traducao += "\tgoto " +$7.label+ ";\n";
				$$.traducao += "\t" +gotoText_ir_para_else+ ":\n";
				$$.traducao += $7.traducao;

				$$.label = $7.label;


				// else_if_string += $4.traducao;
				// // deletadorDeVariavel($4.label);



				// $$.traducao = "\telse if(" +$4.label+ "){\n" +$6.traducao+ "\t}\n";
				// $$.traducao += $7.traducao;
			}
			;

LOOP		: DO
			{
				$$ = $1;
			}
			| WHILE
			{
				$$ = $1;
			}
			| FOR
			{
				$$ = $1;
			}
			;
DO 			: TK_DO BLOCO TK_WHILE '(' E ')' ';'
			{
				int tipo_atual = tipoResult($5.tipo, $5.tipo);

				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT)
				{
					cout << "nao aceita esse tipo no while" << endl;
					exit(0);
				}

				else_if_string += $5.traducao;
				
				Loop loop = getLoop(loop_tack);
				
				string comecoL = loop.comecoL;
				string fimL = loop.fimL;
				string contL = loop.contL;
	
				string linha = "\tif(" + $5.label + ")";
				string showLabel = "{goto "+ comecoL;
				
				$$.traducao  = "\t" + comecoL + ":\n" + $2.traducao + "\n\t" + contL + ":\n";
				// $$.traducao += $5.traducao; 
				$$.traducao += linha + " " + showLabel + "};\n\t" + fimL + ":\n"; 
				
			}
			;
WHILE 		: TK_WHILE '(' E ')' BLOCO
			{
				int tipo_atual = tipoResult($3.tipo, $3.tipo);

				if (tipo_atual != TK_TIPO_BOOL && tipo_atual != TK_TIPO_INT)
				{
					cout << "nao aceita esse tipo no while" << endl;
					exit(0);
				}
				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), $3.tamanho);
				
				Loop loop = getLoop(loop_tack);
				
				string comecoL = loop.comecoL;
				string fimL = loop.fimL;
				string contL = loop.contL;
	
				string voltarProComecoL = "\tgoto "+ comecoL + ";\n\n";

			    $$.traducao = $3.traducao;
			    $$.traducao += "\t" + nome + " = !" + $3.label + ";\n";
			    $$.traducao += "\t" + comecoL +":"+ "\n\tif(" + nome + ") {goto " + fimL +"};";
			    $$.traducao += "\n" + $5.traducao + "\n";
			    $$.traducao += "\t" + contL + ":\n" + voltarProComecoL;
			    $$.traducao += "\t"  + fimL + ":\n\n";


			}
			;
FOR 		: TK_FOR '(' DECLARATION ';' E ';' OPERADOR_UNARIO ')' BLOCO
			{
				
				if( $5.tipo != TK_TIPO_BOOL ){
					cout <<  "COMPILACAO com erro: FOR espera um bool no segundo parametro" <<endl;
					exit(0);
				}


				string nome = geradoraDeNomeDeVariaveis();
				variavel v = criadorDeVariavel(nome, nome, getTipoString($5.tipo), 0);
					
					
				Loop loop = getLoop(loop_tack);

				string comecoL = loop.comecoL;
				string fimL = loop.fimL;
				string contL = loop.contL;
				
				string linha = "\t" + nome + " = !" + $5.label + ";\n";
				
				string atrib_inicial = $3.traducao;
				string showLabel = "\n\t" + comecoL + ": \n" + $5.traducao + linha + "\n";
				string verifica = "\tif(" + nome + ") " + "\tgoto "+ fimL + ";\n";
				
				string dentroFor = $9.traducao + "\n\t" + contL + ": \n" + $7.traducao + $5.traducao + linha + "\n";
				
				$$.traducao = atrib_inicial + showLabel + verifica + dentroFor + "\tgoto " + comecoL + ";\n\t" + fimL + ":\n";
			}
			;
PUSH_LOOP: {
				// mudar de tk_while pra loop, ou mudar na func pra ser so loop? [to-do]
				string label = geradorTextGoto(TK_WHILE);

				string comecoL = "inicio_" + label;
				string fimL = "fim_" + label;
				string contL = "continue_" + label;
				
				Loop loop;
				loop.fimL = fimL;
				loop.comecoL = comecoL;
				loop.contL = contL;
				
				
				pushLoop(loop, loop_tack);
				
				$$.traducao = "";
				$$.label = "";
			}
			;
POP_LOOP:	{
				popLoop(loop_tack);

				$$.traducao = "";
				$$.label = "";
			}
			;
PRINT 		: TK_PRINT PRINT_THINGS
			{
				$$.traducao = $2.traducao + "\tstd::cout << " +$2.label+ "std::endl;\n";
			}
			;
PRINT_THINGS: PRINT_THINGS ',' PRINT_THING
			{
				$$.traducao = $1.traducao + $3.traducao;
				$$.label = $1.label + $3.label ;

			}
			| PRINT_THING
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;

			}
			;
PRINT_THING: E
			{
				// else_if_string += $1.traducao;
				$$.traducao = $1.traducao;
				// deletadorDeVariavel($1.label);
				$$.label = $1.label + " << ";

			}
			;

READ 		: TK_READ READ_THINGS
			{
				$$.traducao = "\tstd::cin " +$2.traducao+ ";\n";
			}
			;
READ_THINGS: READ_THINGS ',' READ_THING
			{
				$$.traducao = $1.traducao + $3.traducao;
			}
			| READ_THING
			{
				$$.traducao = $1.traducao;
			}
			;
READ_THING: TK_ID
			{
				else_if_string += $1.traducao;
				// deletadorDeVariavel($1.label);
				$$.traducao = " >> " +$1.label;

			}
			;


DECLARATION_GLOBAL: DECLARATION ';'
			{
				$$.traducao = $1.traducao;
			}
			| // vazio
			{
				$$.traducao = "";
			}

DECLARATION	: TIPO VARLIST
			{
				$2.tipo = $1.tipo;
				$$.traducao = $1.traducao + $2.traducao;

				$$.tamanho = $2.tamanho;



				// cout << "AQUIII ________ \n" << "Label: " << $$.label << "\nTrad: " << $$.traducao << "\n ACABOUU ---" <<endl; 

			}
			
			;

TIPO 		: TK_TIPO_INT
			{
				$$.tipo = TK_TIPO_INT;
				// $$.traducao = "int";
			}
			| TK_TIPO_FLOAT
			{
				$$.tipo = TK_TIPO_FLOAT;
				// $$.traducao = "float";
			}
			| TK_TIPO_CHAR
			{
				$$.tipo = TK_TIPO_CHAR;
				// $$.traducao = "char";
			}
			| TK_TIPO_BOOL
			{
				$$.tipo = TK_TIPO_BOOL;
				// $$.traducao = "bool";
			}
			| TK_TIPO_STRING
			{
				$$.tipo = TK_TIPO_STRING;
				// $$.traducao = "string";
			}
			// isso seria pra declarar variavel sem o tipo antes do nome da mesma [to-do], rever isso
			| TK_TIPO_VAR
			{
				// $$.traducao = "var";
			}
			| TK_TIPO_VOID
			{
				// $$.traducao = "void";;
			}
			;

VARLIST 	: VARLIST ',' TK_ID
			{
				// cout << "VARLIST, TK_ID _______" <<endl;

				string nome = geradoraDeNomeDeVariaveis();
				$$.traducao = $1.traducao + $3.traducao;

				variavel v = criadorDeVariavel($3.label, nome, getTipoString($0.tipo), 0);
				// addVarEsc(tack, v);

				// cout << " ->>>> " << tack->variaveis_map[0][$3.label].var_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$3.label].temp_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$3.label].tipo << endl;

			}
			| VARLIST ',' ATRIB
			{
				// verificar [to-do] tudo
				$$.traducao = $1.traducao + $3.traducao;

				$1.tipo = $0.tipo;
				$3.tipo = $0.tipo;

				cout << "label>>>>> " << $1.label << endl;
				cout << "traducao>>>>> " << $1.traducao << endl;

				cout << "label>>>>> " << $3.label << endl;
				cout << "traducao>>>>> " << $3.traducao << endl;

			}
			| TK_ID '=' E	
			{
				// cout << "TK_ID = E_______ " << $1.label <<endl;
				string nome = geradoraDeNomeDeVariaveis();
				// inferir tipo
				string tipo_v = "";

				// se o tipo foi dito -> int x = 9
				if (getTipoString($0.tipo) != "")
				{	
					// cout << "1" << endl;
					tipo_v = getTipoString($0.tipo);
				}
				else // se tipo nao foi dito -> x = 9
				{
					// cout << "2" << endl;
					// cout << $3.tipo << endl;

					tipo_v = getTipoString($3.tipo);
				}

				// tipo da expressao = bool e tipo da variavel nao for bool
				if ($3.tipo == TK_TIPO_BOOL && tipo_v != "bool")
				{
					cout << error_msg << endl;
					cout << "tipo de expressao = bool e tipo variavel != bool" << endl;
					exit(0);
				}

				// if (tipo_v == "string")
				// {
					// cout << "é igual string" << endl;
					// cout << $3.label << endl;
					// cout << $3.tamanho << endl;
				// }


				variavel v = criadorDeVariavel($1.label, nome, tipo_v, $3.tamanho);
				$$.tamanho = $3.tamanho;

				cout << "Tamanhoa aqui" << endl;
				cout << $$.tamanho << endl;

				// addVarEsc(tack, v);

				// cout << " ->>>> " << tack->variaveis_map[0][$1.label].var_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$1.label].temp_name << endl;
				// cout << " ->>>> " << tack->variaveis_map[0][$1.label].tipo << endl;

				// cout << " ->>>> " << getTipoString($3.tipo) << endl;


				// cout << " ->>>> " << getVarPorNome($1.label).var_name << endl;
				// cout << " ->>>> " << getVarPorNome($1.label).temp_name << endl;
				// cout << " ->>>> " << getVarPorNome($1.label).tipo << endl;


				variavel minha_var = getVarPorNome($1.label);

				// variavel com tipo diferente da expressao
				if (minha_var.tipo != getTipoString($3.tipo))
				{
					string nomeReal = geradoraDeNomeDeVariaveis();

					// castiando [to-do] verificar isso aqui, se nomeReal troca de lugar com nome
					$$.traducao = $1.traducao + $3.traducao; 
					$$.traducao += "\t" + nome + " = (" + minha_var.tipo + ") " + $3.label +";\n";
					$$.traducao += "\t" + nomeReal + " = " + nome + ";\n";
					
					v = criadorDeVariavel(nomeReal, nomeReal, minha_var.tipo, 0);
				}
				else{ // se o tipo eh igual

					$$.traducao = $1.traducao + $3.traducao + "\t" + nome + " = " + $3.label + ";\n";

				}
	 
			}
			| TK_ID
			{
				// cout << "TK_ID _______" <<endl;

				// tipo nome_var;
				$$.traducao = $1.traducao;
				$$.label = $1.label;

				variavel v = criadorDeVariavel($$.label, geradoraDeNomeDeVariaveis(), getTipoString($0.tipo), 0);

				// cout << v.var_name << endl;

				// addVarEsc(tack, v);

				// for (int i = 0; i < tack->variaveis_map.size(); ++i)
				// {
					// cout << " ->>>> " << tack->variaveis_map[0][$$.label].var_name << endl;
					// cout << " ->>>> " << tack->variaveis_map[0][$$.label].temp_name << endl;
					// cout << " ->>>> " << tack->variaveis_map[0][$$.label].tipo << endl;
					 
				// }

			}
			;

ATRIB 		: TK_ID '=' E
			{
				variavel v = getVarPorNome($1.label);
				string nome = v.temp_name;

				$$.tamanho = $3.tamanho;


				// variavel nao existe
				if (nome == "")
				{
					string tipo_v;

					nome = geradoraDeNomeDeVariaveis();


					// cout << getTipoString($-2.tipo) << endl;

					// cout << getTipoString($3.tipo) << endl;

					// $-2 pois pra chegar em ATRIB eu vim por VARLIST de DECLARATION
					// se vier direto de COMANDO deve ser $0
					if (getTipoString($-2.tipo) != "")
					{	
						tipo_v = getTipoString($-2.tipo);
						// cout << "1" << endl;
					}
					else // se tipo nao foi dito -> x = 9
					{
						tipo_v = getTipoString($3.tipo);
						// cout << "2" << endl;
						
					}

					// tipo da expressao = bool e tipo da variavel nao for bool
					if ($3.tipo == TK_TIPO_BOOL && tipo_v != "bool")
					{
						cout << error_msg << endl;
						cout << "tipo de expressao = bool e tipo variavel != bool" << endl;

						exit(0);
					}

					v = criadorDeVariavel($1.label, nome, tipo_v, $3.tamanho);




				}
				else{
					// if (getTipoString($0.tipo) != "")
					// {	
					// 	tipo_v = getTipoString($0.tipo);
					// 	cout << "1" << endl;
					// }
					
					if ($3.tipo == TK_TIPO_BOOL && v.tipo != "bool")
					{
						cout << error_msg << endl;
						cout << "tipo de expressao = bool e tipo variavel != bool" << endl;

						exit(0);
					}
				}




				if (v.tipo != getTipoString($3.tipo))
				{
					string nomeReal = geradoraDeNomeDeVariaveis();

					// castiando [to-do] verificar isso aqui, se nomeReal troca de lugar com nome
					$$.traducao = $1.traducao + $3.traducao; 
					$$.traducao += "\t" + nome + " = (" + v.tipo + ") " + $3.label +";\n";
					$$.traducao += "\t" + nomeReal + " = " + nome + ";\n";
					
					v = criadorDeVariavel(nomeReal, nomeReal, v.tipo, 0);
				}
				else{ // se o tipo eh igual

					$$.traducao = $1.traducao + $3.traducao + "\t" + nome + " = " + $3.label + ";\n";

				}

				// cout << "TA AQUI2" << endl;




			}
			;

E 			: '(' E ')'
			{
				$$ = $2;
			}
			| '-'E
			{
				$$.tipo = $2.tipo;

				string nome = geradoraDeNomeDeVariaveis();
				// temp(x+1) = -temp(x); usa -temp(x)
				// $$.label = "-" + $2.label; 
				// temp(x+1) = -temp(x); usa temp(x+1)
				$$.label = nome;

				$$.traducao = $2.traducao + "\t" + nome + " = -" + $2.label + ";\n";

				variavel v = criadorDeVariavel(nome, nome, getTipoString($$.tipo), 0);

				 

			}
			| E '-' E
			{
				$$ = tratadoraArith($1, $3, "-");
			}
			| E '+' E
			{
				if ($1.tipo == TK_TIPO_STRING && $3.tipo == TK_TIPO_STRING)
				{
					cout << "TAAAAMMAMAMA" << endl;
					cout << $1.tamanho << endl;
					cout << $3.tamanho << endl;
					$$ = concatenarStrings($1, $3);
				}
				else{
					$$ = tratadoraArith($1, $3, "+");
				}
			}
			| E '*' E
			{
				$$ = tratadoraArith($1, $3, "*");
			}
			| E '/' E
			{
				$$ = tratadoraArith($1, $3, "/");
			}
			| E '>' E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic($1.tipo, $1.label, $3.tipo, $3.label, ">");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E '<' E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic($1.tipo, $1.label, $3.tipo, $3.label, "<");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E TK_GTE E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic($1.tipo, $1.label, $3.tipo, $3.label, ">=");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E TK_LTE E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic($1.tipo, $1.label, $3.tipo, $3.label, "<=");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E TK_EQUAL E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic($1.tipo, $1.label, $3.tipo, $3.label, "==");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E TK_NEQUAL E
			{
				$$.tipo = TK_TIPO_BOOL;

				atributos result = tratadoraLogic($1.tipo, $1.label, $3.tipo, $3.label, "!=");

				$$.traducao = $1.traducao + $3.traducao + result.traducao;
				$$.label = result.label;
			}
			| E TK_AND E
			{	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = geradoraDeNomeDeVariaveis();

				$$.tipo = TK_TIPO_BOOL;
				$$.tipo = tipoResult($1.tipo, $3.tipo);

				variavel v = criadorDeVariavel(nome, nome, getTipoString($$.tipo), 0);

				$$.traducao = $1.traducao + $3.traducao + "\t" + nome +" = "+ $1.label +" && "+ $3.label +";\n";
				
				$$.label = nome;
			}
			| E TK_OR E
			{	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = geradoraDeNomeDeVariaveis();

				$$.tipo = TK_TIPO_BOOL;
				$$.tipo = tipoResult($1.tipo, $3.tipo);

				variavel v = criadorDeVariavel(nome, nome, getTipoString($$.tipo), 0);

				$$.traducao = $1.traducao + $3.traducao + "\t" + nome +" = "+ $1.label +" || "+ $3.label +";\n";

				$$.label = nome;
			}
			| TK_NOT E
			{	
				// bool ou tipo 
				// $$.tipo = TK_TIPO_BOOL;
				string nome = geradoraDeNomeDeVariaveis();

				$$.tipo = tipoResult($2.tipo, $2.tipo);

				variavel v = criadorDeVariavel(nome, nome, getTipoString($$.tipo), 0);


				$$.traducao = $2.traducao + "\t" + nome +" = !"+ $2.label +";\n";

				$$.label = nome;
			}
			| TK_NUM
			{
				$$.tipo = TK_TIPO_INT;

				string nome = geradoraDeNomeDeVariaveis();
				$$.traducao = "\t" + nome + " = " + $1.label + ";\n";
				$$.label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString($$.tipo), 0);

			}
			| TK_REAL
			{
				$$.tipo = TK_TIPO_FLOAT;

				string nome = geradoraDeNomeDeVariaveis();
				$$.traducao = "\t" + nome + " = " + $1.label + ";\n";
				$$.label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString($$.tipo), 0);

			}
			| TK_CHAR
			{
				$$.tipo = TK_TIPO_CHAR;

				string nome = geradoraDeNomeDeVariaveis();
				$$.traducao = "\t" + nome + " = " + $1.label + ";\n";
				$$.label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString($$.tipo), 0);
				// [to-do] checar isso $1.label.size() - 2

			}
			| TK_ID
			{
				variavel v = getVarPorNome($1.label);

				$$.tamanho = v.tamanho;


				// verifica se variavel existe
				if (v.var_name == "")
				{
					cout << error_msg << endl;
					cout << "variavel nao existe" << endl;
					exit(0);
				}
				else{
					$$.traducao = $1.traducao;
					$$.label = v.temp_name;
					$$.tipo = getTipoToken(v.tipo);
				}

				// cout << "TA AQUI" << endl;
				// cout << $$.label << endl;
				// cout << $$.tipo << endl;

			}
			| TK_BOOL
			{
				$$.tipo = TK_TIPO_BOOL;

				string nome = geradoraDeNomeDeVariaveis();
				$$.traducao = "\t" + nome + " = " + $1.label + ";\n";
				$$.label = nome;

				variavel v = criadorDeVariavel(nome, nome, getTipoString($$.tipo), 0);

			}
			| TK_STRING
			{
				$$.tipo = TK_TIPO_STRING;

				string nome = geradoraDeNomeDeVariaveis();
				$$.traducao = "\tstrcpy(" + nome + "," + $1.label + ");\n";
				$$.label = nome;

				$$.tamanho = $1.label.size()-2;

				variavel v = criadorDeVariavel(nome, nome, getTipoString($$.tipo), $1.label.size()-2);

			}
			;

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	// for (int i = 0; i < varsDec.size(); ++i)
	// {
	// 	cout << " ->>>> " << getVarPorNome(varsDec[i].var_name).var_name << endl;
	// 	cout << " ->>>> " << getVarPorNome(varsDec[i].var_name).temp_name << endl;
	// 	cout << " ->>>> " << getVarPorNome(varsDec[i].var_name).tipo << "\n" << endl;
	// }

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}

string exibirVarsDeclaradas(){

	// varsDeclaradas varsDec_aux;

	// for (int i = 0; i < varsDec.size(); ++i)
	// {
	// 	variavel v = getVarPorNome(varsDec[i].var_name);

	// 	cout << "VAAAA " << varsDec[i].var_name << endl;
	// 	if ( varsDec.count(v.var_name) )
	// 	{
	// 		cout << "VBBBB " << v.var_name << endl;
		
	// 	}

	// 	varsDec_aux.push_back(v);
	// 	cout << "VCCCC " << varsDec_aux[i].var_name << endl;

	// }

	return getDeclaradas(varsDec);
}
variavel criadorDeVariavel(string nome, string temp_nome, string tipo, int tamanho){

	variavel v;

	if (tipo == "string" && tamanho == 0)
	{
		// criando sting com tamanho predeterminado, deve melhorar [to-do]
		v = criarVar(nome, temp_nome, tipo, 0);
		
	}else{
		v = criarVar(nome, temp_nome, tipo, tamanho);
	}

	addVarEsc(tack, v);
	varsDec.push_back(v);

	return v;
}
 
void deletadorDeVariavel(string nome){

	tack->variaveis_map[tack->escopo_num].erase(nome);
	cout << "APAGOU " << nome << endl;

	exibirVarsDeclaradas();

	// variavel v = getVarPorNome(nome);
	// cout << v.var_name << endl;
	// variavel v = getVarPorNome(nome);
	// delete v;

}
string geradoraDeNomeDeVariaveis(){
	static int num_para_gerar_nomes = 0;
	// string nome;
	// nome = "temp_" + to_string(num_para_gerar_nomes);

	// num_para_gerar_nomes++;
	return "temp_" + to_string(num_para_gerar_nomes++);
}

string geradoraDeNomeDeFuncoes(){
	static int num_para_gerar_nomes = 0;
	// string nome;
	// nome = "temp_" + to_string(num_para_gerar_nomes);

	// num_para_gerar_nomes++;
	return "func_temp_" + to_string(num_para_gerar_nomes++);
}

int getTipoToken(string tipo){

	if (tipo == "int")
		return TK_TIPO_INT;
	if (tipo == "float")
		return TK_TIPO_FLOAT;
	if (tipo == "char")
		return TK_TIPO_CHAR;
	if (tipo == "bool")
		return TK_TIPO_BOOL;
	if (tipo == "string")
		return TK_TIPO_STRING;

	return 0;
}

string getTipoString(int tipo){

	if (tipo == TK_TIPO_INT)
		return "int";
	if (tipo == TK_TIPO_FLOAT)
		return "float";
	if (tipo == TK_TIPO_CHAR)
		return "char";
	if (tipo == TK_TIPO_BOOL)
		return "bool";
	if (tipo == TK_TIPO_STRING)
		return "string";

	return "";
}

atributos tratadoraLogic(int t1, string atr1_label, int t2, string atr2_label, string sinal){

	atributos retorno;
	// o retorno de uma expressao logica deve ser bool
	retorno.tipo = TK_TIPO_BOOL;
	string nome = geradoraDeNomeDeVariaveis();

	// usando a mesma da arith, depois devo mudar pra uma tabela [to-do]
	int tipo_das_entradas = tipoResult(t1, t2);

	if (tipo_das_entradas == TK_TIPO_INT)
	{
		retorno.label = nome;

		retorno.traducao = "\t" + nome + " = " + atr1_label + " " + sinal + " " + atr2_label + ";\n";

		// tipo da variavel deve ser do tipo int por ser um bool, ou deve ser o tipo da tipo_das_entradas? [to-do]
		variavel v =  criadorDeVariavel(nome, nome, getTipoString(tipo_das_entradas), 0);
	}
	else if(tipo_das_entradas == TK_TIPO_FLOAT){

		string nomeReal = geradoraDeNomeDeVariaveis();
		
		retorno.label = nomeReal;

		// variavel usada pra fazer o cast pra float
		variavel v =  criadorDeVariavel(nome, nome, "float", 0);
		// int por ser bool? [to-do]
		v =  criadorDeVariavel(nomeReal, nomeReal, "int", 0);

		if (t1 == TK_TIPO_INT)
		{
			retorno.traducao = "\t" + nome + " = (float) " + atr1_label + ";\n";
			retorno.traducao += "\t" + nomeReal + " = " + nome + " " + sinal + " " + atr2_label + ";\n";
		}
		else if (t2 == TK_TIPO_INT)
		{	
			retorno.traducao = "\t" + nome + " = (float) " + atr2_label + ";\n";
			retorno.traducao += "\t" + nomeReal + " = " + atr1_label + " " + sinal + " " + nomeReal + ";\n";
		}

	}




	return retorno;


}

int tipoResult(int t1, int t2){

	// verificando com if, deveria ter uma tabela, fazer depois por demandar mais tempo

	if ( (t1 != TK_TIPO_FLOAT && t1 != TK_TIPO_INT) || (t2 != TK_TIPO_FLOAT && t2 != TK_TIPO_INT) )
	{

		if (t1 == TK_TIPO_CHAR && t2 == TK_TIPO_CHAR)
		{
			return TK_TIPO_CHAR;
		}
		else if (t1 == TK_TIPO_BOOL && t2 == TK_TIPO_BOOL)
		{
			return TK_TIPO_BOOL;
		}
		else if (t1 == TK_TIPO_STRING && t2 == TK_TIPO_STRING)
		{
			return TK_TIPO_STRING;
		}
		// tipo de operadores invalidos
		cout << error_msg << endl;
		cout << "tipo de operadores invalidos" << endl;
		exit(0);

	}

	if (t1 == TK_TIPO_FLOAT || t2 == TK_TIPO_FLOAT)
	{
		return TK_TIPO_FLOAT;
	}
	else{
		return TK_TIPO_INT;
	}
}

atributos tratarArithComCast(int tipo1, string atr1_label, int tipo2, string atr2_label, string sinal){

	int tipo_atual = tipoResult(tipo1, tipo2);

	string line = "", line2 = "";

	string nome = geradoraDeNomeDeVariaveis();
	string nomeReal = geradoraDeNomeDeVariaveis();

	// devo castiar
	if (tipo_atual == TK_TIPO_FLOAT)
	{
		
		if (tipo1 == TK_TIPO_INT)
		{
			line = "\t" + nome + " = (float) " + atr1_label + ";\n";
			line2 = "\t" + nomeReal + " = " + nome + " " + sinal + " " + atr2_label + ";\n";
		}
		else if (tipo2 == TK_TIPO_INT)
		{
			line = "\t" + nome + " = (float) " + atr2_label + ";\n";
			line2 = "\t" + nomeReal + " = " + atr1_label + " " + sinal + " " + nome + ";\n";
		}

		variavel v = criadorDeVariavel(nome, nome, getTipoString(tipo_atual), 0);
		v = criadorDeVariavel(nomeReal, nomeReal, getTipoString(tipo_atual), 0);

	}

	atributos turn;
	turn.traducao = line + line2;
	turn.label = nomeReal;
	return turn;

}

atributos tratadoraArith(atributos a1, atributos a2, string sinal){
	
	atributos retorno;
	cout << "tipo" << endl;
	cout << a1.tipo << endl;
	cout << a2.tipo << endl;
	cout << a1.label << endl;
	retorno.tipo = tipoResult(a1.tipo, a2.tipo);
	

	// sem precisar cast
	if (a1.tipo == a2.tipo)
	{
		string nome = geradoraDeNomeDeVariaveis();
		
		retorno.traducao = a1.traducao + a2.traducao + "\t" + nome + " = " + a1.label + " " + sinal + " " + a2.label + ";\n";
	
		retorno.label = nome;

		variavel v = criadorDeVariavel(nome, nome, getTipoString(retorno.tipo), 0);

	}
	else{ // CASTando

		// fazer o cast dependendo do tipo
		atributos atr = tratarArithComCast(a1.tipo, a1.label, a2.tipo, a2.label, sinal);
		atr.tipo = retorno.tipo;

		retorno.traducao = a1.traducao + a2.traducao + atr.traducao;
	
		retorno.label = atr.label;
	}
	

	return retorno;
}	

atributos concatenarStrings(atributos a1, atributos a2){

	string nome = geradoraDeNomeDeVariaveis();

	variavel v1 = getVarPorNome(a1.label);
	variavel v2 = getVarPorNome(a2.label);
	
	variavel v = criadorDeVariavel(nome, nome, getTipoString(TK_TIPO_STRING), (a1.tamanho + a2.tamanho));

	cout << "nome" << endl;
	cout << nome << endl;
	cout << a1.tamanho << endl;
	cout << a2.tamanho << endl;
	cout << v.tamanho << endl;

	string l1 = "\tstrcat(" +nome+ ", " +a1.label+ ");\n";
	string l2 = "\tstrcat(" +nome+ ", " +a2.label+ ");\n";

	atributos atr;
	atr.label = nome;
	atr.traducao = l1 + l2;
	atr.tipo = TK_TIPO_STRING;
	atr.tamanho = (a1.tamanho + a2.tamanho);

	cout << "nome" << endl;

	return atr;

}


variavel getVarPorNome(string name){

	// DECLARADAS
	cout << "DECLARADAS" << endl;
	cout << exibirVarsDeclaradas() << endl;

	// quando for blocos devo procurar no vetor

	Var_table vt = tack->variaveis_map[tack->escopo_num];

	// variavel ja declarada
	if ( vt.count(name) )
	{
		cout << "achou " << name <<endl;
		return vt[name];
	}
	else {
		int esc = tack->escopo_num-1;
		// cout << "esc " << esc << endl;
		for (int i = esc; i > -1; i--)
		{
			Var_table vt = tack->variaveis_map[i];

			if ( vt.count(name) )
			{
				cout << "achou " << name <<endl;

				return vt[name];
			}
		} 
	}
	// cout << "_______ " << tack->variaveis_map[tack->escopo_num][name].var_name << endl;
	// return criarVar("", "", "",  0);
	// return tack->variaveis_map[tack->escopo_num][name];

	cout << "Essa variavel nao 'existe' : " << name << endl;
	return vt[0];
}

string geradorTextGoto(int token){
	static int num_label = 0;
	
	if (token == TK_IF)
	{
		return "token_if_" + to_string(num_label++);
	}
	else if (token == TK_FOR)
	{
		return "token_for_" +to_string(num_label++);
	}
	else if (token == TK_WHILE)
	{
		return "token_while_" +to_string(num_label++);
	}

	return "ISSo nao deveria estar retornando 1 ";
}



const vector<string> explode(const string& s, const char& c)
{
	string buff = "";
	vector<string> v;

	for (int n = 0; n < s.size(); ++n)
	{
		if(s.at(n) != c) buff+=s.at(n); else
		if(s.at(n) == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	
	if(buff != "") v.push_back(buff);
	
	return v;
}




%{
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>    
#include <tuple>
#include <stdlib.h>
#include "tabelas/cabecalhos.h"   


using namespace std;


%}


%token TK_MAIN TK_ID TK_TERMINAL
%token TK_TIPO_INT TK_TIPO TK_OPERACAO TK_RELACIONAL TK_LOGICO

%start S

%%


S             : TK_TIPO TK_MAIN '(' ')' BLOCO
            {
                for(auto& tuple: vetor_variaveis) 
                    cout <<"\t" << get<1>(tuple) << " " << get<2>(tuple) << " = " << get<3>(tuple) << "; " <<endl;   

                cout<<"COMPILADOR WINTER\n" <<"int main()\n{\n"<<endl;
                cout<<$5.traducao <<" return 0;\n}"<<endl;
            }
            ;

BLOCO        : '{' COMANDOS '}'
            {
                $$.traducao = $2.traducao;
            }
            ;

COMANDOS    : COMANDO COMANDOS
            {
                $$.traducao = $1.traducao + $2.traducao;
            }
            |
            ; 

COMANDO     : E ';' 
            {
            	$$.traducao = $1.traducao;
            }

            |  TK_TIPO TK_ID '=' E ';'                            // int a = b + c * d;
            {
                string valor;
                verifica_compatibilidade($1.tipo, $4.tipo);

                if(!verifica_declaracao($2.label)){

                    if($1.tipo != $4.tipo){
                        
                        valor = conversao_atribuicao($1.tipo, $4.label); // cria uma nova temp pra salvar a converte do valor
                        $$.traducao = "\t" + $4.traducao + valor +"\t" +$2.label + " = " + retorna_nome_temp($1.tipo, -1) +";\n\n";
                        cria_variavel($1.tipo, $2.label, $4.valor);
                    }
                    else{
                        cria_variavel($1.tipo, $2.label,$4.valor);
                        $$.traducao = "\t"+ $4.traducao + "\t" + $2.label + " = " + $4.label + ";\n";
                    }
                }
                
                else{
                    erro_declaracao($2.label);
                }   
            }

            | TK_ID '=' E ';'                                    // a = b + c;
            {
                string valor, tipo1 = retorna_tipo($1.label);

                verifica_compatibilidade(tipo1, $3.tipo);
                if(!verifica_declaracao($1.label))
                    erro_nao_declaracao($1.label);

                if(tipo1 != $3.tipo){
                    
                    valor = conversao_atribuicao(tipo1, $3.label); // cria uma nova temp pra salvar a converte do valor
                    $$.traducao = '\t'+ $3.traducao + "\n" + valor +"\t" + $1.label + " = " + retorna_nome_temp(tipo1, -1) +";\n\n";
                    atualiza_valor($1.label, $1.tipo, $3.valor);
                }
                else{
                    atualiza_valor($1.label, $3.tipo, $3.valor);
                    $$.traducao = "\t" + $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n";
                }  
            }

            | TK_TIPO TK_ID ';'                                        // int a;
            {
                $$.traducao = "\t" + cria_variavel($1.tipo, $2.label, string("0")) + ";\n";
            }
            ;
                
E 			:A
			{
				$$.traducao = $1.traducao;
                $$.tipo = $1.tipo;
                $$.valor = $1.valor;
                $$.label = $1.label;
			}
			|L
			{
				$$.traducao = $1.traducao;	
				$$.valor = $1.valor;
                $$.tipo = $1.tipo;
				$$.label = $1.label;
			}
            | TK_TIPO '(' F ')'
            {
                verifica_compatibilidade($1.tipo, $3.tipo);
                $$.label = retorna_nome_temp($1.tipo, 0);
                $$.traducao = conversao_atribuicao($1.tipo, $3.label);
                $$.tipo = $1.tipo;
                $$.valor = to_string(atoi(($3.valor).c_str()) );;

            }
			|
			;


A            : A '+' T
            {
                verifica_compatibilidade($1.tipo, $3.tipo);
                $$.valor = calc($1.valor, $3.valor, string("+"));
                $$.label = retorna_nome_temp($1.tipo, 0);
                $$.tipo = $1.tipo; 
                
                if(!tipos_iguais($1.tipo, $3.tipo)){

                    string aux = prioridade($1.tipo, $3.tipo);
                    $$.tipo = aux;
                    $$.traducao = conversao($1.tipo, $1.label, $1.valor, $1.traducao, $3.tipo, $3.label, $3.valor, $3.traducao, aux, "+");
                    $$.label = retorna_nome_temp(aux, -1);
                }
                else
                    $$.traducao = $1.traducao +  "\n" + $3.traducao + "\n" + cria_temporaria($1.label + " + " + $3.label, $1.tipo);
            }
            
            |A '-' T
            {
                verifica_compatibilidade($1.tipo, $3.tipo);
                $$.valor = calc($1.valor, $3.valor, string("-"));
                $$.label = retorna_nome_temp($1.tipo, 0); 
               
                if($1.tipo != $3.tipo){

                    string aux = prioridade($1.tipo, $3.tipo);
                    $$.tipo = aux;
                    $$.traducao = conversao($1.tipo, $1.label, $1.valor, $1.traducao, $3.tipo, $3.label, $3.valor, $3.traducao, aux, "-");
                    $$.label =  retorna_nome_temp(aux, -1);
                }
                else
                    $$.traducao =  $1.traducao +  "\n" + $3.traducao + "\n" + cria_temporaria($1.label + " - " + $3.label, $1.tipo);          
            }

            | T
            {
                $$.traducao = $1.traducao;
                $$.tipo = $1.tipo;
                $$.valor = $1.valor;
                $$.label = $1.label;
            }
             ;

T             :T '*' F 
            {
                verifica_compatibilidade($1.tipo, $3.tipo);
                $$.valor = calc($1.valor, $3.valor, string("*"));
                $$.label = retorna_nome_temp($1.tipo, 0); 
                $$.tipo = $1.tipo; 
                
                if(!tipos_iguais($1.tipo, $3.tipo)){

                    string aux = prioridade($1.tipo, $3.tipo);
                    $$.tipo = aux;
                    $$.traducao = conversao($1.tipo, $1.label, $1.valor, $1.traducao, $3.tipo, $3.label, $3.valor, $3.traducao, aux, "*");
                    $$.label = retorna_nome_temp(aux, -1); 
                }
                else
                    $$.traducao =  $1.traducao +  "\n" + $3.traducao + "\n" + cria_temporaria($1.label + " * " + $3.label, $1.tipo);   
            }
            | T '/' F
            {
                verifica_compatibilidade($1.tipo, $3.tipo);
                $$.valor = calc($1.valor, $3.valor, string("/"));
                $$.label = retorna_nome_temp($1.tipo, 0); 
                $$.tipo = $1.tipo; 
                
                if(!tipos_iguais($1.tipo, $3.tipo)){

                    string aux = prioridade($1.tipo, $3.tipo);
                    $$.tipo = aux;
                    $$.traducao = conversao($1.tipo, $1.label, $1.valor, $1.traducao, $3.tipo, $3.label, $3.valor, $3.traducao, aux, "/");
                    $$.label = retorna_nome_temp(aux, -1); 
                }
                else
                    $$.traducao =  $1.traducao +  "\n" + $3.traducao + "\n" + cria_temporaria($1.label + " / " + $3.label, $1.tipo);    
            }
            | F
            {
                $$.valor = $1.valor;
                $$.tipo = $1.tipo;
                $$.label = $1.label;
                $$.traducao = " ";
            }
            ;


L 			:L TK_LOGICO R
			{
                $$.label = retorna_nome_temp("bool", 0); 
                $$.valor = calc($1.valor, $3.valor, $2.traducao);
				$$.tipo = "bool";
                $$.traducao = $1.traducao +"\n" + $3.traducao + "\n"+ cria_temporaria($1.label + $2.traducao + $3.label, $$.tipo);
			}
			|TK_LOGICO F
			{
                $$.label = retorna_nome_temp("bool", 0); 
				$$.valor = calc($2.valor,string(" "), $1.traducao);
				$$.tipo = "bool";
                $$.traducao = $2.traducao +"\n" + cria_temporaria($1.traducao + $2.label, $$.tipo);
            }
			;
			|R
			{
				$$.traducao = $1.traducao;
				$$.valor = $1.valor;
				$$.label = $1.label;
				$$.tipo = $1.tipo;
			}
			;   


R 			:A TK_RELACIONAL A
			{
                verifica_compatibilidade($1.tipo, $3.tipo);

                $$.label = retorna_nome_temp("bool", 0); 
                $$.valor = calc($1.valor, $3.valor, $2.traducao);
                $$.tipo = "bool"; 
                $$.traducao = $1.traducao +  "\n" + $3.traducao + "\n" + cria_temporaria($1.label + $2.traducao + $3.label, $$.tipo);
			}

			|TK_LOGICO '(' L ')'
			{
                $$.label = retorna_nome_temp("bool", 0); 
				$$.valor = calc($3.valor,string(" "), $1.traducao);
				$$.tipo = "bool";
                $$.traducao = $3.traducao +"\n" + cria_temporaria($1.traducao + $3.label, $$.tipo);
			}
			;

F           : TK_TERMINAL
            {
                $$.valor = $1.valor;
                $$.tipo = $1.tipo;
                $$.label = $1.valor;
                $$.traducao = " ";
            }

            | TK_ID
            {
                $$.valor = retorna_valor($1.label);
                $$.tipo = $1.tipo;
                $$.label = $1.label;
                $$.traducao = " ";
            }
            ;
            
%%

#include "lex.yy.c"

int main( int argc, char* argv[] )
{


    yyparse();

    return 0;
}

void yyerror( string MSG )
{
    cout << MSG << endl;
    exit (0);
}                
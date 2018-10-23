%{
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>    
#include <tuple>
#include <stdlib.h>
#include "tabelas/cabecalhos.h"   

#define YYDEBUG 1

vector < vector<tuple<string, string, string, string>> > pilha_blocos;
int cont = 1;
int cont_label = 1;

using namespace std;

%}


%token TK_MAIN TK_ID TK_TERMINAL
%token TK_TIPO_INT TK_TIPO TK_OPERACAO TK_RELACIONAL TK_LOGICO
%token TK_IF TK_ELSE TK_FOR TK_WHILE 

%start S

%%

S           :BLOCO_PRINCIPAL
            {
                 for(auto& tuple: pilha_blocos[pilha_blocos.size()-1]) 
                    cout <<"\t" << get<1>(tuple) << " " << get<2>(tuple) << " = " << get<3>(tuple) << "; " <<endl;   

                cout<<"COMPILADOR WINTER\n" <<"int main()\n{\n"<<endl;
                cout<<$1.traducao <<" return 0;\n}"<<endl;
            }


BLOCO_PRINCIPAL: /*X COMANDOS_G */ MAIN
            {
                $$.traducao = /*$1.traducao + */ $1.traducao;
            }
            ;

MAIN:       X TK_TIPO TK_MAIN '(' ')' BLOCO                     { $$.traducao = $6.traducao; }
            ;

X           :                                                   { pilha_blocos.push_back(vector<tuple<string, string, string, string>>()); }
            ;   


// COMANDOS_G   : DECLARACAO COMANDOS_G {$$.traducao = $1.traducao + $2.traducao; }            
//             |{}
//             ;

DECLARACAO:    TK_TIPO TK_ID ';'       { gera_codigo_declaracao($$,$1, $2); }       // float media;
            |  TK_TIPO TK_ID '=' E ';' { gera_codigo_declaracao_atribuicao($$,$1, $2, $4); } // int contador = 1;
            ;

BLOCO       : '{' COMANDOS '}'                                  { $$.traducao = $2.traducao; }
            ;

COMANDOS    : COMANDO COMANDOS                                  { $$.traducao = $1.traducao + $2.traducao; }
            |
            ;   
            ;

COMANDO     : ATRIBUICAO        { $$.traducao = $1.traducao;}
            | DECLARACAO        { $$.traducao = $1.traducao;}
            | IF_ELSE           { $$.traducao = $1.traducao;}
            ;

IF_ELSE:    TK_IF '(' L ')' BLOCO
            {
                string varTeste = retorna_nome_temp("bool", 0);
                string labelFim = cria_label("fim_if");
                $$.tipo = " ";
                $$.valor = " ";
                $$.label = " ";
                $$.traducao = $3.traducao  + cria_temporaria(" !"+ $3.label, "bool") + "\tif( " + varTeste + " ) goto " + labelFim + ";\n" +
                $5.traducao +"\t" + labelFim +":\n"; 
            }
            |TK_IF '(' L ')' BLOCO TK_ELSE BLOCO ';'
            {

            }
            ;


ATRIBUICAO: TK_ID '=' E ';' { gera_codigo_atribuicao($$,$1, $3); }              // a = 7.5; 
            ;
                

E           : A                         {  sobe_valor($$, $1); }
            | L                         {  sobe_valor($$, $1); }
            | TK_TIPO '(' F ')'         { gera_codigo_conversao($$, $1, $3);}   //Converção explícita
            ;

A           : A '+' T                   { gera_codigo_operacao($$, $1, "+", $3); }
            | A '-' T                   { gera_codigo_operacao($$, $1, "-", $3); }
            | T                         { sobe_valor($$, $1); }
            ;

T           :  T '*' F          { gera_codigo_operacao($$, $1, "*", $3); }
            |  T '/' F          { gera_codigo_operacao($$, $1, "/", $3); }
            |  F                { $$.valor = $1.valor; $$.tipo = $1.tipo; $$.label = $1.label; $$.traducao = " "; }
            ;


L           :L TK_LOGICO R      { gera_codigo_operacao_logica($$, $1, $2, $3); }    // a || b
            |TK_LOGICO F        { gera_codigo_operacao_logica2($$, $1, $2);    }    // !a
            |R                  { sobe_valor($$, $1); }
            ;   


R           :A TK_RELACIONAL A      {    gera_codigo_operacao_logica($$, $1, $2, $3); }     // 2 > 3
            |TK_LOGICO '(' L ')'    {    gera_codigo_operacao_logica2($$, $1, $3); }        // !( a > b )
            ;

F           : TK_TERMINAL { sobe_valor_terminal($$, $1); }
            | TK_ID       { sobe_valor_id($$, $1); }
            ;
            
%%

#include "lex.yy.c"

int main( int argc, char* argv[] )
{
    #if YYDEBUG
        yydebug = 1;
    #endif
    yyparse();

    return 0;
}

void yyerror( string MSG )
{
    cout << MSG << endl;
    exit (0);
}                

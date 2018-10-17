#ifndef CABECALHOS_H
#define CABECALHOS_H

#include <iostream>
#include <sstream>
#include <string> 
#include <vector>
#include <tuple>

#define YYSTYPE atributos //assegura o tipo...
#define erro_declaracao(var) (cout<<"ERRO! UMA VARIÁVEL "<<var<< " JÀ FOI DECLARADA."<<endl, exit(0));
#define erro_nao_declaracao(var) (cout<<"ERRO! VARIÁVEL "<<var<< " NÃO DECLARADA."<<endl, exit(0));

using namespace std;

extern int cont;
extern vector<tuple<string, string, string, string>> vetor_variaveis;



int yylex(void);
int yyparse();
void yyerror(string);
string cria_variavel(string, string, string);
string cria_temporaria(string, string);
bool verifica_declaracao(string nome);
void atualiza_valor(string, string, string);
string calc(string, string, string);
void verifica_compatibilidade(string, string);
string retorna_tipo(string);
string retorna_valor(string);
string prioridade(string, string);
string conversao_atribuicao(string, string);
string conversao_explicita(string, string);
string conversao(string,string, string, string,string, string, string, string, string, string);
string converte(string, string, string, string, string);
int tipos_iguais(string, string);
string retorna_nome_temp(string, int);


#endif

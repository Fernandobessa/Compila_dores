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

extern int yy_flex_debug;


extern int cont;
extern int cont_label;
extern vector < vector<tuple<string, string, string, string>> > pilha_blocos;

struct atributos{
    string label;
    string traducao;
    string tipo;
    string valor;
};



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
string cria_label(string);
void gera_codigo_operacao(atributos&, atributos, string, atributos);
void gera_codigo_declaracao(atributos&, atributos, atributos);
void gera_codigo_atribuicao(atributos&ss, atributos s1, atributos s3);
void gera_codigo_declaracao_atribuicao(atributos&, atributos, atributos, atributos);
void sobe_valor(atributos &, atributos);
void sobe_valor_terminal(atributos &, atributos);
void sobe_valor_id(atributos &, atributos);
void gera_codigo_operacao_logica(atributos &, atributos, atributos, atributos);
void gera_codigo_conversao(atributos &, atributos, atributos);
void gera_codigo_operacao_logica2(atributos &, atributos, atributos);


#endif

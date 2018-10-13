#ifndef CABECALHOS_H
#define CABECALHOS_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>    
#include <tuple>

#define YYSTYPE atributos //assegura o tipo...
#define erro_declaracao(var) (cout<<"ERRO! UMA VARIÁVEL "<<var<< " JÀ FOI DECLARADA."<<endl, exit(0));
#define erro_nao_declaracao(var) (cout<<"ERRO! VARIÁVEL "<<var<< " NÃO DECLARADA."<<endl, exit(0));

using namespace std;
static int cont = 1;
static vector<tuple<string, string, string, string>> vetor_variaveis;

#define NUM_LINHAS 6
#define NUM_COLUNAS 3

static string matriz_tipos[NUM_LINHAS][NUM_COLUNAS] = {{"int", "int", "int"}, {"int", "float", "float"}, {"float", "float", "float"}, {"float", "int", "float"}, 
                                                {"bool", "bool", "bool"}, {"char", "char", "char"} };


// typedef struct lista_variaveis Lista_variaveis;
// struct lista_variaveis
// {
//     string tipo;
//     string label;
//     string nome_temp;
//     string valor;
//     Lista_variaveis* prox;
// };
// static Lista_variaveis* lista_var;

struct atributos{
    string label;
    string traducao;
    string tipo;
    string valor;
};


template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{
    std::ostringstream out;
    out << std::setprecision(n) << a_value;
    return out.str();
}

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
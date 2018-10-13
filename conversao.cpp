#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>    
#include <tuple>
#include  "cabecalhos.h"


string conversao(string tipo1, string label1, string valor1, string traducao1,string tipo2, string label2,string valor2, string traducao2, string tipo_prioridade, string operacao){

    string traducao;

        if(tipo1.compare(tipo_prioridade) == 0)
            traducao =  traducao1 + traducao2 + converte(tipo1, label1, tipo2, valor2, operacao);
        else
            traducao =  traducao1 + traducao2 + converte(tipo2, label2, tipo1, valor1, operacao);

    return traducao;
}


string converte(string tipo1, string valor1, string tipo2, string valor2, string operacao){

    string str_temp;

    str_temp += cria_temporaria(valor2, tipo2);
    str_temp += cria_temporaria(tipo1 + " (" + retorna_nome_temp(tipo2, -1) + ")", tipo1);
    str_temp += cria_temporaria(valor1 + operacao + retorna_nome_temp(tipo1, -1), tipo1);

    return str_temp;
}

string conversao_explicita(string tipo_var, string valor){

    if(tipo_var.compare("int") == 0)
        valor = to_string(atoi((valor).c_str()) );   
    else if (tipo_var.compare("float") == 0)   
        valor = to_string_with_precision( (strtof((valor).c_str(),0)));
    return valor;
}


string conversao_atribuicao(string tipo_var, string label){

    return cria_temporaria(tipo_var + "(" + label + ")", tipo_var);
}

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>    
#include <tuple>
#include  "cabecalhos.h"


string cria_variavel(string tipo_var, string label, string valor){
    
    string nome = "TEMP_" + tipo_var +"_" + std::to_string(cont);;
    valor = conversao_explicita(tipo_var, valor);

    auto tupla = std::make_tuple(tipo_var, label, nome, valor);
    vetor_variaveis.push_back(tupla);
    
    cont++; 
    return nome; 
}

string cria_temporaria(string valor, string tipo){

    string nome_temp = "TEMP_" + tipo + "_" + to_string(cont);
    string aux = "\t" + nome_temp + " = "+ valor + ";\n\n";
    
    cout<<"\t"<<nome_temp<<';'<<endl;
    cont++;
    return aux;
}

string retorna_nome_temp(string tipo, int num){
    return "TEMP_" + tipo + "_" +to_string(cont + num);
}

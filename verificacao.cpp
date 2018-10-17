#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>    
#include <tuple>
#include  "cabecalhos.h"
#include "tabela_tipos.h"


bool verifica_declaracao(string nome){

    for(auto& tuple: vetor_variaveis) {
        if(nome.compare(get<1>(tuple)) == 0)
            return true;
    }

   return false;
}

string prioridade(string tipo, string tipo1){

    for(int i = 0; i < NUM_LINHAS; i++){

            if(tipo.compare(matriz_tipos[i][0]) == 0){
                if( (tipo1.compare(matriz_tipos[i][1]) == 0)){
                    return matriz_tipos[i][2];
                }
            }
    }   

    cout<<"ERRO! Tipos incompatíveis para operação. "<<tipo<<" != "<<tipo1<<endl;
    exit(0);
    
}

void atualiza_valor(string label,string tipo_var, string valor){

    for(auto& tuple: vetor_variaveis) {
        if(label.compare(get<1>(tuple)) == 0){
            if(tipo_var.compare("int") == 0)
                valor = to_string(atoi((valor).c_str()) );
            get<3>(tuple) = valor;            
        }
    }
}

string retornatipo(string label){

    if(!verifica_declaracao(label))
        erro_nao_declaracao(label);

    for(auto& tuple: vetor_variaveis) {
        if(label.compare(get<1>(tuple)) == 0)
            return get<0>(tuple);                 
    }
}

string retorna_valor(string label){

    if(!verifica_declaracao(label))
        erro_nao_declaracao(label);

    for(auto& tuple: vetor_variaveis) {
        if(label.compare(get<1>(tuple)) == 0)
            return get<3>(tuple);                 
    }
}

string retorna_tipo(string label){

    if(!verifica_declaracao(label))
        erro_nao_declaracao(label);

    for(auto& tuple: vetor_variaveis) {
        if(label.compare(get<1>(tuple)) == 0)
            return get<0>(tuple);                 
    }
}

void verifica_compatibilidade(string tipo, string tipo1){

    for(int i = 0; i < NUM_LINHAS; i++){

            if(tipo.compare(matriz_tipos[i][0]) == 0){

                if( (tipo1.compare(matriz_tipos[i][1]) == 0 || (tipo1.compare(matriz_tipos[i][2]) == 0))){
                    return;
                }

            }
    }    

    cout<<"ERRO! Tipos incompatíveis para operação. "<<tipo<<" != "<<tipo1<<endl;
    exit(0);
    
}

int tipos_iguais(string tipo1, string tipo2){
    if(tipo1.compare(tipo2) == 0)
        return 1;
    return 0;
}

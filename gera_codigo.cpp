#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>    
#include <tuple>
#include  "cabecalhos.h"
#include "tabela_tipos.h"

void gera_codigo_declaracao_atribuicao(atributos& ss, atributos s1, atributos s2, atributos s4){

        string valor;
        verifica_compatibilidade(s1.tipo, s4.tipo);

        if(!verifica_declaracao(s2.label)){

                if(s1.tipo != s4.tipo){
                    
                    valor = conversao_atribuicao(s1.tipo, s4.label); // cria uma nova temp pra salvar a converte do valor
                    ss.traducao = "\t" + s4.traducao + valor +"\t" +s2.label + " = " + retorna_nome_temp(s1.tipo, 0) +";\n\n";
                    cria_variavel(s1.tipo, s2.label, s4.valor);
                }
                else{
                    cria_variavel(s1.tipo, s2.label,s4.valor);
                    ss.traducao = "\t"+ s4.traducao + "\t" + s2.label + " = " + s4.label + ";\n";
                }
        }
}


void gera_codigo_atribuicao(atributos &ss, atributos s1, atributos s3){

        string valor, tipo1 = retorna_tipo(s1.label);

        verifica_compatibilidade(tipo1, s3.tipo);
        if(!verifica_declaracao(s1.label))
            erro_nao_declaracao(s1.label);

        if(tipo1 != s3.tipo){
            
            valor = conversao_atribuicao(tipo1, s3.label); // cria uma nova temp pra salvar a converte do valor
            ss.traducao = '\t'+ s3.traducao + "\n" + valor +"\t" + s1.label + " = " + retorna_nome_temp(tipo1, -1) +";\n\n";
            atualiza_valor(s1.label, s1.tipo, s3.valor);
        }
        else{
            atualiza_valor(s1.label, s3.tipo, s3.valor);
            ss.traducao = "\t" + s3.traducao + "\t" + s1.label + " = " + s3.label + ";\n";
        }  
}


void gera_codigo_declaracao(atributos &ss, atributos s1, atributos s2){

    if(verifica_declaracao(s2.label))
        erro_declaracao(s2.label);
    
    ss.traducao = "\t" + cria_variavel(s1.tipo, s2.label, string("0")) + ";\n";
}

void gera_codigo_operacao(atributos &ss, atributos s1, string operacao, atributos s3){
    
        verifica_compatibilidade(s1.tipo, s3.tipo);
        ss.valor = calc(s1.valor, s3.valor, operacao);
        ss.label = retorna_nome_temp(s1.tipo, 0);
        ss.tipo = s1.tipo; 
        
        if(!tipos_iguais(s1.tipo, s3.tipo)){

            string aux = prioridade(s1.tipo, s3.tipo);
            ss.tipo = aux;
            ss.traducao = conversao(s1.tipo, s1.label, s1.valor, s1.traducao, s3.tipo, s3.label, s3.valor, s3.traducao, aux, operacao);
            ss.label = retorna_nome_temp(aux, -1);
        }
        else
            ss.traducao = s1.traducao +  "\n" + s3.traducao + "\n" + cria_temporaria(s1.label +" "+ operacao + " " + s3.label, s1.tipo);    
}

void gera_codigo_operacao_logica(atributos &ss, atributos s1, atributos s2, atributos s3){

        verifica_compatibilidade(s1.tipo, s3.tipo);

        ss.label = retorna_nome_temp("bool", 0); 
        ss.valor = calc(s1.valor, s3.valor, s2.traducao);
        ss.tipo = "bool"; 
        ss.traducao = s1.traducao +  "\n" + s3.traducao + "\n" + cria_temporaria(s1.label + s2.traducao + s3.label, ss.tipo);
}
void gera_codigo_operacao_logica2(atributos &ss, atributos s1, atributos s3){

        ss.label = retorna_nome_temp("bool", 0); 
        ss.valor = calc(s3.valor,string(" "), s1.traducao);
        ss.tipo = "bool";
        ss.traducao = s3.traducao +"\n" + cria_temporaria(s1.traducao + s3.label, ss.tipo);
}


void gera_codigo_conversao(atributos &ss, atributos s1, atributos s3){
        
        verifica_compatibilidade(s1.tipo, s3.tipo);
        ss.label = retorna_nome_temp(s1.tipo, 0);
        ss.traducao = conversao_atribuicao(s1.tipo, s3.label);
        ss.tipo = s1.tipo;
        ss.valor = to_string(atoi((s3.valor).c_str()) );
}


void sobe_valor(atributos &ss, atributos s1){
    
    ss.traducao = s1.traducao;
    ss.tipo = s1.tipo;
    ss.valor = s1.valor; 
    ss.label = s1.label;
}

void sobe_valor_terminal(atributos &ss, atributos s1){
    ss.traducao = " ";
    ss.tipo = s1.tipo;
    ss.valor = s1.valor; 
    ss.label = s1.valor;
}

void sobe_valor_id(atributos &ss, atributos s1){
    ss.traducao = " ";
    ss.tipo = s1.tipo;
    ss.valor = retorna_valor(s1.label); 
    ss.label = s1.valor;
}
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// variavel
typedef struct variavel
{
	string tipo;
	string var_name;
	string temp_name;

	// usando pra fazer o cast de steing to char*
	int tamanho;

} variavel;

// tabela de variaveis
typedef map <string, variavel> Var_table;

typedef struct maps
{
	vector< Var_table > variaveis_map;
	int escopo_num;
} maps;

void pushEsc(maps *tack, Var_table mapEsc){

	tack->variaveis_map.push_back(mapEsc);
	tack->escopo_num += 1; // somando um pra indicar que adicionei e fui pro proximo escopo, 0 = global

}

Var_table popEsc(maps *tack)
{
	if(tack->variaveis_map.empty()){
		cout << "Sem escopo pra remover :(" <<endl;
		exit(0);
	}

	// se tiver o que remover
	Var_table esc = tack->variaveis_map.back();
	tack->variaveis_map.pop_back();
	tack->escopo_num -= 1;

	return esc;
}

variavel criarVar(string nome, string temp_nome, string tipo, int tamanho){
	
	variavel var;
	var.tipo = tipo;
	var.var_name = nome;
	var.temp_name = temp_nome;
	var.tamanho = tamanho;

	return var;
}

maps* criarMaps(){

	maps *tack = (maps*) malloc(sizeof(maps));

	Var_table esc;

	pushEsc(tack, esc);
	// voltando pro escopo global, ja que a push adiciona 1 em escopo_num
	tack->escopo_num = 0;

	return tack;
}

void addVarEsc(maps *tack, variavel var){

	tack->variaveis_map[tack->escopo_num][var.var_name] = var;
}

void addVarEscGlobal(maps *tack, variavel var){

	tack->variaveis_map[0][var.var_name] = var;
}

typedef std::vector<variavel> varsDeclaradas;

string getDeclaradas(varsDeclaradas vars){
	
	string line = "";
	string line_int = "int";
	string line_float = "float";
	string line_char = "char";
	string line_bool = "bool";
	string line_string = "";

	int i_int, i_float, i_char, i_bool, i_string = 0;

	for (int i = 0; i < vars.size(); ++i)
	{
		variavel v = vars[i];

		if (v.tipo == "string")
		{
			line += "char* " + v.temp_name + " = (char*) malloc(sizeof(char) * " + to_string(v.tamanho) + " ); \n";
			i_string = 1;
		}
		if(v.tipo == "int"){
		
			line_int += " " + v.temp_name + ",";
			i_int = 1;

		}
		else if(v.tipo == "float"){
		
			line_float += " " + v.temp_name + ",";
			i_float = 1;

		}
		else if(v.tipo == "char"){
		
			line_char += " " + v.temp_name + ",";
			i_char = 1;

		}
		else if(v.tipo == "bool"){
			
			line_int += " " + v.temp_name + ",";
			i_int = 1;
			// line_bool += " " + v.temp_name + ",";
			// i_bool = 1;

		}

	}

	if (i_int == 1)
	{
		line_int.pop_back();
		line_int += ";\n";
		line += line_int;
	}
	if (i_float == 1)
	{
		line_float.pop_back();
		line_float += ";\n";
		line += line_float;
	}
	if (i_char == 1)
	{
		line_char.pop_back();
		line_char += ";\n";
		line += line_char;
	}
	// if (i_bool == 1)
	// {
	// 	line_bool.pop_back();
	// 	line_bool += ";\n";	
	// 	line += line_bool;
	// }
	

	return line;
}
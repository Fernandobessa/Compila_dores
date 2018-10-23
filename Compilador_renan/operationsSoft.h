	using namespace std;

	int yylex(void);
	void yyerror(string);

	static int vars = 0;
	static int temps = 0;
	static int loops = 0;
	static int jumps = 0;
	static int vectors = 0;
	static int switches = 0;
	static int parameters = 0;
	static int lines = 1;

	typedef struct atributos
	{
		string label;
		string nome;
		string traducao;
		string var_tipo;
		string valor;
		string cast;
		string op;
	}ATR;

	typedef struct var{
		string type;
		string name;
		string value;
		string id;
	}VAR;

	typedef struct vectors{
		string name;
		string type;
		string id;
		string row;
		string column;
	}VECTORS;

	typedef struct fun{
		string name;
		string type_return;
		string name_return;
		string body;
		struct fun* next;
		vector <VAR> map_parameters;
		vector <VECTORS> map_vectors;
		vector <VAR> map_vars;
	}FUN;

	vector <VAR> vec_att;
	vector <VAR> params;
	stack <FUN> pilha;
	vector <FUN> funs;
	FUN* first_exestack;
	string declaracoes_globais;
	int main_called = 0;

	string create_var_names();
	string create_temp_names();
	string create_loop_names();
	string create_jump_names();
	string create_vectors_names();
	string create_switch_names();
	string create_param_names();
	string format_boolean(ATR* $$);
	string to_string(int num);
	string in_line();
	VAR* get_var(string name);
	VECTORS* get_vector(string name);
	void set_var(string type, string name, string value, string id);
	void set_vector(string type, string name, string row, string column, string id);
	void explicit_cast(ATR* $$, string type_cast);
	void implicit_cast(ATR* v1, ATR* v2, ATR* var_op);
	void implicit_return(ATR* v, ATR* r);
	void implicit_string(ATR* v1, ATR* v2, ATR* vop);
	bool search_var(string name);
	void print_stack();
	void format_variable(ATR* $$);
	void format_declarations(ATR* $$);
	void free_all(ATR* $$);
	void error_range(string index, string row, string column);

	void explicit_cast(ATR* $$, string type_cast){
		if($$->var_tipo == "bool") yyerror(in_line() + "Booleano não pode ser convertido para outros tipos");
		if(type_cast == "bool") yyerror("Tipos não podem ser convertidos para booleanos");

		ATR new_atr;
		new_atr.label = create_temp_names();

		if(type_cast == "(float)"){
			new_atr.var_tipo = "float";
			new_atr.valor = "(float)"+$$->label;
		} else if (type_cast == "(char)"){
			new_atr.var_tipo = "char";
			new_atr.valor = "(char)"+$$->label;
		} else{
			new_atr.var_tipo = "int";
			new_atr.valor = "(int)"+$$->label;
		}
		//Retirei o \n de new_atr
		new_atr.traducao = "\t" + new_atr.label + " = " + new_atr.valor + ";\n";
		$$->traducao = new_atr.traducao;
		$$->label = new_atr.label;
		$$->var_tipo = new_atr.var_tipo;
		set_var(new_atr.var_tipo, "temp", new_atr.valor, new_atr.label);
	}

	void implicit_cast(ATR* v1, ATR* v2, ATR* var_op){
		if((v1->var_tipo == "bool" && v2->var_tipo != "bool") || (v2->var_tipo == "bool" && v1->var_tipo != "bool")){
			yyerror("Conversão não permitida para o tipo booleano");
		}

		if(var_op->op == "+" || var_op->op == "-" || var_op->op == "*" || var_op->op == "/"){
			if(v1->var_tipo == "int" && v2->var_tipo != "int"){
				explicit_cast(v1, "("+v2->var_tipo+")");
				var_op->var_tipo = v2->var_tipo;
				var_op->traducao = var_op->traducao + v1->traducao;
			} else if(v1->var_tipo != "int" && v2->var_tipo == "int"){
				explicit_cast(v2, "("+v1->var_tipo+")");
				var_op->var_tipo = v1->var_tipo;
				var_op->traducao = var_op->traducao + v2->traducao;
			} else if(v1->var_tipo == "float" && v2->var_tipo == "char"){
				explicit_cast(v2, "("+v1->var_tipo+")");
				var_op->var_tipo = v1->var_tipo;
				var_op->traducao = var_op->traducao + v2->traducao;
			} else if(v1->var_tipo == "char" && v2->var_tipo == "float"){
				explicit_cast(v1, "("+v2->var_tipo+")");
				var_op->var_tipo = v2->var_tipo;
				var_op->traducao = var_op->traducao + v2->traducao;
			}
		} else if (var_op->op == "==" || var_op->op == "!=" || var_op->op == "<=" || var_op->op == ">=" || var_op->op == "<" || var_op->op == ">"){
			if(v1->var_tipo == "int" && v2->var_tipo != "int"){
				explicit_cast(v1, "("+v2->var_tipo+")");
				var_op->traducao = var_op->traducao + v1->traducao;
			} else if (v1->var_tipo != "int" && v2->var_tipo == "int"){
				explicit_cast(v2, "("+v1->var_tipo+")");
				var_op->traducao = var_op->traducao + v2->traducao;
			} else if (v1->var_tipo == "float" && v2->var_tipo == "char"){
				explicit_cast(v2, "("+v1->var_tipo+")");
				var_op->var_tipo = v1->var_tipo;
				var_op->traducao = var_op->traducao + v2->traducao;
			} else if (v1->var_tipo == "char" && v2->var_tipo == "float"){
				explicit_cast(v1, "("+v2->var_tipo+")");
				var_op->var_tipo = v2->var_tipo;
				var_op->traducao = var_op->traducao + v2->traducao;
			}
		}
	}

	void implicit_string(ATR* v1, ATR* v2, ATR* vop){
		ATR new_atr;
		new_atr.label = create_temp_names();
		new_atr.var_tipo = "string";

		vop->var_tipo = "string";

		if(v1->var_tipo == "string" && v2->var_tipo != "string"){
			int tam = v2->valor.size();
			new_atr.traducao = "\t" + new_atr.label + " = (char*)malloc(" + to_string(tam) + "*sizeof(char));\n";
			new_atr.traducao += "\tstrcpy( " + new_atr.label + ",to_string(" + v2->valor + "));\n";
			set_var(new_atr.var_tipo, "temp", new_atr.valor, new_atr.label);
			vop->traducao += new_atr.traducao;
		} else if (v1->var_tipo != "string" && v2->var_tipo == "string"){
			int tam = v1->valor.size();
			new_atr.traducao = "\t" + new_atr.label + " = (char*)malloc(" + to_string(tam) + "*sizeof(char));\n";
			new_atr.traducao += "\tstrcpy(" + new_atr.label + ",to_string(" + v1->valor + "));\n";
			set_var(new_atr.var_tipo, "temp", new_atr.valor, new_atr.label);
			vop->traducao += new_atr.traducao;
		}

		int t1, t2, total;

		if(v1->var_tipo == "string"){
			t1 = v1->valor.size()-2;
		} else{
			t1 = v1->valor.size();
		}

		if(v2->var_tipo == "string"){
			t2 = v2->valor.size()-2;
		} else{
			t2 = v2->valor.size();
		}

		total = t1+t2;

		vop->var_tipo = "string";
		vop->traducao += "\t" + vop->label + " = (char*)malloc(" + to_string(total) + "*sizeof(char));\n";
		vop->traducao += "\tstrcat(" + vop->label + "," + v1->label + ");\n";
		vop->traducao += "\tstrcat(" + vop->label + "," + v2->label + ");\n";
	}

	void implicit_return(ATR* v, ATR* r){
		if(v->var_tipo == "string" && r->var_tipo != "string"){
			string temp = r->traducao;
			ATR new_atr;
			new_atr.label = create_temp_names();
			new_atr.var_tipo = "char*";
			int tam = r->valor.size();
			new_atr.traducao = "\t" + new_atr.label + " = (" + new_atr.var_tipo + ")malloc(" + to_string(tam) + "*sizeof(char));\n";
			new_atr.traducao += "\tstrcpy(" + new_atr.label + ",to_string(" + r->valor + "));\n";
			set_var(new_atr.var_tipo, "temp", new_atr.valor, new_atr.label);
			r->label = new_atr.label;
			r->traducao += new_atr.traducao;
		} else if (v->var_tipo != "string" && r->var_tipo == "string"){
			/*ATR new_atr;*/
			/*new_atr.label = create_temp_names();*/
			/*new_atr.var_tipo = "int";*/
			/*new_atr.valor = r->valor.size();*/
			/*explicit_cast(r, "("+v->var_tipo+")");*/
		} else if((v->var_tipo == "int" && r->var_tipo != "int") || (v->var_tipo != "int" && r->var_tipo == "int")){
			string temp = r->traducao;
			explicit_cast(r, "("+v->var_tipo+")");
			r->traducao = temp + r->traducao;
		} else if (v->var_tipo == "float" && r->var_tipo == "char"){
			string temp = r->traducao;
			explicit_cast(r, "("+v->var_tipo+")");
			r->traducao = temp + r->traducao;
		} else if (v->var_tipo == "char" && r->var_tipo == "float"){
			string temp = r->traducao;
			explicit_cast(r, "("+v->var_tipo+")");
			r->traducao = temp + r->traducao;
		} else if ((v->var_tipo != "bool" && r->var_tipo == "bool") || (v->var_tipo == "bool" && r->var_tipo != "bool")){
			yyerror("Variáveis booleanas apenas aceitam booleanas");
		}
	}

	VECTORS* get_vector(string name){
		FUN* temp = &pilha.top();

		if(pilha.size() > 1){
			for( ; temp; temp = temp->next){
				for(int i=0; i<temp->map_vectors.size(); i++){
					if(temp->map_vectors[i].name == name && temp->map_vectors[i].column == "0") return &temp->map_vectors[i];
				}
			}
		} else{
			for(int i=0; i<temp->map_vectors.size(); i++){
				if(temp->map_vectors[i].name == name && temp->map_vectors[i].column == "0") return &temp->map_vectors[i];
			}
		}

		return NULL;
	}

	VECTORS* get_matrix(string name){
		FUN* temp = &pilha.top();

		if(pilha.size() > 1){
			for( ; temp; temp = temp->next){
				for(int i=0; i<temp->map_vectors.size(); i++){
					if(temp->map_vectors[i].name == name && temp->map_vectors[i].column != "0"){
						//cout << "entrou" << endl;
						return &temp->map_vectors[i];
					} 
				}
			}
		} else{
			for(int i=0; i<temp->map_vectors.size(); i++){
				if(temp->map_vectors[i].name == name && temp->map_vectors[i].column != "0") return &temp->map_vectors[i];
			}
		}

		return NULL;
	}

	VAR* get_var(string name){
		FUN* temp = &pilha.top();

		if(pilha.size() > 1){
			for( ; temp; temp = temp->next){
				for(int i=0; i<temp->map_vars.size(); i++){
					if(temp->map_vars[i].name == name) return &temp->map_vars[i];
				}
			}
		} else{
			for(int i=0; i<temp->map_vars.size(); i++){
				if(temp->map_vars[i].name == name) return &temp->map_vars[i];
			}
		}

		return NULL;
	}

	FUN* get_function(string name){
		for(int i=0; i<funs.size(); i++){
			if(name == funs[i].name) return &funs[i];
		}

		return NULL;
	}

	void set_vector(string type, string name, string row, string column, string id){
		VECTORS new_vector;

		new_vector.type = type;
		new_vector.name = name;
		new_vector.id = id;
		new_vector.row = row;
		new_vector.column = column;

		if(pilha.size() > 1){
			VECTORS temp_vector;
			temp_vector.type = type;
			temp_vector.name = "vec_temp";
			temp_vector.id = id;
			temp_vector.row = row;
			temp_vector.column = column;
			first_exestack->map_vectors.push_back(temp_vector);
		}
		
		pilha.top().map_vectors.push_back(new_vector);
	}

	void set_var(string type, string name, string value, string id){
		VAR new_atr;

		new_atr.type = type;
		new_atr.name = name;
		new_atr.id = id;
		new_atr.value = value;

		if(pilha.size() > 1){
			VAR temp_atr;
			temp_atr.type = type;
			temp_atr.name = "temp";
			temp_atr.id = id;
			temp_atr.value = value;
			first_exestack->map_vars.push_back(temp_atr);
		}

		pilha.top().map_vars.push_back(new_atr);
	}

	void set_parameters(string type, string name, string value, string id){
		VAR new_atr;

		new_atr.type = type;
		new_atr.name = name;
		new_atr.id = id;
		new_atr.value = value;

		pilha.top().map_parameters.push_back(new_atr);
	}

	void set_vars_functions(FUN* function){
		if(function->type_return == "none"){

		} else{

		}
	}

	bool search_var(string name){
		FUN* temp = &pilha.top();

		for(int i = 0; i < temp->map_vars.size(); i++){
			if(temp->map_vars[i].name == name) return true;
		}

		return false;
	}

	void print_stack(){
		FUN* temp = &pilha.top();

		cout << "Tipo" << "\t" << "Nome" << "\t" << "Valor" << "\t" << "ID" << endl;

		for(int i=0; i<temp->map_vars.size(); i++){
			cout << temp->map_vars[i].type << "\t" << temp->map_vars[i].name << "\t" << temp->map_vars[i].value << "\t" << temp->map_vars[i].id << endl;
		}
	}

	string format_boolean(ATR* $$){
		if($$->var_tipo == "bool"){
			string format = "int";

			return format;
		}else{
			return $$->var_tipo;
		}
	}

	void format_variable(ATR* $$){
		if($$->var_tipo == "string"){
			int tam = $$->valor.size();
			$$->traducao = "\t" + $$->label + " = (char*)malloc(" + to_string(tam-1) + "*sizeof(char));\n";
			$$->traducao += "\tstrcpy(" + $$->label + "," + $$->valor + ");\n";
 		} else{
			$$->traducao = "\t" + $$->label + " = " + $$->valor + ";\n";
		}
	}

	void format_declarations(ATR* $$){
		FUN* temp = first_exestack;
		string total_declarations;

		for(int i=0; i<temp->map_vars.size(); i++){
			if(temp->map_vars[i].type == "bool"){
				string tipo_bool = "int";
				total_declarations += "\t" + tipo_bool + " " + temp->map_vars[i].id + ";\n";
			} else if (temp->map_vars[i].type == "string"){
				string tipo_string = "char*";
				total_declarations += "\t" + tipo_string + " " + temp->map_vars[i].id + ";\n";
			} else if (temp->map_vars[i].type == "none"){
				continue;
			} else{
				total_declarations += "\t" + temp->map_vars[i].type + " " + temp->map_vars[i].id + ";\n";
			}
		}
		
		for(int i=0; i<temp->map_vectors.size(); i++){
			total_declarations += "\t" + temp->map_vectors[i].type + "*" + " " + temp->map_vectors[i].id + ";\n";
		}

		$$->traducao = total_declarations + "\n" + $$->traducao;
	}

	void free_all(ATR* $$){
		string total_free;
		FUN* temp = &pilha.top();

		for(int i = 0; i<temp->map_vars.size(); i++){
			if(temp->map_vars[i].type == "string"){
				total_free += "\tfree(" + temp->map_vars[i].id + ");\n";
			}
		}

		$$->traducao += total_free;
	}

	void error_indextype(string indexType){
		if(indexType != "int") yyerror(in_line() + " Índice só trabalha com Inteiros =/");
	}

	void error_slicers(int i1, int i2, int limit){
		if(i1 > i2){
			yyerror(in_line() + " Primeiro índice da função slice é maior que seu limite.");
		} else if (i2 > limit){
			yyerror(in_line() + " Índice da matriz/vetor ultrapassado!");
		} else if(i1 < 0 || i2 < 0){
			yyerror(in_line() + " Só trabalhamos com índice positivo =/");
		}
	}

	string in_line(){
		string error = "\"Erro na Linha" + to_string(lines) + " : \" ";
		return error;
	}

	string to_string(int num){
		ostringstream temp;
		temp << num;
		return temp.str();
	}

	string create_var_names(){
		string var = "var_"+to_string(vars);
		vars++;
		return var;
	}

	string create_temp_names(){
		string temp = "temp"+to_string(temps);
		temps++;
		return temp;
	}

	string create_loop_names(){
		string loop = "loop"+to_string(loops);
		loops++;
		return loop;
	}

	string create_jump_names(){
		string jump = "jump"+to_string(jumps);
		jumps++;
		return jump;
	}

	string create_vectors_names(){
		string vec = "vec"+to_string(vectors);
		vectors++;
		return vec;
	}

	string create_switch_names(){
		string swt = "switch"+to_string(switches);
		switches++;
		return swt;
	}

	string create_param_names(){
		string param = "param"+to_string(parameters);
		parameters++;
		return param;
	}
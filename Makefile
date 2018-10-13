all: 	
		lex wlexica.l
		yacc -d wsintatica.y
		g++ -std=c++11 -o winter_compile y.tab.c tabelas/*.cpp -ll
	
		./winter_compile < exemplo.winter
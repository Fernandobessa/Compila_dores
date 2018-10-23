
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

int main (){


	int temp0;
	int var_0;
	int temp1;
	int temp3;
	int temp4;
	int temp5;
	int temp6;


	var_0 = 4;


	temp1 = var_0;
	loop0:
	temp1 = temp1 - 1;
	var_0 *= temp1;
	if(temp1 != 1) goto loop0;

	cout << "O valor usando fatorial é: " << var_0 << endl;

	temp3 = 3;

 	var_0 = temp3;

	temp4 = 3;

	temp5 =  1;
	temp6 = var_0;
	loop1:
	var_0 = var_0 * temp6;
	temp5 = temp5+ 1;
	if(temp5<temp4) goto loop1;
	cout << "O valor usando expoente é: " << var_0 << endl;


	return 0;
}

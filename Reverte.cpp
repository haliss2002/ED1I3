#include <locale.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	string str = "", strsemespaco = "", strinversa = "";
	char vazio = ' ';
	int size, i = 0;
	int semespaco;
	cout << "Digite uma frase: ";
	getline(cin, str);

	for (i = 0; i <= str.size() - 1; ++i )
	{
		if(str.at(i) != vazio)
		{
			strsemespaco += str.at(i);
		}
	}
	
	for (i = strsemespaco.size() - 1 ; i >= 0; i--)
	{
		strinversa += strsemespaco.at(i);
	}
	cout << ((strinversa == strsemespaco) ? ("A frase é palindromo") : ("A frase nao é palindromo"));

}

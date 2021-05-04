#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");

	ifstream arq("lista.txt");
	string nome, cover;
	int ultimo;
	string linha;
	if(arq.is_open())
	{
		while( getline(arq, linha))
		{
			cout << linha << endl;
			ultimo = nome.size();
			int space = linha.find_last_of(' ');
			nome = linha.substr(0, space);
			cover = linha.substr(space + 1, ultimo);
			cout << cover << ", " << nome.erase(8, 9) << (".") << endl;
		}
		arq.close();
	}
}




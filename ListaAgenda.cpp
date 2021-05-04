#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");

	ifstream arq("lista.txt");
	string name, midname;
	int last;
	string linha;
	if(arq.is_open())
	{		
		while( getline(arq, linha))
		{
			cout << linha << endl;
			last = name.size();
			int space = linha.find_last_of(' ');
			name = linha.substr(0, space);
			midname = linha.substr(space + 1, last);
			cout << midname << ", " << name << endl;
			cout << linha.erase(1, 2);
		}
		arq.close();
	}
	else
	{
		cout << "Não foi possível abrir o arquivo";
	}
}

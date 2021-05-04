#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;

void gotoxy(short x, short y)
{
	COORD coord={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(int argc, char** argv)
{    int linha=0;
	string msg="";
	setlocale(LC_ALL, "");
	cout <<"------digite uma mensagem" << endl;
	cin>>msg;
	int y=5;
	int x=55;

while(y<20){ 
	if(linha>=msg.size())
	{
		y=21;
		cout<<"      "<<msg;
	}
	else
	{
	gotoxy(x,y);
	cout<<msg[linha];
	linha++;
	y++;
	x++;	
	}
}
	return 0;
}
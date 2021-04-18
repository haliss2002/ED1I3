#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#define FIL 16
#define POT 40

int main(int argc, char** argv)
{
	int i;
	int j;
	int k;
	int respo;
	int fila;
	int pote;
	double total;
	respo=9;
	// Declaração do array
	int **mat;
	
		mat = (int**)malloc(FIL * sizeof(int));
	
	for(i=1; i<FIL; ++i) // Percorre as linhas
	{
		mat[i] = (int*)malloc(POT * sizeof(int)); // Inicialização de cada coluna
	}
	// Fim da declaração do array
	
	for(i=1; i<FIL; ++i)
	{
		for(j = 1; j<POT; ++j)
		{
			mat[i][j] = 1;
		}
	}
	
	while(respo!=0)
	{
cout <<""<< endl;
	cout << "0.	Finalizar"<<endl;
cout << "1.	Reservar poltrona"<<endl;
cout << "2.	Mapa de ocupação"<<endl;
cout << "3.	Faturamento"<<endl;
cin >> respo;
cout <<""<< endl;
if(respo==2)
{	
	k = 0;
	for(int i=0; i<FIL; ++i)
	{
		for(int j = 1; j<POT; ++j)
		{if(mat[i][j] == 1)
		{
		cout  <<" . " << " | ";	
		}
		else
		{
		cout  <<" # " << " | ";
		}	
		}
		cout << endl;
		cout << endl;
	};	
	cout << "=======================" << endl;
	}
else if(respo==1)
{
  cout<<"Qual a fileira da pontrona desejada: ";	
  cin >>fila;
  cout<<"Qual o numero da pontrona desejada: ";	
  cin >>pote;

   if(fila<=0 || pote<=0 || fila>15 || pote>40){
	cout <<""<< endl;
	  cout<<"Por favor escolha uma fileira entre 1 e 15;-;"<< endl;
	  cout<<"Por favor escolha uma pontrona entre 1 e 40;-;"<< endl;
	  cout <<""<< endl;	
	}
	else{
	  if(mat[fila][pote]==1)
       {
	    mat[fila][pote]=0;
	      if(fila>=1&&fila<=5)
		  {
			total+=50;
		  }
		  else if(fila>=6&&fila<=10)
		  {
			 total+=30; 
		  }
		  else 
		  {
			 total+=15; 
		  }  
	   }
      else
       {
     	cout <<""<< endl;
	    cout<<"JA ocupada"<< endl;
	    cout <<""<< endl;
       }
   }   
}
else if(respo==3)
{
	cout  <<"total: R$ "<<total;
}
else if(respo==0)
{
}
else
{
	cout <<""<< endl;
cout  <<"Por favor digite um valor valido";	
cout <<""<< endl;	
}
	}
	return 0;
}
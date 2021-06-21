#include <iostream>
using namespace std;

#define MAX 30

struct Pilha{
	int qtde;
	int elementos[MAX];
	int par;
	int impar;
};

Pilha* init(){
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
}

int push(Pilha *p, int v){
	int podeEmpilhar = (p->qtde < MAX);
	int podeEmpilhar1=(p->elementos[p->qtde-1] < v);
	if(podeEmpilhar){
		if(podeEmpilhar1||p->qtde==0){
			p->elementos[p->qtde++] = v;
			do{
		      v=v-2;
	          }	while(v>=3);	
   	          if(v!=2){
	          	p->impar++;
                      }
	          else{
	          	p->par++;
                    	}
		}		
	}

	return podeEmpilhar;
}

int isEmpty(Pilha *p){
	return (p->qtde == 0);
}

void print(Pilha *p){
	for(int i=p->qtde-1; i>=0; --i){
		cout << p->elementos[i] << endl;
	}
	cout << "------------------" << endl;
}

int main(int argc, char** argv)
{
	Pilha *pilhaFloat;
	pilhaFloat = new Pilha;
	pilhaFloat = init();
	int nume;
	
	do{
		cout << "Digite um numero e depois uma maior ate 30 numeros" << endl;
		cin >> nume;
		push(pilhaFloat, nume);
	}while(pilhaFloat->qtde!=30);	
	
	print(pilhaFloat);
	
	
	
	
	return 0;
}
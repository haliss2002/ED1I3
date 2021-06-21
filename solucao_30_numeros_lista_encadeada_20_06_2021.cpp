#include <iostream>
using namespace std;

struct No {
	int dado;
	int par;
	int impar;
	struct No *prox;
};

struct Pilha {
	No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

void push(Pilha *p, int v) {
	No *no = new No;	
		no->dado = v;
      	no->prox = p->topo;
     	p->topo = no;
     		do{
		      v=v-2;
	          }	while(v>=3);	
   	          if(v!=2){
	          	no->impar++;
                      }
	          else{
	          	no->par++;
                    	}
	
	
}


void print(Pilha* p) {
	No* n;
	n = p->topo;
	while (n != NULL) {
		cout << n->dado << endl;
		n = n->prox;
	}
	cout << "--------------------" << endl;
}

int count(Pilha* p) {
	int i = 0;
	No* n;
	n = p->topo;
	while (n != NULL) {
		i++;
		n = n->prox;
	}
	return i;
}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

void freePilha(Pilha *p) {
	No *n = p->topo;
	while(n != NULL) {
		No *t = n->prox;
		free(n);
		n = t;
	}
	free(p);
}

int main(int argc, char** argv)
{
	Pilha *pilhaFloat;
	pilhaFloat = init();
	int nume;
	push(pilhaFloat, 0);
	do{
		
	cout << "digite os 30 numeros em ordem crescente" << endl;
    cin >> nume;
    	
	if(pilhaFloat->topo->dado < nume)
	{
			push(pilhaFloat, nume);
	}
	}while(count(pilhaFloat)!=31);
	
	cout << "Qtde elementos na pilha: " << count(pilhaFloat) << endl;
	
	print(pilhaFloat);
	
	
	
	return 0;
}
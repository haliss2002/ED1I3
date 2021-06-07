#include <iostream>
using namespace std;

struct Lista
{
	int prontuario;
	string nome;
	double salario;	
	struct Lista *prox;
};

Lista* init()
{
	return NULL;
}

int isEmpty(Lista* lista)
{
	return (lista==NULL);	
}

Lista* find(Lista* lista,int i)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL && aux->prontuario != i)
    {
		aux = aux->prox;
	}
	return aux;
}


Lista* insert(Lista* lista, int i, string x, double y)
{
	Lista * procurado = find(lista,i);
	if(procurado != NULL)
	{
		cout<<"Prontuario: "<<procurado->prontuario<<" ja cadastrado"<<endl;
	}
	else
	{
    Lista* novo = new Lista();
	novo->prontuario = i;
	novo->nome = x;
	novo->salario = y;
	novo->prox = lista;
	return novo;
	}	
}

void print(Lista* lista)
{
	Lista *aux;
	aux = lista;
	double total=0;
	while(aux != NULL)
	{
		cout<<"Prontuario: "<<aux->prontuario<<endl;
		cout<<"Nome : "<<aux->nome<<endl;
		cout<<"Salario : "<<aux->salario<<endl;
		total=total+aux->salario;
		cout<<endl;
		aux = aux->prox;		
	}
	cout<<endl;
	cout<<"Total dos Salarios: "<<total<<endl;
	
}

Lista* remove(Lista* lista, int i)
{
	Lista *aux;
	Lista *ant = NULL;
	aux = lista;
	while(aux != NULL && aux->prontuario != i)
	{
		ant = aux;
		aux = aux->prox;
	}
	if (aux==NULL)
	{
		return lista;
	}
	if(ant = NULL)
	{
		aux = aux->prox;
	}
	else
	{
			ant->prox = aux->prox;
	}
	return lista;
}

int main(int argc, char** argv)
{
	int escolhe;
do{	
	cout<<endl;
    cout<<"---------"<<endl;
	cout<<"Menu"<<endl;
	cout<<"0. Sair"<<endl;
	cout<<"1. Incluir"<<endl;
	cout<<"2. Excluir"<<endl;
	cout<<"3. Pesquisar"<<endl;
	cout<<"4. Listar"<<endl;
	cout<<"---------"<<endl;
	cout<<endl;
	cin>>escolhe;
	Lista *minhaLista;
	minhaLista = init();
	if(escolhe==0)
	{
		cout<<"Fim da Execução"<<endl;
	}
    else if(escolhe==1)
    {
    cout<<endl;
    cout<<"Digite o Prontuario, Nome e Salario do Funcionario"<<endl;
    int x1 = 0;
    double x3 = 0;
    string x2= "";
    cin>>x1;
    cin>>x2;
    cin>>x3;
	minhaLista = insert(minhaLista, x1,x2,x3);	
	}
	else if(escolhe==2)
    {
 	  cout<<endl;
 	  int x4;
      cout<<"Digite o Prontuario do Funcionario Que deseja Excluir"<<endl;
      cin>>x4;
      minhaLista = remove(minhaLista,x4);

	}
	else if(escolhe==3)
    {
	   cout<<endl;
 	   int x4;
       cout<<"Digite o Prontuario do Funcionario Que deseja Pesquisar"<<endl;
       cin>>x4;
	   Lista * procurado = find(minhaLista,x4);	
       if(procurado !=NULL)
     	{
           cout<<endl;
	       cout << "Funcionario encontrado" << endl;
	       cout <<"Prontuario: "<< procurado->prontuario << endl;	
	       cout <<"Nome: "<< procurado->nome << endl;
	       cout <<"Salario: "<< procurado->salario << endl;
        }
       else
        {
		   cout<<"Funcionario nao encontrado"<<endl;
        }
	}
	else if (escolhe==4)
    {
		print(minhaLista);
	}
	else
	{
		cout<<"Comando invalido"<<endl;
	}
   }while(escolhe!=0);
	return 0;
}
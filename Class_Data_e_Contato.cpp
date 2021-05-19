#include <iostream>
using namespace std;
    
class Data
{
	private:
		int dia;
		int mes;
		int ano;
		
	public:
		Data(int dia, int mes, int ano)
		{
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}
		
		Data()
		{
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
		}
		
		void setDia(int dia)
		{
			this->dia = dia;
		}
		
		void setMes(int mes)
		{
			this->mes = mes;
		}

		void setAno(int ano)
		{
			this->ano = ano;
		}
		
		int getDia()
		{
			return this->dia;
		}
		
		int getMes()
		{
			return this->mes;
		}

		int getAno()
		{
			return this->ano;
		}
		
		string getData()
        {
 	        return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
        }
        
        Data* dia_seguinte()
        {
		    Data *d1;
			int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			
			d1 = new Data(this->dia, this->mes, this->ano);
			
			if (d1->ano % 4 == 0)
			{
				diasNoMes[1]++;
			}
			
			d1->dia++;
			if (d1->dia > diasNoMes[d1->mes-1])
			{
				d1->dia = 1;
				d1->mes++;
				if (d1->mes>12)
				{
					d1->mes = 1;
					d1->ano++;
				}
			}
			return d1; 
		}
        
};

class contato : Data{
	private:
	    string email;
	    string nome;
	    string telefone;
	    int dia;
		int mes;
		int ano;
    
   public:
		contato(string email,string nome,string telefone)
		{
			this->email = email;
			this->nome = nome;
			this->telefone = telefone;			
		}
	 
	    contato()
	    {
			this->email = "";
			this->nome = "";
			this->telefone = "";			
		}
		
		void setEmail(string email)
		{
			this->email = email;
		}
		
		void setNome(string nome)
		{
			this->nome = nome;
		}

		void setTelefone(string telefone)
		{
			this->telefone = telefone;
		}
		
		string getEmail()
		{
			return this->email;
		}
		
		string getNome()
		{
			return this->nome;
		}

		string getTelefone()
		{
			return this->telefone;
		}
		
		string idade()
        {
		    
			int anot =2021;			
        return(	anot - atoi(getAno()) );
		
			return d1; 
		}
		
		string getContato()
        {
 	        return "Email: "+this->email+" Nome: "+this->nome+" Telefone: " + this->telefone+"Idade: "+idade();
        }
};

int main(int argc, char** argv)
{
	string email,nome,telefone;
	data dtnasc;
	
	Data *hoje = new Data(4, 5, 2021);
	cout << hoje->getData() << endl;

	
	cout << endl;
	
	Data *datas[5];
	
	for(int i=0; i<5; ++i)
	{
		datas[i] = new Data(i+1, 5, 2021);
	}
	
	for(int i=0; i<5; ++i)
	{
		cout << "Dia: " << datas[i]->getData() << " - dia seguinte: " << datas[i]->dia_seguinte()->getData() << endl;
	}
	
	for(int i=0; i<5; ++i)
	{
		cout<<"digite o email,nome,telefone e data de nascimento do contato:"<<endl;
		cin>>email;
		cin>>nome;
		cin>>telefone;
		cin>>dia;
		cin>>mes;
		cin>>ano;
		contato *mostra = new contato(email,nome,telefone,dia,mes,ano);
		cout<<mostra->getContato()<<endl; 
		
		
	}
	return 0;
}

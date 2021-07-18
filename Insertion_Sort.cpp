#include <iostream>
using namespace std;

void print(int t, int *a) {
	for(int i=0; i<t; ++i) {
		cout << "Elemento: " << i << " = " << a[i] << endl;
	}
	cout << "-----------------" << endl;
}

void Insertion_Sort(int t, int *a) {
	int aux;
    int j;
    j=1;    
	while (j=t-1)
    {
     cout << "[" << j << "]: " << a[j] << ", [" << j+1 << "]: " << a[j+1];
			if (a[j] > a[j-1] && j>0) {
				aux = a[j];
				a[j] = a[j-1];
				a[j-1] = aux;
				cout << " - trocou!";
                --j;
			}
            else{
                --j;
            }
			cout << endl;
    }
}

int main(int argc, char** argv)
{
	int v[8] = {26, 49, 38, 13, 58, 87, 34, 93};
	print(8, v);
	Insertion_Sort(8, v);
	print(8, v);
	
	return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream arq;
    arq.open("maq.rcv", ios::out | ios::binary);
    int aux;
    int vet[10];
    for(int k=0;k<10;k++) vet[k] = rand()%1000;

    if(arq.is_open())
    {
        for(int k = 0;k<10;k++) arq.write((char *) &vet[k], sizeof(int));
        arq.close();
    }

    else cout << "Deu ruim!" << endl;

    arq.open("maq.rcv", ios::in | ios::binary);
    if(arq.is_open())
    {
        arq.read((char *) &aux, 4);
        cout << aux << endl;
        arq.seekg(0, ios::beg); // posiciona ponteiro zero bytes do inicio do arquivo
        arq.read((char *) &aux, 4);
        cout << aux << endl;
        arq.seekg(4*5, ios::beg);
        arq.read((char *) &aux, 4);
        cout << aux << endl;

    }
    else cout << "Deu ruim!" << endl;
    return 0;
}

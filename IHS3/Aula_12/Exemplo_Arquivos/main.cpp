#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream arq;
    string aux;
    int a, b;

    cout << "Digite um nome para o arquivo: ";
    cin >> aux;
    aux+=".txt";
    arq.open(aux, ios::out); // MODO: Escrita (texto)

    if (arq.is_open())
    {
        cout << "Digite um numero: ";
        cin >> a;
        cout << "Digite outro: ";
        cin >> b;

        arq << "O resultado de " << a << " + " << b << " eh " << a+b;

        arq.close();
    }
    else cout << "DEU RUIM" << endl;

    arq.open("mengo.txt", ios::in);
    if(arq.is_open())
    {
        arq >> aux;
        cout << aux << endl;
        arq >> aux;
        cout << aux << endl;
        getline(arq, aux);
        cout << aux << endl;
    }
    else cout << "DEU RUIM" << endl;
    return 0;
}

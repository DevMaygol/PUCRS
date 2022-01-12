#include <iostream>

using namespace std;

void le_inteiro(int *ptr)
{
    cout << "Digite um numero inteiro: ";
    // ptr++; esta apontando para o proximo endereço de memoria do inteiro
    cin >> *ptr;
}

void le_inteiro2(int &ref)
{
    cout << "Digite um numero inteiro: ";
    cin >> ref;
}

int main()
{
    int a = 0,b = 0, c = 0;
    le_inteiro(&a);
    le_inteiro(&b);
    le_inteiro2(c); // Atende para a sintaxe

    cout << "Valor de a lido: " << a << endl;
    cout << "Valor de b lido: " << b << endl;
    cout << "Valor de c lido: " << c << endl;
    return 0;
}

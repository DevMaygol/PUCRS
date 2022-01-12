#include <iostream>
#include <string>
using namespace std;

class contaBancaria
{
    public:
        float   saldo;
        float   limite;
        int     numero;
        string  titular;
        void printConta(void);
        void cadastraConta(void);
        void inicializaConta(float, float, int, string);
        void depositaConta (int, string);
        void sacaConta (float, float, int, string);
};

void contaBancaria::depositaConta(int conta, string no)
{
    numero = conta;
    titular = no;
}

void contaBancaria::inicializaConta(float s, float l, int n, string nome)
{
    saldo = s;
    limite = l;
    numero = n;
    titular = nome;
}
/*
void contaBancaria::cadastraConta(void)
{
    cout << "Digite seu nome: ";
    cin >> titular;
    cout << "Informe seu limite: ";
    cin >> limite;
    cout << "Digite o numero da conta: ";
    cin >> numero;
    cout << "Saldo: ";
    cin >> saldo;
}*/

void contaBancaria::printConta(void)
{
    cout << "Conta N: " << numero << endl;
    cout << "Titular: " << titular << endl;
    cout << "Saldo: "   << saldo << endl;
}

int main()
{
    contaBancaria conta;

    contaBancaria c1, c2, c3;
    c3.depositaConta(10000, "Miguel");

    c1.inicializaConta (1000, 100, 123, "Paolo Guerrero");
    c2.inicializaConta (2000, 100, 124, "Miguel");
    c1.printConta();
    c2.printConta();
    c3.printConta();
    //conta.printConta();
    //conta.cadastraConta();

    return 0;
}

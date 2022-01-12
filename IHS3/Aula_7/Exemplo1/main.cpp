#include <iostream>
#include <string>
using namespace std;

class contaBancaria
{
private:
    string  titular;
    float   saldo;
    float   limite;
    int  numero;
public:
    contaBancaria (float, int); // Construtor da classe
    ~contaBancaria(void); //Destrutor da classe
    void consultaDado (void);
    void cadastraConta(void);
    string getTitular (void);
    void   setTitular (string);
    void printConta(void);
};

contaBancaria::contaBancaria(float sal, int num)
{
    cout << "Construtor foi executado!" << endl;
    saldo = sal;
    limite = 0; // Atributos podem agora
    numero = num; // receber valores iniciais

}

contaBancaria::~contaBancaria(void)
{
    cout << "Conta: " << numero << " foi destruida!" << endl;
}

void contaBancaria::printConta(void)
{
    cout << "Conta N: " << numero << endl;
    cout << "Titular: " << titular << endl;
    cout << "Saldo: "   << saldo << endl;
}


void contaBancaria::setTitular(string str)
{
    int tam = str.length();
    if (tam > 1)
    {
        for(int k = 0; k < tam; k++)
        {
            if(str[k] == ' ')
            {
                titular = str;
                break;
            }
        }
    }
}

//void contaBancaria::setTitular(string aux)
//{
   // titular = aux;
   // for ()
//}

void contaBancaria::cadastraConta(void)
{
    cout << "Digite seu nome: ";
    cin >> titular;
    cout << "Informe seu limite: ";
    cin >> limite;
    cout << "Saldo: ";
    cin >> saldo;
    //numero = to_string(rand());
    cin.ignore();
}

void contaBancaria::consultaDado(void)
{
    cout << "Conta: " << numero << "Titular: " << titular << endl;
    cout << "Saldo: R$ " << saldo << endl;
}

int main()
{
    contaBancaria(1000, 1236);
    contaBancaria c2 = contaBancaria(200, 124);

    return 0;
}

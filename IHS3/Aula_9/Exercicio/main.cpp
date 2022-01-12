#include <iostream>

// Desenvolva uma função (não pode ser um metodo) para ler os atributos 'a' e 'b' da classe P1 a partir do teclado.
// Use, obrigatoriamente, funções amigas e parametros de referência

using namespace std;

class P1
{
private:
    int a;
    int b;
public:
    P1(void);
    friend void le_inteiro(P1 &aux);
    void printa(void);
};

P1::P1(void)
{
    a=0, b=0;
}

void P1::printa (void)
{
    cout << "Nota 'a': " << a << endl;
    cout << "Nota 'b': " << b << endl;
}

void le_inteiro(P1 &aux)
{
    cout << "Digite a nota 'a': ";
    cin >> aux.a;
    cout << "Digite a nota 'b': ";
    cin >> aux.b;
}


int main()
{
    P1 obj;
    le_inteiro(obj);
    obj.printa();
    return 0;
}

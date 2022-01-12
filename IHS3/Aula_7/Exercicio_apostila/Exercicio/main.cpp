#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Fisica
{
public:
    Fisica (float, int); // Construtor da classe
    float L = 0, C = 0, ZMod = 0, R = 0;
    float calcFreqRess(void);
    float calcCModImp (float w);
};

float Fisica::calcFreqRess(void)
{
    float Wr;
    cout << "Escreva o valor do cumprimento: ";
    cin >> L;
    cout << "Escreva o valor do capacitor: ";
    cin >> C;
    Wr = 1/(sqrt(L*C));
    cout << "Frequencia: " << Wr << endl;
    return Wr;
}

float calcCModImp (float w)
{
    cout << "Escreva o valor da resistencia: ";
    cin >> R;
    cout << "Escreva o valor da resistencia: ";
    cin >> R;
}

int main()
{
    Fisica calc;
    calc.calcFreqRess();
    return 0;
}

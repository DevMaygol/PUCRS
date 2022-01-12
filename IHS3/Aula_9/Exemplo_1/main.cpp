#include <iostream>
#include <string>

using namespace std;

class capacitor
    {
    private:
        float cap;
        float res;
        float ind;
        string tipo;
    public:
        capacitor(float, float, float, string);
        void printCap(void);
        friend void imprimeCap(capacitor aux);
    };

capacitor::capacitor(float c, float r, float l, string t)
{
    cap = c; res = r; ind = l; tipo = t;
}

void capacitor::printCap(void)
{
    cout << "Tipo: "        << tipo << endl;
    cout << "Valor: "       << cap << endl;
    cout << "Resistencia: " << res << endl;
    cout << "Indutancia: "  << ind << endl;
}

void imprimeCap(capacitor aux)
{
    cout << "Capacitor: " << aux.tipo << endl;
}
int main()
{
    capacitor c1(1e-6,1,0.0001, "Eletrolitico");
    c1.printCap();
    imprimeCap(c1);
    return 0;
}

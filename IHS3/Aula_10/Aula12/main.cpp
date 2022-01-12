#include <iostream>

using namespace std;

float feedback(float g, float h)
{
   return g/(1+g*h);
}

int main()
{
    cout << "Retorno da funcao: " << feedback(2,3) << endl;
    return 0;
}

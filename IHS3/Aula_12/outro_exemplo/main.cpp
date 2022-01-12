#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main()
{
    fstream arq;
    string aux;
    arq.open("main.cpp", ios::in);

    while(!arq.eof())
    {
        getline(arq, aux);
        cout << aux << endl;
    }
    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream arq;
    float b = 15.874;

    arq.open("arquivo.txt", ios::out | ios::binary);
    if(arq.is_open())
    {
        arq.write((char *)&b, 4);
        arq.close();
    }
    else cout << "Deu ruim" << endl;

    return 0;
}

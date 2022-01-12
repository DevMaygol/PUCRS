#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string frase;
    fstream arq;
    arq.open("saida.txt", ios::out);
    if(arq.is_open())
    {
        cout << "Digite uma string: ";
        getline(cin, frase);

        for(int k=0; k<frase.length(); k++)
        {
            arq << (int)frase[k] << " ";
        }
        arq << endl;
        arq.unsetf(ios::basefield);
        arq.setf(ios::hex);

        for(int k=0; k<frase.length(); k++)
        {
            arq << (int) frase[k] << " ";
        }
        arq << endl;
        arq.unsetf(ios::basefield);
        arq.setf(ios::dec);
        for(int k=frase.length()-1; k>=0; k--)
        {
            arq << frase[k];
        }
        arq << endl;

        for(int k=0; k<frase.length(); k++)
        {
            if(frase[k] == ' ') continue;
            arq << frase[k];
        }
        arq << endl;
        for(int k = 0; k<frase.length(); k++)
        {
            arq << (char) toupper (frase[k]);
        }
        arq.close();
    }
    else cout << "Deu ruim" << endl;
    return 0;
}

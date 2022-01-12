#include <iostream>
#include <string>
using namespace std;

int main()
{
    string palavra;
    string aoContrario;
    string semVogal;

    cout << ("Digite uma palavra: ")<< endl;
    getline(cin, palavra);
    aoContrario = palavra;
    semVogal = palavra;
    //Inverte
    for(int j=aoContrario.length()-1; j>=0; j--)
            {
                cout << aoContrario[j];
            }
            cout << endl;

    //Vai tirar as vogais
    for(int i = 0; i < semVogal.length(); i++){
        if(semVogal[i] == 'a' || semVogal[i]== 'e' || semVogal[i]=='i' ||semVogal[i]== 'o'||semVogal[i]== 'u')
            continue;
        cout << semVogal[i];
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool escrevearq (string narq){

    fstream arq;
    arq.open("oi.txt", ios::out);
    if(narq == "oi.txt"){
        if(arq.is_open()){
            string nome = "Miguel";
            arq << nome << endl;
            int nota = 8;
            arq << nota << endl;
            int media = 7;
            arq << media << endl;
            cout << "Deu certo" <<  endl;

        }
        cout << escrevearq;
        return 1;
    }
    else{
        cout << "Deu ruim" << endl;
        return 0;
    }
}

int main()
{
    escrevearq("oi.txt");
    return 0;
}

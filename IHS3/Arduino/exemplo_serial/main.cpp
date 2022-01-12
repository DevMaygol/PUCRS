#include "portaSerial.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    portaSerial door;
    string aux;

    door.open("COM7", 9600); //A COM pode variar (olhar no arduino)

    if(door.ready()){
        while (1) {
            cout << "Digite L para ligar e D para desligar: " ;
            cin >> aux;
            if(aux == "exit"){
                door.close();
                break; // Sai do while
            }
            if(aux == "L") door.writeByte('L');
            if(aux == "D") door.writeByte('D');
        }
    }else
        cout << "Deu ruim!" << endl;

    return 0;
}

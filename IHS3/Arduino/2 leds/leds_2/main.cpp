#include <iostream>
#include "portaserial.h"
#include <windows.h>

using namespace std;

int main()
{
    portaSerial ps;
    unsigned short int x;
    ps.open("COM8", 9600);

    if(ps.ready()){
        for(int k = 0; k < 100; k++){
            ps.writeByte('R');
            while(ps.BytesAvailable() < 2); // Espera chegar 2 bytes
            x = ps.readWord(false);
            cout << x << endl;
            Sleep(100); // Espera 0,1 segundos
        }
    }else cout << "Deu ruim" <<  endl;
    return 0;
}

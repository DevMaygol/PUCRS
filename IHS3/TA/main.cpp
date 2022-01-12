#include <iostream>
#include <string>
#include <fstream>
#include<cctype>
#include<string.h>

using namespace std;

int main()
{
    fstream arq, outrarq;
    string aux, outra[10000], output[10000], palavra, auxiliar[10000];
    int conta = 1, i = 0, j=0, k=0;
    int igual = 0;

    cout << "Digite um nome para o arquivo para ler: ";
    cin >> aux;
    aux+=".txt";

    /*--------------- ABRE OS DOIS TXT ---------------*/

    arq.open(aux, ios::in);                 // MODO: leitura
    outrarq.open("palavras.txt", ios::out); // MODO: escrita
    if (arq.is_open() && outrarq.is_open())
    {
        while (arq >> output[i]) {
            cout << conta << " " <<  output[i] << endl;
            outra[j] = output[i];
            outrarq << output[i] << " ";
            conta++;
            i++;
        }
    }
    else cout << "Deu ruim, nome do arquivo incorreto!" << endl;
    conta--;
    cout << "Quantidade de palavras no texto: " << conta << endl;
    cout << endl;
    cout << endl;
    outrarq.close();
    arq.close();

    /*^^^^^^^^^^^^^^^^ FECHA OS DOIS TXT ^^^^^^^^^^^^^^^^*/

    /*--------------- ABRE OS DOIS TXT NOVAMENTE ---------------*/

    arq.open(aux, ios::in); // MODO: leitura
    outrarq.open("palavras.txt", ios::out); // MODO: escrita

    if(arq.is_open() && outrarq.is_open()){
        int num = 1;
        char guarda_letra;
        string a, b;
        arq >> auxiliar[0];
        string another;
        string anota;
        while(!arq.eof()){ // Lê até o final do arquivo
            arq >> palavra;
            arq >> another;
            a = another;
            for(i=0;i<another.size();i++){
                if((a[i]!=' ')&&(a[i]!='.')&&(a[i]!=',')&&(a[i]!=';')&&(a[i]!=':')&&(a[i]!='!')){
                    cout << another[i] << " teste" << endl;}
                if(isupper(another[i])){
                    another[i]= tolower(another[i]);}
            }
            //        }else{NULL;}
            //        anota = anota + another[i];
            //
            //    }else{
            //        cout << anota << " teste";
            //        //j++;
            //        //anota="";
            //        //cout << anota << endl;
            //        //numero++;
            //    }
            //}

            int j=0; //zera toda vez que o loop passa por aqui
            for(int i=0; i<num; i++){
                if(palavra == output[i]){
                    auxiliar[i] = palavra;
                    j++;
                    cout << auxiliar[i] << endl;
                    outrarq << auxiliar[i] << endl;
                }
            }
            if(j==0){
                output[num] = palavra; //Armazena a palavra que não se repete em um vetor
                num++;
            }
        }
        for(int i=0; i<num; i++){
            cout << output[i] << " ";
            outrarq << output[i] << " "; //printa as palavras que não repetem
        }

        cout << auxiliar[i] << endl;
        cout << endl;

        outrarq.close();
        arq.close();

    }else cout << "Deu ruim, nome do arquivo incorreto!" << endl;

    return 0;
}

#include <iostream>           //Felipe Prates e Otavio Fraga.
#include<fstream>
#include<string.h>
#include<cctype>
using namespace std;
class TA{
    public:
        string conteudo[10000];
        int contador[10000];
};




int main()
{
      ifstream in01("texto padrao.txt",ios::in);
      string aux;
      string palavra;
      string l;
      int i=0,numero=0,j=0,c=0,k=1,q;
      TA valor;
      bool controlador=true;

      if(in01.is_open()){

    while(getline(in01,aux)){
    palavra = "";

    for(i=0;i<aux.size();i++){
        if((aux[i]!=' ')&&(aux[i]!='.')&&(aux[i]!=',')&&(aux[i]!=';')&&(aux[i]!=':')&&(aux[i]!='!')){
            if(isupper(aux[i])){
                aux[i]= tolower(aux[i]);
            }else{NULL;}
            palavra = palavra + aux[i];

        }else{

            valor.conteudo[j]= palavra;
            j++;
            palavra="";
            numero++;
        }
    }

    }

    for(i=0;i<numero;i++){

        c=c;

        j=i+1;
            while(j<numero){
                if(valor.conteudo[i]==valor.conteudo[j]){
                    valor.conteudo[j]="";
                            j++;
                           k++;
                }else{j++;
                    valor.contador[c]=k;
                }


               }


            c++;
            k=1;
            }
   while(controlador==true){
       controlador=false;
    for(i=0;i<numero;i++){

        if(valor.contador[i]<valor.contador[i+1]){
            q=valor.contador[i];
            valor.contador[i]=valor.contador[i+1];
            valor.contador[i+1]=q;
            l=valor.conteudo[i];
            valor.conteudo[i]=valor.conteudo[i+1];
            valor.conteudo[i+1]=l;

            controlador= true;

          }
  }
   }


    for(i=0;i<numero;i++){
        if(valor.conteudo[i]==""){
            NULL;
        }else{
     cout <<" numero de aparicoes: " << valor.conteudo[i]<<endl;
     cout <<" numero de aparicoes: " << valor.contador[i] << endl;
        }
    }






          in01.close();
}
      ofstream out01;
      out01.open("nome_arq.txt", ios::out);
          if(out01.is_open()){
          for(i=0;i<numero;i++){
              if(valor.conteudo[i]==""){
                  NULL;
              }else{

           out01 << valor.conteudo[i]<<endl;
           out01 <<" numero de aparicoes: " << valor.contador[i] << endl;
           out01 << endl;
              }
          }
          out01.close();
          } else{cout << "deu ruim !!!!";}


    return 0;
}

#include <iostream>
using namespace std;
/*
int main()
{
string nome;
int a, b, c;
bool tv;


cout << "Digite um inteiro:";
cin >> a;
cout << "Digite um inteiro:";
cin >> b;

cout<<"Digite um nome:";
//cin >> nome;
cin.ignore(); //Analogo ao fflush do C
getline (cin, nome); //Le a partir de cin, colocado em nome

cout<<"Nome digitado:"<< nome << " Karrer" <
c= a+b;

cout << "O resultado da soma e:" << c << endl;
return 0;
}*/

/*Utilizando cin, cout e a classe string, refaça o exercício da aula passada:
Escreva uma função que lê uma variável struct aluno do teclado.

Posíveis protótipos:
struct aluno le_aluno (void)
void le_aluno2(struct aluno *p);
*/

struct aluno
{
float p1;
float p2;
int faltas;
string nome;
};

//struct  le_aluno2 (void);
void le_aluno2 (struct aluno *);

int main()
{
    struct aluno a1;
    le_aluno2(&a1);
    cout << a1.nome << endl;
    return 0;
}
void le_aluno2(struct aluno *ptr)
{
    cout << "Digite seu nome:";
    getline(cin, ptr->nome);
    cout << "Nota P1:";
    cin >> ptr -> p1;
    cout << "Nota P1:";
    cin >> ptr -> p2;
    cout << "Faltas: ";
    cin >> ptr -> faltas;
}

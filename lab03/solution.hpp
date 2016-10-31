#include "pint.hpp"
#include <vector>
#include <iostream>
#include <utility>
#include <stdlib.h>


using namespace std;

//pares utilizados para reduzir o código
typedef pair<int,int> pii;
typedef pair<Pint,int> ppi;

//retorna o custo total
vector<ppi> solution(vector<vector<ppi> > & input,int M) {
    vector<ppi> out(0);

    //usando pares
    // o atributo first retorna o primeiro elemento do par
    // o atributo second retorna o segundo atributo do par ( e pode ser setado)
    ppi par_pint_int;
    par_pint_int.first = Pint(2);
    par_pint_int.second = 3;

    par_pint_int.first.print();
    cout << endl;
    cout << par_pint_int.second << endl;

    //dicas
    //soma:
    Pint soma = input[0][0].first + input[1][0].first;
    input[0][0].first.print();
    cout << " + ";
    input[1][0].first.print();
    cout << " = ";
    soma.print();
    cout << endl;

    //divisao:
    Pint divide = input[1][0].first / input[0][0].first;
    input[1][0].first.print();
    cout << " / ";
    input[0][0].first.print();
    cout << " = ";
    divide.print();
    cout << endl;

    //tamanho da entrada:
    cout << input.size() << endl;
    // comparando: input[99].compare(input[2]) == 0 // iguais
    //             input[99].compare(input[2]) == -1 // input[99] < input[2]
    //             input[99].compare(input[2]) == 1 // input[99] > input[2]
    return out;
}


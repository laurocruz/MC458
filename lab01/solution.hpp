#include "pint.hpp"
#include <vector>
#include <iostream>
using namespace std;

//retornar o indice (começando em 0) da embalagem mais leve
int solution(const vector<Pint> & input) {
    int in = 0;
    int size = input.size();
    int fi = size - 1;
    int size3, cmp;
    Pint soma1, soma2;

    while (size >= 3) {
        size3 = size/3;
        soma1 = 0;
        soma2 = 0;
        for (int i = in; i <= in + size3 - 1; i++) {
            soma1 = soma1 + input[i];
        }
        for (int i = in + size3; i <= in + 2*size3 - 1; i++) {
            soma2 = soma2 + input[i];
        }

        cmp = soma1.compare(soma2);

        if (cmp == -1) {
            fi = in + size3 - 1;
            size = size3;
        } else if (cmp == 1) {
            fi = in + 2*size3 - 1;
            in = in + size3;
            size = size3;
        } else {
            in = in + 2*size3;
            size = size - 2*size3;
        }
    }
    if (size == 2 && (input[in].compare(input[fi]) == -1)) {
        return in;
    }
    return fi;
/*
  // Dicas:
  //soma:
  Pint soma = input[0] + input[1];
  input[0].print();
  cout << " + ";
  input[1].print();
  cout << " = ";
  soma.print();
  cout << endl;

  //tamanho da entrada:
  cout << input.size() << endl;
  // comparando: input[99].compare(input[2]) == 0 // iguais
  //             input[99].compare(input[2]) == -1 // input[99] < input[2]
  //             input[99].compare(input[2]) == 1 // input[99] > input[2]

  return -1;
  */
}

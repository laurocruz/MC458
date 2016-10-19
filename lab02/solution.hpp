#include "pint.hpp"
#include <vector>
#include <iostream>
#include <utility>
#include <stdlib.h>

using namespace std;
//retorna o custo total
int solution(vector<Pint> & input) {
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
}

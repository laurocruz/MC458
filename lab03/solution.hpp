#include "pint.hpp"
#include <vector>
#include <iostream>
#include <utility>
#include <stdlib.h>
#include <algorithm>

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

bool compare (ppi a, ppi b) {
    if (a.first.compare(b.first) == -1)
        return true;
    return false;
}

int particioneBFPRT(vector <ppi> & escola, int p, int r) {
    int n = r-p+1;
    int n5_u, n5_d, i, j;

    n5_u = n5_d = n/5;
    if (n % 5 != 0) n5_u++;

    for (j = p, i = 0; i < n5_d ; j += 5, i++)
        sort_heap(escola.begin()+j, escola.begin()+j+4, bool (*compare)(ppi,ppi));
    if (j < r)
        sort_heap(escola.begin()+j, escola.begin()+r, bool (*compare)(ppi,ppi));

    for (j = 1; j < n5_u-1; j++) {
        swap(&escola[j], &escola[p + 5*j - 3]);
        swap(&escola[n5_u], &escola[(p + 5*n5_d + n)/2]);
    }

    int k = select(escola, p, p+n5_u-1, (int) (n5_u+1)/2);

    swap(&escola[k], &escola[r]);

    return particione(escola,p,r);
}

int select(vector <ppi> & escola, int p, int r, int i) {
    if (p == r) return p;

    int q = particioneBFPRT(escola,p,r);
    int k = q - p + 1;

    if (i == k) return q;
    else if (i < k) return select(escola, p, q-1, i);
    else return select(escola, q+1, r, i-k);
}

int particione(vector <ppi> & escola, int p, int r) {
    ppi pivo = escola[r];
    int i = p-1;

    for (int j = p; j < r; j++) {
        if (escola[j].first.compare(pivo.first) <= 0) {
            i++;
            swap (&escola[i], &escola[j]);
        }
    }
    swap(&escola[i+1], &escola[r]);
    return i+1;
}

void swap(ppi *a, ppi *b) {
    ppi aux = *a;
    *a = *b;
    *b = aux;
}

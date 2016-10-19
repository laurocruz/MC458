// Lauro Cruz e Souza
// RA: 156175
// lauro.souza@students.ic.unicamp.br

#include "pint.hpp"
#include <vector>
#include <iostream>
#include <utility>
#include <stdlib.h>
#include <cmath>

using namespace std;

// Ordena o vetor de vagões e calcula a quantidade de pares deslocados
int mergeSort(vector<Pint> & input, vector<int> & pos, int i, int f, int size) {
    if (size == 1) return 0;

    else {
        int OT = 0;
        int af = i - 1 + size/2;
        int bi = af + 1;

        OT += mergeSort(input, pos, i, af, size/2);
        OT += mergeSort(input, pos, bi, f, size - size/2);

        vector<Pint> in_aux (size, 0);
        vector<int> pos_aux (size, 0);
        int j,l,k;

        for (j = i; j <= af; j++) {
            in_aux[j-i] = input[j];
            pos_aux[j-i] = pos[j];
        }
        for (j = bi; j <= f; j++) {
            in_aux[size + bi - j - 1] = input[j];
            pos_aux[size + bi - j - 1] = pos[j];
        }

        j = 0; l = f-i;

        for (k = i; k <= f && j <= af-i && l >= size + bi - f - 1; k++) {
            if (in_aux[j].compare(in_aux[l]) == -1) {
                input[k] = in_aux[j];
                pos[k] = pos_aux[j];
                j++;
            } else {
                input[k] = in_aux[l];
                pos[k] = pos_aux[l];
                l--;
                OT += size/2 - j;
            }
        }

        for (k = k; k <= f && j <= af-i; k++, j++) {
            input[k] = in_aux[j];
            pos[k] = pos_aux[j];
        }
        for (k = k; k <= f && l >= size+bi-f-1; k++, l--) {
            input[k] = in_aux[l];
            pos[k] = pos_aux[l];
        }

        return OT;

    }
}

// Encontra maior deslocamento dentro do vetor
int findMax(vector<int> pos, int size) {
    Pint maior_p = pos[0];
    int maior_i = pos[0];
    Pint aux_p;
    int aux_i;


    for (int i = 1; i < size; i++) {
        aux_i = abs(pos[i] - i);
        aux_p = aux_i;

        if (aux_p.compare(maior_p) == 1) {
            maior_p = aux_p;
            maior_i = aux_i;
        }
        
    }
    return maior_i;
}

//retorna o custo total
int solution(vector<Pint> & input) {
    int n = input.size();
    int OT, M;
    vector<int> pos (n, 0);

    for (int i = 0; i < n; i++)
        pos[i] = i;

    OT = mergeSort(input, pos, 0, n-1, n);

    M = findMax(pos, n);

    return M*OT;

}



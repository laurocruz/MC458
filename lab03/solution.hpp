// Lauro Cruz e Souza
// RA: 156175
// email: laurocruzsouza@gmail.com | lauro.souza@students.ic.unicamp.br

#include "pint.hpp"
#include <vector>
#include <iostream>
#include <utility>
#include <stdlib.h>

using namespace std;

//pares utilizados para reduzir o código
typedef pair<int,int> pii;
typedef pair<Pint,int> ppi;

void mergeSort(vector<ppi> & input, int p, int r);
int particione(vector <ppi> & escola, int p, int r);
int particione_random(vector <ppi> & escola, int p, int r);
int select_random(vector <ppi> & escola, int p, int r, int i);
void swapf(vector <ppi> & escola, int a, int b);

//retorna o custo total
vector<ppi> solution(vector<vector<ppi> > & input,int M) {
    int K = input.size();
    int N = input[0].size();

    // Teto de vagas por escola
    int VpE = M/K;
    if (M%K != 0) VpE++;

    vector<ppi> out(M);
    vector<ppi> medias(K);

    for (int i = 0; i < K; i++) {
        medias[i].second = i;
        for (int j = 0; j < N; j++) {
            medias[i].first = medias[i].first + input[i][j].first;
        }
        medias[i].first = medias[i].first/Pint(N);
        select_random(input[i], 0, N-1, N-VpE+1);
        mergeSort(input[i], N-VpE, N-1);
    }

    mergeSort(medias, 0, K-1);

    int k = 0;
    for (int i = N-VpE; i < N && k < M; i++) {
        for (int j = 0; j < K && k < M; j++) {
            out[k++] = input[medias[j].second][i];
        }
    }

    return out;
}

void mergeSort(vector<ppi> & input, int p, int r) {
    int n = r-p+1;

    if (n == 1) return;

    int af = p - 1 + n/2;
    int bi = af + 1;

    mergeSort(input, p, af);
    mergeSort(input, bi, r);

    vector<ppi> in_aux (n);
    int j,l,k;

    for (j = p; j <= af; j++) {
        in_aux[j-p] = input[j];
    }
    for (j = bi; j <= r; j++) {
        in_aux[n + bi - j - 1] = input[j];
    }

    j = 0; l = r-p;

    for (k = p; k <= r && j <= af-p && l >= n + bi - r - 1; k++) {
        if (in_aux[j].first.compare(in_aux[l].first) >= 0) {
            input[k] = in_aux[j];
            j++;
        } else {
            input[k] = in_aux[l];
            l--;
        }
    }

    for (k = k; k <= r && j <= af-p; k++, j++) {
        input[k] = in_aux[j];
    }
    for (k = k; k <= r && l >= n+bi-r-1; k++, l--) {
        input[k] = in_aux[l];
    }
}

int particione(vector <ppi> & escola, int p, int r) {
    ppi pivo = escola[r];
    int i = p-1;

    for (int j = p; j < r; j++) {

        if (escola[j].first.compare(pivo.first) <= 0) {
            i++;
            swapf(escola, i, j);
        }

    }
    swapf(escola, i+1, r);
    return i+1;
}

int particione_random(vector <ppi> & escola, int p, int r) {
    int n = r - p + 1;
    int j = rand() % n + p;

    swapf(escola,j,r);

    return particione(escola,p,r);
}

int select_random(vector<ppi> & escola, int p, int r, int i) {
    if (p == r) return p;

    int q = particione_random(escola, p, r);
    int k = q - p + 1;

    if (i == k) return q;
    else if (i < k) return select_random(escola,p,q-1,i);
    else return select_random(escola,q+1,r,i-k);
}

void swapf(vector <ppi> & escola, int a, int b) {
    ppi aux = escola[a];
    escola[a] = escola[b];
    escola[b] = aux;
}


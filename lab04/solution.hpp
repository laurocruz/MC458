// Lauro Cruz e Souza - 156175
// laurocruzsouza@gmail.com

#include <vector>
#include <iostream>
#include <utility>
#include <stdlib.h>

using namespace std;

int predioMinimo(vector<int> & emp, int S, int n, vector<int> & predio) {
    vector<vector<int> > z(n+1, vector<int>(S+1));
    int d, k, novo;
    
    for (d = 1; d <= S; d++) z[0][d] = -1;
    for (k = 0; k <= n; k++) z[k][0] = 0;

    // Monta matriz de tamanhos mínimos
    for (k = 1; k <= n; k++) {
        for (d = 1; d <= S; d++) {
            z[k][d] = novo = z[k-1][d];

            if (emp[k-1] > d) 
                novo = emp[k-1];
            else if ((z[k-1][d-emp[k-1]] != -1)  &&  (emp[k-1] + z[k-1][d-emp[k-1]] >= d))
                novo = emp[k-1] + z[k-1][d-emp[k-1]];

            if (z[k][d] == -1 || novo < z[k][d])
                z[k][d] = novo;
        }
    }

    // Encontra subconjunto de empresas no maior predio
    k = n; d = S;
    while (k > 0 && d > 0) {
        if (z[k][d] != z[k-1][d]) {
            predio.push_back(k-1);
            d -= emp[k-1];
        }
        k--;
    }
    return z[n][S];
}

//retorna as empresas ( em qualquer ordem) de uma das torres. As empresas restantes são colocadas na outra torre.
vector<int> solution(vector<int> & input) {
    vector<int> items;
    int S = 0, n;

    n = input.size();
    for (int i = 0; i < n; i++) 
        S += input[i];

    S = S/2 + S%2;

    predioMinimo(input, S, n, items);

    return items;
}



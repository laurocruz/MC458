// Lauro Cruz e Souza - 156175
// lauro.souza@students.ic.unicamp.br

#include <vector>
#include <iostream>
#include <utility>
#include <stdlib.h>

using namespace std;

void makeDP(vector< vector<int> > & dp, const vector<int> & t, int L, int n);
int getCost(vector< vector<int> > & dp, int n);

//retorna o custo total como descrito no enunciado
int solution(const vector<int> & input, int L) {
    int n = input.size();
    vector< vector<int> > dp(n, vector<int>(n));

    makeDP(dp, input, L, n);

    return getCost(dp, n);
}

void makeDP(vector< vector<int> > & dp, const vector<int> & t, int L, int n) {
    int i, j, let;
    for (i = 0; i < n; i++) {
        let = L - t[i];
        j = i;

        do {
            dp[i][j++] = let*let;
            let -= (t[j] + 1);
        } while (let >= 0 && j < n);

        while (j < n) dp[i][j++] = -1;
    }
}

int getCost(vector< vector<int> > & dp, int n) {
    vector<int> cost(n);
    int j, aux, small;

    for (int i = n-1; i >= 0; i--) {
        if (dp[i][n-1] != -1) 
            cost[i] = dp[i][n-1];

        else { 
            j = n-1;
            while (dp[i][j-1] == -1) j--;

            small = dp[i][j-1] + cost[j]; j--;

            while (j > i) {
                aux = dp[i][j-1] + cost[j];
                if (aux < small) small = aux;
                j--;
            }
            cost[i] = small;
        }
    }
    return cost[0];
}


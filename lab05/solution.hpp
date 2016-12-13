// Lauro Cruz e Souza - 156175
// lauro.souza@students.ic.unicamp.br

#include <vector>
#include <iostream>
#include <utility>
#include <stdlib.h>

using namespace std;
//tempo dos para natação, ciclismo e corrida, respectivamente.
struct Time {
    int s,p,c;
};

bool comp(struct Time a, struct Time b) {
    if (a.p + a.c > b.p + b.c) return true;
    else if (a.p + a.c == b.p + b.c && a.s <= b.s) return true;

    return false;
}

void heapify(vector<Time> &  arr, vector<int> & order, int n, int i) {
    int later, l, r;
    bool cont;
    later = i;
    do {
        i = later;
        l = 2*i + 1; 
        r = 2*i + 2; 

        if (l < n && comp(arr[later], arr[l]))
            later = l;

        if (r < n && comp(arr[later], arr[r]))
            later = r;

        if (later != i) {
            swap(arr[i], arr[later]);
            swap(order[i], order[later]);
        }
    } while (later != i);
}

void heapSort(vector<Time> & arr, vector<int> & order, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, order, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        swap(order[0], order[i]);

        heapify(arr, order, i, 0);
    }
}

//a funcao deve retornar os indices dos atletas na ordem de participacao.
vector<int> solution(const vector<Time> & input) {
    vector<int> order(input.size());
    vector<Time> ins(input.size());

    for (int i = 0; i < input.size(); i++) {
        ins[i] = input[i];
        order[i] = i;
    }

    heapSort(ins, order, ins.size());

    return order;
}

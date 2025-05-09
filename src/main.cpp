#include "heap.hpp"
#include <iostream>

using namespace std;

int main() {
    int tamanho;
    cin>>tamanho;

    Heap heap(tamanho);

    for (int i = 0; i < tamanho; ++i) {
        int valor;
        cin >> valor;
        heap.Inserir(valor);
    }

    for (int i = 0; i < tamanho; ++i) {
        cout << heap.Remover() << " ";
    }
}
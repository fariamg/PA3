#include "heap.hpp"
#include <algorithm> 
#include <stdexcept>

static int elementsCounter = 0; // GAMBIARRA DA PORRA KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK

Heap::Heap(int maxsize) {
    this->tamanho = maxsize;
    this->data = new int[tamanho];
    elementsCounter = 0;
}

Heap::~Heap() { delete[] this->data; }

bool Heap::Vazio() { return elementsCounter == 0; }

void Heap::Inserir(int x) {
    if (elementsCounter == tamanho)
        throw std::overflow_error("Heap overflow: não é possível inserir em heap cheia");
    data[elementsCounter] = x;
    HeapifyPorCima(elementsCounter);
    ++elementsCounter;
}

int Heap::Remover() {
    if (elementsCounter == 0)
        throw std::underflow_error("Heap underflow: não é possível remover de heap vazia");
    int raiz = data[0];
    data[0] = data[elementsCounter - 1];
    --elementsCounter;
    HeapifyPorBaixo(0);
    return raiz;
}

int Heap::GetAncestral(int posicao) { return (posicao - 1) / 2; }

int Heap::GetSucessorEsq(int posicao) { return 2 * posicao + 1; }

int Heap::GetSucessorDir(int posicao) { return 2 * posicao + 2; }

void Heap::HeapifyPorCima(int posicao) {
    while (posicao > 0) {
        int pai = GetAncestral(posicao);
        if (data[posicao] < data[pai]) {
            std::swap(data[posicao], data[pai]);
            posicao = pai;
        } else {
            break;
        }
    }
}

void Heap::HeapifyPorBaixo(int posicao) {
    while (true) {
        int esq = GetSucessorEsq(posicao);
        int dir = GetSucessorDir(posicao);
        int menor = posicao;

        if (esq < elementsCounter && data[esq] < data[menor])
            menor = esq;
        if (dir < elementsCounter && data[dir] < data[menor])
            menor = dir;
        if (menor == posicao)
            break;

        std::swap(data[posicao], data[menor]);
        posicao = menor;
    }
}
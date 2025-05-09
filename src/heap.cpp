#include "heap.hpp"
#include <stdexcept>

Heap::Heap(int size) {
    this->tamanho = size;
    this->data = new int[tamanho](); // O () no final inicializa o array com 0's
}

Heap::~Heap() { delete[] this->data; }

void Heap::Inserir(int x) {
    // Encontra a primeira posição livre (sentinela = 0)
    int pos = 0;
    while (pos < tamanho && data[pos] != 0) ++pos;

    if (pos == tamanho)
        throw std::overflow_error("Heap overflow: não é possível inserir em heap cheia");

    data[pos] = x;
    HeapifyPorCima(pos);
}

int Heap::Remover() {
    int pos = 0;
    while (pos < tamanho && data[pos] == 0) ++pos;

    if (pos == tamanho)
        throw std::underflow_error("Heap underflow: não é possível remover de heap vazia");

    int valor = data[pos];
    data[pos] = 0; // Remove o valor
    HeapifyPorBaixo(pos);
    return valor;
}

bool Heap::Vazio() {
    for (int i = 0; i < this->tamanho; ++i) {
        if (this->data[i] != 0) {
            return false;
        }
    }
    return true;
}

int Heap::GetAncestral(int posicao) { return (posicao - 1) / 2; }

int Heap::GetSucessorDir(int posicao) { return posicao * 2 + 1; }

int Heap::GetSucessorEsq(int posicao) { return posicao * 2 + 2; }

void Heap::HeapifyPorBaixo(int posicao) {
    int maior = posicao;
    int esq = GetSucessorEsq(posicao);
    int dir = GetSucessorDir(posicao);

    if (esq < tamanho && data[esq] > data[maior]) {
        maior = esq;
    }
    if (dir < tamanho && data[dir] > data[maior]) {
        maior = dir;
    }
    if (maior != posicao) {
        std::swap(data[posicao], data[maior]);
        HeapifyPorBaixo(maior);
    }
}

void Heap::HeapifyPorCima(int posicao) {
    int ancestral = GetAncestral(posicao);
    if (posicao > 0 && data[posicao] > data[ancestral]) {
        std::swap(data[posicao], data[ancestral]);
        HeapifyPorCima(ancestral);
    }
}
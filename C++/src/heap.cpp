#include "heap.hpp"

Heap::Heap(int size) {
    this->tamanho = size;
    this->data = new int[tamanho](); //O () no final inicializa o array com 0's
}

Heap::~Heap() {
    delete[] this->data;
}

bool Heap::Vazio() {
    for (int i = 0; i < this->tamanho; ++i) {
        if (this->data[i] != 0) {
            return false;
        }
    }
    return true;
}
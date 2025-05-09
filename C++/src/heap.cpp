#include "heap.hpp"

Heap::Heap(int size) {
    this->tamanho = size;
    this->data = new int[tamanho];
}

Heap::~Heap() {
    delete[] this->data;
}
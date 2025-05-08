#pragma once

#include "heap.hpp"

class Node {
  public:
    Node(int value);

    Node* getRight(); 
    Node* getLeft(); 
    int getData();

    void setData(int value);

  private:
    int data;
    Node* right;
    Node* left;
};
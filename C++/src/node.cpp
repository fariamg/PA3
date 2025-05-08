#include "node.hpp"

Node::Node(int value) : data(value), right(nullptr), left(nullptr) {}

Node* Node::getRight() { return this->right; }

Node* Node::getLeft() { return this->left; }

int Node::getData() { return this->data; }

void Node::setData(int value) { this->data = value; }
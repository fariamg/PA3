#include "node.hpp"

Node::Node(int value) : data(value), right(nullptr), left(nullptr) {}

Node* Node::getRight() { return right; }

Node* Node::getLeft() { return left; }

int Node::getData() { return data; }

void Node::setData(int value) { data = value; }
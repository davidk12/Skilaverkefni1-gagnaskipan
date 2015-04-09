#include <iostream>
#include "Node.h"

Node::Node() : data(0), link(NULL) {
    // Default constructor
}

Node::Node(int value, Node *next) : data(value), link(next) {
// Constructs a node with a value and next link
}

// Accessor and Mutator methods follow
int Node::getData() const {
    return data;
}

Node* Node::getLink( ) const {
    return link;
}

void Node::setData(int value) {
    data = value;
}

void Node::setLink(Node *next) {
    link = next;
}

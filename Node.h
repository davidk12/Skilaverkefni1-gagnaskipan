#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        // Constructors to initialize a node
        Node();                      // Constructs a node with a 0 value and a NULL link
        Node(int value, Node *next); // Constructs a node with a value and next link

        int getData() const;    // Retrieve value for this node
        Node* getLink() const;  // Retrieve next node in the list

        void setData(int value); // Use to modify the value stored in the list
        void setLink(Node* next); // Use to change the reference to the next node

    private:
        int data;
        Node *link;
};

typedef Node* NodePtr;

#endif // NODE_H

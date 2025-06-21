#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class Tree{
    Node *root = nullptr;

public:
    void insertNode(int d){
        Node *newNode = new Node(d);

        if(root == nullptr){
            root = newNode;
        }
        else{
            Node *cur = root;

            while(cur){
                if(cur->data > d){
                    if(cur->left == nullptr){
                        cur->left = newNode;
                        return;
                    }
                    cur = cur->left;
                }
                else{
                    if(cur->right == nullptr){
                        cur->right = newNode;
                        return;
                    }
                    cur = cur->right;
                }
            }
        }
    }
};

int main() {
    Tree t;
    t.insertNode(5);
    t.insertNode(1);
    t.insertNode(8);
    t.insertNode(4);
    t.insertNode(9);

    return 0;
}
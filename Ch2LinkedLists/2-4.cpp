
#include "LinkedList.hpp"

Node* partitionList(Node* root, int x) {
    Node* par1Head = new Node;
    Node* par2Head = new Node;
    Node* par1 = par1Head;
    Node* par2 = par2Head;

    while (root != nullptr) {
        if (root->val < x) {
            Node* newNode = new Node;
            newNode->val = root->val;
            par1->next = newNode;
            par1 = par1->next;
        }
        else {
            Node* newNode = new Node;
            newNode->val = root->val;
            par2->next = newNode;
            par2 = par2->next;
        }
        root = root->next;
    }

    par1->next = par2Head->next;
    return par1Head->next;
}

int main() {
    Node* list1 = makeListFromString("1 55 48 103 8 4 9 2 5 6 7 5 3 28 385 72 1 23 19");
    printList(list1);
    Node* list1P = partitionList(list1, 10);
    printList(list1P);

    return 0;
}

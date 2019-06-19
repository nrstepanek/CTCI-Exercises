
#include "LinkedList.hpp"

Node* addBackwards(Node* num1, Node* num2) {
    Node* sumHead = nullptr;
    Node* sum = sumHead;
    int remainder = 0;
    
    while (num1 != nullptr && num2 != nullptr) {
        int summed = num1->val + num2->val;
        cout << "summed: " << to_string(summed) << endl;
        if (sum == nullptr) sum = new Node;

        sum->val = (summed + remainder) % 10;
        remainder = (summed + remainder) / 10;
        cout << "sum val: " << to_string(sum->val) << endl;
        cout << "remainder: " << to_string(remainder) << endl;
        Node* nextNode;
        sum->next = nextNode;
        sum = sum->next;

        num1 = num1->next;
        num2 = num2->next;
    }

    while (num1 != nullptr) {
        if (!sum) sum = new Node;
        sum->val = (num1->val + remainder) % 10;
        remainder = (num1->val + remainder) / 10;
        Node* nextNode;
        sum->next = nextNode;
        sum = sum->next;

        num1 = num1->next;
    }

    while (num2 != nullptr) {
        if (!sum) sum = new Node;
        sum->val = (num2->val + remainder) % 10;
        remainder = (num2->val + remainder) / 10;
        Node* nextNode;
        sum->next = nextNode;
        sum = sum->next;

        num2 = num2->next;
    }

    return sumHead;
}

int main() {
    Node* list1 = makeListFromString("7 1 6");
    Node* list2 = makeListFromString("5 9 2");
    printList(addBackwards(list1, list2));

    return 0;
}

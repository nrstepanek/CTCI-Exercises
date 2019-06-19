
#include "LinkedList.hpp"

void deleteMiddleNode(Node* toDelete) {
    Node* temp = toDelete->next;
    toDelete->val = temp->val;
    toDelete->next = temp->next;
    delete temp;
}

int main() {
    Node* list1 = makeListFromString("1 2 3 4 5 6 7");
    printList(list1);
    deleteMiddleNode(list1->next->next->next);
    printList(list1);

    return 0;
}

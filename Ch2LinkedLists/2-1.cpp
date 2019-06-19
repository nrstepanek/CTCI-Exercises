
#include "LinkedList.hpp"

#include <unordered_map>

void removeDupes(Node* head) {
    if (head == nullptr) return;
    unordered_map<int, bool> foundNums;

    Node* curNode = head;
    foundNums[curNode->val] = true;
    while (curNode->next != nullptr) {
        if (foundNums.find(curNode->next->val) != foundNums.end()) {
            Node* temp = curNode->next;
            curNode->next = curNode->next->next;
            delete temp;
        }
        else {
            foundNums[curNode->next->val] = true;
            curNode = curNode->next;
        }
    }
}

int main() {
    Node* list1 = makeListFromString("1 2 3 2 4 5 6 7 5 8 9 9 9 9 1 11 12 1");
    printList(list1);
    removeDupes(list1);
    printList(list1);

    return 0;
}


#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    Node* next;
    int val;
};

Node* deleteNode(Node* head, int toDelete) {
    if (head == nullptr)
        return nullptr;

    if (head->val == toDelete) {
        return head->next;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->val == toDelete) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return head;
        }
        current = current->next;
    }

    return head;
}

Node* makeListFromString(string s) {
    size_t pos = 0;
    vector<int> nodeVals;
    while ((pos = s.find(" ")) != string::npos) {
        nodeVals.push_back(stoi(s.substr(0, pos)));
        s.erase(0, pos + 1);
    }
    if (s.size() != 0)
        nodeVals.push_back(stoi(s));

    if (nodeVals.size() == 0)
        return nullptr;
    Node* head = new Node;
    head->val = nodeVals[0];
    Node* current = head;
    for (int i = 1; i < nodeVals.size(); i++) {
        Node* toAdd = new Node;
        toAdd->val = nodeVals[i];
        current->next = toAdd;
        current = toAdd;
    }

    return head;
}

void printList(Node* head) {
    Node* curNode = head;
    while (curNode != nullptr) {
        cout << to_string(curNode->val) << " ";
        curNode = curNode->next;
    }
    cout << endl;
}

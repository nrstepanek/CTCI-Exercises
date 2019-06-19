
#include "LinkedList.hpp"

int kthToLast(int k, Node* root) {
    if (k < 1) return 0;
    vector<int> nums;
    while (root != nullptr) {
        nums.push_back(root->val);
        root = root->next;
    }

    return nums[nums.size() - k];
}

int kthToLast2(int k, Node* root) {
    Node* runner = root;
    while (k-- > 0) {
        runner = runner->next;
    }

    while (runner != nullptr) {
        root = root->next;
        runner = runner->next;
    }

    return root->val;
}

Node* kthToLast3(int k, Node* root, int &i) {
    if (root == nullptr) return nullptr;

    Node* node = kthToLast3(k, root->next, i);
    i = i + 1;
    if (i == k)
        return root;
    return node;
}

int main() {
    Node* list1 = makeListFromString("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15");
    cout << to_string(kthToLast(5, list1)) << endl;
    cout << to_string(kthToLast2(5, list1)) << endl;
    int i = 0;
    cout << to_string(kthToLast3(5, list1, i)->val) << endl;

    return 0;
}

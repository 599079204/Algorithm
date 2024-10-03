#include <bits/stdc++.h>
#include "ljw.h"

using namespace std;

MyNode *reversal(MyNode *head) {
    MyNode *pre = nullptr, *curr = head, *next;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

int main() {
    int array[10];
    generateArrayData(array, 10, true);
    cout << endl;

    MyNode *head = MyNode::build(array, 10);
    head->print1();

    cout << endl;
    MyNode *newHead = reversal(head);
    newHead->print1();
    return 0;
}
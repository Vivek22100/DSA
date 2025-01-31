#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node* next;
    node(int a) {
        data = a;
        next = NULL;
    }
};

node* arrtoll(vector<int>& arr, int n) {
    if (n == 0) return NULL;
    node* head = new node(arr[0]);
    node* curr = head;
    for (int i = 1; i < n; i++) {
        node* temp = new node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

int len(node* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

node* paddzeros(node* snode, int diff) {
    while (diff--) {
        node* zero = new node(0);
        zero->next = snode;
        snode = zero;
    }
    return snode;
}

// Function to check if l1 < l2
bool isSmaller(node* l1, node* l2) {
    while (l1 && l2) {
        if (l1->data < l2->data) return true;
        if (l1->data > l2->data) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return false;
}

node* subtractllhelper(node* l1, node* l2, bool& borrow) {
    if (!l1) return NULL;

    node* prev = subtractllhelper(l1->next, l2->next, borrow);
    int d1 = l1->data;
    int d2 = l2->data;

    if (borrow) {
        d1--;
        borrow = false;
    }

    if (d1 < d2) {
        borrow = true;
        d1 += 10;
    }

    node* curr = new node(d1 - d2);
    curr->next = prev;
    return curr;
}

node* subtractll(node* l1, node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    int len1 = len(l1);
    int len2 = len(l2);

    if (len1 < len2 || (len1 == len2 && isSmaller(l1, l2))) {
        swap(l1, l2);
    }

    l2 = paddzeros(l2, abs(len1 - len2));

    bool borrow = false;
    node* result = subtractllhelper(l1, l2, borrow);

    // Remove leading zeros
    while (result && result->data == 0) {
        node* temp = result;
        result = result->next;
        delete temp;
    }

    return result ? result : new node(0);
}

void printList(node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n1;
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    int n2;
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    node* l1 = arrtoll(arr1, n1);
    node* l2 = arrtoll(arr2, n2);
    node* l3 = subtractll(l1, l2);

    printList(l3);

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

// 插入節點
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// 計算樹高
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// 找最小值（右子樹最左邊）
Node* findMin(Node* root) {
    while (root->left)
        root = root->left;
    return root;
}

// 刪除節點
Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: 沒有左子樹
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: 沒有右子樹
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: 兩個子節點
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

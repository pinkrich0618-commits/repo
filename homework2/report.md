#41343106

作業二

## 解題說明
本題分為兩部分：

(a)
建立空 BST
插入 n 個隨機數
計算樹高 height
分析：ℎ𝑒𝑖𝑔ℎ𝑡/log

目的：驗證 BST 高度是否為 O(log n)

(b)
實作 BST 刪除節點
分析時間複雜度

## 程式實作

以下為主要程式碼：
(a) 插入 + 高度
```cpp
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

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```
(b) 刪除節點
```
Node* findMin(Node* root) {
    while (root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

```
## 效能分析

(a)
1.BST 平均高度：O(log n)
2.ratio ≈ 常數（約 2）

(b)
情況	複雜度
平均	O(log n)
最差	O(n)

## 測試與驗證
```
int main() {
    srand(time(0));

    for (int n = 100; n <= 10000; n += 100) {
        Node* root = NULL;

        for (int i = 0; i < n; i++) {
            root = insert(root, rand());
        }

        int h = height(root);
        double ratio = h / log2(n);

        cout << n << " " << ratio << endl;
    }
}
```
結果觀察：
ratio 約在 1.8 ~ 2.5
接近常數 → 驗證 O(log n)

### 結論

本實驗證明：

隨機插入 BST 的高度為 O(log n)
刪除操作時間與樹高相關


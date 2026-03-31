#41343106

作業一

## 解題說明

本題要求實作一個 Min Priority Queue（MinPQ），並使用 Min Heap 來完成。

Min Heap 是一種完全二元樹，滿足：

每個節點的值 ≤ 子節點
根節點為最小值

本實作透過：

抽象類別 MinPQ
衍生類別 MinHeap

來完成資料結構設計，並支援：

插入（Push）
刪除最小值（Pop）
取得最小值（Top）

## 程式實作

以下為主要程式碼：

```cpp
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class MinPQ {
public:
    virtual ~MinPQ() {}
    virtual bool IsEmpty() const = 0;
    virtual const T& Top() const = 0;
    virtual void Push(const T&) = 0;
    virtual void Pop() = 0;
};

template <class T>
class MinHeap : public MinPQ<T> {
private:
    vector<T> heap;

    void HeapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] <= heap[i]) break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void HeapifyDown(int i) {
        int n = heap.size();
        while (2*i + 1 < n) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int smallest = left;

            if (right < n && heap[right] < heap[left])
                smallest = right;

            if (heap[i] <= heap[smallest]) break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    bool IsEmpty() const override {
        return heap.empty();
    }

    const T& Top() const override {
        return heap[0];
    }

    void Push(const T& x) override {
        heap.push_back(x);
        HeapifyUp(heap.size() - 1);
    }

    void Pop() override {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        HeapifyDown(0);
    }
};
```
## 效能分析

1.Heap 高度為 log n
2.插入與刪除需調整樹結構（heapify）

## 測試與驗證
```
int main() {
    MinHeap<int> h;

    h.Push(10);
    h.Push(5);
    h.Push(20);
    h.Push(2);

    while (!h.IsEmpty()) {
        cout << h.Top() << " ";
        h.Pop();
    }
}
```
輸出結果：2 5 10 20

### 結論

本題成功實作 Min Heap，並透過抽象類別提升程式彈性。
所有操作時間複雜度符合預期（O(log n)），證明其效率良好。

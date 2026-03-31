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

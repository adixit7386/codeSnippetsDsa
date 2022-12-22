#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

class heap
{
public:
    int *arr;
    int size;
    int cap;

    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    heap(int y)
    {
        cap = y;
        size = 0;
        arr = new int[y];
    }
    bool insert(int val)
    {
        if (size == cap)
        {
            return false;
        }
        size++;
        arr[size - 1] = val;
        int i = size - 1;

        while (i >= 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
        return true;
    }
    void heapify(int i)
    {
        // this operation is used when we find that a particular element at a given index does not obey the rules of the heap data structure so we find a way to arrange them in the order
        // given left and the right of the element are already following the property of the heap data structure
        int sm = i;

        int lt = left(i), rt = right(i);
        if (lt < size && arr[lt] < arr[i])
        {
            sm = lt;
        }
        if (rt < size && arr[rt] < arr[sm])
        {
            sm = rt;
        }
        if (sm != i)
        {
            swap(arr[i], arr[sm]);
            heapify(sm);
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        return;
    }
    int extractMin()
    {
        swap(arr[0], arr[size - 1]);
        size--;
        heapify(0);
        return arr[size];
    }
    void decreaseKey(int i, int val)
    {
        arr[i] = val;
        heapify(i);
        while (i != 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
        return;
    }
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        swap(arr[size - 1], arr[0]);
        size--;
    }
};
int main()
{
    heap hp(100);
    hp.insert(10);
    hp.insert(9);
    hp.insert(4);
    hp.insert(2);
    hp.insert(12);
    hp.insert(34);
    hp.insert(56);
    hp.insert(78);
    hp.decreaseKey(3, 3);
    hp.deleteKey(3);
    hp.print();

    return 0;
}
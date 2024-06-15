#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
public:
	MaxHeap() {}

	void push(int val)
	{
		heap.push_back(val);
		heapifyUp(heap.size() - 1);
	}

	void pop()
	{
		if (heap.size() == 0)
			return;
		swap(heap[0], heap[heap.size() - 1]);
		heap.pop_back();
		heapifyDown(0);
	}

	int top()
	{
		if (heap.size() == 0)
			throw runtime_error("Heap is empty");
		return heap[0];
	}

	bool empty()
	{
		return heap.size() == 0;
	}

	int size()
	{
		return heap.size();
	}

private:
	vector<int> heap;

	void heapifyUp(int index)
	{
		while (index > 0 && heap[parent(index)] < heap[index])
		{
			swap(heap[parent(index)], heap[index]);
			index = parent(index);
		}
	}

	void heapifyDown(int index)
	{
		int largest = index;
		int leftChild = left(index);
		int rightChild = right(index);

		if (leftChild < heap.size() && heap[leftChild] > heap[largest])
		{
			largest = leftChild;
		}

		if (rightChild < heap.size() && heap[rightChild] > heap[largest])
		{
			largest = rightChild;
		}

		if (largest != index)
		{
			swap(heap[index], heap[largest]);
			heapifyDown(largest);
		}
	}

	int parent(int index)
	{
		return (index - 1) / 2;
	}

	int left(int index)
	{
		return 2 * index + 1;
	}

	int right(int index)
	{
		return 2 * index + 2;
	}
};

int main()
{
	MaxHeap heap;

	heap.push(3);
	heap.push(1);
	heap.push(6);
	heap.push(5);
	heap.push(2);
	heap.push(4);

	cout << "Heap size: " << heap.size() << endl;
	cout << "Max element: " << heap.top() << endl;

	while (!heap.empty())
	{
		cout << heap.top() << " ";
		heap.pop();
	}
	cout << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> heap;
        for (int i : stones)
        {
            heap.push(i);
        }
        while (heap.size() > 1)
        {
            int first = heap.top(); // largest stone
            heap.pop();
            int second = heap.top(); // second largest stone
            heap.pop();
            if (first != second)
            {
                heap.push(first - second); // pushing the difference back to the heap
            }
        }
        return heap.empty() ? 0 : heap.top(); // if heap is empty, return 0, else return the last stone weight
    }
};

int main()
{
    Solution sol;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << sol.lastStoneWeight(stones) << endl; // Expected output: 1
    return 0;
}

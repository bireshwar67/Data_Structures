#include <iostream>
#include <vector>
#include <algorithm> // For swap

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                // Swap current element with the element at low pointer
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                // Move to the next element
                mid++;
            }
            else
            {
                // Swap current element with the element at high pointer
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    cout << "Before" << endl;
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    sol.sortColors(nums);
    cout << "After" << endl;
    for (int num : nums)
    {
        cout << num << " ";
    }
    // Expected output: 0 0 1 1 2 2

    return 0;
}
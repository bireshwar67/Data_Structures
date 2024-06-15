#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                int increment = nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
                count += increment;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    cout << "For nums = 3, 2, 1, 2, 1, 7" << endl;
    cout << "Min no of moves to make the array unique: ";
    cout << sol.minIncrementForUnique(nums) << endl; // Expected output: 6

    nums = {1, 2, 2, 4, 7, 8, 9, 9, 9, 9, 3};
    cout << "For nums = 1, 2, 2, 4, 7, 8, 9, 9, 9, 9, 3" << endl;
    cout << "Min no of moves to make the array unique: ";
    cout << sol.minIncrementForUnique(nums) << endl; // Expected output: 1

    return 0;
}
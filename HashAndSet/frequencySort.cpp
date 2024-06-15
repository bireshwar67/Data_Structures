#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (auto it : s)
        {
            freq[it]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto it : freq)
        {
            pq.push({it.second, it.first});
        }

        string ans;
        while (!pq.empty())
        {
            int count = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            ans.append(count, ch); // Appends `count` copies of `ch` to `ans`
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl; // Expected output: "eetr" or "eert"
    return 0;
}
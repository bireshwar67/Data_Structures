#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> charCount;

        // Count the occurrences of each character
        for (char c : s)
        {
            charCount[c]++;
        }

        // Find the first character that appears only once
        for (int i = 0; i < s.size(); i++)
        {
            if (charCount[s[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    string s = "loveleetcode";
    cout << sol.firstUniqChar(s) << endl; // Expected output: 0
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
int main()
{

    // vector<int> nums{10, 20, 20, 10, 30, 40, 10, 20};

    string s = "abccbaacz";
    int n = s.size();
    unordered_map<char, int> hash;

    for (int i = 0; i < n; i++)
    {
        hash[s[i]]++;
    }

    // Printing the frequency of elements
    cout << "Frequency of elements in the array is: "
         << endl;
    for (auto i : hash)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}
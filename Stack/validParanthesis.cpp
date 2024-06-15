#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (char c : s)
        {
            if (isOpen(c))
            {
                stk.push(c);
            }
            else if (isClose(c))
            {
                if (!stk.empty() && isComplete(stk.top(), c))
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return stk.empty();
    }

private:
    bool isOpen(char bracket)
    {
        return bracket == '(' || bracket == '{' || bracket == '[';
    }

    bool isClose(char bracket)
    {
        return bracket == ')' || bracket == '}' || bracket == ']';
    }

    bool isComplete(char open, char close)
    {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
};

int main()
{
    Solution sol;
    string s = "()[]{}";
    cout << (sol.isValid(s) ? "True" : "False") << endl; // Expected output: True

    s = "(]";
    cout << (sol.isValid(s) ? "True" : "False") << endl; // Expected output: False

    return 0;
}

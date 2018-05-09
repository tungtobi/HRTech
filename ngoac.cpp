#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> stk;

    for (unsigned i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            stk.push(str[i]);
        }
        else
        {
            if (!stk.empty() && str[i] - stk.top() == 1)
            {
                if (stk.empty())
                {
                    cout << "NO";
                    break;
                }
                else
                {
                    stk.pop();
                }
            }
        }
    }

    if (stk.empty())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}

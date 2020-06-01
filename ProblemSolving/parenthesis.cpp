#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <string>
using namespace std;

bool checkValidString(string s) {
    stack<char> st;
    int len = s.length();
    int count=0;
    for(int i=0;i<len;i++)
    {
        if(s[i] == '*')
        {
            if(!st.empty())
            {
                st.pop();
            }
            else
            {
                count++;
            }
        }
        else if(s[i] == '(')
            st.push(s[i]);
        else
        {
            if(!st.empty())
                st.pop();
            else if(count)
                count--;
            else
                return false;
        }
    }
    
    if(st.empty())
        return true;
//    else if(count)
//        return (st.size() == count);
    else
        return false;
        
}

// main function
int main12()
{
    string str = "((())()()(*)(*()(())())())()()((()())((()))(*";
    
   

    cout<< checkValidString(str) <<endl;

    return 0;
}

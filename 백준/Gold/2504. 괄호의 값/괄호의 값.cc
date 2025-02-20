#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string input;
    cin >> input;
    
    stack<char> st;
    int result = 0;
    int temp = 1;
    
    for (int i = 0; i < input.size(); i++) {
        char ch = input[i];
        
        // 여는 괄호일 때
        if (ch == '(') {
            st.push(ch);
            temp *= 2;
        } else if (ch == '[') {
            st.push(ch);
            temp *= 3;
        }
        // 닫는 괄호일 때
        else if (ch == ')') {
            // 스택이 비어있거나 짝이 맞지 않으면 잘못된 괄호열
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            // 바로 이전 문자가 여는 괄호면 값을 더함
            if (input[i - 1] == '(')
                result += temp;
            st.pop();
            temp /= 2;
        } else if (ch == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (input[i - 1] == '[')
                result += temp;
            st.pop();
            temp /= 3;
        }
    }
    
    // 남아있는 괄호가 있다면 올바르지 않은 괄호열
    if (!st.empty())
        cout << 0;
    else
        cout << result;
    
    return 0;
}

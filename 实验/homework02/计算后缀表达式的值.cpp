#include <bits/stdc++.h>

using namespace std;

int main(void) {
    stack<int> stk;
    string str;	
    cin >> str;
    
    for (int i = 0; i < (int)str.size();i ++) {
        if (str[i] >= '0' && str[i] <= '9') {
            stk.push(str[i] - '0'); 
        } else {
            if (stk.size() < 2) {
                return 1;
            }

            int val1 = stk.top(); stk.pop(); 
            int val2 = stk.top(); stk.pop(); 

            switch (str[i]) {
                case '+':
                    stk.push(val2 + val1);
                    break;
                case '-':
                    stk.push(val2 - val1);
                    break;
                case '*':
                    stk.push(val2 * val1);
                    break;
                case '/':
                    if (val1 == 0) {
                        return 1; 
                    }
                    stk.push(val2 / val1);
                    break;
                default:
                    cout << str[i] << endl;
                    return 1;
            }
        }
    }

    if (stk.size() != 1) {
        return 1; 
    }

    cout << stk.top() << endl;

    return 0;
}

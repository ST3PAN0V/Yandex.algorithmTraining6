#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    string inp;
    getline(cin, inp);
    stack<int> st;
    for (const char ch : inp) {
        if (ch == ' ') continue;
        if ('0' <= ch && ch <= '9') st.push(ch-'0');
        else {
            int oper1 = st.top();
            st.pop();
            int oper2 = st.top();
            st.pop();
            if (ch == '+') {
                st.push(oper1+oper2);
            } else if (ch == '-') {
                st.push(oper2-oper1);
            } else {
                st.push(oper1*oper2);
            }
        }
    }
    cout << st.top() << endl;
}

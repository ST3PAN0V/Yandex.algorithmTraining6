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
    stack<char> st;
    for (int i = 0; i < inp.size(); i++) {
        if (!st.empty() && ((st.top() == '(' && inp[i] == ')') || (st.top() == '[' && inp[i] == ']') || (st.top() == '{' && inp[i] == '}'))) {
            st.pop();
        } else st.push(inp[i]);
    }
    if (st.empty()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

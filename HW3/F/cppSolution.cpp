#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

void pushInSt(stack<char>& st, char symbol) {
    if (!st.empty() && ((st.top() == '(' && symbol == ')') || (st.top() == '[' && symbol == ']'))) st.pop();
    else st.push(symbol);
}

int main() {
    int n;
    string order;
    string inp;
    stack<char> st;
    int openParen = 0;
    int closeParen = 0;
    int openSqu = 0;
    int closeSqu = 0;
    cin>>n;
    cin>>order;
    cin>>inp;
    for (int i = 0; i < inp.size(); i++) {
        if (inp[i] == '[') openSqu++;
        else if (inp[i] == ']') closeSqu++;
        else if (inp[i] == '(') openParen++;
        else closeParen++;
        pushInSt(st, inp[i]);
    }
    while((openParen + openSqu + closeSqu + closeParen) != n) {
        for (int i = 0; i < 4; i++) {
            if (order[i] == '(') {
                if (openSqu + openParen < n/2) {
                    pushInSt(st, '(');
                    inp += '(';
                    openParen++;
                    break;
                }
            } else if (order[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    pushInSt(st, ')');
                    inp += ')';
                    closeParen++;
                    break;
                }
            } else if (order[i] == '[') {
                if (openSqu + openParen < n/2) {
                    pushInSt(st, '[');
                    inp += '[';
                    openSqu++;
                    break;
                }
            } else {
                if (!st.empty() && st.top() == '[') {
                    pushInSt(st, ']');
                    inp += ']';
                    closeSqu++;
                    break;
                }
            }
        }
    }
    cout << inp << endl;
}

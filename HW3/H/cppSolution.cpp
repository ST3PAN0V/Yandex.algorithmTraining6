#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n;
    cin>>n;
    stack<int> st;
    vector<long int> summpr = {0};

    while(n--) {
        string oper;
        cin>>oper;
        if (oper[0] == '-') {
            cout << st.top() << endl;
            st.pop();
            summpr.pop_back();
        } else if (oper[0] == '+') {
            int num = stoi(oper.substr(1));
            st.push(num);
            summpr.push_back(summpr[summpr.size()-1] + num);
        } else {
            int sz = summpr.size();
            int knum = stoi(oper.substr(1));
            cout << abs(summpr[sz-1-knum] - summpr[sz-1])<< endl;
        }
    }
}


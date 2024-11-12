#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> inp(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }
    stack<pair<int,int>> st;
    for (int i = 0; i < n; i++) {
        while(!st.empty() && (st.top().first > inp[i])) {
            ans[st.top().second] = i;
            st.pop();
        }
        st.push({inp[i], i});
    }
    while (!st.empty()) {
        ans[st.top().second] = -1;
        st.pop();
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

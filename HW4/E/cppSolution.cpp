#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n;
    cin>>n;
    unordered_map<int, vector<int>> tree;
    unordered_map<int, int> son_parent;
    stack<int> revers_order;
    vector<int> ans(n+1, 1);
    int sz = n;
    n--;
    while(n--) {
        int top1, top2;
        cin>>top1>>top2;
        tree[top1].push_back(top2);
        tree[top2].push_back(top1);
    }
    // --- find out tops depth ---

    stack<int> stmain;
    stack<int> sthelp;
    stmain.push(1);
    int cur_top;
    while(!stmain.empty()) {
        while (!stmain.empty()) {
            cur_top = stmain.top();
            stmain.pop();
            revers_order.push(cur_top);
            for (const auto top : tree[cur_top]) {
                if (son_parent[top] == 0 && top != 1) {
                    son_parent[top] = cur_top;
                    sthelp.push(top);
                }
            }
        }
        while (!sthelp.empty()) {
            stmain.push(sthelp.top());
            //son_parent[sthelp.top()] = cur_top;
            sthelp.pop();
        }
    }
    // --- calculate ans ---
    while(!revers_order.empty()) {
        cur_top = revers_order.top();
        revers_order.pop();
        ans[son_parent[cur_top]] += ans[cur_top];
    }

    // --- print anses ---
    for (int i = 1; i < sz + 1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl; 
}

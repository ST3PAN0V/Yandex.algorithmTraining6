#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> son_parent(n+1);
    vector<int> employ_basa(n+1, 1);
    unordered_map<int, vector<int>> workers;
    vector<long long int> ans(n+1, 1);

    for (int i = 1; i < n; i++) {
        cin >> son_parent[i+1];
        workers[son_parent[i+1]].push_back(i+1);
    }
    deque<int> dq;
    vector<int> min_order;
    min_order.reserve(n);
    dq.push_back(1);
    while(!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        min_order.push_back(cur);
        for (const auto top : workers[cur]) {
            dq.push_back(top);
        }
    }
    for (int i = n-1; i > 0; i--) {
        employ_basa[son_parent[min_order[i]]] += employ_basa[min_order[i]];
    }
    for (int i = n-1; i >= 0; i--) {
        long long int profit = 0;
        int cur_top = min_order[i];
        for(const auto worker : workers[cur_top]) {
            profit += ans[worker] + employ_basa[worker];
        }
        ans[cur_top] += profit;
    }
    for (int i = 1; i < n+1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}


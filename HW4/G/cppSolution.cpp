#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <stack>
#include <math.h>

using namespace std;

#define ll long long int

ll useFreeTops(int n, int freeTops, ll k) {
    ll ans = 1;
    n += 2;
    for (int i = 0; i < freeTops; i++) {
        ans *= n+i;
        ans %= k;
    }
    return ans;
}

bool is_real_to_solve(const vector<vector<int>>& tops, vector<vector<int>>& trees, int& free_tops) {
    vector<bool> visited(tops.size(), false);
    visited[0] = true;
    int pointer = 0;
    while (++pointer < tops.size()) {
        if (visited[pointer]) continue;
        int timer = 0;
        vector<int> path_tree;
        deque<pair<int, int>> dfs_deq;
        dfs_deq.push_back({pointer, 0});
        while(!dfs_deq.empty()) {
            int cur_top = dfs_deq.front().first;
            int prev_top = dfs_deq.front().second;
            dfs_deq.pop_front();
            path_tree.push_back(cur_top);
            if (visited[cur_top]) return false;
            visited[cur_top] = true;
            int count_of_subtree = 0;
            for (const auto top : tops[cur_top]) {
                if (tops[top].size() > 1) count_of_subtree++;
                if (top != prev_top) dfs_deq.push_back({top, cur_top});
            }
            if (count_of_subtree > 2) return false;
        }
        if (path_tree.size() <= 1) {
            free_tops++;
        } else {
            trees.push_back(path_tree);
        }
    }
    return true;
}

ll factorial(int val, ll k) {
    if (val == 0) return 1;
    ll ans = 1;
    for (int i = 1; i <= val; i++) {
        ans *= i;
        ans %= k;
    }
    return ans;
}

ll find_ans_to_tree(vector<vector<int>>& trees, const vector<vector<int>>& tops, ll k) {
    ll ans = 1;
    for (const auto& vec : trees) {
        ll local_ans = 1;
        deque<pair<int, int>> dfs_deq;
        bool flag = false;
        dfs_deq.push_back({vec[0], 0});
        while(!dfs_deq.empty()) {
            int cur_top = dfs_deq.front().first;
            int prev_top = dfs_deq.front().second;
            dfs_deq.pop_front();

            int count_of_subtree = 0;
            int single_tops = 0;
            if (tops[cur_top].size() == 1 && vec.size() != 2) {
                dfs_deq.push_back({tops[cur_top][0], 0});
                continue;
            }
            for (const auto top : tops[cur_top]) {
                if (tops[top].size() > 1) count_of_subtree++;
                if (tops[top].size() == 1) single_tops++;
                if (top != prev_top && tops[top].size() > 1) dfs_deq.emplace_back(top, cur_top);
            }
            local_ans *= factorial(single_tops, k);
            local_ans %= k;
            if ((count_of_subtree >= 1) && !flag) {
                local_ans *= 2;
                local_ans %= k;
                flag = true;
            }
        }
        local_ans *= 2;
        local_ans %= k;
        ans *= local_ans;
        ans %= k;
    }
    return ans;
}

int main() {
    int n, m;
    ll k;
    //ifstream file("044.txt");
    cin>>n>>m>>k;
    vector<vector<int>> tops(n+1);
    vector<vector<int>> trees;
    int free_tops = 0;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int top1, top2;
        cin>>top1>>top2;
        tops[top1].push_back(top2);
        tops[top2].push_back(top1); 
    }
    if (is_real_to_solve(tops,  trees, free_tops)) {
        ans += find_ans_to_tree(trees, tops, k);

        int T = trees.size();

        ans *= factorial(T, k);

        ans *= useFreeTops(n-free_tops, free_tops, k);
        ans %= k;
        cout << ans << endl;
    } else {
        cout << ans << endl;
    }
}


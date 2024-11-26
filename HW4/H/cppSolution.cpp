#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#define ll long long int

using namespace std;

ll minim(ll a, ll b) {
    if (a < b) return a;
    else return b;
}

void dfs(vector<int>& parents, vector<vector<ll>>& dp, vector<int>& cost, vector<vector<int>>& adj, int cur_top, int p) {
    parents[cur_top] = p;
    dp[cur_top][0] = 0;
    dp[cur_top][1] = cost[cur_top];
    for (const int top : adj[cur_top]) {
        if (top == p) continue;
        dfs(parents, dp, cost, adj, top, cur_top);
        dp[cur_top][0] += dp[top][1];
        dp[cur_top][1] += minim(dp[top][0], dp[top][1]);
    }
}

void restore(int cur_top, int p, bool state, vector<bool>& visited, vector<vector<int>>& adj, vector<vector<ll>>& dp) {
    if (state) {
        visited[cur_top] = true;
    }
    for (const int top : adj[cur_top]) {
        if (top == p) continue;
        if (!state) {
            restore(top, cur_top, true, visited, adj, dp);
        } else {
            if (dp[top][0] < dp[top][1]) restore(top, cur_top, false, visited, adj, dp);
            else restore(top, cur_top, true, visited, adj, dp);
        }
    }
}

int countVisited(vector<bool>& visited) {
    int count = 0;
    for (int i = 1; i <= visited.size(); i++) {
        if (visited[i]) count++;
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int> cost(n+1);
    vector<int> parents(n+1);
    vector<bool> visited(n+1);
    for (int i = 0; i+1 < n; i++) {
        int top1, top2;
        cin>>top1>>top2;
        adj[top1].push_back(top2);
        adj[top2].push_back(top1);
    }
    for (int i = 1; i <= n; i++) {
        cin>>cost[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(2));
    
    dfs(parents, dp, cost, adj, 1, -1);

    ll minCost = 0;
    if (dp[1][0] < dp[1][1]) {
        minCost = dp[1][0];
        restore(1, -1, false, visited, adj, dp);
    } else {
        minCost = dp[1][1];
        restore(1, -1, true, visited, adj, dp);
    }
    if (n == 1) {
        cout << cost[1] << " " << n << endl;
        cout << 1 << endl;
    } else {
        cout << minCost << " " << countVisited(visited) << endl;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}


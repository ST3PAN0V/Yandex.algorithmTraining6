#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <deque>

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> inp(n);
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }
    for (int i = 0; i+1 < k; i++) {
        while(!dq.empty() && (dq.back().first > inp[i])) {
            dq.pop_back();
        }
        dq.push_back({inp[i], i});
    }
    for (int i = k-1; i < n; i++) {
        while(!dq.empty() && (dq.back().first > inp[i])) {
            dq.pop_back();
        }
        dq.push_back({inp[i], i});
        if (dq.front().second < i-k+1) dq.pop_front();
        cout << dq.front().first << endl;
    }
}

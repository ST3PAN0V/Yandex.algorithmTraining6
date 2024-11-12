#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void pushInDeq(deque<pair<int, int>>& deqmax, vector<vector<int>>& comp, int idx) {
    int height1 = idx-1 >= 0 ? comp[idx-1][1] : comp[idx][1];
    int num = comp[idx][1] - height1;
    while(!deqmax.empty() && deqmax.back().first < num) {
        deqmax.pop_back();
    }
    deqmax.push_back({num, idx});
}

int GetMaxInDeq(deque<pair<int, int>>& deqmax, int leftidx) {
    while(!deqmax.empty() && deqmax.front().second <= leftidx) {
        deqmax.pop_front();
    }
    return (deqmax.empty() ? 0 : deqmax.front().first);
}

int main() {
    int n, H;
    cin>>n>>H;
    vector<int> height(n);
    vector<int> weidth(n);
    for (int i=0; i < n; i++) {
        cin>>height[i];
    }
    for (int i=0; i < n; i++) {
        cin>>weidth[i];
    }
    vector<vector<int>> comb(n); // {ширина, высота, индекс с 0}
    for (int i=0; i < n; i++) {
        comb[i].push_back(weidth[i]);
        comb[i].push_back(height[i]);
        comb[i].push_back(i);
    }
    sort(comb.begin(), comb.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });
    deque<pair<int,int>> deqMax;
    int left = 0;
    long long int curW = 0;
    int ans = 2147483647;
    for (int right = 0; right < n; right++) {
        curW += comb[right][0];
        pushInDeq(deqMax, comb, right);
        while (curW >= H) {
            ans = min(ans, GetMaxInDeq(deqMax, left));
            curW -= comb[left][0];
            left++;
        }
    }
    cout << ans << endl;
}


#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> v(n);

    for (int i = 0; i < n; i++) { 
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ans = 1;

    int slow = 0;
    int fast = 0;

    while(fast != v.size()) {
        if (v[fast] - v[slow] <= k) {
            fast++;
        } else {
            ans = max(ans, (fast - slow));
            slow++;
        }
    }
    ans = max(ans, (fast - slow));
    cout << ans << endl;
}


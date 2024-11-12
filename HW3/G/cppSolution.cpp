#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n,b;
    cin>>n>>b;
    vector<int> inp(n);
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cin>>tmp;
        inp[i] = tmp;
    }
    long long int qu = 0;
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
        qu += static_cast<long long int>(inp[i]);
        ans += static_cast<long long int>(qu);
        if (qu <= b) {
            qu = 0;
        }
        else {
            qu -= b;
        }
    }
    ans += qu;
    cout << ans << endl;
}


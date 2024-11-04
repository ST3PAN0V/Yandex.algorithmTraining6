#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cstdint>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }

    vector<long long int> sum(n);
    long long int help_sum = 0;
    for (int i = 0; i < n; i++) {
        help_sum += inp[i];
        sum[i] = help_sum;
    }

    vector<long long int> ltor(n);
    ltor[0] = 0;
    for (int i = 1; i < n; i++) {
        ltor[i] = ltor[i-1] + sum[i-1];
    }

    reverse(inp.begin(), inp.end());
    help_sum = 0;
    for (int i = 0; i < n; i++) {
        help_sum += inp[i];
        sum[i] = help_sum;
    }
    vector<long long int> rtol(n);
    rtol[0] = 0;
    for (int i = 1; i < n; i++) {
        rtol[i] = rtol[i-1] + sum[i-1];
    }
    reverse(rtol.begin(), rtol.end());

    long long int ans = INT64_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, ltor[i] + rtol[i]);
    }
    cout << ans << endl;
}

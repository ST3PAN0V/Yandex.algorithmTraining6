#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    int n;
    const int mod = 1'000'000'007;
    cin>>n;
    vector<long long int> nums(n);
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }

    vector<long long int> sum(n);
    long long int hlp_sum=0;

    for (int i = 0; i < n; i++) {
        hlp_sum += nums[i];
        hlp_sum %= mod;
        sum[i] = hlp_sum;
    }
    long long int ans = 0;
    

    for (int i = 1; i < n-1; i++) {
        ans += (static_cast<long long int>(((nums[i] * sum[i-1]) % mod)) * (static_cast<long long int>(sum[n-1]-sum[i]%mod))) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}

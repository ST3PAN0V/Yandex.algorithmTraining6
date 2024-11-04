#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> cars(n);

    for (int i = 0; i < n; i++) {
        cin >> cars[i];
    }

    int sum=0;
    unordered_map<int,int> mp;
    int ans=0;
    mp[0]++;
    for (int i = 0; i < n; i++) {
        sum += cars[i];
        if (mp.find(sum-k) != mp.end()) {
            ans += mp[sum-k];
        }
        mp[sum]++;
    }
    cout << ans << endl;
}


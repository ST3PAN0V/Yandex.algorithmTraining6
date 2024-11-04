#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin>>n;
    int r;
    cin>>r;
    vector<int> monument(n);

    for (int i = 0; i < n; i++) { 
        cin >> monument[i];
    }

    int left = 0;
    int right = 0;
    long long int ans = 0;
    while(right < n) {
        if (monument[right]-monument[left] > r) {
            ans += n - right;
            left++;
        } else right++;
    }
    cout << ans << endl;
}

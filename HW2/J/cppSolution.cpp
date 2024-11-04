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
    vector<int> artef(n);
    for (int i =0;i<n;i++) {
        cin>>artef[i];
    }
    int m,k;
    cin>>m>>k;
    vector<int> need(m);
    for (int i =0;i<m;i++) {
        cin>>need[i];
    }
    // -- simple case
    vector<int> counter(n);
    counter[0] = 0;
    for (int i = 1; i<n; i++) {
        counter[i] = counter[i-1] + (artef[i-1] == artef[i] ? 1:0);
    }
    unordered_map<int,int> mp;
    for (int i = n-1; i>=0; i--) {
        mp[counter[i]] = i+1;
    }

    // -- poor case
    vector<int> counterBlock(n);
    counterBlock[0] = 0;
    for (int i = 1; i<n; i++) {
        counterBlock[i] = counterBlock[i-1] + (artef[i-1] > artef[i] ? 1:0);
    }
    unordered_map<int,int> mpBlock;
    for (int i = n-1; i>=0; i--) {
        mpBlock[counterBlock[i]] = i+1;
    }

    // -- ans
    for (auto i : need) {
        int local_ans = -1;
        int block = counterBlock[i-1];
        if (mpBlock[block] == 1) {
            local_ans = max(local_ans, mpBlock[0]);
        } else {
            local_ans = max(local_ans, mpBlock[block]);
        }
        int simple = counter[i-1];
        if (simple-k <= 0) local_ans = max(local_ans, mp[0]);
        else {
            local_ans = max(local_ans, mp[simple-k]);
        }
        cout << local_ans << " ";
    }
    cout << endl;
}

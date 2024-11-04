#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) { 
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> ans(v.size());
    int p = v.size()-1;
    int r =v.size()-1;
    int l = 0;
    while(l<r) {
        ans[p--] = v[r--];
        ans[p--] = v[l++];
    }
    if (v.size()%2 != 0) ans[p--] = v[v.size()/2];
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}


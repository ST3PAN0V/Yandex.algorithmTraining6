#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> ans(n+1, 0);
    for (int i = 1; i < n+1; i++) {
        int tmp;
        cin>>tmp;
        ans[i] = ans[i-1] + tmp;
    }
    for (int i = 1; i < n+1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}


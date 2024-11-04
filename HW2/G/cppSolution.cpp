#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    long long int n, k;
    cin>>n>>k;
    string* s = new string();
    cin>>*s;
    int left = 0, right = 0;
    int ans = 0;
    int count_a = 0, count_b = 0;
    long long int curRude = 0;

    while(right < n) {
        if (curRude <= k) {
            if ((*s)[right] == 'a') count_a++;
            if ((*s)[right] == 'b') {
                count_b++;
                curRude += count_a;
            }
        } else {
            while(curRude > k) {
                if ((*s)[left] == 'a') {
                    count_a--;
                    curRude -= count_b;
                }
                if ((*s)[left] == 'b') count_b--;
                left++;
            }
        }
        if (curRude <= k) ans = max(ans, right - left + 1);
        if (curRude <= k) right++;
    }
    cout << ans << endl; 
}

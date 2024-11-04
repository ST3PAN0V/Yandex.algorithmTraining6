#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cstdint>

using namespace std;

struct algo {
    int number=-1;
    int a = -1;
    int b = -1;
    algo(int num, int a, int b) : number(num), a(a), b(b) {}
    algo() :  number(-1), a(-1), b(-1) {}
};

int main() {
    int n;
    cin>>n;
    vector<int> inpA(n);
    for (int i = 0; i < n; i++) {
        cin >> inpA[i];
    }

    vector<int> inpB(n);
    for (int i = 0; i < n; i++) {
        cin >> inpB[i];
    }

    vector<int> inp(n);
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }

    vector<algo> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = algo(i+1, inpA[i], inpB[i]);
    }

    
    vector<algo> sortedA = vec;
    vector<algo> sortedB = vec;
    sort(sortedA.begin(), sortedA.end(), [](const algo& a, const algo& b){
        return a.a > b.a || (a.a == b.a && (a.b > b.b || (a.b == b.b && a.number < b.number)));
    });

    sort(sortedB.begin(), sortedB.end(), [](const algo& a, const algo& b){
        return a.b > b.b || (a.b == b.b && (a.a > b.a || (a.a == b.a && a.number < b.number)));
    });

    unordered_map<int, bool> mp(false);
    int pa=0;
    int pb=0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (inp[i] == 0 && pa < n) {
            if (mp[sortedA[pa].number] == false) { // если не изучал еще алгос
                ans.push_back(sortedA[pa].number);
                mp[sortedA[pa].number] = true;
                pa++;
            } else {
                while(pa != n) {
                    if (mp[sortedA[pa].number] == false) {
                        ans.push_back(sortedA[pa].number);
                        mp[sortedA[pa].number] = true;
                        pa++;
                        break;
                    }
                    pa++;
                }
            }
        } else if (inp[i] == 1 && pb < n) {
            if (mp[sortedB[pb].number] == false) { // если не изучал еще алгос
                ans.push_back(sortedB[pb].number);
                mp[sortedB[pb].number] = true;
                pb++;
            } else {
                while(pb != n) {
                    if (mp[sortedB[pb].number] == false) {
                        ans.push_back(sortedB[pb].number);
                        mp[sortedB[pb].number] = true;
                        pb++;
                        break;
                    }
                    pb++;
                }
            }
        } else break;
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

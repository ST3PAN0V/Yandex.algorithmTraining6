#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

string solver(unordered_map<string, vector<string>>& mp, unordered_map<string, string>& child_parents, const string& mem1, const string& mem2, string& ans, const string& king) {
    unordered_map<string, int> counter;
    counter[mem1]++;
    counter[mem2]++;
    string cur = mem1;
    while(child_parents[cur] != "-1") {
        counter[child_parents[cur]] += counter[cur];
        cur = child_parents[cur];
    }
    cur = mem2;
    while(ans == "") {
        if (counter[cur] == 2) ans = cur;
        counter[child_parents[cur]] += counter[cur];
        cur = child_parents[cur];
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    n--;
    unordered_map<string, vector<string>> mp;
    unordered_map<string, string> child_parents;
    unordered_map<string, int> king_list;
    string true_king;
    while(n--) {
        string parent, child;
        cin>>child>>parent;
        king_list[child]++;
        mp[parent].push_back(child);
        child_parents[child] = parent;
    }
    for (const auto& pr : mp) {
        if (king_list[pr.first] == 0) {
            true_king = pr.first;
            break;
        }
    }
    child_parents[true_king] = "-1";
    string fm, sm;
    while(cin>>fm>>sm) {
        string ans = "";
        cout <<  solver(mp, child_parents, fm, sm, ans, true_king) << endl;
    }
}

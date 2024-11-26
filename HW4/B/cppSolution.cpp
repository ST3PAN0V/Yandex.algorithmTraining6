#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

int solver(unordered_map<string, vector<string>>& mp, map<string, int>& anses, const string& cur) {
    int all_child = 0;
    for (const auto& el : mp[cur]) {
        int tmp = solver(mp, anses, el);
        all_child += tmp;
    }
    anses[cur] = all_child;
    return all_child+1;
}

int main() {
    int n;
    cin>>n;
    n--;
    unordered_map<string, vector<string>> mp;
    map<string, int> anses;
    unordered_map<string, int> king_list;
    string true_king;
    while(n--) {
        string parent, child;
        cin>>child>>parent;
        king_list[child]++;
        mp[parent].push_back(child);
    }
    for (const auto& pr : mp) {
        if (king_list[pr.first] == 0) {
            true_king = pr.first;
            break;
        }
    }
    int counter = 0;
    solver(mp, anses, true_king);
    for (const auto& el : anses) {
        cout << el.first << " " << el.second << endl;
    }
}

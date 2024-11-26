#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

void solver(unordered_map<string, vector<string>>& mp, map<string, int>& anses, int counter, const string& cur) {
    anses[cur] = counter;
    for (const auto& el : mp[cur]) {
        solver(mp, anses, counter+1, el);
    }
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
    solver(mp, anses, counter, true_king);
    for (const auto& el : anses) {
        cout << el.first << " " << el.second << endl;
    }
}

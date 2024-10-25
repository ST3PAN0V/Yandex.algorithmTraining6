#include <vector>
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<pair<int,int>> var;
    if (a != 0 && c != 0) {
        if (b != 0 && d != 0) {
            var.emplace_back(b+1, d+1);
            var.emplace_back(max(a,b)+1, 1);
            var.emplace_back(1, max(c,d)+1);
        }
        else if (b != 0 && d == 0) var.emplace_back(b+1, 1);
        else if (b == 0 && d != 0) var.emplace_back(1, d+1);
        else var.emplace_back(1, 1);
    }
    if (b != 0 && d != 0) {
        if (a != 0 && c != 0) var.emplace_back(a+1, c+1);
        else if (a != 0 && c == 0) var.emplace_back(a+1, 1);
        else if (a == 0 && c != 0) var.emplace_back(1, c+1);
        else var.emplace_back(1, 1);
    }
    sort(var.begin(), var.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.first + a.second < b.first + b.second;
    });

    cout << var[0].first << " " << var[0].second << endl;
}
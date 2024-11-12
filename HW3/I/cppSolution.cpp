#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <deque>

using namespace std;

bool dequesEmpty(const vector<deque<pair<int,int>>>& roads) {
    return (roads[0].empty() && roads[1].empty() && roads[2].empty() && roads[3].empty());
}

int circlOf4Down(int num) {
    if (num == 0) return 3;
    else return num-1;
}

int circlOf4Up(int num) {
    return (num+1)%4;
}

int circlOf4other(int num) {
    return (num+2)%4;
}

int main() {
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    vector<deque<pair<int,int>>> roads(4);
    vector<bool> mainroads(4, false);
    vector<int> ans(n);
    vector<vector<pair<int, int>>> preproads(4);
    mainroads[a-1] = true;
    mainroads[b-1] = true;
    int index=0;
    while(n--) {
        int d, t;
        cin>>d>>t;
        preproads[d-1].push_back({index++, t});
    }
    
    for (int i = 0; i < 4; i++) {
        sort(preproads[i].begin(), preproads[i].end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.second < b.second;
        });
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < preproads[i].size(); j++) {
            roads[i].push_back({preproads[i][j].first, preproads[i][j].second});
        }
    }
    int time=1;
    vector<bool> queue_of_ans(4, false);
    while (!dequesEmpty(roads)) {
        for (int i = 0; i<4; i++) {
            if (!roads[i].empty() && roads[i].front().second <= time) {
                if (mainroads[i] == true) {
                    if (mainroads[circlOf4Down(i)] != true || roads[circlOf4Down(i)].empty() || roads[circlOf4Down(i)].front().second > time) {
                        ans[roads[i].front().first] = time;
                        queue_of_ans[i] = true;
                    }
                } else {
                    if (((mainroads[circlOf4Up(i)] != true || roads[circlOf4Up(i)].empty() || roads[circlOf4Up(i)].front().second > time) && (roads[circlOf4Down(i)].empty() || roads[circlOf4Down(i)].front().second > time)) && (mainroads[circlOf4other(i)] != true || roads[circlOf4other(i)].empty() || roads[circlOf4other(i)].front().second > time)) {
                        ans[roads[i].front().first] = time;
                        queue_of_ans[i] = true;
                    }
                }
            } 
        }
        for (int i = 0; i < 4; i++) {
            if (queue_of_ans[i] == true) {
                queue_of_ans[i] = false;
                ans[roads[i].front().first] = time;
                roads[i].pop_front();
            }
        }
        time++;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}



#include <vector>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

struct Point {
    int x = 0;
    int y = 0;
    string name = "";
};

int main() {
    int xSW,ySW;
    int xNE,yNE;
    int x,y;
    cin>>xSW>>ySW>>xNE>>yNE>>x>>y;
    Point SW{xSW, ySW, "SW"};
    Point NE{xNE, yNE, "NE"};
    Point NW{xSW, yNE, "NW"};
    Point SE{xNE, ySW, "SE"};
    Point target{x,y, "None"};
    if (target.y > NE.y) {
        if (NW.x > target.x) cout << NW.name << endl;
        else if (NE.x < target.x) cout << NE.name << endl;
        else cout << "N" << endl;
    } else if (target.y >= SW.y) {
        if (SW.x > target.x) cout << "W" << endl;
        else cout << "E" << endl;
    } else {
        if (SW.x > target.x) cout << SW.name << endl;
        else if (SE.x < target.x) cout << SE.name << endl;
        else cout << "S" << endl;
    }
}
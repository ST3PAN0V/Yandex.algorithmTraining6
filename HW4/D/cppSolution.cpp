#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Tree {
private:
    struct Node {
        Node* right;
        Node* left;
        int val;
        Node(): val(0), right(nullptr), left(nullptr) {};
        Node(int val): val(val), right(nullptr), left(nullptr) {};
    };
    Node* root;

    void PrintDots(int number) {
        for (int i = 0; i < number; i++) {
            cout << '.';
        }
    }

    void rec(Node* cur, int depth) {
        if (!cur) return;
        rec(cur->left, depth+1);
        PrintDots(depth);
        cout << cur->val << endl;
        rec(cur->right, depth+1);
    }
public:
    Tree(): root(nullptr) {}

    bool findElem(int val) {
        Node* cur = root;
        while (cur != nullptr) {
            if (val == cur->val) return true;
            if (val > cur->val) cur = cur->right;
            else cur = cur->left;
        }
        return false;
    }
    bool addElem(int val) {
        if (root == nullptr) {
            root = new Node(val);
            return true;
        }
        Node* cur = root;
        while (true) {
            if (val == cur->val) return false;
            if (val > cur->val) {
                if (cur->right == nullptr) {
                    cur->right = new Node(val);
                    return true;
                }
                cur = cur->right;
            } else {
                if (cur->left == nullptr) {
                    cur->left = new Node(val);
                    return true;
                }
                cur = cur->left;
            }
        }
    }

    void print() {
        rec(root, 0);
    }
};

int main() {
    string input;
    Tree tree;
    while(cin>>input) {
        if (input == "ADD" || input == "SEARCH") {
            int number = 0;
            cin>>number;
            if (input == "ADD") {
                if (tree.addElem(number)) cout << "DONE" << endl;
                else cout << "ALREADY" << endl;
            } else {
                if (tree.findElem(number)) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
        else {
            tree.print();
        }
    }
}

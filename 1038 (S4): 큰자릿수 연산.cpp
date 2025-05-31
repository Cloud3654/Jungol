#include <iostream>
using namespace std;
int main() {
    string s1, op, s2; cin >> s1 >> op >> s2;
    if (op == "+") {
        if (s1 == s2) {
            cout << 2;
            for (int i = 0; i < s2.size() - 1; i++) cout << 0;
        }
        else {
            cout << 1;
            for (int i = 0; i < abs((int) s1.size() - (int) s2.size()) - 1; i++) cout << 0;
            if (s1.size() < s2.size()) cout << s1;
            else cout << s2;
        }
    }
    else {
        cout << 1;
        for (int i = 0; i < s1.size() + s2.size() - 2; i++) cout << 0;
    }
}

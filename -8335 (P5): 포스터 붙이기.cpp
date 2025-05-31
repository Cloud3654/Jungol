#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> b;
vector<int> h;
int poster = 0;
void loop() {
    int min_h = 1e9 + 1;
    for (auto& p : h) {
        if (p == 0) continue;
        if (p < min_h) min_h = p, p = 0, poster++;
        else p -= min_h;
    }
}
int main() {
    int cnt; cin >> cnt, b.resize(cnt);
    for (auto& p : b) cin >> p.first >> p.second;
    for (auto p : b) h.push_back(p.second);
    while (*max_element(h.begin(), h.end())) {
        loop();
        for (auto p : h) cout << p << ' '; cout << ": " << poster << endl; 
    }
    cout << poster;
}

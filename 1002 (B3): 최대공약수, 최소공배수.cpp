#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
int main() {
	int ncnt; cin >> ncnt;
	vector<int> v(ncnt);
	for (auto& k : v) cin >> k;
	pair<int, int> p = { v[0], v[0] };
	v.erase(v.begin());
	for (auto k : v) {
		p.first = gcd(p.first, k);
		p.second = lcm(p.second, k);
	}
	cout << p.first << ' ' << p.second;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int n; cin >> n;
	double sn = sqrt(n);
	vector<int> d;
	if ((int)sn * (int)sn == n) d.push_back(sn);
	for (int i = 1; i < sn; i++) {
		if (n % i == 0) {
			d.push_back(i);
			d.push_back(n / i);
		}
	}
	sort(d.begin(), d.end());
	for (auto k : d) cout << k << ' ';
}

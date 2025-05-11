#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(int n) {
	double sn = sqrt(n);
	bool isP = true;
	for (int i = 2; i <= sn; i++) {
		isP = (n % i != 0);
		if (!isP) break;
	}
	return isP;
}
int max_prime_divisor(int n) {
	double sn = sqrt(n);
	int mpd = 0;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0 && isPrime(i)) mpd = i;
	}
	return mpd;
}
int main() {
	int cnt; cin >> cnt;
	int mpdn, mpd = 0, n;
	while (cnt--) {
		cin >> n;
		if (max_prime_divisor(n) > mpd) mpdn = n, mpd = max_prime_divisor(n);
	}
	cout << mpdn;
}

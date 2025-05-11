#include <iostream>
using namespace std;
long gcd(long a, long b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return abs(a * b) / gcd(a, b); }
int main() {
	int p, v, k; cin >> p >> v >> k;
	long long b = k / lcm(p + 1, v + 1);
	long long c = k / (v + 1) - b;
	long long d = k / (p + 1) - b;
	long long a = k - b - c - d;
	printf("%ld %ld %ld %ld", a, b, c, d);
}

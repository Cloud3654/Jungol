#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;
int main() {
	int cnt; cin >> cnt;
	vector<int> val(cnt), dev(cnt);
	for (auto& p : val) cin >> p;
	int sum = accumulate(val.begin(), val.end(), 0);
	double avg = (double) sum / cnt;
	for (int i = 0; i < cnt; i++) dev[i] = pow(val[i] - avg, 2);
	double div = sqrt(accumulate(dev.begin(), dev.end(), 0.0) / cnt);
	cout << sum << endl;
	if (fmod(round(avg * 10) / 10, 1.0) == 0) cout << round(avg) << endl;
	else printf("%.1f\n", avg);
	if (fmod(round(div * 10) / 10, 1.0) == 0) cout << round(div);
	else printf("%.1f", div);
}

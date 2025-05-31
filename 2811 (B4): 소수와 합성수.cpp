#include <iostream>
#include <cmath>
using namespace std;
int isPrime(int n) {
    double sn = sqrt(n);
    bool isP = true;
    for (int i = 2; i <= sn; i++) {
        if (!isP) break;
        if (n % i == 0) isP = false;
    }
    return isP;
}
int main() {
    int num[5];
    for (auto& p : num) cin >> p;
    for (auto p : num) {
        if (p == 1) cout << "number one";
        else if (isPrime(p)) cout << "prime number";
        else cout << "composite number";
        cout << endl;
    }
}

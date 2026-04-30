#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

void solve(int a, int b, int c, int &x, int &y) {
    int d, xx, yy;
    d = gcd(a, b, xx, yy);

    if (c % d != 0) {
        x = 0;
        y = 0;
        return;
    }

    long long cd = c / d;
    long long bx = b / d;
    long long ay = a / d;

    long long X = cd * xx;
    long long Y = cd * yy;

    long long t = -(cd * xx / bx);
    X = cd * xx + bx * t;
    Y = cd * yy - ay * t;

    if (X < 0) {
        X = cd * xx + bx;
        Y = cd * yy - ay;
    }

    x = static_cast<int>(X);
    y = static_cast<int>(Y);
}


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    solve(a, b, c, x, y);
    cout << x << " " << y << endl;
    return 0;
}

int gcd_ext(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

void solve(int a, int b, int c, int& x, int& y) {
    int d = gcd_ext(a, b, x, y);
    
    if (c % d != 0) {
        x = 0;
        y = 0;
        return;
    }
    
    int x0 = x * (c / d);
    int y0 = y * (c / d);
    
    int k = 0;
    if (b != 0) {
        k = -x0 / (b / d);
        if (x0 + (b / d) * k < 0) {
            k++;
        }
    }
    
    x = x0 + (b / d) * k;
    y = y0 - (a / d) * k;
    
    while (x < 0 && b != 0) {
        k++;
        x = x0 + (b / d) * k;
        y = y0 - (a / d) * k;
    }
    
    if (x < 0) {
        x = 0;
        y = 0;
    }
}

// алгоритм
// https://www.cyberforum.ru/python-beginners/thread2709286.html

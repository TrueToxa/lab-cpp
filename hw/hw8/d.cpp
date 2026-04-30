#include <iostream>
using namespace std;

int main() {
    int flag = 0;
    char ch = getchar();
    while (ch == '(' or ch == ')') {
        switch (ch) {
            case '(': flag++;break;
            case ')': flag--;
                if (flag < 0) {
                    cout << "NO" << endl;
                    return 0;
                } break;
        }
        ch = getchar();
    }
    if (flag == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
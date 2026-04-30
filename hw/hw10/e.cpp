#include <iostream>
using namespace std;

int max(int lhv, int rhv) {
    if (lhv>=rhv) return lhv;
    return rhv;
}
int min(int lhv, int rhv) {
    if (lhv<=rhv) return lhv;
    return rhv;
}

int main() {
    std::string s1;
    std::string s2;
    std::cin >> s1 >> s2;
    int l1 = s1.length();
    int l2 = s2.length();


    int** dp = new int*[l1 + 1];
    for (int i = 0; i <= l1; i++) {
        dp[i] = new int[l2 + 1];
        for (int j = 0; j <= l2; j++) {
            dp[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i-1]==s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int dnk_sovp = dp[l1][l2];
    cout << dnk_sovp * 100 / min(l1, l2) << endl;
    
    for (int i = 0; i <= l1; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

using std::cout;
using std::cin;
using std::endl;
// using std::string;

// void root(double &destination, int const base, double const epsilon)
// void root(double &destination, double const base, double const epsilon)

void root(double &destination, double const base, double const epsilon) {
    destination = (base)/2;
    double epsilon_x = ((base)-destination*destination)/(2*destination);
    while (epsilon_x > (epsilon/2)*(epsilon/2) || epsilon_x < -(epsilon/2)*(epsilon/2))
    {
        destination = destination+epsilon_x;
        epsilon_x = ((base)-destination*destination)/(2*destination);
        // cout << epsilon_x << ">" << epsilon;
    }
}

int main() {
    int n;
    double epsilon;
    double sqrt;
    cin >> n >> epsilon;
    root(sqrt, n, epsilon);
    // cout << setprecision(7) << scientific;
    cout << sqrt << endl;

}
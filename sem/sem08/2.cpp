#include <iostream>
#include <string>

using namespace std;
enum MathOperators { minus = 45, plus = 43};
int main() {
    string input;
    while (cin >> input) {
        // Do something
        cout << "Someone put: " << input << endl;
        if (input == "-" or input == "+") {\\i td i tp
            cout << " it is math operator";
            switch (static_cast<MathOperators>(input)) {
                case MathOperators::minus:
                    cout << "it's minus";
                    break;
                case MathOperators::plus:
                    cout << "it's minus";
                    break;
                
            }
        }
    }
}
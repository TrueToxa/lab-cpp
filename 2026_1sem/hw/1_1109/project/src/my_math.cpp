// Should be something included here?
#include "my_math.hpp"

AnswerHandler my_sin(double x) {

    // const double pi = 3.141592;
    const double pi = 3.1415926535897932384626433832795;  // M_PI
    const int n = 10;
	AnswerHandler ans;
    ans.x = x;
    ans.sinx=0;

    // приводим к [-pi, pi]
    double new_x = x-static_cast<long long>(x/(2*pi))*2*pi;
    if (new_x > pi)  new_x -= 2*pi;
    if (new_x < -pi) new_x += 2*pi;

    int idx = 1;
    double coeff = 1*new_x;
    while (idx<=2*n+1 and true) //true для будущего определения по точности
    { 
        ans.sinx += coeff;

        coeff *= -1;
        coeff /= (idx+1)*(idx+2);
        coeff *= new_x*new_x;
        idx = idx+2;
    }

    return ans;
    
}

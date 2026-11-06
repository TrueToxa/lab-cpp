#include <cassert>
#include "grid1.hpp"
#include "n_grid1.hpp"

class Param {
public:
    Param (int x) : x(x) {
    }
private:
    int x;
};

int main() {
    Param p(0);
    Grid<Param> g(p);
    Param *ptr = static_cast<Param*>(operator new(sizeof(Param) * 10));
    for (size_t idx = 0; idx < 10; ++idx) {
        *(ptr + idx) = Param(12);
    }
    return 0;
}
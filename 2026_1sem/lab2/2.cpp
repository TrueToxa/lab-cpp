#include <cassert>
#include "grid1.hpp"
#include "n_grid1.hpp"

class Param {
public:
    Param (int x) : x(x) {
    }
    ~Param() = default;
private:
    int x;
};

int main() {
    Param p(0);
    Grid<Param> g(p);
    Grid<Param> g1(1, 1, p);
}
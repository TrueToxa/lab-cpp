#include <cassert>
#include "grid.hpp"
#include "n_grid.hpp"

int main() {
    Grid<float> g(3, 2, 0.0f);
    assert(3 == g.get_y_size());
    assert(2 == g.get_x_size());

    using gsize_t = Grid<int>::size_type;

    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
            assert(0.0f == g[y_idx][x_idx]);

    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
            g[y_idx][x_idx] = 1.0f;

    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
            assert(1.0f == g(y_idx, x_idx));

    std::cout << "NGrid" << std::endl;
    NGrid<float, 4> g4 (1, 2, 6, 7, 3.14);
    NGrid<float, 2> g2(6, 7, 2.71);
    g4[0][0] = g2;
    std::cout << g4(0, 0, 3, 4) << g4(0, 1, 5, 6) << std::endl;

    std::cout << "OK" << std::endl;
    return 0;
}

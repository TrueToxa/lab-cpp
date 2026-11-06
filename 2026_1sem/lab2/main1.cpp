#include <cassert>
// #include "grid1.hpp"
#include "n_grid1.hpp"

// #define _CRTDBG_MAP_ALLOC
// #include <stdlib.h>
// #include <crtdbg.h>


int main() {
    // Grid<float> g(3, 2, 0.0f);
    // assert(3 == g.get_y_size());
    // assert(2 == g.get_x_size());

    // using gsize_t = Grid<int>::size_type;

    // for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
    //     for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
    //         assert(0.0f == g[y_idx][x_idx]);

    // for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
    //     for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
    //         g[y_idx][x_idx] = 1.0f;

    // for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
    //     for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
    //         assert(1.0f == g(y_idx, x_idx));   
             
    {//тест который я написал, забыв что в условии уже есть
        std::cout << "NGrid" << std::endl;
        NGrid<float, 4> g4(1, 2, 6, 7, 3.14);
        std::cout << "ok1" << std::endl;
        NGrid<float, 2> g2(6, 7, 2.71);
        std::cout << "ok2" << std::endl;
        // g4[0][0] = g2;
        std::cout << "ok3" << std::endl;
        std::cout << g4(0, 0, 3, 4) << g4(0, 1, 5, 6) << std::endl;
    }
    // {//тест из задания
    //     NGrid<float, 3> const g3(2, 3, 4, 1.0f);
    //     assert(1.0f == g3(1, 1, 1));
    //     NGrid<float, 2> g2(2, 5, 2.0f);
    //     assert(2.0f == g2(1, 1));
    //     g2 = g3[1];
    //     assert(1.0f == g2(1, 1));
    // }
    std::cout << "OK" << std::endl;

    // _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    // _CrtDumpMemoryLeaks();
    return 0;
}

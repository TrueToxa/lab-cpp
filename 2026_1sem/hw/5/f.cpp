#include <iostream>
#include <cstring>
// В задаче три теста преобразований: 
// std::int64_t -> double, 
// float -> int, 
// int32_t -> uint32_t.

template<typename T, typename U>
T bitCast(U value) {
    T ans;
    std::memcpy(&ans, &value, sizeof(T));
    return ans;
}

int main(){
    std::cout << bitCast<float, int>(3.6f) << std::endl;;

}
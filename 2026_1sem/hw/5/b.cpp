// Напишите шаблонные реализации 
// min - находит минимум из двух однотипных объектов,
// max - находит максимум из двух однотипных объектов, 
// greater - возвращает true, если первый аргумент строго больше второго, 
// less - возвращает true, если первый аргумент меньше.

template <typename T>
T min (T lha, T rha) {
    if (lha<rha) {
        return lha;
    }
    return rha;
}
template <typename T>
T max (T lha, T rha) {
    if (lha>rha) {
        return lha;
    }
    return rha;
}
template <typename T>
bool greater (T lha, T rha) {
    return (lha>rha);
}

template <typename T>
bool less (T lha, T rha) {
    return (lha<rha);
}

int main() {
    return 0;
}
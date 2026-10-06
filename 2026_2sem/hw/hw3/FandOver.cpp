void mergeArrays(int (&lhs)[N], int (&rhs)[N], int (&res)[2 * N]){
    for (int idx=0; idx<N; ++idx){
        res[idx]=lhs[idx];
    }
    for (int idx=0; idx<N; ++idx){
        res[N+idx]=lhs[idx];
    }
}

int findLastZero(int (&array)[N]){
    if (array[N-1]==0) {
        return N-1;
    }
    int n = (N-1)/2
    while true {
        if (array[n]==0) {
            if (array[n+1]==1) {
                return n;
            }
            else {
                n = (n+N-1)/2
            }
        }
    }
    return -1
}

// int find_unique(int (&a)[N]){
//     int xxx[N];
//     int n = 0;
//     int ans = a[0];
//     xxx[0] = 0;
//     n++;
//     for (int i=1; i<N-1, ++i) {
//         for (int ix=0; i<N, ++i) {
//             if ((a[i]) = xxx[ix]) {
//                 ans = a[i+1];
//                 break;
//             }
//         }
//         else {
            
//         }
//     }
// }
// квадратичная сложность

int find_unique(int (&a)[N]){
    int ans = 0;
    for (int i = 0; i < N; i++) {
        /* 
        используем свойствa XOR == ^
        x ^ x = 0 
        x ^ 0 = x 
        XOR - коммутативна и ассициативна 
        Значит все повторяющиеся при умножении перейдут в 0, 
        а уникальное число при умножении на 0 в себя
        */
        ans ^= a[i];
    }
    return ans;
}

void printTransposed(int (&array)[N][M]){
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++){
            std::cout << array[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


void swap(int& lhv, int& rhv){
    int tmp = lhv;
    lhv = rhv;
    rhv = tmp;
}

void sort2d(int (&array)[N][M]){
    int* ukaz = &array[0][0]; // * распаковка указателя
    for (int i=0; i<N*M-1; ++i){
        for (int j=0; j<N*M-i-1; ++j){
            if (ukaz[j] > ukaz[j+1]){
                swap(ukaz[j], ukaz[j+1]);
                // по аналогии с обращением к одномерному массиву,
                // записанному ранее из другого
            }
        }
    }
}

int trace(int (&array)[N * N]) {
    int tr = 0;
    for (int i=0; i<N; ++i) {
        tr += array[i*i+i];
    }
    return tr;
}
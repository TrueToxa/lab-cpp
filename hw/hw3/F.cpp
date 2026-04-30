void mergeArrays(int (&lhs)[N], int (&rhs)[N], int (&res)[2 * N]){
    for (int idx=0; idx<N; ++idx){
        res[idx]=lhs[idx];
    }
    for (int idx=0; idx<N; ++idx){
        res[N+idx]=lhs[idx];
    }
}

int findLastZero(int (&array)[N])
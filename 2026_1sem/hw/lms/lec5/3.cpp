template <typename InputIt, typename T, typename BinaryOp>
T fold(InputIt begin, InputIt end, T init, BinaryOp op) {
    if (begin == end) {
        return init;
    }
    --end;
    return op(*end, fold(begin, end, init, op));
}
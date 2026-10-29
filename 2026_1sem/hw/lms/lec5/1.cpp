template <typename T>
void array_copy(T * const dst_begin, T const * const src_begin, T const * const src_end) {
    T * dst = dst_begin;
    for (T const * src = src_begin; src != src_end; ++src, ++dst) {
        *dst = *src;
    }
}
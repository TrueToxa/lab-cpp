void swap(void *a, void *b, size_t size)
{
    /* TODO: выделить временный буфер размера size (::operator new[](size)),
       обменять содержимое a и b через memcpy (три вызова) или циклом,
       освободить буфер */

    void *tmp = ::operator new[](size);

    std::memcpy(tmp, a, size);
    std::memcpy(a, b, size);
    std::memcpy(b, tmp, size);

    ::operator delete[](tmp);
}
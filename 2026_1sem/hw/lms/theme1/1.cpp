const void *find_if(const void *base, size_t n, size_t size,
              int (*pred)(const void *elem, void *ctx), void *ctx)
{
    /* TODO: пройти по массиву указателем const unsigned char * с шагом size,
       для каждого элемента вызвать pred(elem, ctx),
       вернуть указатель на первый подошедший или nullptr */
    auto curr = static_cast<const unsigned char *>(base);
    auto last = curr + n*size;

    while (curr<last ) {
        if (pred(curr, ctx)){
            return curr;
        }
        curr = curr + size;
    }

    return nullptr;

}

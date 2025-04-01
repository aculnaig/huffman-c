#include "algorithm/vector.h"

int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    huffman_vector_t* v = huffman_vector_new(size);
    if (v == NULL)
        return 0;

    (void) huffman_vector_destroy(v);

    return 0;
}

#include "algorithm/vector.h"

int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    if (size == 0UL)
        return 0;

    huffman_vector_t* v = huffman_vector_new(size);
    if (v == NULL)
        return 0;

    for (size_t i = 0; i < size; i++) {
        huffman_vector_push(v, data[i]);
    }

    (void) huffman_vector_destroy(v);

    return 0;
}

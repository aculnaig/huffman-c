#ifndef HUFFMAN_ALGORITHM
#define HUFFMAN_ALGORITHM

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct huffman_vector_t {

    // Number of elements in vector
    size_t size;
    // Maximum capacity of the vector
    size_t capacity;
    // Elements in vector
    uint8_t *elems;

} huffman_vector_t;

huffman_vector_t* huffman_vector_new(size_t capacity);
void huffman_vector_destroy(huffman_vector_t *v);
int huffman_vector_push(huffman_vector_t *v, uint8_t elem);
uint8_t huffman_vector_get(huffman_vector_t *v, size_t index);

#endif // HUFFMAN_ALGORITHM

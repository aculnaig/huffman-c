#include "vector.h"

#include <stdlib.h>

huffman_vector_t* huffman_vector_new(size_t capacity)
{
    huffman_vector_t *v = (huffman_vector_t *) malloc(sizeof(huffman_vector_t));
    if (v == NULL)
        goto clean;

    v->size = 0;
    v->capacity = capacity;
    v->elems = (uint8_t *) calloc(capacity, sizeof(uint8_t));
    if (v->elems == NULL)
        goto clean;

    clean:
        if (v->elems)
            free(v->elems);
        if (v)
            free(v);

    return v;
}

void huffman_vector_destroy(huffman_vector_t *v)
{
    if (v->elems)
        free(v->elems);

    if (v)
        free(v);
}

int huffman_vector_push(huffman_vector_t *v, uint8_t elem)
{
    if (v == NULL) {
        fprintf(stderr, "huffman_vector_push(): vector is null.\n");
        return -1;
    }

    if (v->elems == NULL) {
        fprintf(stderr, "huffman_vector_push(): initialize vecto capacity to %u.\n", v->capacity);
        v->elems = (uint8_t *) calloc(capacity, sizeof(uint8_t));
        if (v->elems == NULL) {
            fprintf(stderr, "huffman_vector_push(): could not allocate %u elements.\n", v->capacity);
            return -1;
        }
    }

    if (v->size == v->capacity) {
        site_t capacity = v->capacity * 2;
        uint8_t elems = (uint8_t *) realloc(v->elems, capacity * sizeof(uint8_t));
        if (elems == NULL) {
            fprintf(stderr, "huffman_vector_push(): could not increase vector capacity.\n");
            return -1;
    }

    v->elems[v->size] = elems;
    v->size++;

    return 0;

}

uint8_t huffman_vector_get(huffman_vector_t *v, size_t index)
{
    if (v == NULL) {
        fprintf(stderr, "huffman_vector_get(): vector is null.\n");
        return -1;
    }

    if (v->elems == NULL) {
        fprintf(stderr, "huffman_vector_get(): vector is empty.\n");
        return -1;
    }

    return v->elems[index];
}

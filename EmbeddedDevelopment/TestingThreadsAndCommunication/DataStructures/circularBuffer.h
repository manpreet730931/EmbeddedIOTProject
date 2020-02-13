#include <sys/stdint.h>

#define CIRC_BBUF_DEF(x,y)                \
    char x##_data_space[y];               \
    circ_bbuf_t x = {                     \
        .buffer = x##_data_space,         \
        .head = 0,                        \
        .tail = 0,                        \
        .maxlen = y                       \
    }



typedef struct {
    uint8_t * const buffer;
    int head;
    int tail;
    const int maxlen;
} circ_bbuf_t;


int circularBufferPush(circ_bbuf_t *c, uint8_t data);

int circ_bbuf_pop(circ_bbuf_t *c, uint8_t *data);

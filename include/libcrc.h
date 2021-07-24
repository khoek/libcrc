#ifndef __LIB_LIBCRC_H
#define __LIB_LIBCRC_H

#include <stddef.h>
#include <stdint.h>

#define CRC8_LOOKUP_TABLE_SIZE 256

// LaCrosse CRC8: poly=0x31, init=0x00, reflect_in=false, reflect_out=false, xor_out=0x00
#define CRC8_LACROSSE_INIT 0x00
extern const uint8_t CRC8_LACROSSE_LOOKUP_TABLE[CRC8_LOOKUP_TABLE_SIZE];

static inline uint8_t crc8_calc_with_table(uint8_t init, const uint8_t *table, const uint8_t *buff, size_t len) {
    uint8_t crc = init;
    while (len--) {
        crc = table[crc ^ *buff++];
    }
    return crc;
}

static inline uint8_t crc8_calc_lacrosse(const uint8_t *buff, size_t len) {
    return crc8_calc_with_table(CRC8_LACROSSE_INIT, CRC8_LACROSSE_LOOKUP_TABLE, buff, len);
}

#endif

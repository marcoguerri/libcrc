#ifndef __CRC_H__
#define __CRC_H__

#define CRC_INPUT_REVERSAL      (1 << 0)
#define CRC_OUTPUT_REVERSAL     (1 << 1)
#define CRC_OUTPUT_INVERSION    (1 << 2)

extern uint32_t crc32_table[];

typedef enum 
{ 
    CRC8    = 8,
    CRC16   = 16,
    CRC32   = 32,
} CRC_TYPE;

typedef union
{
    uint8_t crc8;
    uint16_t crc16;
    uint32_t crc32;
} crc_t;

/* Structure to control the parameters of the algorithm */
typedef struct
{
    CRC_TYPE type;
    union
    {
        uint8_t poly_crc8;
        uint16_t poly_crc16;
        uint32_t poly_crc32;
    } poly;

    crc_t crc_init;
    uint8_t flags;

} crc_params_t;


crc_t crc_slow(crc_params_t *crc_params, uint8_t *message, uint32_t msg_len);
uint32_t crc32_fast(uint8_t *message, uint32_t msg_len);
extern uint32_t crc32_table[];
#endif

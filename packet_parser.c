#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_PAYLOAD 1500

typedef struct {
    uint32_t src_ip, dst_ip;
    uint16_t src_port, dst_port;
    uint8_t protocol;
    uint16_t payload_len;
    uint8_t payload[MAX_PAYLOAD];
} PacketInfo;

int match_signature(const uint8_t* payload, uint16_t len, const char* sig) {
    if (len == 0) return 0;
    return strstr((const char*)payload, sig) != NULL;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void auto_block_ip(const char* ip, int duration_sec) {
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "iptables -A INPUT -s %s -j DROP", ip);
    // system(cmd); 
    printf("[DEFENSE] Blocked %s for %ds\n", ip, duration_sec);
}

void rate_limit_ip(const char* ip, int pps) {
    printf("[DEFENSE] Rate limiting %s to %d pps\n", ip, pps);
}
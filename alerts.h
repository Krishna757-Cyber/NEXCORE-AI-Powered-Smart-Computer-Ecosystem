#ifndef ALERTS_H
#define ALERTS_H

#include <time.h>
#include <stdio.h>

typedef enum {
    ALERT_LOW = 1,
    ALERT_MEDIUM = 2,
    ALERT_HIGH = 3,
    ALERT_CRITICAL = 4
} AlertSeverity;

void init_alert_system() {
    printf("[ALERTS] System initialized.\n");
}

void trigger_alert(AlertSeverity severity, const char* module, const char* msg) {
    time_t now = time(NULL);
    printf("[%ld] [SEV:%d] [%s] %s\n", now, severity, module, msg);
}

#endif

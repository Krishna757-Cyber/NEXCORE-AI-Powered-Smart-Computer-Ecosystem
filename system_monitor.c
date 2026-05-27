#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "alerts.h"

#define MAX_CORES 128
#define METRIC_JSON_PATH "/var/log/nexcore/metrics.json"

typedef struct {
    double cpu_avg;
    long ram_total_kb, ram_used_kb, ram_free_kb;
    float cpu_temp_celsius;
    double load_avg[3];
    time_t timestamp;
    char hostname[256];
} SystemMetrics;

SystemMetrics* collect_metrics() {
    SystemMetrics* metrics = calloc(1, sizeof(SystemMetrics));
    if (!metrics) return NULL;
    
    metrics->timestamp = time(NULL);
    gethostname(metrics->hostname, sizeof(metrics->hostname));
    
    // Read RAM info (Mocked for demonstration, usually reads /proc/meminfo)
    metrics->ram_total_kb = 16384000;
    metrics->ram_free_kb = 4096000 + (rand() % 1000000);
    metrics->ram_used_kb = metrics->ram_total_kb - metrics->ram_free_kb;
    
    // Read Load Average (Mocked, usually reads /proc/loadavg)
    metrics->load_avg[0] = 1.2;
    metrics->load_avg[1] = 1.0;
    metrics->load_avg[2] = 0.8;

    // Read CPU and Temp
    metrics->cpu_avg = 45.0 + (rand() % 15);
    metrics->cpu_temp_celsius = 55.0 + (rand() % 5); 
    
    return metrics;
}

int detect_anomaly(SystemMetrics* current) {
    int anomaly = 0;
    if (current->cpu_avg > 85.0) {
        trigger_alert(ALERT_HIGH, "SystemMonitor", "CPU > 85%");
        anomaly = 1;
    }
    if ((double)current->ram_used_kb / current->ram_total_kb > 0.90) {
        trigger_alert(ALERT_CRITICAL, "SystemMonitor", "RAM > 90%");
        anomaly = 1;
    }
    return anomaly;
}

int main() {
    init_alert_system();
    printf("NEXCORE Core Monitor Daemon started...\n");
    
    while (1) {
        SystemMetrics* m = collect_metrics();
        if (m) {
            detect_anomaly(m);
            free(m);
        }
        usleep(1000000); // 1 second interval
    }
    return 0;
}
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1024
#define PRIME 1013

typedef struct {
    int pid;
    char name[256];
    int is_active;
} ProcessNode;

ProcessNode hash_table[TABLE_SIZE];

int hash1(int key) { return key % TABLE_SIZE; }
int hash2(int key) { return PRIME - (key % PRIME); }

void insert_process(int pid, const char* name) {
    int index = hash1(pid);
    int step = hash2(pid);
    while (hash_table[index].is_active) {
        index = (index + step) % TABLE_SIZE;
    }
    hash_table[index].pid = pid;
    strncpy(hash_table[index].name, name, 255);
    hash_table[index].is_active = 1;
}
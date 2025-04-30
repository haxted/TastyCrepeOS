#pragma once
#include <stdint.h>


typedef struct {
    uint8_t priority;
    uint16_t count;
    uint8_t child;
} __attribute__((packed)) PID;


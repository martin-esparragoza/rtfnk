/**
 * @file alloc.h
 * @brief Structure definitions for alloc.c
 */

#ifndef LIB_MEM_ALLOC_H_
#define LIB_MEM_ALLOC_H_

#include "attr.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Serves as a descriptor
 * Actual data is always above it so addresses can be fetched by + the sizeof this structure
 */
typedef struct INCLUDE_COMP_ATTR_PACKED mem_alloc_heap_entry {
    uintptr_t size; ///< Size in bytes (this should probably be changed... I can see this as annoying legacy)
    struct mem_alloc_heap_entry* next; ///< Next entry
} mem_alloc_heap_entry;

#endif
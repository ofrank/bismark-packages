#ifndef _BISMARK_PASSIVE_FLOW_TABLE_H_
#define _BISMARK_PASSIVE_FLOW_TABLE_H_

#include <stdint.h>

#include "constants.h"

typedef struct {
#define ENTRY_EMPTY     0
#define ENTRY_OCCUPIED  1
#define ENTRY_DELETED   2
  uint8_t occupied;

  uint32_t ip_source;
  uint32_t ip_destination;

  uint8_t transport_protocol;
  uint16_t port_source;
  uint16_t port_destination;
} flow_table_entry_t;

typedef struct {
  flow_table_entry_t entries[FLOW_TABLE_ENTRIES];
  uint32_t num_elements;
} flow_table_t;

void flow_table_init(flow_table_t* table);

int flow_table_process_flow(flow_table_t* table, flow_table_entry_t* entry);

#endif
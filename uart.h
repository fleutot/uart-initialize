#include <stdio.h>
#include <stdint.h>

#ifndef UART_H
#define UART_H

#define UART_BASE_ADDR 0xFC000000

// TODO Base Values, provide base values if you deem it necessary,
// otherwise provide them in the code
enum BaudRate {BR_4800, BR_9600, BR_14400, BR_19200, BR_38400};

// Data structure containing UART parameters including base address
// and other settings
typedef struct {
    // TODO Just an example, fill the struct with variables of types
    // you deem appropriate
    enum BaudRate baud_rate;

} uart_config;

void stub_memwrite(uint32_t *mem_addr, uint32_t val);

uint32_t stub_memread(uint32_t *mem_addr);

void init_uart(uart_config *cfg);

#endif //UART_H

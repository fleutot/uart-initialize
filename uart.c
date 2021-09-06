#include <stdio.h>
#include <stdint.h>
#include <stdint-gcc.h>
#include "uart.h"

// Dummy struct to help running the unit tests, see example code in function below.
struct MEMORY_REGISTRY{
};

struct MEMORY_REGISTRY mem_reg;

// TODO: Implement a memory operation for writing to a dummy UART buffer
void stub_memwrite(uint32_t *mem_addr, uint32_t val)
{
    /* Since these methods will be unit tested on ubuntu, and not the actual hardware, we need to create a 
       dummy method to ensure that the memory is accessible. The following is an example way of doing it to ensure 
       that the tests will pass with UART_BASE_ADDR as an input (The base address is provided in the task). Feel free
       to change this line */
    mem_addr = ((uint32_t*) &mem_reg + (mem_addr - (uint32_t*)UART_BASE_ADDR));
}

// TODO: Implement a memory operation for reading from a dummy UART buffer
uint32_t stub_memread(uint32_t *mem_addr)
{
    mem_addr = ((uint32_t*) &mem_reg + (mem_addr - (uint32_t*)UART_BASE_ADDR));
}

// TODO: Implement the initialization function
void init_uart(UART_HANDLE *h)
{

}

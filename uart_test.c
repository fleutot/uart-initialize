#include "uart.h"
#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"

/* Pointer to the file used by the tests. */

static FILE *temp_file = NULL;
uint32_t *base_address = (uint32_t *) 0xFC000000;


/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{
    if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
        return -1;
    }
    else {
        return 0;
    }
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
    if (0 != fclose(temp_file)) {
        return -1;
    }
    else {
        temp_file = NULL;
        return 0;
    }
}


/* Simple tests of data written to the memory registries.
 * Same layout for all tests, check that the value assigned to the
 * memory registry is correct and that the write functions work so
 * that we can re assign the value.
 */

void testBRR(void)
{
    CU_ASSERT(stub_memread(base_address + 0x04) == 0x1024);
    stub_memwrite(base_address + 0x04,0xF);
    CU_ASSERT_FALSE(stub_memread(base_address + 0x04)==0x1024);

}

void testTER(void)
{
    CU_ASSERT(stub_memread(base_address + 0x08) == 0x800000);
    stub_memwrite(base_address + 0x08,0xF);
    CU_ASSERT_FALSE(stub_memread(base_address + 0x08)==0x800000);
}

void testRER(void)
{
    CU_ASSERT(stub_memread(base_address + 0xC) == 0x0);
    stub_memwrite(base_address + 0xC,0xF);
    CU_ASSERT_FALSE(stub_memread(base_address + 0xC)==0x0);
}

void testIER(void)
{
    CU_ASSERT(stub_memread(base_address + 0x10) == 0xC000);
    stub_memwrite(base_address + 0x10,0xF);
    CU_ASSERT_FALSE(stub_memread(base_address + 0x10)==0xC000);
}

void testTDR(void)
{
    CU_ASSERT(stub_memread(base_address + 0x14) == 0x0);
    stub_memwrite(base_address + 0x14,0xF);
    CU_ASSERT_FALSE(stub_memread(base_address + 0x14)==0x0);
}

void testRDR(void)
{
    CU_ASSERT(stub_memread(base_address + 0x18) == 0x0);
    stub_memwrite(base_address + 0x18,0xF);
    CU_ASSERT_FALSE(stub_memread(base_address + 0x18)==0x0);
}



/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
    uart_config cfg;
    init_uart(&cfg); // Initialises for UART baudate 38400,8,None,1,None

    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
    if ((NULL == CU_add_test(pSuite, "test of BRR Registry", testBRR)) ||
        (NULL == CU_add_test(pSuite, "test of TER Registry", testTER)) ||
        (NULL == CU_add_test(pSuite, "test of RER Registry", testRER)) ||
        (NULL == CU_add_test(pSuite, "test of IER Registry", testIER)) ||
        (NULL == CU_add_test(pSuite, "test of TDR Registry", testTDR)) ||
        (NULL == CU_add_test(pSuite, "test of RDR Registry", testRDR)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

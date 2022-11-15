# UART Initialize

Your task is to write an initialization routine for an UART device in C and make the provided unit tests pass.

## Instructions

UART is a memory mapped device at the address `0xFC000000` on an embedded platform.

This peripheral is controlled by the following 32-bit registers (offsets given):

- `BRR`: Baud rate register Offset: `0x4`
    - `BRR[0:3]`: Selects the baud rate as follows:
        - 0: 4800
        - 1: 9600
        - 2: 14400
        - 3: 19200
        - 4: 38400
        - 5: 57600
        - 6: 115200
        - 7: 128000
        - 8: 256000
    - `BRR[4:5]`: Selects parity as follows:
        - 0: Even Parity
        - 1: Odd Parity
        - 2: No Parity
    - `BRR[8]`: Turning this bit on enables hardware flow control
    - `BRR[12:15]`: Contains the number of stop bits
- `TER`: Transmit enable register Offset: `0x8`
    - Bit 23 in this register enables the transmit operation
- `RER`: Receive enable register Offset: `0xC`
    - Bits 3 and 5 notify overrun and framing error and need to be cleared upon reset
- `IER`: Interrupt enable register Offset: `0x10`
    - Bit 14 and 15 enable TX and RX interrupts
- `TDR`: Transmit data register Offset: `0x14`
    - Contains data to be transmitted via UART
- `RDR`: Receive data register Offset: `0x18`
    - Contains data received via UART
    
Use the following configuration to write the initialization routine:
- Baud Rate: 38400, 
- Stop bits: 1
- Parity: none
- Flow control: none
- TX and RX are interrupt based operations, with data registers cleared at the start of operation.

## Before you get started

### Boilerplate

We have pre-uploaeded the following project setup to help you get started:

- [uart_test.c](uart_test.c) - the unit tests that ensure that the provided implementation is correct.
- [uart.h](uart.h) - the necessary constants & data structures.
- [uart.c](uart.c) - the API you're expected to implement by filling in the TODOs.

### Try running the tests locally

1. Ensure you have the gcc compiler installed on your environment.
2. Install CUnit. Ex. Ubuntu: `sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev`
3. Compile your code: `gcc uart_test.c uart.c uart.h -L$HOME/local/lib -lcunit -o uart`
4. Run the tests: `./uart`

## What we expect from you

1. Make the provided unit tests pass.
2. Push your code to the new `implementation` branch. We encourage you to commit and push your changes regularly as it's a good way for you to showcase your thinking process.
3. Create a new pull request, but please **do not merge it**.
4. Document the tech decisions you've made by creating a new review on your PR ([see how](https://www.loom.com/share/94ae305e7fbf45d592099ac9f40d4274)).
5. Await further instructions from the hiring team.

## Need help?

Start with [Troubleshooting](https://www.notion.so/Troubleshooting-d18bdb5d2ac341bb82b21f0ba8fb9546), and in case it didn't help, create a new GitHub issue. We'll get back to you.

## Time estimate

**45 min -2 h** depending on your experience level. But don't worry! There is no countdown. This number is for you to plan your time.

---

Made by [DevSkills](https://devskills.co).

How was your experience? **Give us a shout on [Twitter](https://twitter.com/DevSkillsHQ) / [LinkedIn](https://www.linkedin.com/company/devskills)**.

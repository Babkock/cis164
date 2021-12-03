#include "bank.h"
#include "cli.h"

int main(void) {
    Bank bank;
    Cli cli(bank);
    cli.start();
    return 0;
}

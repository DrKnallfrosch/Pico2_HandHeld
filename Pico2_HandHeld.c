#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

// I2C defines
// This example will use I2C0 on GPIO0 (SDA) and GPIO1 (SCL) running at 400KHz.
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define I2C_PORT i2c0
#define I2C_SDA 0
#define I2C_SCL 1


#include <stdio.h>
#include "pico/stdlib.h"
// DfPlayer Library from github: https://github.com/TuriSc/RP2040-DFPlayer/tree/main
#include "dfplayer.h"
#include "Mersene_Twister/MT19937.h"


dfplayer_t dfplayer;

int main() {
    stdio_init_all();
    MT19937 mt;
    mt_seed(&mt, 432);

    while (true) {
        int random = mt_random_range(&mt, 1, 5);
        if (random < 0) {
            random = -random;
        }
        printf("%d\n", random);
        sleep_ms(1000);
    }
}
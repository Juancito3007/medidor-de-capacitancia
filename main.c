#include <stdio.h>
#include "pico/stdlib.h"

int main(void) {
	stdio_init_all();

gpio_init(CAP_PIN);
gpio_set_dir(CAP_PIN, GPIO_IN);
gpio_init(RES_PIN);
gpio_set_dir(RES_PIN, GPIO_OUT);

while (true) {
	gpio_put (RES_PIN 0);
		sleep_ms (1000);

 gpio_set_dir(RES_PIN, GPIO_IN);
 uint64_t start_time = time_us_64();
  while (!gpio_get(CAP_PIN));
  
	uint64_T charge_time = time_us_64() - start_time;
    
	float capacitance = (float)charge_time / (RESISTANCE * 0.693);

    printf("Capacitance: %.2fμF\n", capacitance * 1e6);

	sleep_ms(1000);
    }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

void main()
{
	const uint LED_PIN = PICO_DEFAULT_LED_PIN;

	stdio_init_all();
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	int min = 0;
	int sec = 0;

	printf("\n\nCONTADOR DE MINUTOS \n\n");
	    while (true)
	    {
	    	printf("\nHan pasado %d minutos\n", min);
	        for (sec; sec < 59; sec ++)
	        {
	        	gpio_put(LED_PIN, 1);
	        	sleep_ms(200);
	    	    gpio_put(LED_PIN, 0);
	      	    sleep_ms(200);

	        	printf("%d minutos, %d segundos \n", min, sec);
	        }

	        min = min +1;
	        sec = 0;

	        if (min == 5)
	        {
	        	printf("LA CUENTA HA FINALIZADO, EMPEZARÁ NUEVAMENTE\n\n");
	        	min = 0;
	        }
	    }
}

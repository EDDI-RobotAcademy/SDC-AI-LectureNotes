#include "led.h"
#include <stdlib.h>
#include <stdbool.h>


led *init_led_object(int count)
{
    led *tmp_led_array = (led *)malloc(sizeof(led)* count);
    return tmp_led_array;
}

void set_led_status(int led_index, bool on_off)
{

}
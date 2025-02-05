#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

const uint led_pin_red = 13;
const uint led_pin_blue = 12;
const uint led_pin_green = 11;

static uint8_t current_led = 0; // Variável para controlar qual LED está aceso

// Função para configurar os pinos dos LEDs
void setup_GPIOs() {
    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);

    gpio_init(led_pin_blue);
    gpio_set_dir(led_pin_blue, GPIO_OUT);

    gpio_init(led_pin_green);
    gpio_set_dir(led_pin_green, GPIO_OUT);
}

// Função para desligar todos os LEDs, exceto o LED passado como parâmetro
void turn_off_leds_except(uint led) {
    gpio_put(led_pin_red, 0);
    gpio_put(led_pin_blue, 0);
    gpio_put(led_pin_green, 0);
    gpio_put(led, 1);
}

// Função de callback do timer
bool repeating_timer_callback(struct repeating_timer *timer) {
    switch (current_led) {
        case 1:
            turn_off_leds_except(led_pin_red);
            break;
        case 2:
            turn_off_leds_except(led_pin_red);
            gpio_put(led_pin_green, 1);
            break;
        case 3:
            turn_off_leds_except(led_pin_green);
            break;
        default:
            current_led = 1;
            turn_off_leds_except(led_pin_red);
            break;
    }
    current_led++;
    printf("Sinal alterado.\n");
    return true;
}

int main()
{
    stdio_init_all(); // Inicializa a comunicação serial
    setup_GPIOs(); // Configura os pinos dos LEDs
    
    struct repeating_timer timer; // Declaração da estrutura do timer
    
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); // Configura o timer para chamar a função de callback a cada 3 segundos

    repeating_timer_callback(&timer); // Chama a função de callback para iniciar com o LED vermelho aceso

    while (true) { // Imprime uma mensagem a cada segundo
        printf("Passou 1 segundo!\n"); 
        sleep_ms(1000); 
    }
}

#include <samd21g18a.h>

#include <port.h>
#include <delay.h>

#define LED_0_PIN PIN_PA17

static void set_output(const uint8_t pin) {
  struct port_config config_port_pin;
  port_get_config_defaults(&config_port_pin);
  config_port_pin.direction = PORT_PIN_DIR_OUTPUT;
  port_pin_set_config(pin, &config_port_pin);
  port_pin_set_output_level(pin, false);
}

static void setup() {
  system_clock_init();
  delay_init();
  set_output(LED_0_PIN);
}

int main() {
  setup();
  while (true) {
    port_pin_toggle_output_level(LED_0_PIN);
    delay_s(2);
  }
}



#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <samd21g18a.h>
#include <port.h>
#include <usart_serial.h>

static struct usart_module stdio_uart_module;

// LIBC SYSCALLS
/////////////////////

extern int _end;

caddr_t _sbrk(int incr) {
  static unsigned char *heap = NULL;
  unsigned char *prev_heap;

  if (heap == NULL) {
    heap = (unsigned char *)&_end;
  }
  prev_heap = heap;

  heap += incr;

  return (caddr_t) prev_heap;
}

int _close(int file) {
  return -1;
}

int _fstat(int file, struct stat *st) {
  st->st_mode = S_IFCHR;

  return 0;
}

int _isatty(int file) {
  return 1;
}

int _lseek(int file, int ptr, int dir) {
  return 0;
}

void _exit(int status) {
  __asm("BKPT #0");
}

void _kill(int pid, int sig) {
  return;
}

int _getpid(void) {
  return -1;
}

int _write (int file, char * ptr, int len) {
  int written = 0;

  if ((file != 1) && (file != 2) && (file != 3)) {
    return -1;
  }

  for (; len != 0; --len) {
    if (usart_serial_putchar(&stdio_uart_module, (uint8_t)*ptr++)) {
      return -1;
    }
    ++written;
  }
  return written;
}

int _read (int file, char * ptr, int len) {
  int read = 0;

  if (file != 0) {
    return -1;
  }

  for (; len > 0; --len) {
    usart_serial_getchar(&stdio_uart_module, (uint8_t *)ptr++);
    read++;
  }
  return read;
}


// APP
////////////////////

#define LED_0_PIN PIN_PA17

static void serial_init(void) {
  struct usart_config usart_conf;

  usart_get_config_defaults(&usart_conf);
  usart_conf.mux_setting = USART_RX_3_TX_2_XCK_3;
  usart_conf.pinmux_pad0 = PINMUX_UNUSED;
  usart_conf.pinmux_pad1 = PINMUX_UNUSED;
  usart_conf.pinmux_pad2 = PINMUX_PB22D_SERCOM5_PAD2;
  usart_conf.pinmux_pad3 = PINMUX_PB23D_SERCOM5_PAD3;

  usart_serial_init(&stdio_uart_module, SERCOM5, &usart_conf);
  usart_enable(&stdio_uart_module);
}

static void set_output(const uint8_t pin) {
  struct port_config config_port_pin;
  port_get_config_defaults(&config_port_pin);
  config_port_pin.direction = PORT_PIN_DIR_OUTPUT;
  port_pin_set_config(pin, &config_port_pin);
  port_pin_set_output_level(pin, false);
}

int main() {
  serial_init();
  set_output(LED_0_PIN);

  printf("Hello, World!\n");
  while (true) {
    port_pin_toggle_output_level(LED_0_PIN);
    for (int i = 0; i < 100000; ++i) {}
  }
}



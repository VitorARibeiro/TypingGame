#include "../include/InputHandler.h"
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

void set_terminal_mode() {
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~(ICANON | ECHO); /* Disable canonical mode and echo */
  tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void reset_terminal_mode() {
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag |= (ICANON | ECHO); /* Restore canonical mode and echo */
  tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

char get_char() {
  char c;
  if (read(STDIN_FILENO, &c, 1) == 1)
    return c;
  return '\0';
}

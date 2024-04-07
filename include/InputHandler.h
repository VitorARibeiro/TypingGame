#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include <termios.h>
void set_terminal_mode();
void reset_terminal_mode();
char get_char();

#endif /* INPUT_HANDLER_H */

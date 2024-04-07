#include "../include/OutputHandler.h"
#include <stdio.h>

void PrintColorFormated(char *input, char *original) {

  char color[] = "\x1b[31m"; // ANSI escape code for red color
  char reset[] = "\x1b[0m";  // ANSI escape code to reset color

  // Print the string with the selected character colored
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] != original[i]) {
      printf("%s%c%s", color, input[i], reset); // Print colored character
    } else {
      printf("%c", input[i]); // Print normal character
    }
  }
}

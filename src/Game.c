
// #include "../include/FileHandler.h"
#include "../include/InputHandler.h"
#include "../include/OutputHandler.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 200 // Tamanho maximo de uma string
#define BACKSPACE 127
#define ENTER 10
int main() {

  // Abrir ficheiro com frases
  FILE *fd = fopen("resources/PhraseFile.txt", "r");
  if (!fd) {
    perror("Erro ao abrir ficheiro\n");
    return 1;
  }

  char *string = (char *)malloc(sizeof(char) * MAXSIZE);
  char *line = (char *)malloc(sizeof(char) * MAXSIZE);

  if (!string) {
    perror("Erro ao alocar memoria para string\n");
    return 1;
  }

  if (!line) {

    perror("Erro ao alocar memoria para line\n");
    return 1;
  }

  // Ler linha para variavel line
  // Criar uma funcao para ler uma linha aleatoria
  fgets(line, MAXSIZE, fd);
  fclose(fd);

  // Mostras texto no ecra e comecar o jogo
  system("clear");
  printf("%s", line);

  // Iniciar leitura do teclado
  int stringIndex = 0;
  char c;

  set_terminal_mode();

  while (1) {

    c = get_char();

    if (c != '\0') { // Caso seja uma character valido

      if (c == BACKSPACE) { // Apagar linha escrita

        if ((stringIndex - 1) >= 0) {

          string[stringIndex - 1] = '\0';
          stringIndex--;
        }
      } else if (c == ENTER) {
        system("clear");
        printf("Jogo terminado\n");
        break;

      } else if ((stringIndex) + 1 <= MAXSIZE) {

        // adicionar a string
        string[stringIndex] = c;
        string[stringIndex + 1] = '\0';
        stringIndex++;
      }

      system("clear");
      printf("%s", line);
      PrintColorFormated(string, line);
      fflush(stdout);
    }
  }
  free(line);
  free(string);
  reset_terminal_mode(); // Reset terminal mode before exiting
  return 0;              // Return success status
}

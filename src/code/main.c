#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    perror("Введите название файла");
    return 1;
  }

  for (int i = 1; i < argc; ++i) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      perror("Файла не существует");
      return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
      printf("%s", buffer);
    }

    fclose(file);
  }

  return 0;
}

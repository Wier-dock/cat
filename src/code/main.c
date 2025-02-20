#include "../headers/cat.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    perror("Введите название файла и флаги");
    return 1;
  } else {
    struct Flags flags = {0, 0, 0, 0, 0, 0};
    if (argc > 1) {
      flag_parse(argv, &flags);
      print_file_BNS(argc, argv, flags);
    }
  }

  return 0;
}

void print_file_EVT(int argc, char **argv, struct Flags flags) {
  for (int i = 2; i < argc; ++i) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      perror("Файла не существует");
      return;
    }
    int ch = fgetc(file);
    while (ch != EOF) {
      fputc(ch, stdout);
      ch = fgetc(file);
    }
    fclose(file);
  }
}

void print_file_BNS(int argc, char **argv, struct Flags flags) {
  int startFromFile = 1;
  bool flag = false;
  if (argc - 1 > 1) {
    flag = true;
  }
  if (flags.flagFree == false) {
    startFromFile = 2;
  }
  for (int i = startFromFile; i < argc; ++i) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      perror("Файла не существует");
      return;
    }

    if (flag == true) {
      printf("%s \n", argv[i]);
    }

    int numberOfLine = 1;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
      if (flags.flagFree == true) {
        printf("%s", buffer);
      }
      if (flags.flagN == true) {
        printf("%d\t%s", numberOfLine++, buffer);
      }
      if (flags.flagE == true) {
        printf("%s", );
      }
      if (flags.flagB == true) {
        if (strlen(buffer) >= 1 && buffer[0] != '\n') {
          printf("%d\t%s", numberOfLine++, buffer);
        } else {
          printf("%s", buffer);
        }
      }
    }

    fclose(file);
  }
}

void flag_parse(char **argv, struct Flags *flags) {
  if (!strcmp(argv[1], "-b")) {
    flags->flagB = true;
  } else if (!strcmp(argv[1], "-e")) {
    flags->flagE = true;
  } else if (!strcmp(argv[1], "-n")) {
    flags->flagN = true;
  } else if (!strcmp(argv[1], "-s")) {
    flags->flagS = true;
  } else if (!strcmp(argv[1], "-t")) {
    flags->flagT = true;
  } else {
    flags->flagFree = true;
  }
}

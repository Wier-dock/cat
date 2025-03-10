#include "../headers/cat.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    perror("Введите название файла и флаги");
    return 1;
  } else {
    struct Flags flags = {0, 0, 0, 0, 0, 0};
    if (argc > 1) {
      flag_parse(argv, &flags);
      int startFromFile = 2;
      if (flags.flagFree == true) {
        startFromFile = 1;
      }

      for (int i = startFromFile; i < argc; i++) {
        FILE *fptr = fopen(argv[i], "r");
        if (fptr == NULL) {
          perror("файла не существует");
          continue;
        }
        if (!flags.flagT || !flags.flagE) {
          print_file_EVT(fptr, flags);
        } else {
          print_file_BNS(file, flags);
        }
      }
    }
  }

  return 0;
}

void print_file_EVT(FILE *fptr, struct Flags flags) {
  if (fptr != NULL) {
    int ch = fgetc(fptr);
    while (ch != EOF) {
      if (flags.flagE && ch == '\n') {
        printf("$");
      }  if (flags.flagT && ch == '\t') {
        printf("^");
        ch = '\t' + 64;
      }
      fputc(ch, stdout);
      ch = fgetc(fptr);
    }
    fclose(fptr);
  } else {
    fprintf(stderr, "cat: No such file or directory\n");
  }
}

void print_file_BNS(FILE *file, struct Flags flags) {
  if(file != NULL){
    int ch = fgetc(file);
    while(ch != EOF)
  }
    flags = true;
  }
  if (!flags.flagFree) {
    startFromFile = 2;
  }
  for (int i = startFromFile; i < argc; ++i) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      perror("Файла не существует");
      return;
    }

    if (!flag) {
      printf("%s \n", argv[i]);
    }

    int numberOfLine = 1;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
      if (!flags.flagFree) {
        printf("%s", buffer);
      }
      if (!flags.flagN) {
        printf("%d\t%s", numberOfLine++, buffer);
      }
      if (!flags.flagB) {
        if (strlen(buffer) >= 1 && buffer[0] != '\n') {
          printf("%d\t%s", numberOfLine++, buffer);
        } else {
          printf("%s", buffer);
        }
      }
    }

    fclose(file);
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

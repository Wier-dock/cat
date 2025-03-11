#include "../headers/cat.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    perror("Введите название файла и флаги");
    return 1;
  } else {
    struct Flags flags = {0, 0, 0, 0, 0, 0};
    if (argc > 1) {
      flag_parse(argv, &flags);

      printf("%d\n%d\n%d\n%d\n%d\n", flags.flagFree, flags.flagB, flags.flagN, flags.flagE, flags.flagT);

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
          print_file_BNS(fptr, flags);
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
      }
      if (flags.flagT && ch == '\t') {
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

void print_file_BNS(FILE *fptr, struct Flags flags) {
  char buffer[2048];
  int counter = 0;
  if (fptr != NULL) {
    while ((fgets(buffer, 2048, fptr)) != NULL) {
      if (flags.flagN) {
        printf("%d\t%s", counter++, buffer);
      }
      if (flags.flagB) {
        if (strlen(buffer) >= 1 && buffer[0] != '\n') {
          printf("%d\t%s", counter++, buffer);
        } else {
          printf("%s", buffer);
        }
      }
      // if (flags.flagFree) {
      //   printf("%s", buffer);
      // }
    }
    fclose(fptr);
  } else {
    fprintf(stderr, "cat: No such file or directory\n");
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

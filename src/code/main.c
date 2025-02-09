#include "../headers/cat.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    perror("Введите название файла и флаги");
    return 1;
  } else {
    struct Flags flags = {0,0,0,0,0,0};
    if (argc > 1) {
      flag_parse(argv, &flags);
      print_file(argc, argv);

      printf("%d\n%d\n%d\n%d\n%d\n%d\n", flags.flagB, flags.flagE, flags.flagN,
             flags.flagS, flags.flagT, flags.flagFree);
    }
  }

  return 0;
}

void print_file(int argc, char **argv, struct Flags *flags) {
  bool flag = false;
  if (argc - 1 > 1) {
    flag = true;
  }

  for (int i = 1; i < argc; ++i) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      perror("Файла не существует");
      return;
    }

    if (flag == true) {
      printf("%s \n", argv[i]);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
      printf("%s", buffer);
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

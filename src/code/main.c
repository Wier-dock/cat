#include "../headers/cat.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    perror("Введите название файла и флаги");
    return 1;
  } else {
    if (argc > 1) {
      print_file(argc, argv);
    }
  }

  return 0;
}

void print_file(int argc, char **argv) {
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

void flag_parse(char **argv, struct Flags *flags){
  switch (argv[1]){
	case "-b":
		flags.flagB = true;
		break;

	default: 
		flags.flagFree = true;
		break;
  }
}


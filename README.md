# Cat
## main.c
#### Добовляем библеотеку.
```c
#include "../headers/cat.h"
```
#### Создаем проверку на наличие файла в строке.
```c
int main(int argc, char *argv[]) {
  if (argc == 1) {
    perror("Введите название файла и флаги");
    return 1;
  } else {
    struct Flags flags = {0, 0, 0, 0, 0, 0,0};
    if (argc > 1) {
      flag_parse(argv, &flags);
```
#### Создаем переменную.
```c
      int startFromFile = 2;
      if (flags.flagFree == true) {
        startFromFile = 1;
      }
```
#### С помошью созданой переменной делаем проверку на наличие файла.
```c
      for (int i = startFromFile; i < argc; i++) {
        FILE *fptr = fopen(argv[i], "r");
        if (fptr == NULL) {
          perror("файла не существует");
          continue;
        }
```
#### Показываем флаги.
```c
        if (flags.flagT || flags.flagE || flags.flagV) {
          print_file_EVT(fptr, flags);
        } else {
          print_file_BNS(fptr, flags);
        }
      }
    }
  }

  return 0;
}
```
#### Создаем переменную.
```c
void print_file_EVT(FILE *fptr, struct Flags flags) {
  if (fptr != NULL) {
    int ch = fgetc(fptr);
    while (ch != EOF) {
      if(flags.flagV ){
        print_flag_V(ch);
      }
```
#### Создаем флаг Е.
```c
      if (flags.flagE && ch == '\n') {
        printf("$");
      }
```
#### Создаем флаг T.
```c
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
```
#### Создаем флаг V.
```c
void print_flag_V(int ch){
  if (ch > 127 && ch < 160){
    printf("M-^");
  }
  if((ch < 32 && ch != '\n' && ch != '\t')|| ch == 127){
    printf("^");
  }
  if((ch < 32 || (ch > 126 && ch < 160)) && ch != '\n' && ch != '\t'){
    ch = ch > 126 ? ch - 128 + 64 : ch + 64;
  }
}
```
#### Создаем переменную.
```c
void print_file_BNS(FILE *fptr, struct Flags flags) {
  char buffer[2048];
  int counter = 1;
  int gobble = 0;

  if (fptr != NULL) {
    while ((fgets(buffer, 2048, fptr)) != NULL) {
      if (flags.flagN) {
        printf("%d\t%s", counter++, buffer);
      }
```
#### Создаем флаг B.
```c
      if (flags.flagB) {
        if (strlen(buffer) >= 1 && buffer[1] != '\n') {
          printf("%6d\t%s", counter++, buffer);
        } else {
          printf("%s", buffer);
        }
      }
```
#### Создаем флаг S.
```c
      if (flags.flagS) {
        gobble = print_flag_S(buffer, gobble);
      }
```
#### Создаем флаг Free.
```c
      if (flags.flagFree) {
        printf("%s", buffer);
      }
    }
    fclose(fptr);
  } else {
    fprintf(stderr, "cat: No such file or directory\n");
  }
}
```
#### Продолжаем делать флаг S.
```c
int print_flag_S(char buffer[2048], int gobble){
  if (strlen(buffer) <= 2) {
    if (gobble == 1) {
      return 1;
    } else {
      gobble++;
      printf("%s", buffer);
    }
  } else {
    gobble = 0;
    printf("%s", buffer);
  }

  return gobble;
}
```
#### Создаем фунцию с помошью которой обьявляем все флаги.
```c
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
  }else if(!strcmp(argv[1], "-v")){
    flags->flagV = true;
  } else {
    flags->flagFree = true;
  }
}
```

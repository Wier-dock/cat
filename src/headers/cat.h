#ifndef CAT_H
#define CAT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Flags {
  bool flagB;  // нумерует только непустые строки //
  bool flagE;  // также отображает символы конца строки как $ //
  bool flagN;  // нумерует все выходные строки //
  bool flagS;  // сжимает несколько смежных пустых строк //
  bool flagT;     // также отображает табы как ^I //
  bool flagFree;  // когда флага нет //
};

void flag_parse(char **argv, struct Flags *flags);
int handling_error(char **argv);
void print_file(int argc, char **argv, struct Flags *flags);

#endif

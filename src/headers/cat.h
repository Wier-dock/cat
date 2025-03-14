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
  bool flagV;
  bool flagFree;  // когда флага нет //
};

void flag_parse(char **argv, struct Flags *flags);
int handling_error(char **argv);
void print_file_BNS(FILE *fptr, struct Flags flags);
void print_file_EVT(FILE *fptr, struct Flags flags);

#endif

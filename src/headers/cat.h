#ifndef CAT_H
#define CAT_H

struct Flags {
  bool flagB;  // нумерует только непустые строки //
  bool flagE;  // также отображает символы конца строки как $ //
  bool flagN;  // нумерует все выходные строки //
  bool flagS;  // сжимает несколько смежных пустых строк //
  bool flagT;  // также отображает табы как ^I //
};

void flag_parse(char **argv, struct *flags);
int handling_error(char **argv);
void print_file(char filename);

#endif

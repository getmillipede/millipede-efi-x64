#ifndef MILI_H
#define MILI_H

typedef struct mili_arg
{
  int mode;
  int size;
  CHAR16 *text;
} mili_arg_t;

int arg_parse(EFI_SYSTEM_TABLE *stbl, mili_arg_t *arg, CHAR16 *opt);

void mili_draw(EFI_SYSTEM_TABLE *stbl, mili_arg_t *arg);

int is_num(CHAR16 c);
int pow(int b, int e);

#endif

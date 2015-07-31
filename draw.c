#include "efi_types.h"
#include "efi.h"
#include "mili.h"

void draw_spaces(EFI_SYSTEM_TABLE *stbl, int sp)
{
  for (; sp; sp--)
    stbl->cons_out->output(stbl->cons_out, L" ");
}

void mili_draw(EFI_SYSTEM_TABLE *stbl, mili_arg_t *arg)
{
  int val;
  int sp;
  int i;
  
  if (!(arg->mode & 1))
  {
    if (arg->text)
    {
      stbl->cons_out->output(stbl->cons_out, arg->text);
      stbl->cons_out->output(stbl->cons_out, L"\r\n\r\n");
    }
    stbl->cons_out->output(stbl->cons_out, L"     ╚0 0╝\r\n");
  }
  for (val = -1, sp = 3, i = 0; i < arg->size; i++, sp += val)
  {
    if (sp == -1)
    {
      val = 1;
      sp = 1;
    }
    if (sp == 5)
    {
      val = -1;
      sp = 4;
    }
    if (arg->mode & 1)
    {
      draw_spaces(stbl, sp);
      stbl->cons_out->output(stbl->cons_out, L"╔═(███)═╗\r\n");
    }
    else
    {
      draw_spaces(stbl, sp);
      stbl->cons_out->output(stbl->cons_out, L"╚═(███)═╝\r\n");
    }
  }
  if (arg->mode & 1)
  {
    draw_spaces(stbl, sp + 3);
    stbl->cons_out->output(stbl->cons_out, L"╔0 0╗\r\n\r\n");
    if (arg->text)
    {
      stbl->cons_out->output(stbl->cons_out, arg->text);
      stbl->cons_out->output(stbl->cons_out, L"\r\n");
    }
  }
}

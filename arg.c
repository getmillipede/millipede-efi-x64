#include "efi_types.h"
#include "efi.h"
#include "mili.h"

int arg_parse_size(CHAR16 *opt, mili_arg_t *arg)
{
  int i;
  int mul;
  int beg;
  int end;
  int ret;

  for (i = 0; opt[i] && (opt[i] == ' '); i++)
    ;
  for (beg = i; opt[i] && is_num(opt[i]); i++)
    ;
  if (beg == i)
    return 0;
  end = i--;
  for (ret = 0, mul = 0; i >= beg; i--)
    ret += ((opt[i] - '0') * pow(10, mul++));
  arg->size = ret;

  return end;
}

int arg_parse(EFI_SYSTEM_TABLE *stbl, mili_arg_t *arg, CHAR16 *opt)
{
  int ret;
  int i;

  for (i = 0; opt[i] && opt[i] != ' '; i++)
    ;
  for (; opt[i]; i++)
  {
    if (opt[i] == ' ')
      continue;
    if (opt[i] == '-')
      switch (opt[i + 1])
      {
      case 'r':
	arg->mode |= 1;
	i++;
	continue;
      case 's':
	ret = arg_parse_size(opt + i + 2, arg);
	if (!ret)
	{
	  stbl->cons_out->output(stbl->cons_out, L"parse error: ");
	  stbl->cons_out->output(stbl->cons_out, opt + i);
	  stbl->cons_out->output(stbl->cons_out, L"\r\n");
	  return 1;
	}
	i += ret + 1;
	continue;
      default:
	stbl->cons_out->output(stbl->cons_out, L"unknown argument: ");
	stbl->cons_out->output(stbl->cons_out, opt + i);
	stbl->cons_out->output(stbl->cons_out, L"\r\n");
	return 1;
      }
    arg->text = opt + i;
    break;
  }

  return 0;
}

int is_num(short c)
{
  if ((c >= '0') && (c <= '9'))
    return 1;
  return 0;
}

int pow(int b, int e)
{
  int ret;
  int i;

  for (ret = 1, i = e; i; i--)
    ret *= b;
  return ret;
}

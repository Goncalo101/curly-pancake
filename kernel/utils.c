void memory_copy(char *source, char *dest, int nbytes)
{
  while (nbytes > 0) {
    *dest = *source;
    
    source++;
    dest++;
    nbytes--;
  }
}

void int_to_ascii(int n, char str[])
{
  int sign = n, i = 0;

  if (n < 0) n = -n;

  do {
    str[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) str[i++] = '-';
  str[i] = '\0';
}

//
// Why does the following program display the incorrect
// size of the string?
//
// If get_string_length returned sizeof(*str) instead, would
// that fix it?
//
// Time: 15 seconds
//
#include <stdio.h>

int get_string_length(char *str)
{
  return sizeof(str);
}

int main()
{
  char *m = "The quick brown fox jumped over the lazy dog.";

  printf("length of string = %d\n",get_string_length(m));
}

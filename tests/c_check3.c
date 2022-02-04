
// To Compile
//
//  gcc -o check3 check3.c
//
// To Run
//
//  ./check3
//   The quick brown fox jumped over the lazy dog.
//
// One of your programmers has come up with a fast way to pass data to
// subroutines.
//
// Explain why this works AND
// explain why this code should never be included in the project.
//
// Explain what you know of the Intel Application Binary Interface (ABI).
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MYSTR "The quick brown fox jumped over the lazy dog.\0"

void subroutine()
{
  char *m;
  char *n = (char *)&m;;

  n += 40;
  
  while ( *n != 0 ) {
    if ( *n == 0 ) break;
    putchar(*n++);
  }
  putchar('\n');
  
}

int main()
{
  char m[64];;

  strcpy(m,MYSTR);

  subroutine();

}

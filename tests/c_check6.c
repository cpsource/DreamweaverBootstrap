#include <stdio.h>

// Compile
//
//  gcc -o check6 check6.c
//
// Execute
//
//  ./check6
//  x = 4
//  x now equals 0
//

// Why isn't x = 0 printed when x = 5 was?

int main()
{
  auto int x = 3;

  if ( x = 5 )
    printf("x = 4\n");

  if ( x = 0 )
    printf("x = 0\n");

  printf("x now equals %d\n",x);
}

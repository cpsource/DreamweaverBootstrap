#include <stdio.h>

//
// Why doesn't main recognize the error from subroutine ?
//
// When run, we get:
//   ./check2
//   No Error Detected
//

unsigned int subroutine()
{
  // do something useful
  
  // detect an error and return
  return -1;
}

int main()
{
  if ( subroutine() < 0 ) {
    printf("Error Detected\n");
  } else {
    printf("No Error Detected\n");
  }
}

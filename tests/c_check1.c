#include <string.h>

//
// Why does this program corrupt the stack?
//

int main()
{
  char m[4];

  strcpy(m,"1234");
  
}

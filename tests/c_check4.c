#include <setjmp.h>
#include <stdlib.h>

// to compile
//
//  gcc -g -o check4 check4.c
//
// Explain why valgrind objects
//
// valgrind ./check4
// ==8291== Memcheck, a memory error detector
// ==8291== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==8291== Using Valgrind-3.17.0 and LibVEX; rerun with -h for copyright info
// ==8291== Command: ./check4
// ==8291== 
// ==8291== 
// ==8291== HEAP SUMMARY:
// ==8291==     in use at exit: 1,024 bytes in 1 blocks
// ==8291==   total heap usage: 1 allocs, 0 frees, 1,024 bytes allocated
// ==8291== 
// ==8291== LEAK SUMMARY:
// ==8291==    definitely lost: 1,024 bytes in 1 blocks
// ==8291==    indirectly lost: 0 bytes in 0 blocks
// ==8291==      possibly lost: 0 bytes in 0 blocks
// ==8291==    still reachable: 0 bytes in 0 blocks
// ==8291==         suppressed: 0 bytes in 0 blocks
// ==8291== Rerun with --leak-check=full to see details of leaked memory
// ==8291== 
// ==8291== For lists of detected and suppressed errors, rerun with: -s
// ==8291== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
//

static jmp_buf env;

static void inner(void)
{
  longjmp(env, 1);
}

static void middle(void)
{
  void *ptr = malloc(1024);
  inner();
  free(ptr);
}

void outer(void)
{
  int i;

  i = setjmp(env);
  if (i == 0)
    middle();
}

int main()
{
  outer();
}

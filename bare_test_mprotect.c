#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{
  int myarray[7] = {9, 8, 7, 6, 5, 4, 3};
  int x = PGROUNDDOWN(((int)myarray));
  int mprotect_return = mprotect((void*) x, 4);
  printf(1, "mprotect returned %d\n", mprotect_return);

  exit();
} 

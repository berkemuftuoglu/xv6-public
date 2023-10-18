#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{
  char* start = sbrk(0);
  sbrk(PGSIZE);
  *start=100;
  mprotect(start, 1);
  printf(1, "protected value = %d\n", *start);

  int pid = fork();
  if (pid == 0) {
    printf(1, "I am child\n");
    printf(1, "protected value = %d\n", *start);
    munprotect(start, 1);

    *start = 101;
    printf(1, "if you see this change you succeed, unprotected value became: %d.\n", *start);
    exit();
  } else if (pid > 0) {
    wait();
    printf(1, "I am parent, i will fail\n");
    printf(1, "protected value = %d\n", *start);
    *start = 101;
    printf(1, "if you see this you fail.\n");
    exit();
  }


  exit();
} 

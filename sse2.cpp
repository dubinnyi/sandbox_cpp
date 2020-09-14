#include <time.h>
#include <stdio.h>


#define N 102030
#define NTIMES 12345

//#define ALIGN __attribute__ ((aligned (16)))
#define ALIGN 

double a[N] ALIGN;
double b[N] ALIGN;
double c[N] ALIGN;
double r[N] ALIGN;

int
main (void)
{
  struct timespec wall_clock_start, wall_clock_finish;
  clock_gettime(CLOCK_MONOTONIC, &wall_clock_start);

  int i, times;
  for (i = 0; i < N; ++i)
    r[i] = (a[i] + b[i]) * c[i];
  for (times = 0; times < NTIMES-1; times++)
    {
      for (i = 0; i < N; ++i)
        r[i] += (a[i] + b[i]) * c[i];
    }

  clock_gettime(CLOCK_MONOTONIC, &wall_clock_finish);
  double wall_clock_seconds = (wall_clock_finish.tv_sec - wall_clock_start.tv_sec);
  wall_clock_seconds += (wall_clock_finish.tv_nsec - wall_clock_start.tv_nsec) / 1000000000.0;
   
  long n=N, nt = NTIMES;
  printf("N=%ld NTIMES=%ld, N*NTIMES=%ld\n", n, nt, n*nt);
  printf("The wall clock time:  %f seconds\n", wall_clock_seconds);
  printf("Speed:  %6.3f GHz\n", 1e-9*n*nt/wall_clock_seconds);

  return 0;
}

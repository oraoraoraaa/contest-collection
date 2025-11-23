#include <stdio.h>

int
main ()
{
  int t1, p1, t2, p2;
  scanf ("%d %d %d %d", &t1, &p1, &t2, &p2);

  // division precision
  double v = (double)(p2 - p1) / (t2 - t1);

  if (v > 0)
    printf ("%.0f", (float)t2 + (100 - p2) / v);
  else if (v < 0)
    printf ("%.0f", (float)t2 - p2 / v);
  else
    return 0;

  return 0;
}
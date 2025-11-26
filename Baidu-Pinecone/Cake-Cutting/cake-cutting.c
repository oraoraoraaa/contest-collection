#include <stdio.h>

int
main ()
{
  int n, m, k;
  int rec[20][20] = { 0 };
  scanf ("%d %d %d", &n, &m, &k);

  for (int i = 0; i < k; i++)
    {
      int y, direction;
      scanf ("%d %d", &y, &direction);

      // align axis
      int current_n = 0;
      int current_m = y - 1;

      // while in-bound, cut through
      while (current_n < n && current_m >= 0 && current_m < m)
        {
          rec[current_n][current_m] = 1;
          current_n++;
          if (direction == -1)
            {
              current_m--;
            }
          else if (direction == 1)
            {
              current_m++;
            }
          else
            {
              return -1;
            }
        }
    }

  int cut_count = 0;
  for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
        {
          if (rec[j][k] == 1)
            cut_count++;
        }
    }

  printf ("%d", cut_count);
}
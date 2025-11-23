#include <stdio.h>

int
main ()
{
  int N;
  if (scanf ("%d", &N) != 1)
    return -1;

  long long ans;
  int last_diff = -2;
  long prev_val, current_val, diff_len;
  scanf ("%ld", &prev_val);

  for (int i = 1; i < N; i++)
    {
      scanf ("%ld", &current_val);
      int diff = current_val - prev_val;
      if (diff == 0 || diff == 1)
        {
          if (last_diff == -2)
            {
              diff_len = 1;
              last_diff = diff;
              prev_val = current_val;
              continue;
            }
          if (diff == last_diff)
            {
              diff_len = 1;
              last_diff = diff;
              prev_val = current_val;
              continue;
            }

          diff_len++;

          if (diff_len >= 2)
            ans += (diff_len - 1);

          last_diff = diff;
        }
      else
        {
          diff_len = 0;
          last_diff = -2;
        }
      prev_val = current_val;
    }

  printf ("%lld", ans);
  return 0;
}
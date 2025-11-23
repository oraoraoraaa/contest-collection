#include <stdio.h>

int
main ()
{
  int string_count;
  if (scanf ("%d", &string_count) != 1)
    return 0;

  int grapes[101] = { 0 };
  int total_grapes = 0;

  for (int i = 0; i < string_count; i++)
    {
      if (scanf ("%d", &grapes[i]) != 1)
        return 0;
      total_grapes += grapes[i];
    }

  int half = total_grapes / 2;
  int current_sum = 0;
  int max = 0;

  for (int j = 0; j < string_count; j++)
    {
      if ((current_sum + grapes[j]) <= half)
        {
          current_sum += grapes[j];
          if (max < current_sum)
            max = current_sum;
        }
      else
        {
          int remaining = total_grapes - current_sum - grapes[j];
          if (remaining >= max)
            max = remaining;
          break;
        }
    }
  printf ("%d\n", max);
  return 0;
}
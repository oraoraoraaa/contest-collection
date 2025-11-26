#include <stdio.h>
#include <string.h>

#define BUFSIZ 101
#define INPUT 2

void
reverse_copy (char *dest, const char *src)
{
  for (int i = 0; i < strlen (src); i++)
    {
      dest[i] = src[strlen (src) - i - 1];
    }
}

int
get_lis (const char *src)
{
  const int len = (int)strlen (src);
  int dp[2 * BUFSIZ] = { 0 };

  int global_maximum = 1;

  for (int i = 0; i < len; i++)
    {
      dp[i] = 1;
      for (int j = 0; j < i; j++)
        {
          if (src[j] >= src[i])
            continue;
          if (dp[j] + 1 > dp[i])
            dp[i] = dp[j] + 1;
        }
      if (dp[i] > global_maximum)
        global_maximum = dp[i];
    }

  return global_maximum;
}

int
main ()
{
  char A[BUFSIZ] = { 0 };
  char B[BUFSIZ] = { 0 };
  char A_reversed[BUFSIZ] = { 0 };
  char B_reversed[BUFSIZ] = { 0 };

  scanf ("%s", A);
  scanf ("%s", B);

  reverse_copy (A_reversed, A);
  reverse_copy (B_reversed, B);

  char *form_A[INPUT] = { A, A_reversed };
  char *form_B[INPUT] = { B, B_reversed };

  int max_count = 0;
  char combined[2 * BUFSIZ] = { 0 };

  for (int i = 0; i < INPUT; i++)
    {
      for (int j = 0; j < INPUT; j++)
        {
          // form A + form B
          strcpy (combined, form_A[i]);
          strcat (combined, form_B[j]);
          if (get_lis (combined) > max_count)
            max_count = get_lis (combined);

          // form B + form A
          strcpy (combined, form_B[i]);
          strcat (combined, form_A[j]);
          if (get_lis (combined) > max_count)
            max_count = get_lis (combined);
        }
    }
  printf ("%d", max_count);
}

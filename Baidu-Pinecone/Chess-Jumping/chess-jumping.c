#include <stdio.h>
#include <string.h>

int
main ()
{
  char buf[20];
  int k = 0;

  scanf ("%s", buf);
  scanf ("%d", &k);

  int N = strlen (buf);
  int max_end = (N % 2 == 1) ? N : N - 1;

  int has_piece[20] = { 0 };
  int piece_count = 0;

  // map the pieces in the whole field and
  // calculate the total number (except the jumping piece)
  for (int i = 0; i < N; i++)
    {
      if (buf[i] == 'o')
        {
          has_piece[i] = 1;
          if (i != 0)
            piece_count++;
        }
    }

  for (int y = max_end; y >= 1; y -= 2)
    {
      int bridges_needed = (y - 1) / 2;
      if (bridges_needed > piece_count)
        continue;

      int extras = piece_count - bridges_needed;
      int remaining_space = N - y;

      if (extras > remaining_space)
        continue;

      int bridges_kept = 0;
      for (int j = 1; j < y; j += 2)
        {
          if (has_piece[j])
            bridges_kept++;
        }

      int pieces_in_zone = 0;
      for (int m = y; m < N; m++)
        {
          if (has_piece[m])
            pieces_in_zone++;
        }

      int extras_kept = (pieces_in_zone < extras) ? pieces_in_zone : extras;

      int pieces_moved = piece_count - extras_kept - bridges_kept;

      if (pieces_moved <= k)
        {
          printf ("%d", y);
          return 0;
        }
    }
  return 0;
}
# Step Sequence

## Overall Logic

To detect a "step sequence", we can introduce a `diff` array that will show the difference between two values in the sequence array `A`.

We therefore only need to check if `0` and `1` are appearing in the `diff` array one by one.

![step sequence overall logic](https://github.com/user-attachments/assets/53639ad4-29fc-491c-8e1c-458af3ba13e6)

## Implementation

Since the amount of the input could be very large, it's not wise to use an array to hold all the input. We only care about:

1. Is current `diff` value different from the previous one `last_diff`?

2. How many alternately appearing `diff`s we have caught in total (`diff_len`) right now?

To calculate the amount of subsets in total, we should look at how many new subsets it brings us when `diff_len` increments:

![step sequence subset calculation](https://github.com/user-attachments/assets/9ce4a5c1-a9e2-4ef9-9493-3a594d34f0ca)

Every time `diff_len` increments by one, the new subsets it brings always including itself. Therefore, we can find out that the increment will bring us `diff_len - 1` new subsets.

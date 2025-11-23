# Chess Jumping

## Overall Logic

If the starting jumping piece is in position `0`, the ideal circumstance is when every piece is put on odd number positions (`1`, `3`, `5`, ...) and every even number positions are empty.

We call the odd number positions _bridge positions_.

To go to the position `Y` we want, we must make all the pieces before `Y` in the bridge positions while making even number positions empty, and other pieces after `Y` doesn't matter.

## Implementation

Starting from the largest possible place that the piece can jump to, do the conditional test. Upon failure, decrease the examining position `Y` to the next possible place until conditions met.

![jumping chess implementation](https://github.com/user-attachments/assets/f8428daf-3124-4a94-9c62-d9a4853eb838)

The three conditions and their detailed implementation are listed as follows:

1. Are there enough pieces in the whole field to put on bridge positions?

We will need `Y / 2` pieces to put in all bridge positions.

![jumping chess bridges needed](https://github.com/user-attachments/assets/a6582cf6-660c-4b62-bfbe-46c574dd079f)

2. Is there enough space after `Y` to put all extra pieces?

- Extra pieces can be calculated by `total_pieces - bridges_needed`
- Available space can be calculated by `total_position - Y`.

3. Can we do the moving in the restricted `k` steps?

To calculate the moving steps, we can calculate the pieces that can be reserved (position kept). Using the total amount of pieces to subtract the number of pieces that can be kept, we get the amount of pieces that must be moved.

![jumping chess example workflow](https://github.com/user-attachments/assets/8d5f577c-3971-4430-aceb-9b65bb4efe71)

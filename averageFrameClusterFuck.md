## WHAT THE HELL DOES THIS CODE EVEN DO???
### Explaining what my clusterfuck of a code is doing

Short answer:
The code chooses a frame that is closest to the average frame.

-Why?
-So we can sorta "compress" all three frames into one frame, thus saving space (With a loss of data of course)

### More detailed explanation:

-Average frame of all of them, just means that I got the average value of each position in the 3d array
For example:
I got 7.66 because I summed up 6, 10, 7 and multiplied the result by 3

-The distances (Euclidean), is finding the distance of each position in the 3d array from the average value of said position.
For example:
I got 1.66 by taking the absolute value of 6 - 7.66

The sum of each frame is just adding up all the euclidean distances for a certain frame.
I then chose the frame that has the smallest sum.

<img width="786" height="537" alt="AverageFrame" src="https://github.com/user-attachments/assets/e5f21413-5eda-417d-9741-951745190c01" />

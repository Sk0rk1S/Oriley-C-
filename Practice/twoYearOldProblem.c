//4 13 40 121, I want this sequence of numbers x 4

/*I noticed the sequence was Current number and Prev number's difference
ADDED to the current number, This was a problem I struggled in math 2 years ago
but now I realized I'm able to solve this via programming
as its similar to the Fibonacci sequence algorithm...
HOLY FUCKING SHIT IT WORKS A<SJFGAWKYGDUAYDFBUK */

//a - b = 9 (c) c is equal to a - b

//a + (9(c) x 3)) = 40(d) d is equal to a + difference x 3

//b(4) = a(13) assign a val to b

//a(13) = e(d) assign d to a
#include <stdio.h>

int twoYearOldProblem(int x){
  int a = 4;
  int b = 0;
  int c, d;
  for (int i = 0; i <= x; i++)
  {
    if (i == 0)
    {
      a = 1;
    }
    else
    {
      c = a - b;
      d = a + (c * 3);
      b = a;
      a = d;
    }
  }
  return a * 4;
}

int main()
{
  int x;
  printf("Enter Iteration");
  scanf("%d", &x);
  printf("%d", twoYearOldProblem(x));
}

#include <stdio.h>
//First thing Ive ever coded that kinda works March 12 2025!!!
//Yes it does accurately calculate your GPA based on your percentages!
//Edit I was wrong it doesnt

int iteration(int grade){
    int n0, n;
    n0 = 100 - grade;
    n = n0 / 5.22;
    return n;
}

//OLD CODE BELOW
/*
int main() {
  int grade;
  int classes;
  int sum = 0;
  float divideBy = 0;

  printf("enter classes\n");
  scanf("%d", & classes);
  for (int i = 0; i < classes; i++) {
    printf("enter grade\n");
    scanf("%d", & grade);
    if (grade > 100 || grade < 0) {
      printf("invalid grade enter again");
      scanf("%d", & grade);
    }
    else if(grade < 50){
      grade = 0;
    }
    sum += grade;
    divideBy += 23.3;
  }
  float gpa = sum / divideBy;
  printf("Your average GPA is %f\n", gpa);
}
*/

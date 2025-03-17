#include <stdio.h>
//First thing Ive ever coded that kinda works March 12 2025!!!
//Yes it does accurately calculate your GPA based on your percentages!
//Edit I was wrong it doesnt
//Ok it works now 
float iteration(int grade){    //This function is used to implement the rate of change from each Grade 
    float n0, n;               //For example how much would the GPA point change from 100% to 90%?
    n0 = 100 - grade;           //I found the value 5.22 on paper and added it here
    n = n0 / 5.22;
    return n;
}


int main() {
int grade, classes;
float tempgrade1, tempgrade2;
float sum = 0;
float gpa = 0;

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
    tempgrade1 = 23.3 + (0.33 * iteration(grade));    //23.3 Is how much the grade is divided by to get the GPA of 100% initially
    tempgrade2 = grade/tempgrade1;                    //But as the grade goes lower, dividing by 23.3 doesnt give the accurate GPA anymore,
    sum += tempgrade2;                                //so the dividing needs to change accordingly with the corresponding drop in grade from 100% 
  }                                                   // I found the value 0.33 on paper and added it here
  gpa = sum / classes;
  printf("Your average GPA is %f\n", gpa);
}


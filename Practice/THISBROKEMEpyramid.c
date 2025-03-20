#include <stdio.h>
void test(int stars){
    char a = 'a';                          ///Dont mind me calling the variables 'stars' even though it doesnt print out stars lol
    char b = 'b';
    for(int i = 1; i < stars + 1; i++){     ///If I = 1, it skips the first iteration! cause the first iteration is entirely made of "a"s
                                             //Find the rate of change in the how many 'a's are printed before 'b' is printed, as each iteration passes
        for(int j = stars; j > i; j--){     
            printf("%c", a);
        }
        for(int k = 0; k < i; k++){         ///THAT WAS THE FUCKIN ANSWER I JUST NEEDED TO ADD A SPACE IN THE PRINT STATMENT
            printf("%c ", b);               ///LIKE ALL I NEEDED TO FUCKIN DO WAS ADD A SPACE AFTER IT PRINTED 'b' OMFG
        }                                   /// 9:19am 2025 March 20 I finally understand it
        printf("\n");                       /// All i needed to do was make an upside down triangle and a right side up triangle with a space after
    }                                       /// printf("%c(SPACE)", b); THAT WAS LITERALLY IT BRO HOLY SHIT
}

int main(){
    int stars;
    printf("How many Stars would you like?");
    scanf("%d", &stars);
    test(stars);
}

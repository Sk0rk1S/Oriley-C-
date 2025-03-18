#include <stdio.h>
void printStar(int stars){      ///a and b variables were there to help me trace the code easier
    int sum;                    //To be honest this code was a guess and check and I got lucky
    char star = 'a';            //Finally...HOLY FUCKIN SHIT MY ACCOMPLISHMENT SUNK IN ACTUALLY FUVKING WORKS!!!!!!!!!
    char test = 'b';            ///THIS WAS ALL ME NO CHAT GPT STACK OVERFLOW NOTHING HELPED ME
    for(int i = 0; i < stars; i++){     ///WHICH IS WHY IM CELEBRATING THIS SO MUCH
        for(int j = 0; j < i; j++){     ///MARCH 18 2025 AT 9:32AM PST I COMPLETED THIS HOLY SHIIITTT
            printf("%c", star);         ///NO INSTRUCTION MANUAL EITHER LIKE I DID IT ALL ON MY OWN OMMMGGG
        }
        printf("%c\n", test);
    }
}

int main(){
    int stars;
    printf("Enter how many stars you'd like");
    scanf("%d", &stars);
    printStar(stars);
}

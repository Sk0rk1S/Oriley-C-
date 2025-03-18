#include <stdio.h>
void printBetterStar(int stars){    //FINISHED AT 10:53AM
char star = '*';                    //ONCE AGAIN I TRACED THE CODE USING A AND B TO FIND OUT THE CODE STRUCTURE
char a = 'a';                       //I REALLY DONT KNOW HOW I GOT TO THE SOLUTION BUT I SOMEHOW DID
char b = 'b';                       //ONCE AGAIN I FIGURED ALL OF THIS OUT ON MY OWN
for(int i = 0; i < stars; i++){     //LIKE HOLYSHIT I CANT BELIVE
    for(int j = 0; j < i; j++){     //I DIDNT SO A SINGLE GOOGLE/STACKOVERFLOW/CHATGPT IT WAS ALL ME FROM MY BRAIN
        printf("%c", a);            //LIKE EVEN I CANT BELIVE I ACTUALLY DID IT?!?!?!
    }
    printf("%c\n", b);
}
for(int i = 0; i < stars +1 ; i++){ 
    for(int j = stars; j > i; j-- ){
        printf("%c", a);
    }
    printf("%c\n", b);
}
}

int main(void){
    int stars;
    printf("enter how many stars the sideways pyramids gonna be");
    scanf("%d", &stars);
    printBetterStar(stars);
}

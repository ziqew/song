# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <signal.h>
# include <netinet/in.h>
# include <sys/socket.h>

int* distributeCandies(int candies, int num_people, int* returnSize);

int main(){
    int candies=10;
    int num_people =3;
    int* returnSize=&num_people;
    int* result=distributeCandies(candies,num_people,returnSize);
    for(int i=0;i<*returnSize;i++){
        printf("%d ", result[i]);
    }
    char c='a';
    if (isalpha (c))
        printf ("The character `%c' is alphabetic.\n", c);

}

int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize = num_people;
    int *result = malloc(sizeof(int) * num_people);
    memset(result,0,sizeof(int) * num_people);
    int currentCandies = 0;
    int loop = 0;
    while(candies > 0) {
        for(int i = 0;i< num_people;i++) {
            currentCandies = loop*num_people + i + 1;
            if(candies - currentCandies >= 0) {
                result[i] += currentCandies;
            } else {
                result[i] += candies;
            }
            candies -= currentCandies;
            if (candies <= 0) break;
        }
        loop++;
    }
    return result;
}
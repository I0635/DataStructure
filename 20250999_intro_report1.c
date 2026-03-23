#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

double calculateAverage(int scores[], int size)
{
    int total = 0;
    double average;
    
    for(int i=0;i<size;i++){
        total = total + scores[i];
    }
    printf("점수 합계: %d\n", total);
    average = (double)total / size;
    
    return average;
}

int main()
{
    srand(time(NULL));
    
    int scores[SIZE] = {0};
    double average = 0;
    
    for(int i=0;i<SIZE;i++){
        scores[i] = rand() % 101;
        printf("%3d번 학생: %3d점\n", i+1, scores[i]);
    }
    
    average = calculateAverage(scores, SIZE);
    printf("평균 점수 : %.1f\n", average);
    
    return 0;
}

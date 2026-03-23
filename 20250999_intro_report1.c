#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);

int main()
{
    srand(time(NULL));
    
    int scores[SIZE] = {0};
    double average = 0;
    int studentNumber;
    
    for(int i=0;i<SIZE;i++){
        scores[i] = rand() % 101;
    }
    
    average = calculateAverage(scores, SIZE);
    printf("학급 평균 점수 : %.2f\n", average);
    
    printf("학생 번호를 입력하세요 (1 ~ %d): ", SIZE);
    scanf("%d", &studentNumber);
    
    int score = getStudentScore(scores, SIZE, studentNumber);
    if(score != -1) {
        printf("%d번 학생의 점수: %d\n", studentNumber, score);
    } else {
        printf("유효하지 않은 학생 번호입니다.\n");
    }
    
    printScore(scores, SIZE, average, 0);
    printScore(scores, SIZE, average, 1);
    printScore(scores, SIZE, average, 2);
    
    return 0;
}

double calculateAverage(int scores[], int size){
    int total = 0;
    double average;
    
    for(int i=0;i<size;i++){
        total = total + scores[i];
    }
    average = (double)total / size;
    
    return average;
}

int getStudentScore(int scores[], int size, int studentNumber){
    if(studentNumber >= 1 && studentNumber <= size){
        return scores[studentNumber - 1 ];
    } else {
        return -1;
    }
}

void printScore(int scores[], int size, double average, int option){
    switch(option){
        case 0:
            for(int i =0;i<size;i++){
                printf("학생번호: %d, 점수 %d\n", i+1, scores[i]);
            }
            break;
        case 1:
            printf("평균 이상 학생\n");
            for(int i =0;i<size;i++){
                if(scores[i] >= average) printf("학생번호: %d, 점수 %d\n", i+1, scores[i]);
            }
            break;
        case 2:
            printf("평균 미만 학생\n");
            for(int i =0;i<size;i++){
                if(scores[i] < average) printf("학생번호: %d, 점수 %d\n", i+1, scores[i]);
            }
            break;
        default:
            printf("유효하지 않은 옵션입니다\n");
            break;
    }
}

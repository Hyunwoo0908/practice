#include <stdio.h>
#include <string.h>

struct Student{
    char name[50];
    int age;
    int score;
};
void printAllStudents(struct Student student[], int n){
    for(int i = 0; i < n; i++){
        printf("%s %d %d\n", student[i].name, student[i].age, student[i].score);
    }
}

double calculateAverage(struct Student student[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += student[i].score;
    }
    return (double) sum / n;
}

int main(){
    struct Student student[10];
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%d%d", student[i].name, &student[i].age, &student[i].score);
    }
    for(int i = 0; i < n; i++){
        printf("%s %d %d\n", student[i].name, student[i].age, student[i].score);
    }

    while(1){
        printf("1. 학생 추가\n");
        printf("2. 전체 목록 보기\n");
        printf("3. 평균 점수 보기\n");
        printf("4. 종료\n");

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("학생 추가 선택됨\n");
                scanf("%s%d%d", student[n].name, &student[n].age, &student[n].score);
                n += 1;
                break;

            case 2:
                printf("전체 목록 보기 선택됨\n");
                printAllStudents(student, n);
                break;
            case 3:
            {
                printf("평균 점수 보기 선택됨\n");
                double avg = calculateAverage(student, n);
                printf("평균 점수: %.2f\n", avg);
                break;
            }
            case 4:
                printf("종료합니다.\n");
                break;
            default:
                printf("잘못된 선택입니다.\n");
        }
        if(choice == 4){
            break;
        }
    }

}
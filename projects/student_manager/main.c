#include <stdio.h>
#include <string.h>
#include <stdbool.h> /*0과 1 대신 false, true를 쓰려면 헤더를 추가해야함
헤더 추가 안하면 0과 1로 사용*/

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
        printf("4. 학생 검색\n");
        printf("5. 학생 삭제\n");
        printf("6. 종료\n");

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
            {
                printf("학생 검색 선택 됨\n");

                char searchName[50];

                printf("검색할 이름을 입력해 주세요: ");
                scanf("%s", searchName);

                int found = false; //<stdbool.h> 헤더 사용 안할 시 0입력

                for(int i = 0; i < n; i++){
                    if(strcmp(student[i].name, searchName) == 0){ //strcmp(문자열1, 문자열2) -> 두 문자열이 같은지 비교하는 함수
                        printf("%s %d %d\n", student[i].name,     //반환값: 0 -> 두 문자열이 같음
                        student[i].age, student[i].score);        //0보다 작은 값 -> 문자열 1이 문자열 2보다 앞에 있음
                                                                  //0보다 큰 값 -> 문자열 1이 문자열 2보다 뒤에 있음
                                                                  //여기서는 문자열이 같은지만 확인(학생의 이름이 찾는 이름인지)
                    found = 1;
                    }
                }
                if(found == 0){
                    printf("해당 학생을 찾을 수 없습니다.\n");
                }
                break;
            }

            case 5:
            {
                char deleteName[50];

                printf("삭제할 이름을 입력해 주세요: ");
                scanf("%s", deleteName);

                int index = -1;

                for(int i = 0; i < n; i++){
                    if(strcmp(student[i].name, deleteName) == 0){
                        index = i;
                    }
                }
                if(index == -1){
                    printf("해당 학생을 찾을 수 없습니다.\n");
                }else{
                    for(int i = index; i < n-1; i++){
                        student[i] = student[i+1];
                    }
                    n -= 1;
                    printf("%s 학생을 삭제했습니다.\n", deleteName);
                }
                break;
            }

            case 6:
                printf("종료합니다.\n");
                break;
            default:
                printf("잘못된 선택입니다.\n");
        }
        if(choice == 6){
            break;
        }
    }
    FILE *outFile = fopen("students.txt","w");
    /*fopen("파일 이름", "w") -> 파일을 열어 데이터를 저장하기 위한 함수

    "students.txt -> 저장할 파일 이름"
    "w" -> write(쓰기) 모드*/
    
    fprintf(outFile, "%d\n", n);
    /*fprintf(파일 포인터, 출력 형식, 값)
    printf() -> 화면에 출력
    fprintf() -> 파일에 출력
    
    outFile -> 데이터를 저장할 파일*/
    for(int i = 0; i < n; i++){
        fprintf(outFile, "%s %d %d\n", student[i].name,
        student[i].age, student[i].score);
    }
    fclose(outFile);

    return 0;

}
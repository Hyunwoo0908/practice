#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int age;
    int score;
};
void printAllStudents(Student student[], int n){
    for(int i = 0; i < n; i++){
        cout<<student[i].name<<" "<<student[i].age<<" "<<student[i].score<<"\n";
    }
}
/*void -> return 해주는게 없는 것
ex) calculateAverage -> double을 돌려줌
findMax -> int를 돌려줌
화면에 출력만 하고 끝 -> void*/

double calculateAverage(Student student[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += student[i].score;
    }
    return (double) sum / n;
}
int main(){
    Student student[10];
    int n;

    cin>>n;
    for(int i = 0;  i < n; i++){
        cin>>student[i].name>>student[i].age>>student[i].score;
    }
    for(int i = 0; i < n; i++){
        cout<<student[i].name<<" "<<student[i].age<<" "<<student[i].score<<"\n";
    }

    while(true){
        cout<<"1. 학생 추가\n";
        cout<<"2. 전체 목록 보기\n";
        cout<<"3. 평균 점수 보기\n";
        cout<<"4. 종료\n";

        int choice;
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"학생 추가 선택됨\n";
                cin>>student[n].name>>student[n].age>>student[n].score;
                cout<<student[n].name<<" 학생을 추가했습니다.\n";
                n = n+1;
                break;
            case 2:
                cout<<"전체 목록 보기 선택됨\n";
                printAllStudents(student, n);
                break;
                
            case 3:
                {
                cout<<"평균 점수 보기 선택됨\n";
                double avg = calculateAverage(student, n);
                cout<<"평균 점수: "<<avg<<"\n";
                break;
                }
            case 4:
                cout<<"종료합니다.\n";
                break;
            default:
                cout<<"잘못된 선택입니다.\n";
        }
        if(choice == 4){
        break;
        }
    }
    return 0;

}
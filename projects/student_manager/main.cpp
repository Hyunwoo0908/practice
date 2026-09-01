#include <iostream>
#include <string>
#include <fstream>
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

    ifstream inFile("students.txt");

    inFile>>n; //파일에서 학생 수 읽기(영구 저장)

    /*cin >> n;
    for(int i = 0; i < n; i++){
    cin >> student[i].name >> student[i].age >> student[i].score;
    } <- 기존 코드(실행 할 때 마다 입력받아야 했음)*/


    for(int i = 0; i < n; i++){
        inFile>>student[i].name>>student[i].age>>student[i].score;
    }

    inFile.close();

    for(int i = 0; i < n; i++){
        cout<<student[i].name<<" "<<student[i].age<<" "<<student[i].score<<"\n";
    }

    while(true){
        cout<<"1. 학생 추가\n";
        cout<<"2. 전체 목록 보기\n";
        cout<<"3. 평균 점수 보기\n";
        cout<<"4. 학생 검색\n";
        cout<<"5. 학생 삭제\n";
        cout<<"6. 종료\n";

        int choice;
        cin>>choice;

//case문 안에 새로운 변수 선언 시 해당 case는 중괄호로 묶어주기
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
                {
                cout<<"학생 검색 선택됨\n";
                string searchName;
                cout<<"검색할 이름을 입력해 주세요: ";
                cin>>searchName;

                bool found = false;
                /*bool이 false로 시작하는 이유
                -> 아직 학생을 못 찾은 상태에서 검색을 시작하기 때문
                (아직 for문을 한 번도 안 돌았으니, 당연히 아직 못 찾음 -> false)*/

                for(int i = 0; i < n; i++){
                    if(student[i].name == searchName){
                        cout<<student[i].name<<" "<<student[i].age<<" "<<student[i].score<<"\n";
                        found = true; //찾을 시 -> 상태를 "찾음" 으로 바꿔줌
                    }
                }
                /*for문을 다 돈 후 확인
                found가 여전히 false라면 -> 한 번도 못 찾았다는 것*/
                if(found == false){
                    cout<<"해당 학생을 찾을 수 없습니다.\n";
                }
                break;
            }

            case 5:
            {
                string deleteName;
                cout<<"삭제할 이름을 입력해 주세요: ";
                cin>>deleteName;

                int index = -1; //아직 못 찾은 상태를 표시 bool something = false; 와 같은 방식

                for(int i = 0; i < n; i++){
                    if(student[i].name == deleteName){
                        index = i; //찾으면 실제 위치(0,1,2...)로 바뀜
                    }
                }
                /*index를 -1로 시작하는 이유
                : 배열의 실제 인덱스는 항상 0이상이라서 -1은 "그런 위치가 없다 = 아직 못 찾았다"
                는 의미로 쓸 수 있음
                (0으로 시작 시 "0번째에서 찾은 것"과 "못 찾은 것"을 구분할 수 없음) */
                if(index == -1){ //못 찾은 경우
                    cout<<"해당 학생을 찾을 수 없습니다.\n";
                }else{

                    for(int i = index; i < n-1; i++){
                        student[i] = student[i+1];
                    }

                    n -= 1;
                    cout<<deleteName<<" 학생을 삭제했습니다.\n";
                }
                break;
            }
            case 6:
            cout<<"종료합니다.\n";
                break;
            default:
                cout<<"잘못된 선택입니다.\n";
        }
        if(choice == 6){
        break;
        }
    }
    ofstream outFile("students.txt");
    outFile << n <<"\n";

    for(int i = 0; i < n; i++){
        outFile << student[i].name <<" "<<student[i].age<<" "<<student[i].score<<"\n";
    }
    outFile.close();
    
    return 0;

}
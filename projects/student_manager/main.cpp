#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int age;
    int score;
};

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
    return 0;

}
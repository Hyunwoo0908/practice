#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int age;
    int score;
};

int main(){
    Student s1;
    
    cin>>s1.name >> s1.age >> s1.score;


    cout<<s1.name <<" "<< s1.age<<" "<<s1.score;

    return 0;

}
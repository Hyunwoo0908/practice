#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream inFile("data.txt"); //읽기 모드로 파일 열기

    string line;
    int number;

    inFile >> line; //첫 번째 줄 읽기 - "안녕하세요"
    inFile >> number; //두 번째 줄 읽기 - 100

    cout<<"읽은 내용: "<<line<<" "<<number<<"\n";

    inFile.close();

    return 0;
}
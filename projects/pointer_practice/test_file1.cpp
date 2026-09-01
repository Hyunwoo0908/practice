#include <iostream>
#include <fstream> //파일 입출력 기능
using namespace std;
int main(){
    ofstream outFile("data.txt"); //"data.txt" 라는 파일을 쓰기 모드로 염

    outFile <<"안녕하세요\n"; //cout 쓰듯이 파일에 씀
    outFile<<100<<"\n";

    outFile.close(); //다 썼으면 파일 닫기

    cout<<"파일 저장 완료\n";
    
    return 0;
}
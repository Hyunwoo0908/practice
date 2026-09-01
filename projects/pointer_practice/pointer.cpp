#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int *arr = new int[n]; //정수 n개가 들어갈 공간
                           //arr은 그 공간의 시작 주소를 가리키는 포인터

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    delete[] arr; //new로 만들었던 메모리 반납
                  //new로 배열을 만들었으면 delete[]로 짝 맞추기
                  //배열 아닌 단일 값이면 delete만, 배열이면 delete[]

    return 0;
}
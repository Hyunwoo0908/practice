#include <iostream>
using namespace std;

int main(){
    int student;
    int arr[5];

    cin>>student;

    for(int i = 0; i < student; i++){
        cin>>arr[i];
        cout<<arr[i]<<" ";
    }


    return 0;
}
#include <iostream>
using namespace std;

double calculateAverage(int scores[], int count){

    int sum = 0;

    for(int i = 0; i < count; i++){

        sum += scores[i];
    }

    return (double)sum/count;
}
int findMax(int scores[], int count){
    int max = scores[0];

    for(int i = 0; i < count; i++){
        if(max < scores[i]){
            max = scores[i];
        }
    }
    return max;
}
int findMin(int scores[], int count){
    int min = scores[0];

    for(int i = 0; i < count; i++){
        if(min > scores[i]){
            min = scores[i];
        }
    }
    return min;

}

int main(){
    int student;
    int arr[5];

    cin>>student;

    for(int i = 0; i < student; i++){
        cin>>arr[i];
        cout<<arr[i]<<" ";
    }

    double avg = calculateAverage(arr, student);
    
    cout<<"\n평균 값 :" << avg<<"\n";

    int MaxValue = findMax(arr, student);

    cout<<"최고점 :"<< MaxValue<<"\n";

    int MinValue = findMin(arr, student);

    cout<<"최저점 :"<<MinValue<<"\n";

    for(int i = 0; i < student; i++){
        if(arr[i] >= avg){
            cout<<arr[i] << "점 - 평균 이상\n";
        }else{
            cout<<arr[i] << "점 - 평균 이하\n";
        }
    }

    return 0;
}
//cd projects\grade_manager 로 위치 바꾸고 실행하기
//g++ main.cpp -o main
// ./main
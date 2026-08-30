#include <iostream>
using namespace std;

double calculateAverage(int scores[], int count){

    int sum = 0;

    for(int i = 0; i < count; i++){

        sum += scores[i];
    }

    return (double)sum/count;
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
    
    cout<< avg;
    return 0;
}
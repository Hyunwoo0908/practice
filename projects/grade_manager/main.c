#include <stdio.h>

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

    scanf("%d", &student);

    for(int i = 0; i < student; i++){
        scanf("%d", &arr[i]);
        printf("%d ", arr[i]);
    }

    double avg = calculateAverage(arr, student);

    printf("\n평균값 : %.2lf", avg);

    int MaxValue = findMax(arr, student);

    printf("\n최대값 :%d", MaxValue);

    int MinValue = findMin(arr, student);

    printf("\n최소값 :%d", MinValue);

    for(int i = 0; i < student; i++){
        if(arr[i] > avg){
            printf("\n%d 점 - 평균 이상", arr[i]);
        }else{
            printf("\n%d 점 - 평균 이하", arr[i]);
        }
    }

    return 0;
}
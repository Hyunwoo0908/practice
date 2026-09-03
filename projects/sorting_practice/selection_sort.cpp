/*선택정렬(Selection Sort)
남은 것들 중에서 가장 작은 값을 찾아 맨 앞으로 보낸다
-> 배열 끝까지 반복*/
#include <iostream>
using namespace std;
int main(){

    int arr[5] = {5, 2, 8, 1, 9};
    int n = 5;

    /*바깥 for문 : 몇 번째 자리를 확정할 차례인지 나타냄
    i = 0일 때 -> 0번째 자리를 확정, i = 1일때 -> 1번째 자리를 확정
    n-1까지만 도는 이유 : 마지막 하나는 나머지가 자동으로 정해지니 확정할 필요 없음*/
    for(int i = 0;  i < n-1; i++){
        /*minIndex : 지금까지 찾은 가장 작은 값의 위치(인덱스) 저장
        처음엔 일단 "나 자신(i번째)이 가장 작다"고 가정하고 시작*/
        int minIndex = i;
        /*안쪽 for문 : i 다음 자리(i+1)부터 배열 끝(n) 까지 전부 흝으며
        "진짜 가장 작은 값이 더이 있는지" 찾는 역할
        (i까지는 이미 확정됐거나 minIndex 초기값으로 처리했으니 i+1부터 시작)*/
        for(int j = i + 1; j < n; j++){
            /*지금 보고 있는 값(arr[i]이 지금까지 찾은 최솟값(arr[minIndex])보다 작다면)*/
            if(arr[j] < arr[minIndex]){
                minIndex = j; //더 작은 값을 찾았으니 위치 정보 갱신
            } 
        }
        /*안쪽 for문이 다 끝나면 minIndex에는 "남은 것 중 진짜 가장 작은 값의 위치"가 들어있음
        이제 그 값을 i번째 자리와 바꿔 i번째 자리를 확정시킴*/
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
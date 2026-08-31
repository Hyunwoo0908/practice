import java.util.Scanner;
public class Main{

    static double calculateAverage(int scores[], int count){
        int sum = 0;
        for(int i = 0; i < count; i++){
            sum += scores[i];
        }
        return (double) sum / count;
    }

    static int findMax(int scores[], int count){
        int max = scores[0];
        for(int i = 0; i < count; i++){
            if(max < scores[i]){
                max = scores[i];
            }
        }
        return max;
    }

    static int findMin(int scores[], int count){
        int min = scores[0];
        for(int i = 0; i < count; i++){
            if(min > scores[i]){
                min = scores[i];
            }
        }
        return min;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int student = sc.nextInt();
        int[] arr = new int[5];

        for(int i = 0; i < student; i++){
            arr[i] = sc.nextInt();
            System.out.print(arr[i] + " ");
        }

        double avg = calculateAverage(arr, student);
        System.out.println("평균값: "+avg);

        int MaxValue = findMax(arr, student);
        System.out.println("최대값 : "+MaxValue);

        int MinValue = findMin(arr, student);
        System.out.println("최소값 : "+MinValue);

        for(int i = 0; i < student; i++){
            if(arr[i] > avg){
                System.out.println(arr[i] + "점 - 평균 이상");
            }else{
                System.out.println(arr[i] + "점 - 평균 이하");
            }
        }
    }

}
//main 함수 안에서 calculateAverage 호출하려면 calculateAverage도 static이어야 함
//static 함수는 객체 없이 존재하는 함수 -> 마찬가지로 객체 없이 존재하는 다른 static 함수는 바로 호출 가능
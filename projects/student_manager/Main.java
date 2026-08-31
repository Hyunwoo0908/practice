//package projects.student_manager;
import java.util.Scanner;

class Student{
    String name;
    int age;
    int score;
}
public class Main {
    static void printAllStudents(Student student[], int n){
        for(int i = 0; i < n; i++){
            System.out.println(student[i].name+ " " + student[i].age + " " + student[i].score);
        }
    }
    static double calculateAverage(Student student[], int n){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += student[i].score;
        }
        return (double) sum / n;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Student[] student = new Student[10];
        int n = sc.nextInt();

    
        for(int i = 0; i < n; i++){
            student[i] = new Student();
            student[i].name = sc.next();
            student[i].age = sc.nextInt();
            student[i].score = sc.nextInt();
        }
        for(int i = 0; i < n; i++){
            System.out.println(student[i].name+ " " + student[i].age + " " + student[i].score);
        }
        while(true){
            System.out.println("1. 학생 추가");
            System.out.println("2. 전체 목록 보기");
            System.out.println("3. 평균 점수 보기");
            System.out.println("4. 종료");

            int choice = sc.nextInt();

            switch(choice){
                case 1:
                    System.out.println("학생 추가 선택됨");
                    student[n] = new Student();
                    student[n].name = sc.next();
                    student[n].age = sc.nextInt();
                    student[n].score = sc.nextInt();
                    System.out.println(student[n].name + "학생을 추가했습니다.");
                    n += 1;
                    break;
                
                case 2:
                    System.out.println("전체 목록 보기 선택됨");
                    printAllStudents(student, n);
                    break;
                
                case 3:
                    System.out.println("평균 점수 보기 선택됨");
                    double avg = calculateAverage(student, n);
                    System.out.println("평균 점수 : " + avg);
                    break;

                case 4:
                    System.out.println("종료합니다.");
                    break;

                default:
                    System.out.println("잘못된 선택입니다. ");

            }
            if(choice == 4){
                break;
            }
        }
    }
}

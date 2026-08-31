#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int *p = &a;

    cout<<a<<"\n"; // <- a의 값
    cout<<&a<<"\n"; // <- a가 저장된 메모리 주소(&a)
    cout<<p<<"\n"; // <- p 안에 담긴 값도 똑같은 주소(p = &a 니까 당연히 같음)
    cout<<*p<<"\n"; // <- p가 가리키는 곳에 가서 실제 값을 꺼내옴(*p)

    return 0;
}
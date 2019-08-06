#include<stdio.h>
#include<stdlib.h>

int main(){
    int a;
    int b;
    int count_one;
    int count_two;

    printf("The number of bytes written %n is stored in count_one and the number of bytes written %n is stored in count_two\n",&count_one, &count_two);

    printf("count one: %d\n", count_one);
    printf("count two: %d\n", count_two);

    printf("a is %d and b is at %x. b is %x.\n", a, &b, b);
    return 0;
}
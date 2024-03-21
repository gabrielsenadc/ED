#include <stdio.h>

int main(){
    int n1 = 1, n2 = 0, n3 = 2, n4 = 0;
    int *p1, *p2, *p3, *p4;

    p1 = &n1;
    p2 = &n2;
    p4 = &n4;
    *p1 = 8;
    *p2 = 3;
    *p4 = 2;
    p3 = &n3;
    *p3 += 2;
    printf("%d %d %d %d\n", n1 , n2, n3, n4);

    return 0;
}
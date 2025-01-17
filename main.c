#include <stdio.h>

int main()
{
    int a = 2 ;
    printf("%p", &a);
    int *p = &a ;
    printf("%p" , p );
    printf("%p" , &p );
    *p = 5 ; 
    printf("%d" , a ) ;
}
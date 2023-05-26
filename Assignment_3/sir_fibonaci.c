#include <stdio.h>
#include <string.h>

char n_char_fibonaci(int n,char* s1, char* s2){
    int s1_length = strlen(s1), s2_length = strlen(s2);
    s1 = strcat(s1,s2);
    if(n < s1_length + s2_length){
        return s1[n];
    } 
    else
    {
        return n_char_fibonaci(n,s2,s1);
    }
}

int main(){
    int n;
    char s1[1000],s2[1000];
    scanf("%d %s %s",&n,s1,s2);
    printf("%c",n_char_fibonaci(n,s1,s2));
    printf("\n");
    return 0;
}
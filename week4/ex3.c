#include <stdio.h>
#include <unistd.h> 

int main(){
    char s[100];

    while (1) {
        printf("> ");
        scanf("%s", s);
        system(s);
    }
}
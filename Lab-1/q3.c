#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    printf("Q3-Keyword Identification and Token generation\n");
    printf("N Sai Pavan Krishna - AM.EN.U4CSE19347\n");
    char keywords[7][10]={"if","else","while","then","switch","int","float"};
    for(int p=0;p<3;p++){
        char s[10];
        printf("Please Enter a string: ");
        scanf("%s",s);
        int f=0;
        int valid=0;
        int n=strlen(s);
        printf("Length: %d\n",n);
        for(int i=0;i<7;i++){
            if(strcmp(s,keywords[i])==0){
                valid=1;
                break;
            }
        }
        if(!valid){
            printf("Invalid Identifier\n");
        }
        else{
            printf("<%s>\n",s);
        }
    }
    return 0;
}
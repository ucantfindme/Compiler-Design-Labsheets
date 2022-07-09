#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    printf("Q2-Identifier Validation\n");
    printf("N Sai Pavan Krishna - AM.EN.U4CSE19347\n");
    for(int p=0;p<3;p++){
        char s[10];
        printf("Please Enter a Identifier:");
        scanf("%s",s);
        int f=0;
        int inv=0;
        int n=strlen(s);
        printf("Length: %d\n",n);
        for(int i=0;i<n;i++){
            if(!isalnum(s[i]) && s[i]!='_'){
                inv=1;
                break;
            }
        }
        if(isdigit(s[0])){
            inv=1;
        }
        if(inv){
            printf("Invalid Identifier\n");
        }
        else{
            printf("<ID,%s>\n",s);
        }
    }
    return 0;
}
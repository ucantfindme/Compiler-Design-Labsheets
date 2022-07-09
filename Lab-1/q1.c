#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    printf("Q1-Number-type Identification\n");
    printf("N Sai Pavan Krishna - AM.EN.U4CSE19347\n");
    for(int p=0;p<3;p++){
        char s[10];
        printf("Please Enter a Number:");
        scanf("%s",s);
        int f=0;
        int inv=0;
        int n=strlen(s);
        printf("%d\n",n);
        for(int i=0;i<n;i++){
            if(inv){
                break;
            }
            if(!isdigit(s[i])){
                if(s[i]=='.'){
                    if(f){
                        inv=1;
                    }
                    else{
                        f=1;
                    }
                }
                else{
                    inv=1;
                }
            }
        }
        if(!inv){
            if(s[0]=='0' && n>1){
                if(s[1]!='.'){
                    inv=1;
                }
            }
            if(s[n-1]=='.'){
                inv=1;
            }
        }
        if(inv){
            printf("Invalid Number\n");
        }
        else{
            if(f){
                printf("<FLOAT,%s>\n",s);
            }
            else{
                printf("<INT,%s>\n",s);
            }
        }
    }
    return 0;
}
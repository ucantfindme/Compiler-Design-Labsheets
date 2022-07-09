#include<stdio.h>
#include<ctype.h>
#include<string.h>
int isIdentifier(char s[]){
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if(!isalnum(s[i]) && s[i]!='_'){
            return 0;
        }
    }
    if(isdigit(s[0])){
        return 0;
    }
    return 1;
}
int isKeyword(char s[]){
    char keywords[30][10]={"if","else","while","then","switch","int","float","double","for","char","return","include","break","continue","case","void","short","long","const","struct","auto","static","enum","extern","typedef","union","register","signed","unsigned","sizeof"};
    int n=strlen(s);
    for(int i=0;i<30;i++){
        if(strcmp(s,keywords[i])==0){
            return 1;
        }
    }
    return 0;
}
int typeNumber(char s[]){
    int f=0;
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if(!isdigit(s[i])){
            if(s[i]=='.'){
                if(f){
                    return 0;
                }
                else{
                    f=1;
                }
            }
            else{
                return 0;
            }
        }
    }
    if(s[0]=='0' && n>1){
        if(s[1]!='.'){
            return 0;
        }
    }
    if(s[n-1]=='.'){
        return 0;
    }
    if(f){
        return 2;
    }
    return 1;
}
int main(){
    printf("\n\nQ4-List tokens from the statement\n");
    printf("N Sai Pavan Krishna - AM.EN.U4CSE19347\n\n\n");
    for(int p=0;p<3;p++){
        char st[100];
        printf("Please Enter a statement: ");
        scanf("%s",st);
        printf("\n");
        char stack[100]="";
        char ans[2000]="";
        int n=strlen(st);
        int inv=0;
        //printf("%d\n",n);
        for(int i=0;i<n;i++){
            if(st[i]==' '){
                continue;
            }
            if(isalnum(st[i])||st[i]=='.'){
                strcat(stack,(char[2]){st[i],'\0'});
            }
            else{
                if(isKeyword(stack)){
                    strcat(ans,(char[2]){'<','\0'});
                    int t=strlen(stack);
                    for(int j=0;j<t;j++){
                        strcat(ans,(char[2]){stack[j]-32,'\0'});
                    }
                    strcat(ans,(char[2]){'>','\0'});
                }
                else if(isIdentifier(stack)){
                    strcat(ans,"<ID,");
                    strcat(ans,stack);
                    strcat(ans,(char[2]){'>','\0'});
                }
                else if(typeNumber(stack)){
                    int f=typeNumber(stack)-1;
                    if(f){
                        strcat(ans,"<FLOAT,");
                        strcat(ans,stack);
                        strcat(ans,(char[2]){'>','\0'});
                    }
                    else{
                        strcat(ans,"<INT,");
                        strcat(ans,stack);
                        strcat(ans,(char[2]){'>','\0'});
                    }
                }
                else{
                    inv=1;
                    break;
                }
                if(st[i]==';'){
                    strcat(ans,"<SEMI>");
                }
                else{
                    strcat(ans,(char[2]){'<','\0'});
                    strcat(ans,(char[2]){st[i],'\0'});
                    strcat(ans,(char[2]){'>','\0'});
                }
                stack[0]=0;
                //printf("%s : %d, %d, %d\n",stack,isKeyword(stack),isIdentifier(stack),typeNumber(stack));
            }
        }
        if(inv){
            printf("Syntax Error\n\n");
        }
        else{
            printf("Generated Tokens: %s\n\n",ans);
        }
    }
    return 0;
}
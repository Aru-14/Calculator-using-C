#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
char stack[20];
char stack2[20];
int stack3[20];
int top = -1;
int top2 = -1;
int top3 = -1;
void push(char x){
    stack[++top]=x;
}
void push2(char m){
    stack2[++top2]=m;
}
void push3(double m){
    stack3[++top3]=m;
}

char pop(){
    if(top==-1){
        return -1;
    }
    else{
        return stack[top--];
    }
}
int pop2(){
    if(top2==-1){
        return -1;
    }
    else{
        return stack2[top2--];
    }
}
int pop3(){
    if(top3==-1){
        return -1;
    }
    else{
        int item = (int)stack3[top3];
        top3--;
        return item;
    }
}
int priority(char x){
    if(x=='(')
    return 0;
    if(x=='+'|| x== '-')
    return 1;
    if(x=='*'|| x=='/')
    return 2;
    if(x=='^')
    return 3;
    else
    return -1;
}
int main(){
    system("cls");
    char exp[20];
    char *e;
    char x;
    printf("Enter the expression\n");
    scanf("%s",exp);
    e = exp;
    while(*e !='\0'){
        if(isdigit(*e))
        push2(*e);
        else if(*e == '(')
        push(*e);
        else if(*e == ')'){
            while((x = pop())!='('){
                push2(x);
            }
        }
        else {
            if(priority(stack[top])==4 && priority(*e)==4){
                push(*e);
            }
          else{ while(priority(stack[top])>=priority(*e)){
              push2(pop());
            }
              push(*e);
          }
        }
        e++;
    }
    while(top!=-1){
        push2(pop());
    }
    int ans;
    char* p=stack2;
    while(*p!='\0'){
        if(isalnum(*p)){
            push3(*p-'0'); }
        else{
            int num1 = pop3();
            int num2 = pop3();

           switch(*p){
            case '+':ans = num2+num1;
            push3(ans);
            break;
            case '-':ans = num2-num1;
            push3(ans);
            break;
            case '*':ans = num2*num1;
            push3(ans);
            break;
            case '/':ans = num2/num1;
            push3(ans);
            break;
            case '^':ans = pow(num2,num1);
            push3(ans);
            break;
            default:break;
        }
    }
p++;
}

printf("%d",pop3());
return 0;
}
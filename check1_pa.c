#include<stdio.h>
#include<stdlib.h>
int check_paranthesis(const char* str){
    char stack[1000];
    int top=-1;
    for(int i=0;i !='\0';i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
        {
            stack[++top]=str[i];
        }
        else if((str[i]==')'||str[i]=='}'||str[i]==']'))
        {
            if(top==-1)
            return 0;  
        }
        else{
            char topchar=stack[top--];
            if(str[i]==')' && topchar!='(' ||str[i]=='}' && topchar!='{' ||str[i]==']' && topchar!='[')
            return 0;
        }

    }

    return top==-1;
}
int main()
{
 
     const char* str = "{[])]}"; // Balanced
    // const char* test2 = "{[(])}"; // Not balanced
    // const char* test3 = "{[(";    // Not balanced

    printf("Test 1: %s -> %s\n", str, check_paranthesis(str) ? "Balanced" : "Not Balanced");
   // printf("Test 2: %s -> %s\n", test2, check_parenthesis(test2) ? "Balanced" : "Not Balanced");
    //printf("Test 3: %s -> %s\n", test3, check_parenthesis(test3) ? "Balanced" : "Not Balanced");

    return 0;
}
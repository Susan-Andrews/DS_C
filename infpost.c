#include <ctype.h>
#include <stdio.h>
#define SIZE 50 
char s[SIZE];
int top = -1;
void push(char elem);
char pop();
char priority(char x);
void infix_to_postfix(char *infix, char *postfix);
int eval_postfix(char *postfix);
void main()
{ 
 char infx[50], pofx[50];
 printf("\nInput the infix expression: ");
 fgets(infx, 50, stdin);
 
 infix_to_postfix(infx, pofx);

 printf("\nGiven Infix Expression: %sPostfix Expression: %s\n", infx, pofx);
 top = -1;
 printf("\nResult of evaluation of postfix expression : %d", eval_postfix(pofx));
}
void push(char elem) {                                              // PUSH FUNCTION
 s[++top] = elem;
}
char pop() {                                                       // POP FUNCTION
 return (s[top--]);
}
char priority(char x)                                             //PRIORITY
{
    if(x=='(' || x==')')
    return 1;
    else if(x=='-'|| x=='+')
    return 2;
    else if(x=='*' || x=='/')
    return 3;
    else if(x=='^')
    return 4;
    else 
    return 0; 
}
void infix_to_postfix(char *infix, char *postfix) {              //INFIX TO POSTFIX
 char ch, elem;
 int i = 0, k = 0;
 push('#');
 
 while ((ch = infix[i++]) != '\n') {
 if (ch == '(')
 push(ch);
 else if (isalnum(ch))
 postfix[k++] = ch;
 else if (ch == ')') {
 while (s[top] != '(')
 postfix[k++] = pop();
 elem = pop(); /* Remove ( */
 } else { /* Operator */
 while (priority(s[top]) >= priority(ch))
 postfix[k++] = pop();
 push(ch);
 }
 }
 
 while (s[top] != '#') /* Pop from stack till empty */
 postfix[k++] = pop();
 
 postfix[k] = 0; /* Make postfix as valid string */
}
int eval_postfix(char *postfix) {   
        int i,v,op1,op2;                                                                  //POSTFIX EVALUATION
 for(i=0;postfix[i]!='\0';i++)
    {
        if(isalpha(postfix[i]))
        {
            printf("enter the value of %c :",postfix[i]);
            scanf("%d",&v);
            push(v);
        }
        else if(isdigit(postfix[i]))
        push(postfix[i]-'0');
        else
        {
            op2=pop();
            op1=pop();
            switch(postfix[i])
            {
                case '+': push(op1+op2);
                break;
                case '-': push(op1-op2);
                break;
                case '*': push(op1*op2);
                break;
                case '/': push(op1/op2);
                break;
                case '%': push(op1%op2);
                break;
                case '^': push(op1^op2);
                break;
                default:
                printf("invlid operation");
            }
        }
    }
 return s[top];
}
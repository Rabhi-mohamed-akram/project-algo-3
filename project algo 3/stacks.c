#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack {
    node *top;
} stack;


void initstack(stack *s) {
    s->top = NULL;
}


int isempty(stack *s) {
    return (s->top == NULL);
}


void push(stack *s, int value) {
    node *newnode = malloc(sizeof(node));
    if (!newnode) {
            printf("Memory allocation failed.\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = s->top;
    s->top = newnode;
}


int pop(stack *s) {
    if (isempty(s)) {
        printf("The stack is empty.\n");
        exit(1);
    }
    node *temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}
int peek(stack *s) {
    if (isempty(s)) {
       printf("The stack is empty.\n");
       exit(1);
       }
       return s->top->data;
}

void display(stack *s) {
    if (isempty(s)) {
       printf("The stack is empty.\n");
        return;
        }
        node *current = s->top;
        while (current != NULL) {

         if (current->data >= 32 && current->data <= 126)
            printf("%c ", current->data);
         else
            printf("%d ", current->data);
         current = current->next;
         }
         printf("\n");
}


int evaluatePostfix(char exp[]) {
    stack s;
    initstack(&s);

for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

     if (ch >= '0' && ch <= '9') {
       push(&s, ch - '0');
}
else {
    int b = pop(&s);
    int a = pop(&s);

    switch (ch) {
        case '+': push(&s, a + b); break;
        case '-': push(&s, a - b); break;
        case '*': push(&s, a * b); break;
        case '/': push(&s, a / b); break;
    }
}

}
    return pop(&s);
}



int main() {

    printf("Stack demonstration:\n");
    stack s;
    initstack(&s);
    push(&s, 'A');
    push(&s, 'B');
    push(&s, 'C');
    push(&s, 'D');
    display(&s);
    peek(&s);
    pop(&s);
    display(&s);


    printf("\nPostfix evaluation:\n");
    char exp[] = "63+2*4/";
    int result = evaluatePostfix(exp);
    printf("Result of postfix '%s' = %d\n", exp, result);

    return 0 ;
    }

#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //tamaño máximo de la pila y cola

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

struct Stack {
    int items[MAX];
    int top;
};

void enqueue(struct Queue *q, int num) {
    if(q->rear == MAX - 1) {
        printf("La cola está llena\n");
    } else {
        if(q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = num;
        printf("Tu turno es %d\n", q->rear + 1);
    }
}

void push(struct Stack *s, int num) {
    if(s->top == MAX - 1) {
        printf("No hay mas turnos\n");
    } else {
        s->top++;
        s->items[s->top] = num;
        printf("Tu turno es %d\n", s->top + 1);
    }
}

void menu() {
    printf("\nElija una opción:\n");
    printf("1. Formarse\n");
    printf("2. Salir\n");
}

int main() {
    int choice = 0, num = 0;
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    struct Stack s;
    s.top = -1;

    while(choice != 2) {
        menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                num++;
                enqueue(&q, num);
                push(&s, num);
                break;
            case 2:
                printf("Hasta pronto!\n");
                exit(0);
                break;
            default:
                printf("Opción no válida.\n");
        }
    }
    return 0;
}


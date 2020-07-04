//
// Created by andress on 6/30/20.
//

#ifndef ALGORITHMS_DATA_STRUCTURES_STACKCHAR_H
#define ALGORITHMS_DATA_STRUCTURES_STACKCHAR_H

struct Node {
    char value;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

void init(struct Stack *s, const char *a, int n);

void display(struct Stack s);

int is_empty(struct Stack s);

void push(struct Stack *s, char value);

char pop(struct Stack *s);

char peek(struct Stack s, int i);

char top(struct Stack s);

#endif //ALGORITHMS_DATA_STRUCTURES_STACKCHAR_H

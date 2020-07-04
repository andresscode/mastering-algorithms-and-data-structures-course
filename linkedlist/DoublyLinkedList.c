#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

void init(struct LinkedList *list, const int *a, int n);

void display(struct LinkedList l);

void insert(struct LinkedList *l, int value, unsigned short index);

int delete(struct LinkedList *l, unsigned short index);

void reverse(struct LinkedList *l);

struct Node* get_middle(struct LinkedList *l);

int main() {
  struct LinkedList l;
  init(&l, (int []) {1, 2, 3, 4, 5}, 5);
  display(l);
  printf("middle=%d\n", get_middle(&l)->value);
  return 0;
}

struct Node* get_middle(struct LinkedList *l) {
  if (l->head) {
    struct Node *p = l->head;
    struct Node *m = l->head;
    while (p->next) {
      p = p->next;
      if (p->next) {
        p = p->next;
        m = m->next;
      }
    }
    return m;
  }
  return NULL;
}

void reverse(struct LinkedList *l) {
  if (l->head) {
    struct Node *p = l->head;
    struct Node *tmp = NULL;
    while (p) {
      tmp = p->prev;
      p->prev = p->next;
      p->next = tmp;
      if (!p->prev)
        l->head = p;
      p = p->prev;
    }
  }
}

int delete(struct LinkedList *l, unsigned short index) {
  if (l->head) {
    if (index == 0) {
      struct Node *p = l->head;
      l->head = l->head->next;
      int deleted = p->value;
      free(p);
      if (l->head)
        l->head->prev = NULL;
      return deleted;
    } else {
      struct Node *p = l->head;
      int i;
      for (i = 1; i < index && p->next; ++i)
        p = p->next;
      if (i == index && p->next) {
        struct Node *tmp = p->next;
        p->next = tmp->next;
        if (tmp->next)
          tmp->prev = p;
        int deleted = tmp->value;
        free(tmp);
        return deleted;
      }
    }
  }
  return INT_MIN;
}

void insert(struct LinkedList *l, int value, unsigned short index) {
  if (index == 0) {
    if (l->head == NULL) {
      l->head = (struct Node *) malloc(sizeof(struct Node));
      l->head->value = value;
      l->head->prev = l->head->next = NULL;
    } else {
      struct Node *n = (struct Node *) malloc(sizeof(struct Node));
      n->value = value;
      n->prev = NULL;
      n->next = l->head;
      l->head = n;
    }
  } else if (l->head) {
    struct Node *p = l->head;
    int i;
    for (i = 1; i < index && p->next; ++i)
      p = p->next;
    if (i == index) {
      struct Node *n = (struct Node *) malloc(sizeof(struct Node));
      n->value = value;
      n->prev = p;
      n->next = p->next;
      p->next = n;
      if (n->next)
        n->next->prev = n;
    }
  }
}

void display(struct LinkedList l) {
  if (l.head) {
    struct Node *p = l.head;
    do {
      printf("%d ", p->value);
      p = p->next;
    } while (p);
    printf("\n");
  }
}

void init(struct LinkedList *list, const int *a, int n) {
  if (n > 0) {
    list->head = (struct Node *) malloc(sizeof(struct Node));
    list->head->value = a[0];
    list->head->prev = NULL;
    list->head->next = NULL;
    struct Node *p = list->head;
    for (int i = 1; i < n; ++i) {
      p->next = (struct Node *) malloc(sizeof(struct Node));
      p->next->value = a[i];
      p->next->prev = p;
      p->next->next = NULL;
      p = p->next;
    }
  } else {
    list->head = NULL;
  }
}
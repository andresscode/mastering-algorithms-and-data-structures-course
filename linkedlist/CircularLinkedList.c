#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int value;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

void init(struct LinkedList *l, const int *a, int n);

void display(struct LinkedList l);

void insert(struct LinkedList *l, int value, unsigned short index);

int delete(struct LinkedList *l, unsigned short index);

int main() {
  struct LinkedList list;
  init(&list, (int[]) {1, 2, 3, 4, 5}, 5);
  display(list);
  printf("%d\n", delete(&list, 5));
  display(list);
  return 0;
}

int delete(struct LinkedList *l, unsigned short index) {
  if (l->head) {
    struct Node *p = l->head;
    struct Node *q = NULL;
    if (index == 0) {
      if (l->head->next == l->head) {
        int deleted = l->head->value;
        free(l->head);
        l->head = NULL;
        return deleted;
      } else {
        while (p->next != l->head) {
          p = p->next;
        }
        q = l->head;
        int deleted = q->value;
        p->next = l->head = l->head->next;
        free(q);
        return deleted;
      }
    } else {
      int i;
      for (i = 0; i < index && p->next != l->head; ++i) {
        q = p;
        p = p->next;
      }
      if (index == i) {
        int deleted = p->value;
        q->next = p->next;
        free(p);
        return deleted;
      }
    }
  }
  return INT_MIN;
}

void insert(struct LinkedList *l, int value, unsigned short index) {
  if (index == 0) {
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    new->value = value;
    if (l->head == NULL) {
      new->next = l->head = new;
    } else {
      struct Node *p = l->head;
      while (p->next != l->head) {
        p = p->next;
      }
      new->next = l->head;
      l->head = p->next = new;
    }
  } else if (l->head) {
    int i = 0;
    struct Node *p = l->head;
    struct Node *q = NULL;
    while (p->next != l->head) {
      q = p;
      p = p->next;
      if (++i == index) {
        struct Node *new = (struct Node *) malloc(sizeof(struct Node));
        new->value = value;
        new->next = p;
        q->next = new;
        break;
      }
    }
    if (index == i + 1) {
      struct Node *new = (struct Node *) malloc(sizeof(struct Node));
      new->value = value;
      new->next = l->head;
      p->next = new;
    }
  }
}

void display(struct LinkedList l) {
  if (l.head) {
    struct Node *p = l.head;
    do {
      printf("%d ", p->value);
      p = p->next;
    } while (p != l.head);
    printf("\n");
  }
}

void init(struct LinkedList *l, const int *a, int n) {
  if (n > 0) {
    l->head = (struct Node *) malloc(sizeof(struct Node));
    l->head->value = a[0];
    l->head->next = l->head;
    struct Node *prev = l->head;
    struct Node *p;
    for (int i = 1; i < n; i++) {
      p = (struct Node *) malloc(sizeof(struct Node));
      p->value = a[i];
      p->next = prev->next;
      prev->next = p;
      prev = prev->next;
    }
  } else {
    l->head = NULL;
  }
}
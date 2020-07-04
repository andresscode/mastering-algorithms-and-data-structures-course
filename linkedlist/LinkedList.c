#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
    struct Node *tail;
};

void init(struct LinkedList *list, int n);

void display(struct LinkedList list);

void display_recursive(struct Node *node);

short count(struct LinkedList list);

unsigned short sum(struct LinkedList list);

short find(short n, struct LinkedList list);

short max(struct LinkedList list);

void insert(struct LinkedList *list, int value, unsigned short index);

void append(struct LinkedList *list, int value);

void insert_sorted(struct LinkedList *list, int value);

int delete(struct LinkedList *list, unsigned short index);

short is_sorted(struct LinkedList list);

void remove_duplicates(struct LinkedList *list);

void reverse(struct LinkedList *list);

void append_list(struct LinkedList *a, struct LinkedList *b);

void merge(struct LinkedList *a, struct LinkedList *b);

short is_loop(struct LinkedList *l);

int main() {
  struct LinkedList linkedList;
  linkedList.head = NULL;
  linkedList.tail = NULL;
  init(&linkedList, 5);
  linkedList.tail->next = linkedList.head->next;
  printf("%d\n", is_loop(&linkedList));
  return 0;
}

short is_loop(struct LinkedList *l) {
  if (l->head) {
    struct Node *p = l->head;
    struct Node *q = l->head;
    while (p && q) {
      p = p->next;
      q = q->next ? q->next->next : NULL;
      if (p == q)
        return 1;
    }
    return 0;
  }
}

void merge(struct LinkedList *a, struct LinkedList *b) {
  struct Node *h = NULL;
  struct Node *t = NULL;
  if (a->head->value < b->head->value) {
    h = a->head;
    t = a->head;
    a->head = a->head->next;
  } else {
    h = b->head;
    t = b->head;
    b->head = b->head->next;
  }
  t->next = NULL;
  while (a->head && b->head) {
    if (a->head->value < b->head->value) {
      t->next = a->head;
      a->head = a->head->next;
    } else {
      t->next = b->head;
      b->head = b->head->next;
    }
    t = t->next;
    t->next = NULL;
  }
  if (a->head)
    t->next = a->head;
  else
    t->next = b->head;
  a->head = h;
  b->head = NULL;
}

void append_list(struct LinkedList *a, struct LinkedList *b) {
  a->tail->next = b->head;
  a->tail = b->tail;
}

void reverse(struct LinkedList *list) {
  if (list->head) {
    struct Node *p = list->head;
    struct Node *a = NULL;
    struct Node *b = NULL;
    while (p != NULL) {
      a = b;
      b = p;
      p = p->next;
      b->next = a;
    }
    list->head = b;
  }
}

void remove_duplicates(struct LinkedList *list) {
  if (list->head) {
    struct Node *p = list->head;
    while (p->next) {
      if (p->value == p->next->value) {
        struct Node *tmp = p->next;
        p->next = tmp->next;
        free(tmp);
      } else
        p = p->next;
    }
  }
}

short is_sorted(struct LinkedList list) {
  if (list.head) {
    struct Node *p = list.head;
    while (p->next) {
      if (p->value > p->next->value)
        return 0;
      p = p->next;
    }
  }
  return 1;
}

int delete(struct LinkedList *list, unsigned short index) {
  if (index == 0) {
    struct Node *p = list->head;
    list->head = p->next;
    int result = p->value;
    free(p);
    return result;
  } else if (index > 0) {
    int count = 1;
    struct Node *p = list->head;
    while (p->next && count < index) p = p->next, count++;
    if (p->next) {
      struct Node *tmp = p->next;
      p->next = tmp->next;
      int result = tmp->value;
      free(tmp);
      return result;
    }
  }
  return -1;
}

void insert_sorted(struct LinkedList *list, int value) {
  if (!list->head || value >= list->tail->value) {
    append(list, value);
  } else {
    struct Node *prev = NULL;
    struct Node *p = list->head;
    while (p != NULL &&  p->value < value) {
      prev = p;
      p = p->next;
    }
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    new->value = value;
    new->next = p;
    list->tail = p;
    if (prev)
      prev->next = new;
    else
      list->head = new;
  }
}

void append(struct LinkedList *list, int value) {
  struct Node *new = (struct Node *) malloc(sizeof(struct Node));
  new->value = value;
  new->next = NULL;
  if (!list->head) {
    list->head = new;
    list->tail = new;
  } else {
    list->tail->next = new;
    list->tail = new;
  }
}

void init(struct LinkedList *list, int n) {
  if (n > 0) {
    list->head = (struct Node *) malloc(sizeof(struct Node));
    list->head->value = 1;
    list->head->next = NULL;
    list->tail = list->head;
    struct Node *prev = list->head;
    struct Node *current;
    for (int i = 0; i < n - 1; i++) {
      current = (struct Node *) malloc(sizeof(struct Node));
      current->value = i + 2;
      current->next = NULL;
      list->tail = current;
      prev->next = current;
      prev = current;
    }
  }
}

void display(struct LinkedList list) {
  if (list.head) {
    struct Node *current = list.head;
    while (current != NULL) {
      printf("%d ", current->value);
      current = current->next;
    }
    printf("\n");
  }
}

void display_recursive(struct Node *node) {
  if (node != NULL) {
    printf("%d\n", node->value);
    display_recursive(node->next);
  }
}

short count(struct LinkedList list) {
  if (list.head) {
    int count = 1;
    struct Node *p = list.head;
    while (p->next != NULL) p = p->next, count++;
    return count;
  } else
    return 0;
}

unsigned short sum(struct LinkedList list) {
  if (list.head) {
    struct Node *p = list.head;
    int sum = p->value;
    while (p->next != NULL) p = p->next, sum += p->value;
    return sum;
  } else
    return 0;
}

short find(short n, struct LinkedList list) {
  if (list.head) {
    struct Node *p = list.head;
    while (p) {
      if (p->value == n)
        return 1;
      p = p->next;
    }
  } else
    return 0;
}

short max(struct LinkedList list) {
  if (list.head) {
    struct Node *p = list.head;
    short max = p->value;
    while (p) {
      if (p->value > max)
        max = p->value;
      p = p->next;
    }
    return max;
  } else
    return 0;
}

void insert(struct LinkedList *list, int value, unsigned short index) {
  if (index == 0) {
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    new->value = value;
    new->next = list->head;
    list->head = new;
  } else if (list->head) {
    struct Node *prev = NULL;
    struct Node *p = list->head;
    int i = 0;
    while (p != NULL && i < index) {
      prev = p;
      p = p->next;
      i++;
    }
    if (i == index) {
      struct Node *new = (struct Node *) malloc(sizeof(struct Node));
      new->value = value;
      new->next = p;
      prev->next = new;
    }
  }
}
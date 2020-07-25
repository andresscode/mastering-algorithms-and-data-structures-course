#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct HashTable
{
  int size;
  struct Node **table;
};

void init(struct HashTable *t, int size);

void insert(struct HashTable *t, int x);

int hash(int x, int size);

int contains(struct HashTable t, int x);

void delete(struct HashTable *t, int x);

void display(struct HashTable t);

int main()
{
  struct HashTable t;
  init(&t, 10);
  insert(&t, 1);
  insert(&t, 22);
  insert(&t, 2);
  insert(&t, 3);
  insert(&t, 4);
  insert(&t, 5);
  insert(&t, 6);
  insert(&t, 77);
  insert(&t, 27);
  insert(&t, 37);
  insert(&t, 8);
  insert(&t, 9);
  insert(&t, 310);
  insert(&t, 20);
  insert(&t, 10);
  delete(&t, 10);
  delete(&t, 22);
  display(t);
  return 0;
}

void init(struct HashTable *t, int size)
{
  t->size = size;
  t->table = (struct Node **) malloc(sizeof(struct Node *) * t->size);
  for (int i = 0; i < size; ++i)
    t->table[i] = NULL;
}

void insert(struct HashTable *t, int x)
{
  struct Node *new = (struct Node *) malloc(sizeof(struct Node));
  new->data = x;
  new->next = NULL;
  int root = hash(x, t->size);
  if (!t->table[root])
    t->table[root] = new;
  else
  {
    struct Node *p = t->table[root];
    struct Node *q = NULL;
    while (p)
    {
      if (x <= p->data)
        break;
      q = p;
      p = p->next;
    }
    if (p && !q)
    {
      t->table[root] = new;
      new->next = p;
    }
    else
    {
      q->next = new;
      new->next = p;
    }
  }
}

int hash(int x, int size)
{
  return x % size;
}

int contains(struct HashTable t, int x)
{
  struct Node *p = t.table[hash(x, t.size)];
  while (p)
  {
    if (p->data == x)
      return 1;
    p = p->next;
  }
  return 0;
}

void delete(struct HashTable *t, int x)
{
  int root = hash(x, t->size);
  struct Node *p = t->table[root];
  struct Node *q = NULL;
  while (p)
  {
    if (p->data == x)
    {
      if (q)
      {
        q->next = p->next;
        free(p);
      }
      else
      {
        t->table[root] = p->next;
        free(p);
      }
      break;
    }
    q = p;
    p = p->next;
  }
}

void display(struct HashTable t)
{
  struct Node *p;
  for (int i = 0; i < t.size; ++i)
  {
    printf("\nroot=%d\n", i);
    p = t.table[i];
    while (p)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  }
}
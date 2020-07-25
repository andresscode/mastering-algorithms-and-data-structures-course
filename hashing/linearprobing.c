#include <stdio.h>
#include <stdlib.h>

struct HashTable
{
  int size;
  int *table;
};

void init(struct HashTable *t, int size);

void insert(struct HashTable *t, int x);

int search(struct HashTable t, int x);

void display(struct HashTable t);

int main()
{
  struct HashTable t;
  init(&t, 10);
  insert(&t, 2);
  insert(&t, 5);
  insert(&t, 19);
  insert(&t, 9);
  display(t);
  printf("\nsearch=%d", search(t, 2));
  printf("\nsearch=%d", search(t, 9));
  return 0;
}

void init(struct HashTable *t, int size)
{
  t->size = size;
  t->table = (int *) malloc(sizeof(int) * t->size);
  for (int i = 0; i < t->size; ++i)
    t->table[i] = -1;
}

void insert(struct HashTable *t, int x)
{
  int i = x % t->size;
  while (t->table[i] != -1)
    i = (i + 1) % t->size;
  t->table[i] = x;
}

int search(struct HashTable t, int x)
{
  int root = x % t.size;
  int i = root;
  do {
    if (t.table[i] == x)
      return i;
    i = (i + 1) % t.size;
  } while (i != root && t.table[i] != -1);
  return -1;
}

void display(struct HashTable t)
{
  for (int i = 0; i < t.size; ++i)
    printf("%d ", t.table[i]);
}
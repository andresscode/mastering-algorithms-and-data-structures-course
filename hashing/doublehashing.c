#include <stdio.h>
#include <stdlib.h>

struct HashTable
{
  int size;
  int *table;
};

void init(struct HashTable *t, int size);

void insert(struct HashTable *t, int x);

void display(struct HashTable t);

int main()
{
  struct HashTable t;
  init(&t, 10);
  insert(&t, 1);
  insert(&t, 10);
  insert(&t, 20);
  insert(&t, 5);
  insert(&t, 25);
  insert(&t, 8);
  display(t);
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
  int j = 7 - (x % 7);
  int k = 1;
  while (t->table[i] != -1)
    i = (i + (k++ * j)) % t->size;
  t->table[i] = x;
}

void display(struct HashTable t)
{
  for (int i = 0; i < t.size; ++i)
    printf("%d ", t.table[i]);
}
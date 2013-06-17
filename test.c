#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Gora {
  char *name;
  int height;
  int id;
};

struct Gora *Create_gora(char *name, int height, int id) {

  struct Gora *item = malloc(sizeof(struct Gora));
  assert(item != NULL);

  item->name = strdup(name);
  item->height = height;
  item->id = id;

  return item;
}

void Gora_destroy(struct Gora *gora) {

  assert(gora != NULL);

  free(gora->name);
  free(gora);
}

void Print_gora(struct Gora *gora) {

  printf("Name: %s\n", gora->name);
  printf("Height: %d\n", gora->height);
  printf("Id: %d\n\n", gora->id);
}

int main(int argc, char *argv[]) {

  struct Gora *rysy = Create_gora("Rysy", 2495, 1);
  struct Gora *marcy = Create_gora("Mt. Marcy", 1800, 2);

  Print_gora(rysy);
  Print_gora(marcy);

  Gora_destroy(rysy);
  Gora_destroy(marcy);

  return 0;
}
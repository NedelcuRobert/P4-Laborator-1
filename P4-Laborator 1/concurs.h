#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct nod {
	char nume[20];
	int nota;
	struct nod* urm;
};

void creare(struct nod** head,char key[20], int data);
void afisare(struct nod* head);
bool cautare(struct nod* ptr,char key[20]);
void swap(struct nod* a, struct nod* b);
void sortare(struct nod* head);
void MoveNode(struct nod** destRef, struct nod** sourceRef);
void separare(struct nod* head,struct nod** aRef,struct nod** bRef);
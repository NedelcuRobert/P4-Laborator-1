#include "concurs.h"
#include <assert.h>

void creare(struct nod** head,char key[20], int data) {

    struct nod* new_node = (struct nod*)malloc(sizeof(struct nod));
    strcpy(new_node->nume, key);
    new_node->nota = data;
    new_node->urm = (*head);
    (*head) = new_node;
}

void afisare(struct nod* head) {
    struct nod* temp = head;
    while (temp != NULL) {
        printf("(%s,%d) ", temp->nume, temp->nota);
        temp = temp->urm;
    }
}

bool cautare(struct nod* head,char key[20])
{
    struct nod* current = head;
    while (current != NULL)
    {
        if (strcmp(current->nume, key) == 0) {
            return true;
        }
        current = current->urm;
    }
    return false;
}

void swap(struct nod* a, struct nod* b){
    char temp2[20];
    strcpy(temp2, a->nume);
    int temp = a->nota;
    a->nota = b->nota;
    strcpy(a->nume, b->nume);
    strcpy(b->nume, temp2);
    b->nota = temp;
}


void sortare(struct nod* head) {
    int swapped, i;
    struct nod* ptr1;
    struct nod* lptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->urm != lptr)
        {
            if (ptr1->nota > ptr1->urm->nota)
            {
                swap(ptr1, ptr1->urm);
                swapped = 1;
            }
            ptr1 = ptr1->urm;
        }
        lptr = ptr1;
    } while (swapped);
}

void MoveNode(struct nod** destRef, struct nod** sourceRef)
{
    struct nod* newNode = *sourceRef;
    assert(newNode != NULL);

    *sourceRef = newNode->urm;

    newNode->urm = *destRef;

    *destRef = newNode;
}

void separare(struct nod* head, struct nod** aRef, struct nod** bRef) {
    struct Node* a = NULL;
    struct Node* b = NULL;

    struct Node* current = head;
    while (current != NULL)
    {
        MoveNode(&a, &current);
        if (current != NULL)
        {
            MoveNode(&b, &current);
        }
    }
    *aRef = a;
    *bRef = b;
}
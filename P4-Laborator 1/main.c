#include "concurs.h"

int main() {
	struct nod* lista = NULL;
	struct nod* a = NULL;
	struct nod* b = NULL;
	int optiune;

	do {
		printf("1.Adaugare:\n");
		printf("2.Afisare:\n");
		printf("3.Cautare:\n");
		printf("4.Sortare:\n");
		printf("5.Separare:\n");
		printf("6.Iesire:\n");
		printf("Introduceti optiunea dvs:");
		scanf("%d", &optiune);
		switch (optiune) {
		case 1:printf("\nAdaugare:");
			int nota;
			char nume[20];
			printf("\nIntroduceti nota:");
			scanf("%d",&nota);
			printf("\nIntroduceti nume:");
			scanf("%s", nume);
			creare(&lista, nume, nota);
			break;
		case 2:printf("\nAfisare:");
			afisare(lista);
			break;
		case 3:printf("\nCautare:");
			char n[20];
			printf("\nNume pt cautare:");
			scanf("%s", n);
			int val = cautare(lista, "daad");
			if (val == 0) {
				printf("Gasit");
			}
			else {
				printf("Negasit");
			}
			break;
		case 4:printf("\nSortare:");
			sortare(lista);
			break;
		case 5:printf("\nSeparare:");
			separare(lista, &a, &b);
			printf("Lista1");
			afisare(a);
			printf("Lista2");
			afisare(b);
			break;
		case 6:exit(1);
		default:printf("\nIntroduceti o optiune valida\n");
		}
		printf("\n");
	} while (1);
	return 0;
}
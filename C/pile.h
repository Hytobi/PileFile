#ifndef PILE_H
#define PILE_H

typedef struct _Element {
    int value;
    struct _Element *next;
} Element;

typedef struct _Pile {
    Element *first;
} Pile;

Pile *createPile();
void addPile(Pile *pile, int value);
int removePile(Pile *pile);
void printPile(Pile *pile);
void freePile(Pile *pile);

#endif
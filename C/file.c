#include "file.h"

#include <stdio.h>

File *createFile() {
    File *file = malloc(sizeof(File));
    file->head = NULL;
    return file;
}
void addFile(File *file, int value) {
    if (file->head == NULL) {
        file->head = malloc(sizeof(Element));
        file->head->value = value;
        file->head->next = NULL;
    } else {
        Element *current = file->head;
        while (current->next != NULL) {
            current = current->next;
        }
        // Create new element and add it to the end of the list
        current->next = malloc(sizeof(Element));
        current->next->value = value;
        current->next->next = NULL;
    }
}
int removeFile(File *file) {
    if (file->head == NULL) return -1;

    Element *current = file->head;
    file->head = file->head->next;
    int value = current->value;
    free(current);
    return value;
}
void printFile(File *file) {
    Element *current = file->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
void freeFile(File *file) {
    Element *current = file->head;
    while (current != NULL) {
        Element *next = current->next;
        free(current);
        current = next;
    }
    free(file);
}
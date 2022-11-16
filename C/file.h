#ifndef FILE_H
#define FILE_H

typedef struct _Element {
    int value;
    struct _Element *next;
} Element;

typedef struct _File {
    Element *head;
} File;

File *createFile();
void addFile(File *file, int value);
int removeFile(File *file);
void printFile(File *file);
void freeFile(File *file);

#endif
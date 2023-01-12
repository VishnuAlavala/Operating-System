#include <stdio.h>
#include <string.h>
#define MAX_FILES 10
#define MAX_BLOCKS 100
struct File {
    char name[20];
    int numBlocks;
    int indexBlock[MAX_BLOCKS];
} files[MAX_FILES];
int numFiles = 0;
int blocks[MAX_BLOCKS];
int numBlocks = 0;
void addFile(char name[20], int size) {
    if (numFiles == MAX_FILES) {
       printf("Error: Maximum number of files reached.\n");
        return;
    }
    if (numBlocks + size > MAX_BLOCKS) {
        printf("Error: Not enough space to create file %s.\n", name);
        return;
    }
    strcpy(files[numFiles].name, name);
    files[numFiles].numBlocks = size;
    int i;
    for (i = 0; i < size; i++) {
        files[numFiles].indexBlock[i] = numBlocks;
        blocks[numBlocks] = i;
        numBlocks++;
    }
    numFiles++;
}
void readFile(char fileName[20]) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, fileName) == 0) {
            printf("Content of file %s:\n", fileName);
            int j;
            for (j = 0; j < files[i].numBlocks; j++) {
                printf("Block %d: %d\n", j, blocks[files[i].indexBlock[j]]);
            }
            return;
        }
    }
    printf("Error: File %s not found.\n", fileName);
}
int main() {
    addFile("SSE", 4);
    readFile("SSE");
    return 0;
}

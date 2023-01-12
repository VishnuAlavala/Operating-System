#include <stdio.h>
#include <string.h>
#define MAX_FILES 10
#define MAX_RECORDS 100
struct File {
    char name[20];
    int numRecords;
    int records[MAX_RECORDS];
} files[MAX_FILES];
int numFiles = 0;
void addFile(char name[20]) {
    if (numFiles == MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    strcpy(files[numFiles].name, name);
    files[numFiles].numRecords = 0;
    numFiles++;
}
void addRecord(char fileName[20], int record) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, fileName) == 0) {
            if (files[i].numRecords == MAX_RECORDS) {
                printf("Error: Maximum number of records reached for file %s.\n", fileName);
                return;
            }
            files[i].records[files[i].numRecords] = record;
            files[i].numRecords++;
            return;
        }
    }
    printf("Error: File %s not found.\n", fileName);
}
void readFile(char fileName[20]) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, fileName) == 0) {
            int j;
            printf("Records in file %s:\n", fileName);
            for (j = 0; j < files[i].numRecords; j++) {
                printf("%d\n", files[i].records[j]);
            }
            return;
        }
    }
    printf("Error: File %s not found.\n", fileName);
}
int main() {
    addFile("SSE");
    addRecord("SSE", 192011743);
    addRecord("SSE", 192111002);
    addRecord("SSE", 192110059);
    readFile("SSE");
    return 0;
}

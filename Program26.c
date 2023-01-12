#include <stdio.h>
int main() {
    FILE *fp;
    fp = fopen("example.txt", "w");
    fprintf(fp, "Saveetha School of Engineering.\n");
    fclose(fp);
    return 0;
}


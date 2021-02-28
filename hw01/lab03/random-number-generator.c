#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEYSIZE 16


void key_gen(int t);

int main()
{
	for(int i = 1524006529; i >= (1524006529-7200);i--){
		key_gen(i);
	}
	
	return 0;
}

void key_gen(int t) {
	int i;
    char key[KEYSIZE];

    //srand (time(NULL));
    srand (t);
	FILE *file = fopen("keys.txt", "a");
    for (i = 0; i< KEYSIZE; i++){
        key[i] = rand()%256;
        printf("%.2x", (unsigned char)key[i]);
		fprintf(file, "%.2x", (unsigned char)key[i]);
    }

	fprintf(file, "\n");
	fclose(file);

	printf("\n");
}

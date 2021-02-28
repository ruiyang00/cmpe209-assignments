#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KEYSIZE 16


void main()
{
	int i;
	char key[KEYSIZE];
	printf("%lld\n", (long long) time(NULL));
	
	//srand (time(NULL));
	srand (1614197798); 
	for (i = 0; i< KEYSIZE; i++){
		key[i] = rand()%256;
     	printf("%.2x", (unsigned char)key[i]);
  	}
  	printf("\n");
}

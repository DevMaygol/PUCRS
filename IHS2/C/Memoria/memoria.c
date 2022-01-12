#include <stdio.h>


int main() {

FILE *oi;

oi = fopen ("oi.txt","r");

if(!oi){
	printf("Error!\n");
}
	else{
			printf ("LEU\n");
	}
}

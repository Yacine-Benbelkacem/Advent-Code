#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE_NAME "input"

int main(){
	int pos = 50;
	int dist, count = 0;
	char dir;

	FILE* f = fopen(INPUT_FILE_NAME, "rw");

	fseek(f, 0, SEEK_END);

	int size = ftell(f);

	fseek(f, 0, SEEK_SET);

	printf("Total combinations : %d \n", size);

	while(!feof(f)){

		fscanf(f,"%c%d\n",&dir,&dist);

		if ( dir == 'R' ){
			pos += dist;
		}else{
			pos -= dist;
		}

		pos = pos % 100;

		if ((pos == 0))
			count ++;

	}

	printf("password --> %d\n",count);

	fclose(f);

	return 0;
}

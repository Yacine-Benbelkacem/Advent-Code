#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE_NAME "input"

int main(){
	int pos = 50;
	int sdist, dist, times,  count = 0;
	char dir;
	int last_zero = 0;
	int passed_zero = 0;
	FILE* f = fopen(INPUT_FILE_NAME, "rw");

	fseek(f, 0, SEEK_END);

	int size = ftell(f);

	fseek(f, 0, SEEK_SET);

	printf("Total combinations : %d \n", size);

	while(!feof(f)){
		times = 0;
		fscanf(f,"%c%d\n",&dir,&dist);
		sdist = dist;

		if ( dir == 'R' ){
			last_zero = 0;
			while(dist){
				pos++;
				if (pos == 100){
					pos = 0;
					count++;
					passed_zero++;
				}
				dist--;
			}
			if(pos == 0){
				last_zero = 1;
			}
		}else{
			printf("%d\n",last_zero);
			while(dist){
				pos --;
				if(pos == -1){
					pos = 99;
					if(!last_zero){
						count ++;
						passed_zero++;
					}else{
						last_zero = 0;
					}
				}
				dist--;
			}

			if (pos == 0){
				count ++;
				last_zero = 1;
			}
		}

		printf("- The dial is rotated %c%d to point at %d", dir, sdist, pos);

		if(passed_zero){
			printf("during this rotation, it pointed at 0 : %d times \n", passed_zero);
		}else {
			printf("\n");
		}

		passed_zero=0;

	}

	printf("password --> %d\n",count);

	fclose(f);

	return 0;
}

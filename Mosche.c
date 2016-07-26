#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fd;
	fd = fopen("input.txt", "r");
	int r, s, k, i, j;
	int x, y;
	int max = 0, m = 0, c = 0;

	fscanf(fd, "%d %d %d\n", &r, &s, &k);

	char display[r][s];

	for(i = 0; i <= r-1; i++){ //itero sulle righe del display
		for(j = 0; j <= s-1; j++){ //itero sulle colonne del display
			fscanf(fd, "%c\n", &display[i][j]);
			if(display[i][j] == '*')
				m++;
		} //finisco di iterare sulle colonne del display
	}//finisco di iterare sulle righe del display

	for(i = 0; i < r; i++){
		for(j = 0; j < s; j++){
			if(i+k <= r && j+k <= s){
				printf("\n");
				c = 0;
				for(x = 0; x < k; x++){
					for(y = 0; y < k; y++){
						printf("%c", display[i+x][j+y]);
						if(display[i+x][j+y] == '*'){
							if(x != 0 || x != k-1 || y != 0 || y != k-1)
								c++;
						}
					}
					printf("\n");
					if(c > max)
						max = c;
				}
			}
		}
	}


	//debug
	printf("%d %d %d\n", r, s, k);

	for(i = 0; i <= r-1; i++){
		for(j = 0; j <= s-1; j++){
			printf("%c", display[i][j]);
		}
		printf("\n");
	}

	printf("Le mosche in totale sono %d\n", m);
	printf("Il numero massimo di mosche uccise è %d\n", max);

	return 0;
}

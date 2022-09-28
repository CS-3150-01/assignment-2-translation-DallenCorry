#include <stdio.h>

int main() {
    char charMap[20][100];
	charMap[0][0] = 'X';
	char directions[4][10] = { "North", "East", "South", "West" };
	int directionX[] = {0,     -1,       0,      1};
	int directionY[] = {1,      0,      -1,      0};

	//charMap[][];

	for (int i=0; i<20; i++){
		for (int j=0; j<100; j++){
			if (charMap[i][j] == NULL) {
				printf("+");
			}
			else {
				printf("%c", charMap[i][j]);
			}
		}
		printf("\n");
	}



    return 0;
}
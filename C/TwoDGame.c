#include <stdio.h>
#include <stdbool.h>

int main() {
    int intMap[20][100] = {0};
	//0 means nothing there: ( . ), 1 means path: ( # ), 2 means player: ( P ).

    intMap[5][5] = 2;//Set player to position 5,5

    char directions[4][10] = {"North","East","South","West"};
	int directionX[] = {0,      -1,       0,      1};
	int directionY[] = {1,      0,      -1,      0};
	int currentPosition[] = {5,5};
	int currentDirection = 0;
	bool proceed = true;

	while (proceed) {
		char input[1][10];
		printMap(intMap);
		printf("Please traverse the world and explore using these commands: \n  W - Walk Forward\n  A - Turn Left\n  D - Turn Right\n  E - Check Direction\n  Q - Quit the Game\n");
		scanf("%s", input);

		char command = input[0][0];

		switch (command) {
			case 'w':
				intMap[currentPosition[1]][currentPosition[0]] = 1;
				if(!((currentPosition[0] - directionX[currentDirection] < 0) || (currentPosition[0] - directionX[currentDirection] > 100)||(currentPosition[1] - directionY[currentDirection] < 0) || (currentPosition[1] - directionY[currentDirection] > 20))){
					//checks if you're bumping into the edge
					currentPosition[0] = currentPosition[0] - directionX[currentDirection];
					currentPosition[1] = currentPosition[1] - directionY[currentDirection];
				}
				intMap[currentPosition[1]][currentPosition[0]] = 2;
				break;
			case 'a':
				currentDirection--;
				if(currentDirection < 0){
					currentDirection = 3;
				}
				break;
			case 'd':
				currentDirection++;
				if(currentDirection > 3){
					currentDirection = 0;
				}
				break;
			case 'e':
				printf("You are facing in the %sward direction!\n", directions[currentDirection]);
				break;
			case 'q':
				proceed = false;
				break;
			default:
				printf("UwU 0 _ 0");
		}
	}
    return 0;
}

void printMap(int map[20][100]) {
	for (int i=0; i<20; i++) {
		for (int j=0; j<100; j++){
			if (map [i][j] == 2) {
				printf("P");
			} else if (map [i][j] == 1) {
				printf("#");
			}
			else {
				printf(".");
                //printf("%c", intMap[i][j]);
			}
		}
		printf("\n");
	}
}
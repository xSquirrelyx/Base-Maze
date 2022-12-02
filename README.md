// MAKE SURE TO INCLUDE 

 #include <windows.h>

// below "int main() 

{
system("color 05");

// DrawMap 

void DrawMap()
{
	int y = 0;
	for (y = 0; y < c; y++)				//draw rows, how could this be a different number? Set Diff c value
	{
		int s = 0;



		printf("\t");	//may need to change, how to make match the columns? Fixed
		for (s = 0; s < (c * 4) + 1; s++) {
			printf("-");
		}
		printf("\n");
		printf("\t");

		int x = 0;
		for (x = 0; x < c + 1; x++)			//draw columns, how could this be a different number? Set Diff c value
		{
			printf("|");

			// Note these are one-line IF statements, for more lines you would need {} code blocks
			if (x == target.x && y == target.y) {			//Target position
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				printf("[T]");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			}
			else if (x == enemy1.x && y == enemy1.y) {	//Enemy1 position
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("< >");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			}
			else if (x == enemy2.x && y == enemy2.y) {	//Enemy2 position
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("< >");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			}
			else if (x == player.x && y == player.y) {	//Player position
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("-_-");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			}
			else if (x == object.x && y == object.y) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("###");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			}
			else
				printf("   ");
		}
		printf("\n");
	}
	int d = 0;
	printf("\t");	//may need to change, how to make match the columns? Fixed
	for (d = 0; d < (c * 4) + 1; d++) {
		printf("-");
	}
	printf("\n");
}

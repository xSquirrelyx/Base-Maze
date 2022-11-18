#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <conio.h>

/////////////////////////////////////////

struct Position
{
	int x;
	int y;
};

/////////////////////////////////////////

struct Position player;
struct Position target;
struct Position enemy1, enemy2;

// Note 1 = true, 0 = false
char direction1 = 1, direction2 = 1;

/////////////////////////////////////////

void DrawMap();//Henny
void HandleEnemy();
int	Modulo(int nb, int mod);
void HandlePlayer(char input);
int rando(int a, int b);
int check(int a, int b, int c, int d);



/////////////////////////////////////////0

int main()
{
	srand(time(0));
	int Tx = rando(1, 7); //2-7
	int E1x = rando(0, 4); /*0-3*/
	int E2x = rando(4, 4); //5-7
	int Px = rando(0, 4); //0-3
	int Py = rando(7, 3); //5-8
	int E1y = rando(1, 3); //1-3
	int E2y = rando(4, 3); //4-5
	
	
	//Initial positions
	player.x = Px, player.y = Py;  // Note these are currently constant
	target.x = Tx, target.y = 0;
	enemy1.x = E1x, enemy1.y = E1y;
	enemy2.x = E2x, enemy2.y = E2y;

	//Game Loop
	while (1)  // What could stop this loop?  It is set to always true
	{
		DrawMap();  // First redraw the game

		printf("Enter a choice: a(Left), d(Right), w(Up), s(Down) and e(Exit)\n");

		char input = _getch();  // Gets input without typing enter

		//scanf_s(" %c", &input, 1);  // Note we feed the _address_ of input into scanf_s here

		if (input == 'e') {
			printf("\n");
			return 0;
		}
		else
		{
			HandlePlayer(input);
			HandleEnemy();

			system("cls");  // Wipe the console window preparatory to the 

			// Interaction code here
			if ((player.x == enemy1.x && player.y == enemy1.y) ||		//colliding with an enemy
				(player.x == enemy2.x && player.y == enemy2.y))
			{
				printf("Sorry, you failed...\n");
				printf("\n");
				return 0;
			}
			else if (player.x == target.x && player.y == target.y)		//Target reached
			{
				printf("Congratulations, you won...\n");
				printf("\n");
				return 0;
			}
		}
	}
}

/////////////////////////////////////////
int c = 10; // keep even number or breaks enemy 1
void DrawMap()
{
	int y = 0;
	for (y = 0; y < c; y++)				//draw rows, how could this be a different number? Set Diff c value
	{
		int s = 0;
		printf("\t");	//may need to change, how to make match the columns? Fixed
		for (s = 0; s < (c*3)+1;s++){
			printf("-");
		}
		printf("\n");
		printf("\t");

		int x = 0;
		for (x = 0; x < c + 1; x++)			//draw columns, how could this be a different number? Set Diff c value
		{
			printf("|");

			// Note these are one-line IF statements, for more lines you would need {} code blocks
			if (x == target.x && y == target.y)			//Target position
				printf("T ");
			else if (x == enemy1.x && y == enemy1.y)	//Enemy1 position
				printf("<>");
			else if (x == enemy2.x && y == enemy2.y)	//Enemy2 position
				printf("<>");
			else if (x == player.x && y == player.y)	//Player position
				printf("P ");
			else
				printf("  ");
		}
		printf("\n");
	}
	int d = 0;
	printf("\t");	//may need to change, how to make match the columns? Fixed
	for (d = 0; d < (c * 3) + 1; d++) {
		printf("-");
	}
	printf("\n");
}

/////////////////////////////////////////

void HandlePlayer(char input)
{
	int tempx = player.x,
		tempy = player.y;

	// l, r, u, d?  really? Fixed
	if (input == 'a')
		tempx--;
	else if (input == 'd')
		tempx++;
	else if (input == 'w')
		tempy--;
	else if (input == 's')
		tempy++;

	if (input == 'A')
		tempx--;
	else if (input == 'D')
		tempx++;
	else if (input == 'W')
		tempy--;
	else if (input == 'S')
		tempy++;

	// Pacman style, based on a fixed size
	player.x = Modulo(tempx, c);
	player.y = Modulo(tempy, c);
}

/////////////////////////////////////////

void HandleEnemy()
{
	//  Note: Lots of one-line IF statements, and use of INT variable as a boolean ...
	//Enemy1
	if (direction1)
		enemy1.x++;
	else
		enemy1.x--;

	if (enemy1.x == 0 || enemy1.x == c - 1) 
		direction1 = !direction1;

	//Enemy2
	if (direction2)
		enemy2.x -= 2;
	else
		enemy2.x += 2;

	if (enemy2.x <= 0 || enemy2.x >= c -1)
	{
		if (direction2)
			enemy2.x++;
		else
			enemy2.x--;

		direction2 = !direction2;
	}
}

/////////////////////////////////////////
// Manages the Pacman style movement
int Modulo(int nb, int mod)
{
	if (nb < 0)
		nb += mod;

	return nb % mod;
}

/////////////////////////////////////////

int rando(int a, int b) {
	return (a+rand()%b);
}

/////////////////////////////////////////

int check(int a, int b, int ab, int ba) {
	if (a == b) {
		int x = (ab + rand() % ba);
		x = b;
		return b;
	}
}



#include <iostream>
using namespace std;

int main ()
{	
	int x = 0, y = 0, tx, ty, i, j;
	int command, pen, step;
	char arr[20][20];
	char turtle_front = 'N';
	// there is a turtle in (0,0) position
	
	for (i=0; i<20; i++)
		for (j=0; j<20; j++)
			arr[i][j] = ' ';

	pen = 1;
	cin >> command;
	
	while (1)
	{			
		tx = x;
		ty = y;
		// the turtle is coming in (x,y) position		
		if (command == 1 || command == 2)
		{
			
			pen = command;
			cin >> command;
		}		
		if (x==0 && y==0 && pen==2)
			arr[x][y] = '*';
					
		if (command == 3)
		{
			
			cin >> command;
	        if (command == 5)
			{
				
				cin >> step;
				
				if(turtle_front == 'N')			// north
				{
				
					y = y+step;
					turtle_front = 'E';
					
					for (j=ty+1; j<=y; j++)
					{
						
						if(pen == 1)
							arr[x][j] = ' ';
						else if(pen == 2)
							arr[x][j] = '*';
					}
				}
				else if(turtle_front == 'E')	//	east
				{
					
					x = x+step;
					turtle_front = 'S';
					
					for (i=tx+1; i<=x; i++)
					{
						
						if(pen == 1)
							arr[i][y] = ' ';
						else if(pen == 2)
							arr[i][y] = '*';
					}
				}
				else if(turtle_front == 'S')	// south
				{
					
					y = y-step;
					turtle_front = 'W';
					
					for (j=ty-1; j>=y; j--)
					{
						
						if(pen == 1)
							arr[x][j] = ' ';
						else if(pen == 2)
							arr[x][j] = '*';
					}
				}
				else if(turtle_front == 'W')	// west
				{
					
					x = x-step;
					turtle_front = 'N';
					
					for (i=tx-1; i>=x; i--)
					{
						
						if(pen == 1)
							arr[i][y] = ' ';
						else if(pen == 2)
							arr[i][y] = '*';
					}
				}

				cin >> command;
			}
		}
	
		if (command == 4)
		{
			
			cin >> command;
	        if (command == 5)
			{
				
				cin >> step;

				if(turtle_front == 'N')			// north
				{
				
					y = y-step;
					turtle_front = 'W';
					
					for (j=ty-1; j>=y; j--)
					{
						
						if(pen == 1)
							arr[x][j] = ' ';
						else if(pen == 2)
							arr[x][j] = '*';
					}
				}
				else if(turtle_front == 'E')	// east
				{
					
					x = x-step;
					turtle_front = 'N';
					
					for (i=tx-1; i>=x; i--)
					{
						
						if(pen == 1)
							arr[i][y] = ' ';
						else if(pen == 2)
							arr[i][y] = '*';
					}
				}
				else if(turtle_front == 'S')	// south
				{
					
					y = y+step;
					turtle_front = 'E';
					
					for (j=ty+1; j<=y; j++)
					{
						
						if(pen == 1)
							arr[x][j] = ' ';
						else if(pen == 2)
							arr[x][j] = '*';
					}
				}
				else if(turtle_front == 'W')	// west
				{
					
					x = x+step;
					turtle_front = 'S';
					
					for (i=tx+1; i<=x; i++)
					{
						
						if(pen == 1)
							arr[i][y] = ' ';
						else if(pen == 2)
							arr[i][y] = '*';
					}
				}
				
				cin >> command;
			}			
		}
		
		if (command == 5)
		{
				
			cin >> step;
			
			if(x==0 && y==0)
			{
				
					y = y+step;
					turtle_front = 'E';
					
					for (j=ty+1; j<=y; j++)
					{
						
						if(pen == 1)
							arr[x][j] = ' ';
						else if(pen == 2)
							arr[x][j] = '*';
					}
			}
				
			else if(turtle_front == 'N')				// north
			{
				
				x = x-step;
					
				for (i=tx-1; i>=x; i--)
				{
						
					if(pen == 1)
						arr[i][y] = ' ';
					else if(pen == 2)
						arr[i][y] = '*';
				}
			}
			else if(turtle_front == 'E')		// east
			{
				
				y = y+step;
					
				for (j=ty+1; j<=y; j++)
				{
						
					if(pen == 1)
						arr[x][j] = ' ';
					else if(pen == 2)
						arr[x][j] = '*';
				}
			}
			else if(turtle_front == 'S')		// south
			{
				
				x = x+step;
					
				for (i=tx+1; i<=x; i++)
				{
						
					if(pen == 1)
						arr[i][y] = ' ';
					else if(pen == 2)
						arr[i][y] = '*';
				}
			}
			else if(turtle_front == 'W')		// west
			{
					
				y = y-step;
				
				for (j=ty-1; j>=y; j--)
				{
						
					if(pen == 1)
						arr[x][j] = ' ';
					else if(pen == 2)
						arr[x][j] = '*';
				}
			}

			cin >> command;
		}
				
		if (command == 6)						// it should be output on the screen with this command
		{
			

			for (i=0; i<20 ; i++)
			{
				
				for (j=0; j<20 ; j++)	
					cout << arr[i][j];
				
				cout << endl;
			}
			
			cin >> command;
		}
		
		else if (command == 9)					// terminal
			break;
	}
}

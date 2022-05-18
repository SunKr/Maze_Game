#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
0: 벽
1: 길
2: 시작점
3: 도착점
*/


void SetMaze(char Maze[21][21]) //null 값이 맨마지막에 들어가야해서 21로 설정
{
	
	strcpy_s(Maze[0],  "21100000000000000000");
	strcpy_s(Maze[1],  "00111111000000000000");
	strcpy_s(Maze[2],  "10110000000000000000");
	strcpy_s(Maze[3],  "00110000000000000000");
	strcpy_s(Maze[4],  "01100000000000000000");
	strcpy_s(Maze[5],  "01100000000000000000");
	strcpy_s(Maze[6],  "01100000000000000000");
	strcpy_s(Maze[7],  "01100000000000000000");
	strcpy_s(Maze[8],  "01100000000000000000");
	strcpy_s(Maze[9],  "01100000000000000000");
	strcpy_s(Maze[10], "01100000000000000000");
	strcpy_s(Maze[11], "01100000000000000000");
	strcpy_s(Maze[12], "01100000000000000000");
	strcpy_s(Maze[13], "01100000000000000000");
	strcpy_s(Maze[14], "01100000000000000000");
	strcpy_s(Maze[15], "01100000000000000000");
	strcpy_s(Maze[16], "01100000000000000000");
	strcpy_s(Maze[17], "01100000000000000000");
	strcpy_s(Maze[18], "01111111000000000000");
	strcpy_s(Maze[19], "00000003000000000000");
}

void Output(char Maze[21][21])
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (Maze[i][j] == '0')
				cout << "■";
			
			else if (Maze[i][j] == '1')
				cout << "  ";

			else if (Maze[i][j] == '2')
				cout << "∑";

			else if (Maze[i][j] == '3')
				cout << "Ο";

		}
		cout << endl;
	}
}


int main()
{

	// 20 X 20 미로를 만들어준다.

	char strMaze[21][21];


	// 미로를 설정
	SetMaze(strMaze);

	//미로를 출력
	Output(strMaze);





	return 0;
}
#include <iostream>
#include <conio.h>


using namespace std;

/*
0: 벽
1: 길
2: 시작점
3: 도착점
*/
struct _tagPoint
{
	int x;
	int y;
	bool destination = false;
};

//타입 재정의
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;




void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos,
PPOINT pEndPos) //null 값이 맨마지막에 들어가야해서 21로 설정
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlayerPos = *pStartPos;
	
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

void Output(char Maze[21][21], PPOINT pPlayerPos)
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (pPlayerPos->x == j && pPlayerPos->y == i)
			{
				cout << "Δ";
				if (Maze[pPlayerPos->y][pPlayerPos->x] == '3')
				{
					pPlayerPos->destination = true;
				}
					
			}
				

			else if (Maze[i][j] == '0')
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


void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	//y 축 값을 조정해야한다.
	if (pPlayerPos->y - 1 >= 0)
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0')
		{
			--pPlayerPos->y;
		}
	}
}


void MoveDown(char Maze[21][21], PPOINT pPlayerPos)
{
	//y 축 값을 조정해야한다.
	if (pPlayerPos->y + 1 < 20)
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0')
		{
			++pPlayerPos->y;
		}
	}
}

void MoveRight(char Maze[21][21], PPOINT pPlayerPos)
{
	//y 축 값을 조정해야한다.
	if (pPlayerPos->x + 1 < 20)
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y][pPlayerPos->x+1] != '0')
		{
			++pPlayerPos->x;
		}
	}
}


void MoveLeft(char Maze[21][21], PPOINT pPlayerPos)
{
	//y 축 값을 조정해야한다.
	if (pPlayerPos->x - 1 >= 0)
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0')
		{
			--pPlayerPos->x;
		}
	}
}

void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cInput)
{
	switch (cInput)
	{
		//w를 누르면 위로 움직임
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;
	}
}



int main()
{

	// 20 X 20 미로를 만들어준다.

	char strMaze[21][21];


	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;


	// 미로를 설정
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	while (true)
	{
		system("cls");
		//미로를 출력
		

		Output(strMaze, &tPlayerPos);
		if (tPlayerPos.destination == true)
		{
			//cout << endl;
			cout << " 도착하였습니다. " << endl;
			system("pause");
		}

		cout << "w : 위  s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 ";
		char cInput = _getch();  //키 입력


		if (cInput == 'q' || cInput == 'Q')
			break;

		MovePlayer(strMaze, &tPlayerPos, cInput);

		
		
	}

	





	return 0;
}
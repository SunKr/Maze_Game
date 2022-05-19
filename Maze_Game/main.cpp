#include <iostream>
#include <conio.h>
#include <time.h>


using namespace std;

/*
0: 벽
1: 길
2: 시작점
3: 도착점
4: 지뢰 : 지뢰를 밟으면 좌우 상하 벽 다 터짐
5: 투명 : 투명 아이템 먹을시 자유롭게 돌아 다닐수 있음
6: 벽 건너 뛰기 : 벽넘어에 길이 있다면 넘을수 잇음
7: 벽 밀기 : 벽 뒷부분에 공간이 있다면 벽을 밀수 있음
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
	strcpy_s(Maze[1],  "00111111111111000000");
	strcpy_s(Maze[2],  "10110000000001000000");
	strcpy_s(Maze[3],  "00110000000111000000");
	strcpy_s(Maze[4],  "01100000000011000000");
	strcpy_s(Maze[5],  "01100000011111100000");
	strcpy_s(Maze[6],  "01100000001100000000");
	strcpy_s(Maze[7],  "01100000111110000000");
	strcpy_s(Maze[8],  "01100000001111000000");
	strcpy_s(Maze[9],  "01100000000001100000");
	strcpy_s(Maze[10], "01111111110000100000");
	strcpy_s(Maze[11], "01000000000000100000");
	strcpy_s(Maze[12], "01000000000111100000");
	strcpy_s(Maze[13], "01000000111100000000");
	strcpy_s(Maze[14], "01000000000111100000");
	strcpy_s(Maze[15], "01000000000000011100");
	strcpy_s(Maze[16], "01101000000000000110");
	strcpy_s(Maze[17], "01100000110000000100");
	strcpy_s(Maze[18], "01111011111101111100");
	strcpy_s(Maze[19], "00000003000111000000");
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


			else if (Maze[i][j] == '0') //벽
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


// 지뢰 아이템(특징: 먹으면 상하 좌우 벽이 터진다. 터진후 길로 변경된다.)
void Bomb(char Maze[21][21], PPOINT pPlayerPos)
{
	// 아이템을 먹은후 아이템은 사라지고 그곳은 길로 변경된다.
	// 아이템을 먹었기 때문에 아이템 효과 발동 시킨다.
	// 첫번째 지뢰 아이템(일회성 아이템)
	// 먹는 순간 지뢰 좌우상하 벽이 터진다.
	if (Maze[pPlayerPos->y][pPlayerPos->x] == '4')
	{
		// 지뢰가 있던자리 길로 변경
		Maze[pPlayerPos->y][pPlayerPos->x] = '1';
		// 길로 변경되었으면 상하좌우에 벽이 있는지 체크해준다.
		// 체크하기전 맵 범위 내에서 작동하게 설정한다.
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] == '0') //상
			Maze[pPlayerPos->y + 1][pPlayerPos->x] = '1';
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] == '0') //우
			Maze[pPlayerPos->y][pPlayerPos->x + 1] = '1';
		if (Maze[pPlayerPos->y-1][pPlayerPos->x] == '0') //하
			Maze[pPlayerPos->y-1][pPlayerPos->x] = '1';
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] == '0') //좌
			Maze[pPlayerPos->y][pPlayerPos->x-1] = '1';
	}
}

void JumpWall(char Maze[21][21], PPOINT pPlayerPos)
{
	//점프wall 아이템의 경우 지속적으로 사용가능하도록 설계(아이템 사용 버튼 생성)
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
			break;
		}

		cout << "w : 위  s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 ";
		
		char cInput = _getch();  //키 입력


		if (cInput == 'q' || cInput == 'Q')
			break;

		MovePlayer(strMaze, &tPlayerPos, cInput);

		
		
	}

	





	return 0;
}
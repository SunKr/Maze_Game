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




void SetItem(char Maze[21][21], PPOINT pPlayerPos)
{
	srand((unsigned int)time(0)); // 랜덤 으로 시간 설정

	int iRand = 0;
	int iStat = 0;
	
	// for loop 을 통해서 배열을 체크하여 1(길)인 지점을 랜덤하게 골라서 아이템을 놓아 준다.
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (Maze[j][i] == '1') // 메이즈 내부가 길이면 랜덤하게 아이템 놓기
			{
				iStat = rand() % 100; //5% 의 확률로 
				//if 로 진입해서  길위에 아이템을 놓는다.
				if (iStat < 3) //3%의 확률로 맵에 뜨게 설정
				{
					iRand = (rand() % 4 + 4); // 아이템이 랜덤하게 골라졌다면 그 아이템을 칸중에 5% 확률로 떨궈준다.
					// 이전에 확률 변수를 넣어서 if 문으로 들어가는 확률을 다시 설정해준다.
					if (iRand == 4)
					{
						Maze[j][i] = '4'; //지뢰
					}
					else if (iRand == 5)
					{
						Maze[j][i] = '5'; //투명
					}
					else if (iRand == 6)
					{
						Maze[j][i] = '6'; //벽 건너뛰기
					}
					else if (iRand == 7)
					{
						Maze[j][i] = '7'; //벽 밀기
					}

				}
			}
		}
	}
	
}

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

			else if (Maze[i][j] == '4') //지뢰 폭탄으로 좌우 상하 벽 없애기
				cout << "※";

			else if (Maze[i][j] == '5') //투명 상태여서 아무곳으로 이동가능
				cout << "±";

			else if (Maze[i][j] == '6') //벽 건너뛰기
				cout << "℃";
			
			else if (Maze[i][j] == '7') //벽 밀치기
				cout << "℉";
			
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
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos); //맵 초기 설정
	SetItem(strMaze, &tPlayerPos); // 아이템을 길에 3% 확률로 떨군다
	//메이즈를 설정한 이후에 빈공간(1) 길쪽에 랜덤하게 아이템 설정해준다.

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
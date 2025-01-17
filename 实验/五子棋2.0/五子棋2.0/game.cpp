#include"all.h"
int Chess[ROW][LINE] = { 0 };

int mm = 0;
int	n = 0;

//长宽约19.6  左上（17，7）

void board()
{
	settextcolor(WHITE);
	settextstyle(25, 0, _T("Consolas"));
	outtextxy(900, 300, _T("保存记录"));
	outtextxy(900, 500, _T("悔棋"));
	for (int i = 0; i < 16; i++)
	{
		line(900/15*i, 0, 900/15*i, 900);
		line(0, 900 / 15 * i, 900, 900 / 15 * i);
	}
	/*loadimage(NULL, _T("C:\\Users\\麦克斯韦\\Desktop\\偷跑代码库\\五子棋\\f11f3a292df5e0fe62dc27035e6034a85fdf72e81.jpg"));*/
}






void player(int x,int y)
{
	FlushMouseMsgBuffer();
	setfillcolor(BLACK);
	int line, row;
				row = x;
				line = y;
				chess(&row, &line);
				if (Chess[mm][n] == 0)
				{
					Chess[mm][n] = 1;
					printf("(%d,%d) %d\n", mm, n, 1);
					solidcircle(row, line, 10);
				}
				else
					return ;
		//case WM_MOUSEMOVE:
		//	char s[12];
		//	setfillcolor(BLACK);
		//	solidrectangle(0, 0, 75, 20);
		//	sprintf(s, "[%d,%d]", m.x, m.y);
		//	outtextxy(0, 0, s);
		
	
}





void chess(int *row,int *line)
{
		*row = *row - OROW;
		*line = *line - OLINE;
		for (int i = 0; i < 15; i++)
		{
			if (i * S - S / 2 < *row && i * S + S / 2 > *row)
			{
				*row = S * i + OROW;
				mm = i;
				break;
			}

		}
		for (int i = 0; i < 15; i++)
		{
			if (i * S - S / 2 <*line && i * S + S / 2 > *line)
			{
				*line = S * i + OLINE;
				n = i;
				break;
			}
		}
}

void computer()
{
	setfillcolor(WHITE);
	int row = 7 , line  = 7;
	dfs(&row,&line);
	solidcircle(60*row, 60*line, 10);
}





int judge1()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int y = 0; y < LINE - 5; y++)
		{
			if (Chess[i][y] == Chess[i][y + 1] && Chess[i][y] == Chess[i][y + 2] && Chess[i][y] == Chess[i][y + 3] && Chess[i][y] == Chess[i][y + 4] && Chess[i][y] != 0)
			{
				return 1;
			}
			if (Chess[y][i] == Chess[y + 1][i] && Chess[y][i] == Chess[y + 2][i] && Chess[y + 3][i] == Chess[y][i] && Chess[y][i] == Chess[y + 4][i] && Chess[y][i] != 0)
			{
				return 1;
			}
		}
	}
	return 0;
}








int judge12()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int y = 0; y < LINE - 5; y++)
		{
			if (Chess[i][y] == Chess[i +1][y + 1] && Chess[i][y] == Chess[i + 2][y + 2] && Chess[i][y] == Chess[i + 3][y + 3] && Chess[i][y] == Chess[i + 4][y + 4] && Chess[i][y] != 0)
			{
				return 1;
			}
			if (i - 4 < 0 || y - 4 < 0)
				continue;
			if (Chess[y][i] == Chess[y -1][i - 1] && Chess[y][i] == Chess[y - 2][i - 2] && Chess[y - 3][i - 3] == Chess[y][i] && Chess[y][i] == Chess[y - 4][i - 4] && Chess[y][i] != 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

int judge21()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int y = 0; y < LINE - 5; y++)
		{
			if (i - 4 > 0&&y+4<15)
			{
				if (Chess[i][y] == Chess[i - 1][y + 1] && Chess[i][y] == Chess[i - 2][y + 2] && Chess[i][y] == Chess[i - 3][y + 3] && Chess[i][y] == Chess[i - 4][y + 4] && Chess[i][y] != 0)
				{
					return 1;
				}
				if (Chess[y][i] == Chess[y + 1][i - 1] && Chess[y][i] == Chess[y + 2][i - 2] && Chess[y + 3][i - 3] == Chess[y][i] && Chess[y][i] == Chess[y + 4][i - 4] && Chess[y][i] != 0)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}





int judge2()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int y = 0; y < LINE - 5; y++)
		{
			if (Chess[i][y] == Chess[i][y + 1] && Chess[i][y] == Chess[i][y + 2] && Chess[i][y] == Chess[i][y + 3] &&Chess[i][y]== Chess[i][y + 4] && Chess[i][y] != 0)
			{
				return 1;
			}
			if (Chess[y][i] == Chess[y + 1][i] && Chess[y][i] == Chess[y + 2][i] && Chess[y + 3][i] == Chess[y][i]&& Chess[y][i] == Chess[y+4][i] && Chess[y][i] != 0)
			{
				return 1;
			}
		}
	}
	return 0;
}





int game()
{

	//目录
	initgraph(1000, 900);
	menu();

//黑一白二

	switch (showchoice())
	{
		Sleep(100);
	case 1:
		board();
		Sleep(100);
		break;
	case 2:
		board();
		Sleep(100);
		saving();
		break;
	case 3:
		board();
		reading();
		Sleep(100);
		saving();
		break;
	default:
		printf("error");
	}
	//开始
	while (1)
	{
		computer();
		if (judge1()==1||judge12()==1||judge21()==1)
		{
			cleardevice();
			settextcolor(RED);
			settextstyle(60, 0, _T("Consolas"));
			outtextxy(350, 300, _T("computer win"));
			printf("computer win");
			Sleep(500);
			break;
		}
		if (saving() == 1)
			break;
		if (judge2() == 1||judge12()==1||judge21()==1)
		{
			cleardevice();
			settextcolor(RED);
			settextstyle(60, 0, _T("Consolas"));
			outtextxy(350, 300, _T("player win"));
			printf("player win");
			Sleep(500);
			break;
		}


	}





	return 0;
}



int menu()
{
	settextcolor(RED);
	settextstyle(60, 0, _T("Consolas"));
	outtextxy(350, 300, _T("五子棋"));
	settextstyle(20, 0, _T("Consolas"));
	while (!_kbhit())
	{
		beginanimation();
	}
	settextcolor(BLACK);
	settextstyle(60, 0, _T("Consolas"));
	outtextxy(350, 300, _T("五子棋"));
	return 0;
}

void beginanimation()
{
	settextcolor(WHITE);
	outtextxy(250, 500, _T(">  clik any key in the control board to play  <"));
	Sleep(100);
	settextcolor(BLACK);
	outtextxy(250, 500, _T(">  clik any key in the control board to play  <"));
	Sleep(100);
}


int showchoice()
{
	settextcolor(WHITE);
	settextstyle(30, 0, _T("Consolas"));
	outtextxy(400, 300, _T("后手"));
	outtextxy(400, 500, _T("先手"));
	outtextxy(380, 700, _T("恢复对局"));
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if ((m.x >= 400 && m.x <= 450) && (m.y >= 300 && m.y <= 330))
			{//清除文字
				settextcolor(BLACK);
				settextstyle(30, 0, _T("Consolas"));
				outtextxy(400, 300, _T("后手"));
				outtextxy(400, 500, _T("先手"));
				outtextxy(380, 700, _T("恢复对局"));
				return 1;
			}
			if ((m.x >= 400 && m.x <= 450) && (m.y >= 500 && m.y <= 530))
			{
				settextcolor(BLACK);
				settextstyle(30, 0, _T("Consolas"));
				outtextxy(400, 300, _T("后手"));
				outtextxy(400, 500, _T("先手"));
				outtextxy(380, 700, _T("恢复对局"));
				return 2;
			}
			if ((m.x >= 380 && m.x <= 500) && (m.y >= 700 && m.y <= 730))
			{
				settextcolor(BLACK);
				settextstyle(30, 0, _T("Consolas"));
				outtextxy(400, 300, _T("后手"));
				outtextxy(400, 500, _T("先手"));
				outtextxy(380, 700, _T("恢复对局"));
				return 3;
			}
		}
	}
	return 0;
}


int saving()
{
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
			case WM_LBUTTONDOWN:
				if (m.x < 900)
				{
					save_file();
					player(m.x, m.y);
					return 0;
				}				
				if (m.y > 300 && m.y < 325)
				{
					save_file();
					return 1;
				}
				if (m.y > 500 || m.y < 525)
				{
					reading();
					continue;
				}
			case WM_LBUTTONUP:
				break;
		}
	}
	return 0;
}

void save_file()
{
	FILE* fp = fopen("./记录/记录.txt", "w");
	if (!fp)
	{
		printf("error");
		return;
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			fprintf(fp, "%d ", Chess[i][j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}


void reading()
{
	FILE* fp = fopen("./记录/记录.txt", "r");
	if (!fp)
	{
		printf("error");
		return;
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			fscanf(fp,"%d ", &Chess[i][j]);
		}
		fscanf(fp, "\n");
	}
	fclose(fp);
	cleardevice();
	board();
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (Chess[i][j] == 1)
			{
				setfillcolor(BLACK);		
				solidcircle(i*S+ OROW, j*S+ OLINE, 10);
			}
			if (Chess[i][j] == 2)
			{
				setfillcolor(WHITE);
				solidcircle(i * S + OROW, j * S + OLINE, 10);
			}
		}
	}
	return;
}

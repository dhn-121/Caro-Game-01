#include "Library.h"
using namespace std;
bool has_empty_cell = 0;
int count_moves = 0;
void getij(int& i,int& j,int x,int y)
{
    i = (x - xbegin) / (CellWidth + 1);
	j = (y - ybegin) / (CellHeight + 1);
}
void getxy(int& x, int& y, int i, int j)
{
	x = xbegin + i * (CellWidth + 1);
	y = ybegin + j * (CellHeight + 1);
}
bool check_iswin(int x, int y, char a[N][N])
{
	char cur = a[x][y];
	int dmove[4][2] = { {0,1}, {1,0}, {1,1}, {1,-1} }; // ngang, dọc, chéo phải-xuống, chéo trái-xuống
	for (int k = 0; k < 4; k++)
	{
		int dx = dmove[k][0];
		int dy = dmove[k][1];

		int count = 1;

		// Duyệt theo hướng dương (forward)
		for (int step = 1; step < 5; step++)
		{
			int nx = x + dx * step;
			int ny = y + dy * step;
			// Kiểm tra biên và quân cờ
			if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && a[nx][ny] == cur)
				count++;
			else
				break;
		}

		// Duyệt theo hướng âm (backward)
		for (int step = 1; step < 5; step++)
		{
			int nx = x - dx * step;
			int ny = y - dy * step;
			// Kiểm tra biên và quân cờ
			if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && a[nx][ny] == cur)
				count++;
			else
				break;
		}

		if (count >= 5)
			return true;
	}
	return false;
}

// Hàm kiểm tra hòa: So sánh số nước đã đi với tổng số ô trên bàn cờ
bool check_isdraw(int count_moves)
{
	// Nếu số nước đi == Tổng số ô (N * N hoặc BOARD_SIZE * BOARD_SIZE)
	if (count_moves == BOARD_SIZE * BOARD_SIZE)
		return true;
	return false;
}
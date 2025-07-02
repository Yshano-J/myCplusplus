#define _CRT_SECURE_NO_WARNINGS 




#include<stdio.h>
#include<string.h>
#define ROWCOL 210

char a[ROWCOL][ROWCOL];
int m, n, t;
int sx, sy;
int ans_x, ans_y;
int dist[ROWCOL][ROWCOL][11];
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };

struct point
{
    int x, y, t;
}queue[ROWCOL * ROWCOL];
int rear, front;

void push(int x, int y, int t)
{
    queue[rear].x = x;
    queue[rear].y = y;
    queue[rear].t = t;
    rear++;
}

struct point pop()
{
    return queue[front++];
}

bool bfs(int s, int d, int t)
{
    push(s, d, t);
    dist[s][d][t] = 0;

    while (front < rear)
    {
        struct point pre = pop();
        int x = pre.x, y = pre.y, t = pre.t;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (t <= 0 && a[nx][ny] == '#') continue;

                if (a[nx][ny] == '+')
                {
                    dist[nx][ny][t] = dist[x][y][t] + 1;
					printf("%d", dist[nx][ny][t]);
                    return true;
                }

                if (a[nx][ny] == '*')
                {
                    if (dist[nx][ny][t] == -1)
                    {
                        dist[nx][ny][t] = dist[x][y][t] + 1;
                        push(nx, ny, t);
                    }
                }
                else if (a[nx][ny] == '#')
                {
                    if (t > 0)
                    {
						if (dist[nx][ny][t - 1] == -1)
						{
							dist[nx][ny][t - 1] = dist[x][y][t] + 1;
							push(nx, ny, t - 1);
						}
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d %d %d", &m, &n, &t);
    for (int i = 0; i < m; i++)
        scanf("%s", a[i]);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '@')
            {
                sx = i;
                sy = j;
            }
            if (a[i][j] == '+')
            {
                ans_x = i;
                ans_y = j;
            }
        }
    }

	if (sx == ans_x && sy == ans_y)
	{
		printf("0");
		return 0;
	}

    for (int i = 0; i < ROWCOL; i++)
        for (int j = 0; j < ROWCOL; j++)
            for(int k = 0;k < 11;k++)
                dist[i][j][k] = -1;

    if(!bfs(sx, sy, t))
        printf("-1");
    return 0;
}

//
//#include<stdio.h>
//#include<string.h>
//#define ROWCOL 210
//
//char a[ROWCOL][ROWCOL];
//int m, n, t;
//int sx, sy;
//int ans_x, ans_y;
//int dist[ROWCOL][ROWCOL][11];
//int dx[4] = { 0, 1, -1, 0 };
//int dy[4] = { 1, 0, 0, -1 };
//
//struct point
//{
//    int x, y;
//}queue[ROWCOL * ROWCOL];
//int rear, front;
//
//void push(int x, int y)
//{
//    queue[rear].x = x;
//    queue[rear].y = y;
//    rear++;
//}
//
//struct point pop()
//{
//    return queue[front++];
//}
//
//void bfs(int s, int d)
//{
//    push(s, d);
//    dist[s][d][t] = 0;
//
//    while (front < rear)
//    {
//        struct point pre = pop();
//        int x = pre.x, y = pre.y;
//	
//        for (int i = 0; i < 4; i++)
//        {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//            if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny][t] == -1)
//            {
//                if (t <= 0 && a[nx][ny] == '#') continue;
//
//                if (nx == ans_x && ny == ans_y)
//                {
//                    dist[nx][ny][t] = dist[x][y][t] + 1;
//					printf("%d", dist[nx][ny][t]); 
//                    return;
//                }
//
//                if (a[nx][ny] == '*')
//                {
//                    dist[nx][ny][t] = dist[x][y][t] + 1;
//                    push(nx, ny);
//                }
//
//                if (a[nx][ny] == '#' && t > 0)
//                {
//                    dist[nx][ny][t - 1] = dist[x][y][t] + 1;
//                    push(nx, ny);
//                }
//            }
//        }
//    }
//}
//
//int main()
//{
//    scanf("%d %d %d", &m, &n, &t);
//    for (int i = 0; i < m; i++)
//        scanf("%s", a[i]);
//
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (a[i][j] == '@')
//            {
//                sx = i;
//                sy = j;
//            }
//            if (a[i][j] == '+')
//            {
//                ans_x = i;
//                ans_y = j;
//            }
//        }
//    }
//	for (int i = 0; i < ROWCOL; i++)
//		for (int j = 0; j < ROWCOL; j++)
//			for (int k = 0; k <= 10; k++)
//				dist[i][j][k] = -1;
//
//    bfs(sx, sy);
//
//    return 0;
//}


//#include<stdio.h>
//#include<stdbool.h>
//#include<string.h>
//
//#define ROWCOL 2001
//int n, m;
//int sx, sy;
//int ans_x, ans_y;
//char a[ROWCOL][ROWCOL];
//int dist[ROWCOL][ROWCOL][2];
//int dx[4] = {1, 0, -1, 0 };
//int dy[4] = {0, 1, 0, -1 };
//
//struct node
//{
//    int x, y, status;
//}queue[ROWCOL * ROWCOL];
//int front, rear;
//
//void push(int x, int y, int s)
//{
//    queue[rear].x = x;
//    queue[rear].y = y;
//    queue[rear].status = s;
//    rear++;
//}
//
//struct node pop()
//{
//    return queue[front++];
//}
//
//void bfs(int s, int d, int st)
//{
//    push(s, d, st);
//    dist[s][d][st] = 0;
//
//    while (front < rear)
//    {
//        struct node pre = pop();
//
//        int x = pre.x, y = pre.y, pre_s = pre.status;
//        //printf("%d %d %d %d\n",dist[x][y][pre_s], x, y, pre_s);
//        if (x == ans_x && y == ans_y && pre_s)
//            return;
//
//        for (int i = 0; i < 4; i++)
//        {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//
//            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#')
//            {
//                if (pre_s == 0)
//                {
//                    if (a[nx][ny] == 'P' && dist[nx][ny][1] == -1)
//                    {
//                        dist[nx][ny][1] = dist[x][y][0] + 1;
//                        push(nx, ny, 1);
//                    }
//
//                    if (dist[nx][ny][0] == -1)
//                    {
//                        dist[nx][ny][0] = dist[x][y][0] + 1;
//                        push(nx, ny, 0);
//                    }
//                }
//				else if (pre_s == 1 && dist[nx][ny][1] == -1)
//                {
//                    dist[nx][ny][1] = dist[x][y][1] + 1;
//                    push(nx, ny, 1);
//                }
//            }
//        }
//    }
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);
//
//    for (int i = 0; i < n; i++)
//        scanf("%s", a[i]);
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (a[i][j] == 'S')
//            {
//                sx = i;
//                sy = j;
//            }
//
//            if (a[i][j] == 'T')
//            {
//                ans_x = i;
//                ans_y = j;
//            }
//        }
//    }
//    for(int i = 0;i <ROWCOL;i++)
//		for (int j = 0; j < ROWCOL; j++)
//			dist[i][j][0] = dist[i][j][1] = -1;
//
//    bfs(sx, sy, 0);
//
//   /* for (int i = 0; i < ROWCOL; i++)
//        for (int j = 0; j < ROWCOL; j++)
//            printf("%d\n", dist[i][j][1]);*/
//
//    printf("%d", dist[ans_x][ans_y][1]);
//    return 0;
//}




// 
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//#define ROWCOL 2001
//int n, m;
//char a[ROWCOL][ROWCOL];
//int dist[ROWCOL][ROWCOL][2];  // 0:未拿钥匙, 1:已拿钥匙
//int dx[4] = { 0, 1, -1, 0 };
//int dy[4] = { 1, 0, 0, -1 };
//
//struct Node {
//    int x, y;
//    int status;  // 当前状态:0/1
//} q[8000000];    // 队列大小 = 2 * n * m
//int front, rear;
//
//int main() {
//    scanf("%d%d", &n, &m);
//    int sx = 0, sy = 0, tx = 0, ty = 0;
//
//     读取地图并定位关键位置
//    for (int i = 0; i < n; i++) {
//        scanf("%s", a[i]);
//        for (int j = 0; j < m; j++) {
//            if (a[i][j] == 's') {
//                sx = i;
//                sy = j;
//            }
//            else if (a[i][j] == 'T') {
//                tx = i;
//                ty = j;
//            }
//        }
//    }
//
//     初始化距离为-1 (未访问)
//    memset(dist, -1, sizeof(dist));
//    front = rear = 0;
//
//     起点入队 (状态0)
//    dist[sx][sy][0] = 0;
//    q[rear].x = sx;
//    q[rear].y = sy;
//    q[rear].status = 0;
//    rear++;
//
//    while (front < rear) {
//        int x = q[front].x;
//        int y = q[front].y;
//        int s = q[front].status;
//        front++;
//
//         已拿钥匙且到家：输出答案
//        if (s == 1 && x == tx && y == ty) {
//            printf("%d\n", dist[x][y][1]);
//            return 0;
//        }
//
//        for (int i = 0; i < 4; i++) {
//            int nx = x + dx[i], ny = y + dy[i];
//
//             边界和障碍检查
//            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#')
//                continue;
//
//             状态0处理 (未拿钥匙)
//            if (s == 0) {
//                 遇到钥匙：生成新状态1
//                if (a[nx][ny] == 'p' && dist[nx][ny][1] == -1) {
//                    dist[nx][ny][1] = dist[x][y][0] + 1;
//                    q[rear].x = nx;
//                    q[rear].y = ny;
//                    q[rear].status = 1;
//                    rear++;
//                }
//                 继续状态0 (无论是否钥匙)
//                if (dist[nx][ny][0] == -1) {
//                    dist[nx][ny][0] = dist[x][y][0] + 1;
//                    q[rear].x = nx;
//                    q[rear].y = ny;
//                    q[rear].status = 0;
//                    rear++;
//                }
//            }
//             状态1处理 (已拿钥匙)
//            else if (s == 1 && dist[nx][ny][1] == -1) {
//                dist[nx][ny][1] = dist[x][y][1] + 1;
//                q[rear].x = nx;
//                q[rear].y = ny;
//                q[rear].status = 1;
//                rear++;
//            }
//        }
//    }
//     理论上题目保证有解，这里添加安全返回
//    return 0;
//}
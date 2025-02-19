#include<iostream>
using namespace std;

int n;

//�������� 
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int pos;//��¼λ��

const int N = 10;
int arr[N][N]; 

int main()
{
	cin >> n;
	
	//����
	int x = 1, y = 1; 
	int num = 1;
	
	while(num <= n * n)
	{
		arr[x][y] = num++;
		int a = x + dx[pos];
		int b = y + dy[pos];
		
		//������
		if(a > n || a < 1 || b > n || b < 1 || arr[a][b])
		{
			pos = (pos + 1) % 4;
		} 
		x = x + dx[pos];
		y = y + dy[pos];
	}
	
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			printf("%3d",arr[i][j]);
		}
		cout << endl;
	}
	return 0;
}

 

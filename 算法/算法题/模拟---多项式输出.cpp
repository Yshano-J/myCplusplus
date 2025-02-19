#include<iostream>

using namespace std;

int n;

int main()
{
	cin >> n;
	for(int i = n;i>=0;i--)
	{
		int x; cin >> x;
		if(x > 0)
		{
			if(i != n) cout << "+";
		}
		else if(x < 0)
			cout << "-";
		else
			continue;
		
		x = abs(x);
		if(x != 1 || (x == 1 && i == 0)) cout << x;
		
		if(i == 1)cout << "x";
		else if (i == 0) continue;
		else cout << "x^" << i;
	}
	return 0;
}

//int main()
//{
//	cin >> n;
//	int j = n; 
//	for(int i = 0;i <= n;i++)
//	{
//		int t;
//		cin >> t;
//		
//		if(t > 0)
//		{
//			if(i > 0)
//		   		cout << "+";
//		}
//		else if(t == 0)
//		{
//			j--;
//			continue;
//		}
//			
//			
//		if(t == 1)
//		{
//			if(j == 1)
//				cout << "x";
//			else if(j == 0)
//			{
//				cout << t;	
//				break;
//			}
//			else
//				cout << "x^" << j;
//		}
//		else if(t == -1)
//		{
//			if(j == 1)
//				cout << "x";
//			else if(j == 0)
//			{
//				cout << t;	
//				break;
//			}
//			else
//				cout << "-" << "x^" << j;
//		}
//		else
//		{
//			if(j == 1)
//				cout << t << "x" ;
//			else if(j == 0)
//			{
//				cout << t;	
//				break;
//			}
//			else
//				cout << t << "x^" << j;
//		}
//		j--;
//	}
//	return 0;
// } 

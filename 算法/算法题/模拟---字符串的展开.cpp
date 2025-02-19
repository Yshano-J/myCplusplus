#include<iostream>
#include<string>
#include<algorithm>
 
using namespace std;
 
int p1, p2, p3, n;
string ret;
string s;

bool isSame(char left, char right)
{
	return ((left >= '0' && left <='9' && right >= '0' && right <= '9')
		||(left >= 'a' && left <='z' && right >= 'a' && right <= 'z'));
}

void unfold(char left, char right)
{
	string tmp;
	for(char t = left + 1;t < right;t++)
	{
		char ch = t;
		if(p1 == 2) 
		{ 
			if(ch >= 'a' && ch <= 'z')
			{
				ch = ch - 32;
			}
		}
		else if(p1 == 3)
		{
			ch = '*';
		}
		
		for(int i = 0;i < p2;i++)
		{
			tmp += ch;
		}
	}	
	
	if(p3 == 2) reverse(tmp.begin(),tmp.end());
	ret += tmp;
}

int main()
{
	cin >> p1 >> p2 >> p3 >> s;
	n = s.size();
	for(int i = 0;i < n;i++)
	{
		char ch = s[i];
		
		//判断是否为减号
		if(ch != '-' || i == 0 || i == n - 1) ret += ch;
		else
		{
			char left = s[i - 1], right = s[i + 1];	
			//判断是否展开
			if(isSame(left, right) && left < right)
			{
				//展开
				unfold(left, right); 
			} 
			else
				ret += ch;
		} 
	}
	cout << ret << endl;
	return 0;
 } 

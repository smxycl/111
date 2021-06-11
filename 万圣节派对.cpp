//真·门票的排列规则有些奇怪：
//门票号是由0~6组成的六位数（0~6这几个数字可重用）
//每一个门票号的每一位不能有三个连续相同的数字
//每一个门票号相邻的两位相差必须在四以下（≤4）
#include<stdio.h>
#include<math.h>

int ch1, ch2;//全局变量，保存原始输入数据，即为题中的x和y
int s[7];//全局变量，保存x到y之间的每个数字分离出的每一位

//分离x到y之间的每个数字
void Fl(int x)
{
	for (int i = 5; i >= 0; i--)
	{
		s[i] = x % 10;
		x /= 10;
	}
}
//判断是否含有大于6的数字，如果有，返回0，否则返回1
bool Isliu(int x)
{
	for (int i = 0; i < 6; i++)
		if (s[i] > 6)
			return false;
	return true;
}
//判断是否存在3个连续相等的数字，如果有，返回0，否则返回1
bool Islx(int x)

{
	for (int i = 0; i < 4; i++)//一共六位数字，当i = 3，i + 2 = 5,可判断到最后一位
	{
		if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
			return false;
	}
	return true;
}
//判断是否存在相邻的数字之差大于4，如果有，返回0，否则返回1
bool Isxx(int x)
{
	for (int i = 0; i < 5; i++)
	{
		if (fabs(s[i] - s[i + 1]) > 4)
			return false;
	}
	return true;
}
int main()
{
	int max, min;//保存上下限
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d", &ch1, &ch2);
		//scanf("%s %s",ch1,ch2);
		//printf("%s %s\n",ch1,ch2);
		//min = (ch1[0] - '0') * 100000 + (ch1[1] - '0') * 10000 + (ch1[2] - '0') * 1000 + (ch1[3] - '0') * 100 +(ch1[4] - '0') * 10 + (ch1[5] - '0') * 1;
		//max = (ch2[0] - '0') * 100000 + (ch2[1] - '0') * 10000 + (ch2[2] - '0') * 1000 + (ch2[3] - '0') * 100 +(ch2[4] - '0') * 10 + (ch2[5] - '0') * 1;
		//printf("%d %d\n",max,min);
		for (int j = ch1; j <= ch2; j++)
		{
			Fl(j);//分离出每一位数字
			if (Isxx(j) && Islx(j) && Isliu(j)) {//同时满足三个条件
				for (int k = 0; k < 6; k++)
					printf("%d", s[k]);
				printf("\n");
			}
		}
	}
	return 0;
}

#include <stdio.h>
#include<string.h>
#include<math.h>
double bao()
{
	char wowotou[101];
	double yikuaiqian = 0;
	char* s;
	int ddd = 0;
	gets_s(wowotou, 101);
	s = wowotou;
	if (*s != '\0' && strlen(s) <= 100)
	{
		for (; *s != '\0'; s++)
		{
			if (*s == '.') ddd++;
			if ((*s != '.' && (*s < '0' || *s>'9')) || ddd > 1)
			{
				printf("\033[41;33mThis is not a number because it contains some  non-numeric symbols, or this number < 0. Pleaze enter a correct number again.\033[0m\n");
				return bao();
			}
		}
		int d;//d:小数点前长度,e:小数点后长度
		for (s = wowotou, d = -1; *s != '.' && *s != '\0'; d++, s++);
		for (s = wowotou; *s != '\0'; d--, s++)
		{	
			if (*s=='.') s++;
			yikuaiqian += ((double)*s - '0') * pow(10, d);
		}
		return yikuaiqian;
	}
	else
	{
		printf("\033[41;33mThis number is out of range. Pleaze enter a number that between 0 and 1000.\033[0m\n");
		return bao();
	}	
}
double kao(double heihei)
{
	if (heihei >= 1000 || heihei <= 0)
	{	
		printf("\033[41;33mThis number is out of range. Pleaze enter a number that between 0 and 1000.\033[0m\n");
		return kao(bao());
	}
	return heihei;
}
void cao(double y)
{
	int z;
	double x;
	z = (int)y;
	x = y - z;
	printf("The Hexadecimal of %lf is %x.", y, z);
	if (x == 0) printf("000000");
	for (int j = 0, u = 0; j < 6 && x != 0; j++)
	{
		x *= 16;
		u = (int)x;
		x -= u;
		if (u < 10)	 printf("%d", u);
		else if (u == 10) printf("a");
		else if (u == 11) printf("b");
		else if (u == 12) printf("c");
		else if (u == 13) printf("d");
		else if (u == 14) printf("e");
		else if (u == 15) printf("f");
	}
	printf("\nPress enter to continue.\n");
	getchar();
	system("cls");
}
int main()
{	
	system("color 16");
	printf("Please enter a number that bettwen 0 and 1000.\n");
	cao(kao(bao()));
	return main();
	return 0;
}
#include <stdio.h>
#include<string.h>
#include<math.h>
double bao()
{
	char wowotou[101];
	double yikuaiqian = 0;
	char* s= wowotou;
	gets_s(wowotou, 101);
	system("color 16");	system("cls");
	if (*s != '\0' && strlen(s) <= 100)
	{
		for (int ddd = 0; *s != '\0'; s++)
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
	if (heihei > 1000 || heihei < 0)
	{	
		printf("\033[41;33mThis number is out of range. Pleaze enter a number that between 0 and 1000.\033[0m\n");
		return kao(bao());
	}
	return heihei;
}
int cao(double y)
{	
	printf("The exadecimal of %lf is %x.", y, (int)y);
	char sige[10] = "000000", * p = sige;
	y -= (int)y;
	for (int j = 0, u = 0; j < 6 && y != 0; j++)
	{
		u = (int)(y *= 16);
		y -= u;
		if (j == 5 && (int)(y * 16) > 7)
			u++;
		if (u < 10)
			sige[j] += u;
		else
			sige[j] += u + 39;
	}
	printf("%s\nEnter another number to continue.\n",p);
	scanf_s("/*[^\n]/*c");
	return 0;
}
int main()
{	
	system("color 16");	system("cls");
	printf("Please enter a number that bettwen 0 and 1000.\n");
	return main(cao(kao(bao())));
	return 0;
}

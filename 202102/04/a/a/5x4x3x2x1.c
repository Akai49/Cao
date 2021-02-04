#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int fac(int a)
{
	if (a <= 1)
		return 1;
	else
		return a * fac(a - 1);
}
int main()
{
	int n = 0;
	int f = 0;
	scanf("%d", &n);
	f = fac(n);
	printf("f = %d\n", f);
	
	return 0;
}
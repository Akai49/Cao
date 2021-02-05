#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
//ì³²¨ÄÇÆõÊýÁÐ 1£¬1£¬2£¬3£¬5£¬8£¬13£¬21£¬34£¬55......
int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = fib(n);
	printf("ret =%d\n", ret);


	return 0;
}
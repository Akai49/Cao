#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//ÅÅÁÐÊý×é9£¬8£¬7£¬6£¬5£¬4£¬3£¬2£¬1£¬0
void ppz(int a[], int b)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < b-1; i++)
	{
		for (j = 0; j < b - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int i = 0;
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ppz(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}



	return 0;
}
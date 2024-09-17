# include <stdio.h>


int main()
{
	int x, y, d, c;
	scanf_s("%d", &x, &y);
	d = x / 60 + y;
	c = d / 60;
	printf("%d\n%d", d, c);
	return 0;
}
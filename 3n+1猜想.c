#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, step=0;
	scanf("%d", &n);
	if ((n <= 0) || (n > 1000))
		return 0;
	while (n != 1){
		if (n % 2)
			n = (3 * n + 1) / 2;
		else
			n /= 2;
		step++;
	}
	printf("%d\n", step);
	//system("pause");
	return 0;
}

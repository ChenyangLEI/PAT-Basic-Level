#include<stdio.h>
#include <stdlib.h> 
#include <math.h>

int IsSu(int i)
{	
	double d_i = i;
	int j=2;
	/*避免超时，用sqrt*/
	int sqrt_i = sqrt(d_i);
	while (j <= sqrt_i){
		if (i % j == 0)	return 0;
		j++;
	}
	return 1;
}

int main(){
	int n, i, j;
	int last_su = 3, su;
	int count = 0;
	scanf("%d", &n);
	if (n <= 3)
		printf("0\n");
	else{
		for (i = 4; i <= n; i++){
			if (IsSu(i)){
				if (i - last_su == 2) count++;
				last_su = i;
			}
		}
		printf("%d\n", count);
	}
	system("pause");
	return 0;
}
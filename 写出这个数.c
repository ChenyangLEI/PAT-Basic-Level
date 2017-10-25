#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c = '0';
	int n, count = 0;
	int reverse_count = 0;
	int zero_flag = 0;
	char * hanyu[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

	while (c != '\n'){
		c = getchar();
		if (c != '\n')
			count = count + (c - '0');
	}

	if ((count % 10) == 0)
		zero_flag = 1;
	while (count != 0){
		reverse_count = reverse_count * 10 + (count % 10);
		count /= 10;
	}

	while (reverse_count != 0){
		printf("%s", hanyu[reverse_count % 10]);
		reverse_count /= 10;
		if ( !((!zero_flag)&&(reverse_count==0)))
			printf(" ");
	}

	if (zero_flag)
		printf("%s", hanyu[0]);

	system("pause");
	return 0;
}


/*代码2*/
#include<stdio.h>
#include <stdlib.h> 
#include <string.h>
void printf_num(int num)
{
	int zonghe[10];
	char *name[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi" };
	int i = 0;
	for (i = 0; num >= 10; i++){
		zonghe[i] = num % 10;
		num = num / 10;
	}
	zonghe[i++] = num;
	while (i--){
		if (i != 0){
			printf("%s ", name[zonghe[i]]);
		}
		else{
			printf("%s\n", name[zonghe[i]]);
		}
	}
}

int main(){
	char n[100];
	char *p = n;
	int sum = 0;
	int i = 0;

	scanf("%s", n);

	while (*p != '\0'){
		sum = sum + (*p - '0');  //（*p - '0'）将字符型数字转化为整型数字
		p++;
	}
	printf_num(sum);
	system("pause");
	return 0;
}
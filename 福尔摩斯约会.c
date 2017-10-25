/*Count Prime*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*The 1st same high-case English character*/
int GetDay(char a[], char b[])
{
	int idx = 0;
	int len, len_a, len_b;
	len_a = strlen(a);
	len_b = strlen(b);
	len = (len_a < len_b) ? len_a : len_b;
	while (idx < len){
		if ((a[idx] >= 'A') && (a[idx] <= 'G')){
			if (a[idx] == b[idx]) return a[idx] - 'A';
		}
		idx++;
	}
	return 0;
}

/*The second charater: 0-9, A-N*/
int GetHour(char a[], char b[])
{
	int idx = 0;
	int count = 0;
	int len, len_a, len_b;
	len_a = strlen(a);
	len_b = strlen(b);
	len =  (len_a < len_b)? len_a : len_b;
	while (idx < len){
		if ((a[idx] >= 'A') && (a[idx] <= 'G')){
			if (a[idx] == b[idx]) break;
		}
		idx++;
	}
	idx++;
	while (idx < len){
		if (a[idx] == b[idx]) {
			if (a[idx] >= 'A' && a[idx] <= 'N') 
				return a[idx] - 'A' + 10;
			else if (a[idx] >= '0' && a[idx] <= '9') 
				return a[idx] - '0';
		}
		idx++;
	}
	/*
	while (idx < len){
		if (a[idx] == b[idx]) {
			if (a[idx] >= 'A' && a[idx] <= 'N') {
				count++;
				if (count == 2) return a[idx] - 'A' + 10;
			}
			else if (a[idx] >= '0' && a[idx] <= '9') {
				count++;
				if (count == 2) return a[idx]-'0';
			}
		}
		idx++;
	}*/
	return -1;
}

/*The position of 1st same English character*/
int GetMin(char a[], char b[])
{
	int idx = 0;
	int len, len_a, len_b;
	len_a = strlen(a);
	len_b = strlen(b);
	len = (len_a < len_b) ? len_a : len_b;
	while (idx < len){
		if ((a[idx] >= 'A' && a[idx] <= 'Z') || (a[idx] >= 'a' && a[idx] <= 'z')){
			if (a[idx] == b[idx]) return idx;
		}
		idx++;
	}
	return 0;
}
int main(void)
{
	char *Days[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	char str[4][61];
	for (int i = 0; i < 4; i++)
		gets(str[i]);
	int Day, Hour, Min;
	Day = GetDay(str[0], str[1]);
	Hour = GetHour(str[0], str[1]);
	Min = GetMin(str[2], str[3]);
//	printf("%d, %d, %d", Day, Hour, Min);
	printf("%s ", Days[Day]);
	if (Hour < 10) 	printf("0%d:", Hour);
	else printf("%d:", Hour);

	if (Min < 10) printf("0%d", Min);
	else printf("%d", Min);
	system("pause");
	return 0;
}


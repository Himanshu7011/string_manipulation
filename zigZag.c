#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * To show the string in ZIG ZAG fasion based on number of raws given as input.
 *
 * Input string: abcdefghijk
 *
 * ----------------------------
 *	a   e   i
 *	b d f h j      num = 3
 *	c   g   k
 * ----------------------------
 *	a c e g i k    num = 2
 *	b d f h j
 * ----------------------------
 *
 */

void zigZag(char *ptr, int num) {

	char *temp = NULL;	
	char arr[num][50];
	int x = 0, flag = 0;
	memset(arr, 0, sizeof(arr));
	while(*ptr) {
		if(!flag) {
			strncat(arr[x], ptr, 1);
			if(++x == (num-1))
				flag = 1;
			ptr++;
		} else {
			strncat(arr[x], ptr, 1);
			if(--x == 0)
				flag = 0;	
			ptr++;
		}
	}

	for(x = 0; x < num; x++)
		printf("RAW[%d] :: %s\n", x, arr[x]);
}

int main() {

	char *str = "Thisisasamplegeeksforgeeksprogram";
	int num = 5;
	zigZag(str, num);
}

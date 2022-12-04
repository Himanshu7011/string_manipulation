#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/* Set the bit in array based on character value. */
void fillArray(int *a, char ch){
	
	if(ch >= 65 && ch <= 90) {
		ch = ch - 65;
		a[ch] = a[ch] | 1;
	} else if(ch >= 97 && ch <= 122) {
		ch = ch - 97;
		a[ch] = a[ch] | 1;
	}
}

/* 
 * Check if the bit is set or not, if set return false.
 * 
 * Return Value: 
 * False - If [ch] bit is set.
 * True - If [ch] bit is clear.
 *
 */
bool checkArray(int *a, char ch) {

	if(ch >= 65 && ch <= 90) {
		ch = ch - 65;
		if(a[ch] & 1)
			return false;
		else
			return true;
	} else if(ch >= 97 && ch <= 122) {
		ch = ch - 97;
		if(a[ch] & 1)
			return false;
		else
			return true;
	}
}

/* main() to find largest substring will repetition */
int main(){
	int array[26];
	int i, j, subCount = 0;
	char *str = "abcabcabc";
	memset(array, 0, 26);
	for(i=0; i<strlen(str); i++) {
		for(j=i;j<strlen(str); j++) {
			if(str[i] == str[j]) {
				if(checkArray(array, str[j]))
					subCount++;
				fillArray(array, str[j]);
			} 
		}
	}
	printf("Largest sub-string length = %d\n", subCount);
}

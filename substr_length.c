#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void fillArray(int *a, char ch){
	
	if(ch >= 65 && ch <= 90) {
		ch = ch - 65;
		a[ch] = a[ch] | 1;
	} else if(ch >= 97 && ch <= 122) {
		ch = ch - 97;
		a[ch] = a[ch] | 1;
	}
}

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

int main(){

	int array[26];
	int len = 0;
	int subStrCount = 0;
	int i,j;
	char *str = "abcdjfghjfabcd";
	int subCount = 0, big = 0;
	int temp = 0;
	bool tf;
	memset(array, 0, 26);
	for(i=0; i<strlen(str); i++) {
		temp = i;
		for(j=i;j<strlen(str); j++) {
			if(str[temp] == str[j]) {
				if(checkArray(array, str[j]))
					subCount++;
				fillArray(array, str[j]);
			} 
		}
	}
	printf("Biggest sub string length = %d\n", subCount);
}

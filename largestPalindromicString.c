#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/* Calculate the length of Palindromic string. */
int lenCalculator(char *front, char *back) {
	int len = 0;
	while(front != back) {
		len++;
		back++;
	}
	return len;
}

/* Check if the string is in Palindrome pattern or not.*/
int palindromicCheck(char *front, char *back) {
	
	int len = 0;
	while(front >= back) {
		if(*front == *back) {
			if(!len)
				len = lenCalculator(front, back);
			front--;
			back++;
		} else {
			len = -1;
			return len;
		}
	}
	/* Return (len + 1) becuase one character is always remain uncounted. */
	return(len + 1);
}

/* main() to find largest palindromic string */
int main(){
	int i, j, plen = 0, oldLen = 0;
	char *str = "abccbaabccba";
	char *front = str + 1, *back = str;

	for(i=0; i<strlen(str); i++) {
		for(j=i+1; j<strlen(str); j++) {
			if(str[j] == str[i])
				plen = palindromicCheck(&str[j], &str[i]);
		}
		if(oldLen < plen)
			oldLen = plen;
	} 
	printf("\nLargest palindromic string length is %d\n", oldLen);
	printf("------------ END ------------\n\n");
}

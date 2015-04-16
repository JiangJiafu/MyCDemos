#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char args[]) 
{
	char str1[8] = "Python";
	char str2[6] = "Perl";
  
	printf("str1 is %s.\n", str1);
	printf("str2 is %s.\n", str2);
	printf("\n");

	printf("length of str1 is %d.\n", strlen(str1));
	printf("length of str2 is %d.\n", strlen(str2));

	// connect two strings
	// It is unsafe to use strcat or strncat, use snprintf instead.
	// For example the code below is very dangerous.
	// strncat(str1, str2, sizeof(str1) - strlen(str1));
	// The safe way should be:
	// strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);
	char str3[8];
	snprintf(str3, sizeof(str3), "%s%s", str1, str2);
	printf("str3 is %s.\n", str3);
	
	// compare two strings
	char *str4 = "abc";
	char *str5 = "abd";
	printf("str4 is %s.\n", str4);
	printf("str5 is %s.\n", str5);
	printf("strcmp(str4, str5) is %d.\n", strcmp(str4, str5));

	return 0;
}

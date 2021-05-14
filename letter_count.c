#include <stdio.h>
int main(int argc, char const *argv[]){
	char str[20];
	int letter=0;
	int vowel=0;
	int i=0;

	printf("Please enter a string: ");
	scanf("%[^\n]s",str);
	
	while(str[i]!='\0'){
		if ((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))
			letter++;
		if (str[i]==65 || str[i]==97 || 
			str[i]==69 || str[i]==101 ||
			str[i]==73 || str[i]==105 ||
			str[i]==79 || str[i]==111 ||
			str[i]==85 || str[i]==117 )
			vowel++;
		i++;
	}
	printf("Total consonants found: %d\n",(letter-vowel));
	printf("Total vowels found: %d\n",vowel);

	return 0;
}
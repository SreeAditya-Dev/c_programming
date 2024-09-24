// C
#include <stdio.h>
#include <string.h>

int main() {
	char text[200];
    scanf("%[^\n]%*c", text);
	int len = strlen(text);
    printf("%d",len);
    fgets(text, sizeof(text), stdin);
    printf("%s",text);

	for (int i = 0; i < len; i++) {
		printf("%c\n", text[i]);
	}

	return 0;
}

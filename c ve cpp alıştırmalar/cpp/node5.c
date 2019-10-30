#include <stdio.h>
#include <string.h>

struct n{

	int x;
	char y;
	float z;
	char t[10];
}root;

int main()
{

	char d[10], k;
	struct n root;

	scanf("%d", &root.x);

	root.y = 'G';

	scanf("%f", &root.z);

	scanf("%s", d);
	strcpy(root.t, d);

	scanf("%c", &k);

	printf("%d %c %.2f %s %c\n", root.x, root.y, root.z, root.t, k);
}

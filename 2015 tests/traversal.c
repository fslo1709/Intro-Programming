#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n, m, pointx, pointy;
	while (scanf("%d %d %d %d",&n, &m, &pointx, &pointy) != EOF) {
		printf("%d %d\n", pointx, pointy);
		for (int i = 0; i < n*m; i++) {
			if (!(pointx) && pointy)
				pointy--;
			else
				if (pointx && !(pointy^m-1))
					pointx--;
				else
					if (!(pointy&1) && pointx < n-1)
						pointx++;
					else
						if (pointy&1 && pointx > 1)
							pointx--;
						else
							pointy++;
			printf("%d %d\n", pointx, pointy);
		}
	}
	return 0;
}
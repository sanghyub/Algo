#include<cstdio>
#include<cstring>
int main() {
	char buffer[110];
	while (fgets(buffer, 102, stdin) != NULL) {
		int so = 0, dae = 0, num = 0, blank = 0;
		for (int i = 0; i < strlen(buffer); i++) {
			if (buffer[i] >= 'a' && buffer[i] <= 'z') so++;
			else if (buffer[i] >= 'A' && buffer[i] <= 'Z') dae++;
			else if (buffer[i] >= '0' && buffer[i] <= '9') num++;
			else if (buffer[i]==' ')blank++;
		}
		printf("%d %d %d %d\n", so, dae, num, blank);
	}
}
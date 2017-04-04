#include<cstdio>
#include<cstring>
char s[51];
int main() {
	scanf("%s", s);
	int num = 0, sum = 0;
	bool minusFlag = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			if (num == 0) 	num += s[i] - '0';
			else num = num * 10 + s[i] - '0';
		}
		else if (s[i] == '+') {
			if (minusFlag == 1)  sum += (-1)*num;
			else sum += num;
			num = 0;
		}
		else if(s[i]=='-'){
			if(minusFlag==1)sum += (-1)*num;
			else sum += num;
			minusFlag = 1;
			num = 0;
		}
	}
	if (minusFlag) sum += (-1)*num;
	else sum += num;
	printf("%d", sum);
}
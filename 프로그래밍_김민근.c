#include <stdio.h>
#include <termio.h>
#include <stdlib.h>
#include <time.h>
int getch(void) { //getch 함수
	int ch;
	struct termios buf;
	struct termios save;
	tcgetattr(0, &save);
	buf = save;
	buf.c_lflag &= ~(ICANON | ECHO );
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch = getchar();
	tcsetattr(0, TCSAFLUSH, &save);
	return ch;
}

void main(){
	char a[100] = "I like a banana.";
	char b[100];
	int cnt = 0, cnt2 = 0, pgs = 0, ct = 0, ht = 0, acc = 0, wl = 0, n;
	// pgs = 진행도, ct = 현재타수, ht = 최고타수, acc = 정확도, wl = 오타

	while(1){
		printf(">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
		printf("진행도 : %d%%, 현재타수 : %d%%, 최고타수 : %d%%, 정확도 : %d%%\n", pgs, ct, ht, acc);
		for (int i = 0; a[i] != '\0'; i++)
			printf("%c", a[i]);
		printf("\n");
		for (int i = 0; i <= cnt2; i++)
			printf("%c", b[i]);
		b[cnt2] = getch();

		if (b[cnt2] == '\n')
			break;
		if (b[cnt2] == 127)
			cnt2 = cnt2 - 2;
		if (cnt2 < 0)
			cnt2 = -1;
		
		cnt2++;
		system("clear");
		printf("\n");
	}
}

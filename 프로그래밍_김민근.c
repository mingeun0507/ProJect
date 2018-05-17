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
		printf("진행도 : %d%%, 현재타수 : %d%%, 최고타수 : %d%%, 정확도 : %d%%\n", 
				pgs, ct, ht, acc);
		for (int i = 0; a[i] != '\0'; i++) // a 배열 출력
			printf("%c", a[i]);
		printf("\n"); //개행
			wl = 0; // 오타 개수 초기화
		for (int i = 0; i < cnt2; i++){
			printf("%c", b[i]); // b 배열 출력
		}
		b[cnt2] = getch(); // getch 함수를 통해 b 배열에 저장
		if (b[cnt2] == '\n') // 개행 입력시 반복문 나감
			break;
		if (b[cnt2] == 127) // 백스페이스 구현
			cnt2 = cnt2 - 2;
		for (int i = 0; i <= cnt2; i++)
				if (b[i] != a[i]) // a 배열과 b 배열 비교를 통해 오타 개수 체크
					wl++;	
		
		if (cnt2 >= 0) 
			acc = (double) (cnt2 + 1 - wl) / (cnt2 + 1) * 100; // 정확도 구현
		else{
			acc = 0; // 입력한 개수가 0이면 정확도는 0
			cnt2 = -1; //cnt2 값 음수 안되게 설정
		}
		
		
		
		cnt2++;
		system("clear"); //화면 지우기
	}
}

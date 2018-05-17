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
	char a[][30] = {"I like A.", "I like B.", "I like C.", "I like D.", "I like E.", "I like F.", "I like G.", "I like H.", "I like I.", "I like J.", "I like K.", "I like L.", "I like M.", "I like N.", "I like O.", "I like P.", "I like Q.", "I like R.", "I like S.", "I like T.", "I like U.", "I like V.", "I like W.", "I like X.", "I like Y.", "I like Z.", "I like a.", "I like b.", "I like c.", "I like d."};
	char b[30];
	int cnt = 0, cnt2 = 0, pgs = 0, ct = 0, ht = 0, acc = 0, wl = 0, n, x, q;
	// pgs = 진행도, ct = 현재타수, ht = 최고타수, acc = 정확도, wl = 오타
	
	srand(time(NULL)); // 킬 때마다 랜덤 바뀌게 하기
	while(1){ 
		x = rand() % 29; // 랜덤 배정
		for (int i = 0; i <= 30; i++) // b 배열 초기화
			b[i] = '\0'; 
		while(1){
			printf(">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n"); 
			printf("진행도 : %d%%, 현재타수 : %d%%, 최고타수 : %d%%, 정확도 : %d%%\n", 
					pgs, ct, ht, acc);
			for (int i = 0; a[x][i] != '\0'; i++) // a 배열 출력
				printf("%c", a[x][i]);
			printf("\n"); //개행
			for (int i = 0; i < cnt2; i++)
				printf("%c", b[i]); // b 배열 출력
			b[cnt2] = getch(); // getch 함수를 통해 b 배열에 저장
			if (b[cnt2] == '\n') // 개행 입력시 반복문 나감
				break;
			if (b[cnt2] == 127) // 백스페이스 구현
				cnt2 = cnt2 - 2;
			wl = 0; // 오타 개수 초기화
			for (int i = 0; i <= cnt2; i++)
				if (b[i] != a[x][i]) // a 배열과 b 배열 비교를 통해 오타 개수 체크
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
		acc = 0, cnt2 = 0; //정확도 및 b 배열 카운트 초기화
		pgs+= 20; // 진행도 증가
	}
		
		
	
}

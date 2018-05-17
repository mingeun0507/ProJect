#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
/*	리눅스 getch()
#include <term.h>  
#include <termios.h>  
#include <unistd.h>  
*/
#define TRUE 1
#define FALSE 0

void clearBuffer();		// 버퍼 정리
int menu();			// 메뉴
void spacePractice();		// 자리 연습
void wordPractice();		// 단어 연습

void shortScript();		// 짧은글 연습
//void longScript();		// 긴글 연습
/*
int getch(void)
{
	int ch;
	struct termios buf;
	struct termios save;

	tcgetattr(0, &save);
	buf = save;
	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch = getchar();
	tcsetattr(0, TCSAFLUSH, &save);
	return ch;
}
*/					// 리눅스 getch()


int main(void)
{
	while (menu() != FALSE);
	return 0;
}

void clearBuffer()
{
	while (getchar() != '\n');
}

int menu()
{
	int input;
	//system("clear");	// 리눅스 clear	
	system("cls");
	
	printf(">> 영문 타자 연습 프로그램 <<\n");
	printf("1) 자리 연습	2) 낱말 연습\n\
3) 짧은 글 연습	4) 긴 글 연습\n\
5) 프로그램 종료\n\n\
번호를 선택하세요: ");
	scanf("%d", &input);
	clearBuffer();
	
	switch (input)
	{
	case 1:
		spacePractice();
		return TRUE;
	case 2:
		wordPractice();
		return TRUE;
	case 3:
		//shortScript();
		return TRUE;
	case 4:
		//longScript();
		return TRUE;
	case 5:
		return FALSE;
	}
}

void spacePractice()
{
	int word, how, wrong, acc, insert;
	char input;
	wrong = how = insert = acc = 0;
	while (how <= 20)
	{
		srand(time(NULL));
		word = (rand() % 58) + 65;
		if (word >= 91 && word <= 96)
			continue;
		while (1)
		{
			input = 0;
			if (insert != 0)
				acc = 100 - (100 * wrong / insert);
			//system("clear");	// 리눅스 clear	
			system("cls");
			printf(">> 영문 타자 연습 프로그램 : 자리 연습 <<\n");
			printf("진행도 : %d%%	오타수 : %d		정확도 : %d%%\n\n", (how * 100 / 20), wrong, acc);
			printf("%c\n-\n", word);
			input = getch();
			insert++;
			if ((int)input == word || (int)input == 27)
				break;
			else
				wrong++;
		}
		if (input == 27)
			break;
		how++;
	}
}

void wordPractice()
{
	int how, wrong, acc, insert, myWord;
	char *word[] = {"hello", "hi", "help"};
	char input[20] = { NULL };

	wrong = how = insert = acc = myWord = 0;
	
	while (how <= 20)
	{
		srand(time(NULL));
		myWord = (rand() % 3);
		while (1)
		{
			if (insert != 0)
				acc = 100 - (100 * wrong / insert);
			//system("clear");	// 리눅스 clear	
			system("cls");
			printf(">> 영문 타자 연습 프로그램 : 낱말 연습 <<\n");
			printf("진행도 : %d%%	오타수 : %d		정확도 : %d%%\n\n", (how * 100 / 20), wrong, acc);
			puts(word[myWord]); // 개행 수정
			fgets(input, sizeof(input), stdin);
			
			if (input[strlen(input) - 1] == '\n')
				input[strlen(input) - 1] = '\0';
			insert++;
			if ((!strcmp(input, word[myWord])) || (!strcmp(input, "###")))
				break;
			else
			{
				wrong++;
				break;
			}
		}
		if (!strcmp(input, "###"))
			break;
		how++;
	}
}

void shortScript()
{
	int how, wrong, acc, insert, myWord;
	wrong = how = insert = acc = myWord = 0;
	char input[100] = {NULL};
	char *sentence[30][] = {[0]="Hi my name is ABC", [1]="Hello I'm fine thank you", [2] = "I am a banana"};
	
	while (how <= 20)
	{
		while(1)
		{
			printf(">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
			printf("진행도 : %d%%	현재타수 : %d	최고타수 : %d	정확도 : %d%%\n\n", (how * 100 / 20), wrong, acc);

		}
		how++;
	}
}

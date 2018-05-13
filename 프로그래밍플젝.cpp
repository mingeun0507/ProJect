#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define TRUE 1
#define FALSE 0

void spacePractice();
//void wordPractice();
//void shortScript();
//void longScript();
int menu();

int main(void)
{
	while (menu() != FALSE);
	return 0;
}

int menu()
{
	int input;
	printf(">> 영문 타자 연습 프로그램 <<\n");
	printf("1) 자리 연습	2) 낱말 연습\n\
3) 짧은 글 연습	4) 긴 글 연습\n\
5) 프로그램 종료\n\n\
번호를 선택하세요: ");
	scanf("%d", &input);
	fflush(stdin);

	switch (input)
	{
		case 1:
			spacePractice();
			return TRUE;
		case 2:
			//wordPractice();
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
			if(insert != 0)
			acc = 100 - (100 * wrong / insert);
			//system("clear");
			printf(">> 영문 타자 연습 프로그램 : 자리 연습 <<\n");
			printf("진행도 : %d%%	오타수 : %d		정확도 : %d%%\n\n", (how*100/20), wrong, acc);
			printf("%c\n-\n", word);
			fflush(stdin);
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
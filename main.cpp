#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>

#if defined(__MINGW32__) || defined(_MSC_VER)
#define limpar_input() fflush(stdin)
#define clear() system("cls")
#else
#define limpar_input() __fpurge(stdin)
#define clear() system("clear")
#endif

#define LINE_NUMBER 100

bool is_digit_first_position(char string[]) {
	char digit[] = {string[0]};
	if(strcmp(digit, "3") == -1)
		return true;
	return false;
}

void get_questions(char questions[][100]) {
	FILE *file = fopen("questions.txt", "rt");
	int count=0;
	char line[LINE_NUMBER];
	char *result;
	for(int i=0; i<LINE_NUMBER; i++) {
		result = fgets(line, 100, file);
		if(is_digit_first_position(result)) {
			strcpy(questions[count], result);
			count++;
		}
	}
	fclose(file);
}

void get_responses(char responses[][100]) {
	FILE *file = fopen("questions.txt", "rt");
	int count=0;
	char line[LINE_NUMBER];
	char *result;
	for(int i=0; i<LINE_NUMBER; i++) {
		result = fgets(line, 100, file);
		if(!is_digit_first_position(result)) {
			strcpy(responses[count], result);
			count++;
		}
	}
	fclose(file);
}

int main() {
    setlocale(LC_ALL, "");
	char responses[80][100], questions[20][100], responses_users[20][2];
	int count_responses=0;

	printf("Salveeeeee");
	getchar();
	clear();
	printf("Bem vindo ao jogo de perguntas e respostas!\nAqui voce terá¡ que Responder a perguntas sobre o tema que você escolher\n");

	get_questions(questions);
	get_responses(responses);
	
	for(int i=0; i<20; i++) {
		printf("%s", questions[i]);
		for(int j=0; j<4; j++) {
			printf("\n%s", responses[count_responses]);
			count_responses++;
		}

		printf("\n\n");
		scanf("%s", responses_users[i]);
		clear();
	}
}

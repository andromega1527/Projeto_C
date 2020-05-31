#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>

#define LINE_NUMBER 100

bool is_digit_first_position(char string[]) {
	char digit[] = {string[0]};
	if(strcmp(digit, "3") == -1)
		return true;
	return false;
}

bool is_correct_response(char response[]) {
	char digit[] = {response[1]};
	if(strcmp(digit, "*") == 1)
		return true;
	return false;
}

char *clear_result(char result[]) {
	char character[]=" ";
	result[1] = character[0];
	return result;
}

void get_questions(char questions[][100]) {
	FILE *file = fopen("questions.txt", "rt");
	int count=0;
	char line[LINE_NUMBER], *result;
	for(int i=0; i<LINE_NUMBER; i++) {
		result = fgets(line, 100, file);
		if(is_digit_first_position(result)) {
			strcpy(questions[count], result);
			count++;
		}
	}
	fclose(file);
}

void get_responses(char responses[][100], char correct_responses[][100]) {
	FILE *file = fopen("questions.txt", "rt");
	int count=0, count_correct_responses=0;
	char line[LINE_NUMBER], *result;
	for(int i=0; i<LINE_NUMBER; i++) {
		result = fgets(line, 100, file);
		if(!is_digit_first_position(result)) {
			if(is_correct_response(result)) {
				result = clear_result(result);
				strcpy(correct_responses[count_correct_responses], result);
				count_correct_responses++;
			}
			strcpy(responses[count], result);
			count++;
		}
	}
	fclose(file);
}

void print_points(int points, int life) {
	printf("Você fez %d de 20000", points);
	if(life == 0)
		printf("\nMas infelismente você perdeu tudo, então até a próxima :)");
	else
		printf("\nVocê chegou ao final sem perder todas as suas vidas, PARABÉNS!!!");
	getchar();
}

int main() {
    setlocale(LC_ALL, "");
	char responses[80][100], questions[20][100], responses_users[20][2], correct_responses[20][100];
	int count_responses=0, life=3, points;

	printf("Salveeeeee");
	getchar();
	system("cls");
	printf("Bem vindo ao jogo de perguntas e respostas!\nAqui voce terá que Responder a perguntas sobre o tema que você escolher\n");
	getchar();
	system("cls");
	
	get_questions(questions);
	get_responses(responses, correct_responses);
	
	for(int i=0; i<20; i++) {
		printf("%s", questions[i]);
		for(int j=0; j<4; j++) {
			printf("\n%s", responses[count_responses]);
			count_responses++;
		}

		printf("\n\n");
		scanf("%s", responses_users[i]);
		system("cls");
		
		if(((char*)correct_responses[i])[0] != ((char*)responses_users[i])[0])
			life--;
		else
			points += 100;
			
		if(life==0) {
			printf("Suas vidas acabaram!");
			getchar();
			break;
		}
	}
	
	print_points(points, life);
}

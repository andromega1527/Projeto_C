#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "interface.cpp"

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
	char line[100], *result;
	for(int i=0; i<100; i++) {
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
	char line[100], *result;
	for(int i=0; i<100; i++) {
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

void get_tips(char tips[][500]) {
	FILE *file = fopen("tips.txt", "rt");
	char line[500], *result;
	for(int i=0; i<20; i++) {
		result = fgets(line, 500, file);
		strcpy(tips[i], result);
	}
	fclose(file);
}

void make_question(int count_responses, char responses[][100], char response_user[2], char question[100], int lifes, int points, int tips) {
	questions_interface(lifes, points, tips, (char*)"Digite uma das opções para continuar, ou digite help");
	printf("%s", question);
	for(int j=0; j<4; j++) {
		printf("\n%s", responses[count_responses]);
		count_responses++;
	}

	printf("\n\n");
	gets(response_user);
	system("cls");
}

void remake_question(int count_responses, char responses[][100], char response_user[2], char question[100], int lifes, int points, int tips) {
	system("cls");
	count_responses -= 4;
	make_question(count_responses, responses, response_user, question, lifes, points, tips);
}

bool is_request_for_help(char *response) {
	return strcmp(response, "help") == 0;
}

int main() {
	config_screen();
    setlocale(LC_ALL, "Portuguese");
	char responses[80][100], questions[20][100], response_user[20][5], correct_responses[20][100], tips[20][500];
	int count_responses=0, life=3, points, tips_number=2;
	bool help=true;
	
	init_interface();
	
	get_questions(questions);
	get_responses(responses, correct_responses);
	get_tips(tips);
	
	for(int i=0; i<20; i++) {
		help = true;
		make_question(count_responses, responses, response_user[i], questions[i], life, points, tips_number);
		count_responses += 4;
		
		while(is_request_for_help(response_user[i])) {
			if(tips_number != 0 && help == true) {
				tips_number--;
				questions_interface(life, points, tips_number, (char*)"Pressione enter para continuar");
				printf("\n\nDica: %s\n\n", tips[i]);
				getchar();
				remake_question(count_responses, responses, response_user[i], questions[i], life, points, tips_number);
				help = false;
			} else if(help == false && tips_number != 0) {
				print_tips_questions_end();
				remake_question(count_responses, responses, response_user[i], questions[i], life, points, tips_number);
			} else {
				print_all_tips_end();
				remake_question(count_responses, responses, response_user[i], questions[i], life, points, tips_number);
			}
		}
		
		if(((char*)correct_responses[i])[0] != ((char*)response_user[i])[0]) {
			life--;
			print_wrong();
			system("cls");
		} else {
			print_right();
			system("cls");
			points += 25;
		}
			
		if(life==0) {
			print_lifes_end();
			system("cls");
			break;
		}
	}
	
	print_points(points, life);
}

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <unistd.h>

#if defined(__MINGW32__) || defined(_MSC_VER)
#define limpar_input() fflush(stdin)
#define clear() system("cls")
#else
#define limpar_input() __fpurge(stdin)
#define clear() system("clear")
#endif

void get_questions(char questions[]) {
	FILE *file = fopen("questions.txt", "rt");
	char line[119];
	char *result = fgets(line, 119, file);
}

int main() {
    setlocale(LC_ALL, "");
	char responses[20], questions[20][4];

	printf("Salveeeeee");
	getchar();
	clear();
	printf("Bem vindo ao jogo de perguntas e respostas!\nAqui voce ter� que Responder a perguntas sobre o tema que voc� escolher");

	for(int i=0; i<20; i++) {
		printf("%s", questions[i]);
		for(int j=0; j<4; j++)
			printf("%s", questions[i][j]);
		scanf("%s", &responses);
	}
}
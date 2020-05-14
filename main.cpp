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

int main() {
    setlocale(LC_ALL, "");

	printf("Salveeeeee");
	getchar();
	clear();
	printf("Bem vindo ao jogo de perguntas e respostas!\nAqui voce terá que Responder a perguntas sobre o tema que você escolher");
	
	
}

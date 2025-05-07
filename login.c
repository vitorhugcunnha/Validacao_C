#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_LEN 50
#define MAX_USERS 100

typedef struct {
    char nome[MAX_LEN];
    char senha[MAX_LEN];
} Usuario;

Usuario usuarios[MAX_USERS];
int contador_usuario = 0;

void cadastro() {
    char nomeUsuario[MAX_LEN], senhaCadastro[MAX_LEN];

    if (contador_usuario >= MAX_USERS) {
        printf("Numero maximo de usuarios atingido!\n");
        return;
    }

    printf("----- Cadastro -----\n");
    printf("Nome de usuario: ");
    scanf("%s", &nomeUsuario);

    for (int i = 0; i < contador_usuario; i++) {
        if (strcmp(usuarios[i].nome, nomeUsuario) == 0) {
            printf("Usuario ja existe! Escolha outro nome.\n");
            return;
        }
    }

    printf("Senha: ");
    scanf("%s", &senhaCadastro);

    strcpy(usuarios[contador_usuario].nome, nomeUsuario);
    strcpy(usuarios[contador_usuario].senha, senhaCadastro);
    contador_usuario++;
    system("cls");

    printf("Cadastro realizado com sucesso!\n");
}

void login() {
    char usuarioLogin[MAX_LEN], senhaLogin[MAX_LEN];

    printf("----- Login -----\n");
    printf("Usuario: ");
    scanf("%s", &
    usuarioLogin);
    printf("Senha: ");
    scanf("%s", &senhaLogin);

    for (int i = 0; i < contador_usuario; i++) {
        if (strcmp(usuarios[i].nome, usuarioLogin) == 0 &&
            strcmp(usuarios[i].senha, senhaLogin) == 0) {
            system("cls");
            printf("Bem-vindo, %s.\n", usuarioLogin);
            return;
        }
    }

    system("cls");
    printf("Usuario ou senha incorretos!\n");
}

int main(int argc, char const *argv[]){

    int opcao;


    while (opcao != 4){
        printf("Escolha uma opcao!\n");
        printf("[1] - Criar Cadastro!\n");
        printf("[2] - Login!\n");
        printf("[3] - Sair!\n");
        scanf("%i", &opcao);

        switch (opcao){
        case 1:
            cadastro();
            break;
        case 2:
            login();
            break;
        case 3:
            printf("Saindo!");
            return 0;
        default:
            break;
        }
    }
        
    return 0;
}

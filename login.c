#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_leght  100
#define max_len  12
#define max_ema 50
#define max_usuarios 10

typedef struct {
    char usuario[max_leght];
    char senhas[max_len];
} usuarios;

usuarios usuario[max_usuarios];
int contador_usuario = 0;

void cadastro(){

    char senhaCadastro[max_len], nomeUsuario[max_leght], emailUsuario[max_ema];

    if(contador_usuario >= max_usuarios){
        printf("Numero maximo atingido!");
    }

    printf("-----Cadastro-----\n");
    printf("Nome de Usuario:\n");
    scanf("%s", &nomeUsuario);

    for (int i = 0; i < contador_usuario; i++) {
            if (strcmp(usuario[i].usuario, nomeUsuario) == 0) {
                printf("Usuario a existente! Troque de nome!\n");
            }
        }

    printf("Email: \n");
    scanf("%s", &emailUsuario);
    printf("Senha: \n");
    scanf("%s", &senhaCadastro);

    strcpy(usuario[contador_usuario].usuario, nomeUsuario);
    strcpy(usuario[contador_usuario].senhas, senhaCadastro);
    contador_usuario++;

    printf("Cadastro Realizado!!");

}

void login(){

    char senhaLogin[max_len], usuarioLogin[max_leght];

    printf("-----Login-----\n");
    printf("Usuario: \n");
    scanf("%s", &usuarioLogin);
    printf("Senha: \n");
    scanf("%s", &senhaLogin);
    for(int i = 1; i <= contador_usuario; i++){
        if (strcmp(usuario[i].usuario, usuarioLogin) == 0 && strcmp(usuario[i].senhas, senhaLogin) == 0) {
            printf("Bem-vindo, %s.\n", usuarioLogin);
        }
    }

    printf("Usuario ou Senha incorretos!!\n");

}

int main(int argc, char const *argv[]){

    int opcao;


    while (opcao != 4){
        printf("Escolha uma opcao!\n");
        printf("[1] - Criar Cadastro!\n");
        printf("[2] - Login!\n");
        printf("[3] - Voltar\n");
        printf("[4] - Sair!\n");
        scanf("%i", &opcao);

        switch (opcao){
        case 1:
            cadastro();
            break;
        case 2:
            login();
            break;
        case 3:
            
        default:
            break;
        }
    }
        
    return 0;
}

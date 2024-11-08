#include <stdio.h>

char acao;
int senha_normal[50];
int senha_prioridade[50];
int quantidade_de_senhas_normais = 0;
int quantidade_de_senhas_prioritarias = 0;
int senha = 1;
int ultima_senha_consumida = 0;

void inserir_senha_normal() {
    senha_normal[quantidade_de_senhas_normais] = senha;
    printf("Sua senha é %d\n", senha);
    quantidade_de_senhas_normais++;
    senha++;
}

void inserir_senha_prioritaria() {
    senha_prioridade[quantidade_de_senhas_prioritarias] = senha;
    printf("Sua senha é %d\n", senha);
    quantidade_de_senhas_prioritarias++;
    senha++;
}

void consumir_senha() {
    if (quantidade_de_senhas_prioritarias > 0 && (ultima_senha_consumida == 0 || quantidade_de_senhas_normais == 0)) {

        printf("Senha consumida: %d\n", senha_prioridade[0]);

        for (int i = 0; i < quantidade_de_senhas_prioritarias - 1; i++) {
            senha_prioridade[i] = senha_prioridade[i + 1];
        }
        quantidade_de_senhas_prioritarias--;
        ultima_senha_consumida = 1;

    } else if (quantidade_de_senhas_normais > 0) {
        printf("Senha consumida: %d\n", senha_normal[0]);
        
        for (int i = 0; i < quantidade_de_senhas_normais - 1; i++) {
            senha_normal[i] = senha_normal[i + 1];
        }
        quantidade_de_senhas_normais--;
        ultima_senha_consumida = 0;

    } else {
        printf("Nenhuma senha disponível\n");
    }
}

void visualizar_fila() {
    printf("Senhas normais: ");

    for (int i = 0; i < quantidade_de_senhas_normais; i++) {
        printf("%d \n", senha_normal[i]);
    }

    printf("Senhas prioritárias: ");
    for (int i = 0; i < quantidade_de_senhas_prioritarias; i++) {
        printf("%d \n", senha_prioridade[i]);
    }
    
}

int main() {
    while (1) {
        printf("Bem-Vindo! Digite de acordo com a tabela a ação que você quer realizar!\n");
        printf(" N - Criar uma senha normal.\n P - Criar uma senha prioritária.\n C - Consumir a senha da vez.\n V - Visualizar a fila.\n S - Sair.\n");

        scanf(" %c", &acao);

        switch (acao) {
            case 'N':
                inserir_senha_normal();
                break;
            case 'P':
                inserir_senha_prioritaria();
                break;
            case 'C':
                consumir_senha();
                break;
            case 'V':
                visualizar_fila();
                break;
            case 'S':
                return 0;
            default:
                printf("Opção inválida\n");
        }
    }

    return 0;
}
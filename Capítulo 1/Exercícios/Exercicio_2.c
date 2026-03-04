/**
 *
 * Cenário: Você está construindo um sistema de controle de acesso para uma aplicação web interna. Cada usuário tem um conjunto de permissões que são armazenadas como flags em um único byte. Isso é exatamente como sistemas UNIX gerenciam permissões de arquivos.

O que fazer:

Defina as flags: LEITURA (bit 0), ESCRITA (bit 1), EXECUCAO (bit 2), ADMIN (bit 3)
Crie um usuário com permissões LEITURA + ESCRITA
Escreva uma função que verifica se um usuário tem uma permissão específica
Adicione, remova e faça toggle de permissões, imprimindo o estado após cada operação

 */

#include <stdio.h>
#include <stdbool.h>

/*
 * POR QUÊ usar (1 << N) ao invés de valores hard-coded:
 * (1 << 0) = 1, (1 << 1) = 2, (1 << 2) = 4, (1 << 3) = 8
 * Se você precisar adicionar um novo bit, não precisa recalcular os outros.
 */
enum permission
{
    PERM_LEITURA = (1 << 0),
    PERM_ESCRITA = (1 << 1),
    PERM_EXECUCAO = (1 << 2),
    PERM_ADMIN = (1 << 3)
};

int user = 0;

void addPermission(int *user, enum permission pem);
void removePermission(int *user, enum permission perm);
void togglePermission(int *user, enum permission perm);
bool chekPermission(int *user, enum permission perm);
void printPermission(int *user);

int main(void)
{
    printf("Estado inicial: \n");
    printPermission(&user);

    /* Configurando multiplos bits */
    printf("Adicionando permissão de leitura e escrita simutâneo\n");
    user = PERM_LEITURA | PERM_ESCRITA;
    printPermission(&user);

    /* Adicionar permissão de execução com OR (|=)*/
    printf("Adicionando a função de Execução\n");
    addPermission(&user, PERM_EXECUCAO);
    printPermission(&user);

    /* Remover escrita com AND + NOT (&= ~) */
    printf("Removendo permissão de escrita\n");
    removePermission(&user, PERM_ESCRITA);
    printPermission(&user);

    /* Toggle ADMIN com XOR (^=) */
    printf("Toggle na permissão de ADMIN. Adicionando permissão\n");
    togglePermission(&user, PERM_ADMIN);
    printPermission(&user);
    printf("Toggle na permissão de ADMIN. Removendo permissão\n");
    togglePermission(&user, PERM_ADMIN);
    printPermission(&user);

    return 0;
}

bool chekPermission(int *user, enum permission perm)
{
    /*
     * POR QUÊ usar & e não ==:
     * flags pode ter múltiplas permissões.
     * (flags & perm) isola apenas o bit que queremos verificar.
     * Se o bit estiver setado, o resultado é != 0 (truthy).
     */
    return (*user & perm) != 0;
}

void printPermission(int *user)
{
    printf(" Permissões: [ %s ] [ %s ] [ %s ] [ %s ] | bits: ",
           chekPermission(user, PERM_LEITURA) ? "L" : "-",
           chekPermission(user, PERM_ESCRITA) ? "E" : "-",
           chekPermission(user, PERM_EXECUCAO) ? "X" : "-",
           chekPermission(user, PERM_ADMIN) ? "A" : "-");

    for (int i = 3; i >= 0; i--)
    {
        printf("%d", (*user >> i) & 1);
    }
    printf("\n");
}

void addPermission(int *user, enum permission perm)
{
    *user |= perm;
}

void removePermission(int *user, enum permission perm)
{
    *user &= ~(perm);
}

void togglePermission(int *user, enum permission perm)
{
    *user ^= perm;
}

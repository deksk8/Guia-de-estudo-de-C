/*
 * arquivo: operadores.c
 *
 * Demonstração de todos os operadores importantes em C.
 * Compile com: gcc -Wall -Wextra -std=c17 -o operadores operadores.c
 */

#include <stdio.h>
#include <stdint-gcc.h>

/*
 * Porquê esse enum com potência de 2:
 * Flags são sempre potências de 2 porque em binário,
 * cada um ocupa apens 1 bit. Isso permit combinar
 * mútiplas flags em um único inteiro usando bitwise OR.
 */

enum Permissao
{
    PERM_LEITURA = 1, /* 001 em binário*/
    PERM_ESCRITA = 2, /* 010 em binário*/
    PERM_EXECUCAO = 4 /* 100  em binário */
};

void printBinario(int value);
void checkPermission(int permission);

int main(void)
{
    /* === OPERADORES ARITMÉTICOS ===*/
    int a = 17;
    int b = 5;

    printf("=== Aritméticos ===\n");
    printf(" %d + %d = %d\n", a, b, a + b);  /* 22 */
    printf(" %d - %d = %d\n", a, b, a - b);  /* 12 */
    printf(" %d * %d = %d\n", a, b, a * b);  /* 85 */
    printf(" %d / %d = %d\n", a, b, a / b);  /* 3 - divisão inteira */
    printf(" %d %% %d = %d\n", a, b, a % b); /* 2 - resta da divisão */

    /**
     * Por quê o cast para double:
     * Sem cast, 17/5 = 3 (inteiro)
     * Com cast, pelo menos um operando é float -> resultado é float
     */
    printf("%.2f / %.2f = %.4f\n", (double)a, (double)b, (double)a / b);

    /**
     * === OPERADORES BITWISE - a alma do C ===
     */
    uint8_t flags = 0; /* Nenhuma permissão */

    /* Adicionar permissões com OR (|) */
    flags |= PERM_LEITURA;  /* flags = 001 */
    flags |= PERM_EXECUCAO; /* flags = 101 (leitura + execução) */

    printf("\n === Bitiwise - Sistema de Permissões ===\n");
    printf("Flags atuais: %d (binário: ", flags);
    /* Imprimir em binário manualmente - printf não tem %b em C padrão */
    for (int i = 2; i >= 0; i--)
    {
        printf("%d", (flags >> i) & 1);
    }
    printf(")\n");

    /* Verificar se uma permissão existe com AND (&) */
    printf("Tem Leitura? %s\n", (flags & PERM_LEITURA) ? "Sim" : "Não");
    printf("Tem Escrita? %s\n", (flags & PERM_ESCRITA) ? "Sim" : "Não");
    printf("Tem Execução? %s\n", (flags & PERM_EXECUCAO) ? "Sim" : "Não");

    /* Remover um permissão com AND + NOT (~) */
    flags &= ~PERM_EXECUCAO; /* Remove execução: flags (101) & 011 (not de 100) = 001 */
    printf("\nApós remover execução\n");
    printBinario(flags);
    checkPermission(flags);

    /* Toggle (inverter uma permissão com XOR (^) */
    flags ^= PERM_ESCRITA; /* Adiciona escrita (estava 0, vira 1) */
    printf("\nApós toggle escrita:\n");
    printBinario(flags);
    checkPermission(flags);

    /* === SHIFT OPERATORS: << e >> === */
    printf("\n=== Shift Operators ===\n");
    int valor = 1;
    printf("1 << 0 = %d (1)\n", valor << 0);
    printf("1 << 1 = %d (2)\n", valor << 1);
    printf("1 << 2 = %d (4)\n", valor << 2);
    printf("1 << 3 = %d (8)\n", valor << 3);
    /* * Por quê isso importa: 1 << N é equivalante a 2^N,
     * Mas MUITO mais rápido ( uma instrução CPU vs multiplicação). */

    printf("16 >> 2 = %d (divido por 4)\n", 16 >> 2);

    /* === OPERADOR LÓGICOS COM SHORT-CIRCUIT */
    printf("\n=== Shor-Circuit Evaluation ===\n");
    int x = 0;
    /**
     * Por quê isso funciona sem dividir por zero:
     * && avalia da esqueda para diretia.
     * Se o primeiro operando é false (x == 0), o segundo não é avaliado.
     * Isso é "short-circuit" - o circuito é cortado cedo.
     * Usado extensivamente em c para verificações de segurança.
     */
    if (x != 0 && (100 / x > 5))
    {
        printf("Isso não executa\n");
    }
    else
    {
        printf("Short-circuito: não dividiu por zero!\n");
    }

    /* === OPERADOR TERMINÁRIO === */
    int idade = 20;
    /**
     * Por quê usar ternário aqui e não if/else:
     * Para expressões simples com resultado que vai para uma variável,
     * o ternário é mais conciso. Para lógica complexa, use if/else
     */
    const char *status = (idade >= 18) ? "Adulto" : "Menor";
    printf("Idade: %d: %s\n", idade, status);

    /* === OPERADORES DE ATRIBUIÇÃO COMPOSTOS */
    int contador = 10;
    contador += 5; /* contador = contador + 5 = 15 */
    contador -= 3; /* contador = contador - 3 = 12 */
    contador *= 2; /* contador = contador * 2 = 24 */
    contador /= 4; /* contador = contador / 4 = 6  */
    contador %= 4; /* contador = contador % 4 = 2  */
    printf("Contador após operações compostas: %d\n", contador);

    return 0;
}

void printBinario(int value)
{
    printf("Flags atuais: %d (binário: ", value);
    for (int i = 2; i >= 0; i--)
    {
        printf("%d", (value >> i) & 1);
    }
    printf(")\n");
}

void checkPermission(int permission)
{
    printf("=== Check Permission ===\n");
    printf("Tem Leitura? %s\n", (permission & PERM_LEITURA) ? "Sim" : "Não");
    printf("Tem Escrita? %s\n", (permission & PERM_ESCRITA) ? "Sim" : "Não");
    printf("Tem Execução? %s\n", (permission & PERM_EXECUCAO) ? "Sim" : "Não");
}
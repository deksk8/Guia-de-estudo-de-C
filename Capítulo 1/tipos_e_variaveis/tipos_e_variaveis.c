/*
 * arquivo: tipos_e_variaveis.c
 *
 * Demonstração completa de tipos, variáveis e constantes.
 * Compile com: gcc -Wall -Wextra -std=c17 -o tipos tipos_e_variaveis.c
 */

#include <stdio.h>
#include <stdint.h>  /* tipos de tamanho fixo: int32_t, uint8_t, etc. */
#include <limits.h>  /* limites dos tipos: INT_MAX, CHAR_MIN, etc. */
#include <float.h>   /* limites de float: FLT_MAX, DBL_EPSILON, etc. */
#include <stdbool.h> /* bool, true, false (C99+) */
#define PI 3.14159265358979323846
#define MAX_NOME 64
#define VERSAO "1.0.0"
const int LIMITE_TENTATIVAS = 3;
enum Cor
{
    COR_VERMELHOR = 0,
    COR_VERDE = 1,
    COR_AZUL = 2
};
int main(void)
{
    /* === TIPOS INTEIROS === */

    /* POR QUÊ int8_t ao invés de char para números:
     * char pode ser signed ou unsigned dependendo da plataforma.
     * int8_t é SEMPRE 8 bits signed. Sem ambiguidade. */
    int8_t byte_valor = 127;                       /* máximo de um byte com sinal */
    uint8_t byte_sem_sinal = 255;                  /* máximo sem sinal: 2^8 - 1 */
    int16_t numero_curto = 32767;                  /* máximo de 16 bits com sinal */
    int32_t numero_int = 2147483647;               /* máximo de 32 bits com sinal */
    int64_t numero_grande = 9223372036854775807LL; /* LL = sufixo long long */

    /* TIPOS DE PONTO FLUTUANTE */
    /* POR QUÊ 3.14f e não 3.14:
     * 3.14 sem sufixo é um double (8 bytes).
     * 3.14f é um float (4 bytes).
     * Assigning um double a um float sem 'f' gera aviso com -Wall. */
    float valor_float = 3.14f;
    double valor_double = 3.14159265358979;

    /* === TIPO CARACTERE === */
    char letra = 'A'; /* Internamente, 'A' é apenas o número 65 (tabela ASCII) */
    /* === TIPO BOOLEANO (C99+) ===*/
    bool esta_ativo = true; /* true = 1, false = 0 */
    /* === CONSTANTES USANDO ENUM ===*/
    enum Cor minha_cor = COR_AZUL;
    /* === IMPRIMINDO VALORES E TAMANHOS ===*/
    printf("=== Tipos Inteiros ===\n");
    printf("int8_t:  valor=%d,  tamanho=%zu bytes\n", byte_valor, sizeof(byte_valor));
    printf("uint8_t: valor=%u,  tamanho=%zu bytes\n", byte_sem_sinal, sizeof(byte_sem_sinal));
    printf("int16_t: valor=%d,  tamanho=%zu bytes\n", numero_curto, sizeof(numero_curto));
    printf("int32_t: valor=%d,  tamanho=%zu bytes\n", numero_int, sizeof(numero_int));
    printf("int64_t: valor=%ld, tamanho=%zu bytes\n", numero_grande, sizeof(numero_grande));

    printf("\n=== Tipos Float ===\n");
    printf("float:  valor=%.2f, tamanho=%zu bytes\n", valor_float, sizeof(valor_float));
    printf("double: valor=%.14f, tamanho=%zu bytes\n", valor_double, sizeof(valor_double));

    printf("\n=== Char e Bool ===\n");
    printf("char: '%c' (valor numérico: %d), tamanho=%zu byte\n", letra, letra, sizeof(letra));
    printf("bool: %s, tamanho=%zu byte\n", esta_ativo ? "true" : "false", sizeof(esta_ativo));

    printf("\n=== Constante ===\n");
    printf("PI (Macro): %.15f\n", PI);
    printf("LIMITE_TENTATIVAS (const): %d\n", LIMITE_TENTATIVAS);
    printf("Cor atual (enum): %d\n", minha_cor);
    printf("Versão (macro string): %s\n", VERSAO);

    printf("\n === Limites dos tipos (do <limits.h) ===\n");
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("CHAR_MAX: %d\n", CHAR_MAX);
    return 0;
}
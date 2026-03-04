/**
 * Cenário: Você está desenvolvendo um sistema de monitoramento de sensores IoT. Cada sensor reporta temperatura como um valor inteiro (em décimos de grau Celsius) para economizar banda. Você precisa converter e exibir esse valor corretamente.

O que fazer:

Declare uma variável int chamada temp_raw com o valor 237 (representa 23.7°C)
Calcule a temperatura real dividindo por 10.0 e armazenando em um double chamado temp_real
Imprima ambos os valores com formatos apropriados
Mostre o tamanho em bytes de cada variável usando sizeof()
 */

#include <stdio.h>
#include <stdint-gcc.h>

int temp_raw = 237;
double temp_real = 0;

int main(void)
{

    temp_real = temp_raw / 10.0;

    printf(" === Valores das temperaturas === \n");
    printf("Temperatura raw: %d (décimos de °C)\n", temp_raw);
    printf("Temperatura real: %.2f °C\n", temp_real);
    printf(" === Tamanhos das variáveis === \n");
    printf("Tamanho de temp_raw (int) em bytes: %ld\n", sizeof(temp_raw));
    printf("Tamanho de temp_real (double) em bytes: %ld\n", sizeof(temp_real));

    return 0;
}
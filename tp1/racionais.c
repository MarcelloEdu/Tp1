#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>

int aleat(int min, int max)
{
    return rand() % (max - min + 1);
}

int mdc(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
int mmc (int a, int b)
{
    return a * b / mdc (a, b);
}

/* Recebe um numero racional e o simplifica.
 * Por exemplo, ao receber 10/8 devera retornar 5/4
 * Se ambos numerador e denominador forem negativos, devera retornar um positivo
 * Se o denominador for negativo, o sinal deve migrar para o numerador
 * Quem chama esta funcao deve garantir que o racional r eh valido */
struct racional simplifica_r (struct racional r){
    if (!valido_r(r)) {
        return r; // Retorna o número racional original se não for válido
    }

    int divisor_comum = mdc(r.num, r.den);
    /* Simplificando dividindo numerador e denominador pelo MDC */
    r.num = r.num / divisor_comum;
    r.den = r.den / divisor_comum;

    /* Lidando com casos de sinal */
    if (r.den < 0) {
        r.num = -r.num;
        r.den = -r.den;
    } else if (r.num < 0 && r.den > 0) {
        r.num = -r.num;
        r.den = -r.den;
    }

    /*retorna o numero racional simplificado*/
    return r;
}

/* Cria um numero racional com base nas informacoes dos parametros. */
struct racional cria_r (int numerador, int denominador){
    struct racional novo_racional;

    novo_racional.num = numerador;
    novo_racional.den = denominador;

    return simplifica_r(novo_racional);
}

/* Retorna um numero racional aleatorio na forma simplificada.
 * O numerador e o denominador devem ser inteiros entre 0 e n.
 * O racional deve conter a informacao se ele eh valido ou nao */
struct racional sorteia_r (int n){
    int numerador = aleat(0, n);
    int denominador = aleat(0, n);

    return cria_r(numerador, denominador);
}

/* Imprime um racional r
   A impressao deve respeitar o seguinte:
   - o racional deve estar na forma simplificada;
   - o formato de saida deve ser "r.num/r.den", a menos dos casos abaixo;
   - nao use espacos em branco apos o numero e nao mude de linha;
   - se o numerador for igual a 0, deve ser impresso somente zero;tg
   - se o denominador for igual a 1, deve ser impresso somente o numerador;
   - se o numerador e denominador forem o mesmo valor, deve imprimir somente 1;
   - se o racional for negativo, o sinal deve ser impresso antes do numero;
   - se ambos numerador e denominador forem negativos, o racional eh positivo;
   - se o racional for invalido, deve imprimir a mensagem "INVALIDO"           */
void imprime_r (struct racional r){
    if (r.num == 0) {
        /* Se o numerador for zero, imprime apenas "0"*/
        printf("0");
    } else if (r.den == 1) {
        /* Se o denominador for 1, imprime apenas o numerador*/
        printf("%d", r.num);
    }
    else if (r.num == r.den)
    {
        /* Se o numerador for igual ao denominador, imprime "1"*/
        printf("1");
    }
    else
    {
        /* Se nenhum dos casos for atendido, imprime o número racional*/
    if (r.num < 0 && r.den < 0) {
            r.num = -r.num;
            r.den = -r.den;
    }
    if (r.den < 0)
    {
            r.num = -r.num;
            r.den = -r.den;
    }

    if (r.num < 0)
    {
            printf("-");
            r.num = -r.num;
    }
        printf("%d/%d", r.num, r.den);
    }

}

/* Retorna 1 se o racional r eh valido ou 0 caso contrario
 * Um racional eh invalido se o denominador for nulo */
int valido_r (struct racional r)
{
    return r.den != 0;
}

/* Retorna a soma dos racionais r1 e r2.
 * Quem chama esta funcao deve garantir que os racionais r1 e r2 sao validos */
struct racional soma_r (struct racional r1, struct racional r2){
    struct racional resultado;

    /*verifica se os racionais são válidos*/
    if (!valido_r(r1) || !valido_r(r2)) {
        /*Se algum dos racionais não for válido, retorna um número racional inválido*/
        resultado.num = 0;
        resultado.den = 0;
        return resultado;
    }

    /*realiza a soma dos racionais*/
    resultado.num = (r1.num * r2.den) + (r2.num * r1.den);
    resultado.den = r1.den * r2.den;

    /*Simplifica o resultado*/
    resultado = simplifica_r(resultado);

    return resultado;
}

/* Retorna a subtracao dos racionais r1 e r2.
 * Quem chama esta funcao deve garantir que os racionais r1 e r2 sao validos */
struct racional subtrai_r (struct racional r1, struct racional r2){
struct racional resultado;

    /* Verifica se os racionais são válidos */
    if (!valido_r(r1) || !valido_r(r2)) {
        /* Se algum dos racionais não for válido, retorna um número racional inválido*/
        resultado.num = 0;
        resultado.den = 0;
        return resultado;
    }

    /* Realiza a subtração dos racionais */
    resultado.num = (r1.num * r2.den) - (r2.num * r1.den);
    resultado.den = r1.den * r2.den;

    /*Simplifica o resultado*/
    resultado = simplifica_r(resultado);

    return resultado;
}


/* Retorna a multiplicacao dos racionais r1 e r2.
 * Quem chama esta funcao deve garantir que os racionais r1 e r2 sao validos */
struct racional multiplica_r (struct racional r1, struct racional r2){
    struct racional resultado;

    /* Verifica se os racionais são válidos*/
    if (!valido_r(r1) || !valido_r(r2)) {
        /*se algum dos racionais não for válido, retorna um número racional inválido*/
        resultado.num = 0;
        resultado.den = 0;
        return resultado;
    }

    /*Realiza a multiplicação dos racionais*/
    resultado.num = r1.num * r2.num;
    resultado.den = r1.den * r2.den;

    // Simplifica o resultado
    resultado = simplifica_r(resultado);

    return resultado;
}
/* Retorna a divisao dos racionais r1 e r2.
 * Quem chama esta funcao deve:
     - garantir que os racionais r1 e r2 sao validos
     - em seguida deve garantir que o racional retornado tambem seja valido */
struct racional divide_r (struct racional r1, struct racional r2){
struct racional resultado;

    /*Verifica se os racionais são válidos*/
    if (!valido_r(r1) || !valido_r(r2)) {
        /* Se algum dos racionais não for válido, retorna um número racional inválido*/
        resultado.num = 0;
        resultado.den = 0;
        return resultado;
    }

    /*Verifica se o divisor (r2) é diferente de zero*/
    if (r2.num == 0) {
        /* Se o divisor for zero, retorna um número racional inválido*/
        resultado.num = 0;
        resultado.den = 0;
        return resultado;
    }

    /* Realiza a divisão dos racionais (r1 / r2)*/
    resultado.num = r1.num * r2.den;
    resultado.den = r1.den * r2.num;

    /* Verifica se o resultado é válido (denominador diferente de zero)*/
    if (resultado.den == 0) {
        /*se o denominador for zero, retorna um número racional inválido*/
        resultado.num = 0;
        resultado.den = 0;
        return resultado;
    }

    /*simplifica o resultado*/
    resultado = simplifica_r(resultado);

    return resultado;
}

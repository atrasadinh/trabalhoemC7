#include <stdio.h>

int main() {
    int n, k;

    do {
        printf("Digite o numero de elementos na sequencia: ");
        scanf("%d", &n);
        if (n < 2) {
            printf("Valor incorreto, tente novamente\n");
        }
    } while (n < 2);

    int S[n];
    printf("Digite a sequencia de %d numeros inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    do {
        printf("Digite o comprimento da subsequencia: ");
        scanf("%d", &k);
        if (k < 2 || k > n) {
            printf("Valor incorreto, tente novamente\n", n);
        }
    } while (k < 2 || k > n);

    int soma_p = S[0] + S[1];
    int ini_sub = 0;

    for (int i = 0; i <= n - k; i++) {
        int soma_atual = 0;

        for (int j = i; j < i + k; j++) {
            soma_atual = soma_atual + S[j];
        }

        if ((soma_atual < 0 ? -soma_atual : soma_atual) < (soma_p < 0 ? -soma_p : soma_p)) {
            soma_p = soma_atual;
            ini_sub = i;
        }
    }

    for (int i = ini_sub; i < ini_sub + k; i++) {
        printf("%d ", S[i]);
    }
    printf("\n: %d\n", soma_p);
}

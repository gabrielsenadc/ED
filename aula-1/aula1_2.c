#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14

void calc_esfera (float r, float* area, float* volume){
    *area  = 4 * PI * r * r;
    *volume = (4 * PI * r * r * r) / 3;
}

int raizes(float a, float b, float c, float* x1, float* x2){  
    int delta = (b * b) - (4 * a * c);
    if(delta < 0) return 0;
    *x1 = ((-1 * b) + sqrt(delta)) / (2 * a);
    *x2 = ((-1 * b) - sqrt(delta)) / (2 * a);
    if(delta == 0) return 1;
    return 2;
}

int pares (int n, int* vet){
    int pares = 0;
    for(int i = 0; i < n; i++){
        if(!(vet[i] % 2)) pares++;
    }
    return pares;
}

void inverte (int n, int* vet){
    int aux;
    for(int i = 0, j = n - 1; i < n/2; i++, j--){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }
}

double avalia (double* poli, int grau, double x){
    double result = 0;
    for(int i = 0; i < grau + 1; i++){
        result += poli[i] * pow(x, i); 
    }
    return result;
}


/*int main() {
    float r = 0;
    printf("Qual o raio? ");
    scanf("%f", &r);
    float area = 0, volume = 0;
    calc_esfera(r, &area, &volume);
    printf("Area = %.2f\nVolume = %.2f\n", area, volume);

    return 0;
}*/

/*int main(){
    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    printf("Qual os coeficientes da funcao de segundo grau? (a, b, c) ");
    scanf("%f %f %f", &a, &b, &c);
    int qtd = raizes(a, b, c, &x1, &x2);
    if(qtd == 0) printf("Sem raizes!\n");
    if(qtd == 1) printf("Uma raiz: \nx = %.2f\n", x1);
    if(qtd == 2) printf("Duas raizes: \nx1 = %.2f\nx2 = %.2f\n", x1, x2);
    
    return 0;
}*/

/*int main() {
    int qtd = 0;
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &qtd);
    int *vet = malloc(qtd * sizeof(int));
    printf("Digite os numeros do vetor ");
    for(int i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }
    printf("O vetor tem %d par(es)", pares(qtd, vet));
    free(vet);

    return 0;
}*/

/*int main() {
    int qtd = 0;
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &qtd);
    int *vet = malloc(qtd * sizeof(int));
    printf("Digite os numeros do vetor ");
    for(int i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }
    inverte (qtd, vet);
    for(int i = 0; i < qtd; i++){
        printf("%d ", vet[i]);
    }
}*/

/*int main() {
    int grau;
    printf("Qual o grau do polinomio? ");
    scanf("%d", &grau);

    double *poli = malloc((grau + 1) * sizeof(double));
    printf("Digite os coeficientes ");
    for(int i = 0; i < grau + 1; i++){
        scanf("%lf", &poli[i]);
    }

    double x;
    printf("Qual o valor de x? ");
    scanf("%lf", &x);

    printf("Resultado: %.2lf", avalia(poli, grau, x));

    free(poli);

    return 0;
}*/
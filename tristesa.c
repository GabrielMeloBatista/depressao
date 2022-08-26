#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct lista
{
  int den;
  int num;
  int mdc;
  struct lista *prox;
} resultado;

int maximoDivisorComum(int x, int y)
{
  if (y == 0)
  {
    return x;
  }
  else
  {
    return maximoDivisorComum(y, x % y);
  }
}

void soma(int N1, int N2, int D1, int D2, int *num, int *den)
{
  //(N1*D2 + N2*D1) / (D1*D2)
  *num = N1 * D2 + N2 * D1;
  *den = D1 * D2;
}

void subtracao(int N1, int N2, int D1, int D2, int *num, int *den)
{
  //(N1*D2 - N2*D1) / (D1*D2)
  *num = N1 * D2 - N2 * D1;
  *den = D1 * D2;
}

void multiplicacao(int N1, int N2, int D1, int D2, int *num, int *den)
{
  //(N1*N2) / (D1*D2)
  *num = N1 * N2;
  *den = D1 * D2;
}

void divisao(int N1, int N2, int D1, int D2, int *num, int *den)
{
  //(N1*D2)/(N2*D1)
  *num = N1 * D2;
  *den = N2 * D1;
}

void menu(int N1, int N2, int D1, int D2, char operador, int *num, int *den)
{
  switch (operador)
  {
  case '+':
    soma(N1, N2, D1, D2, num, den);
    break;

  case '-':
    subtracao(N1, N2, D1, D2, num, den);
    break;

  case '*':
    multiplicacao(N1, N2, D1, D2, num, den);
    break;

  case '/':
    divisao(N1, N2, D1, D2, num, den);
    break;
  }
}

resultado inserir(resultado *p, int den, int num, int mdcr)
{
  resultado *nova = (resultado *)malloc(sizeof(resultado));
  nova->prox = p->prox;
  p->prox = nova;
  nova->den = den;
  nova->num = num;
  nova->mdc = mdcr;
}

void imprimir(resultado *p)
{
  resultado *novo = p;
  resultado *aux;
  aux = (resultado *)malloc(sizeof(resultado));
  int num, den, mdcr;
  while (novo->prox != NULL)
  {
    novo = novo->prox;
    num = novo->num;
    den = novo->den;
    mdcr = novo->mdc;
    inserir(aux, den, num, mdcr);
  }
  resultado *nova = aux;
  while (nova->prox != NULL)
  {
    nova = nova->prox;
    num = nova->num;
    den = nova->den;
    mdcr = nova->mdc;
    printf("%d/%d = %d/%d\n", num, den, num / mdcr, den / mdcr);
  }
}

int main()
{
  int N, N1, N2, D1, D2, mdcr, num, den;
  int i = 0;
  char operador;
  resultado *resposta;
  resposta = (resultado *)malloc(sizeof(resultado));

  scanf("%d", &N);
  if (N >= 1 && N <= 10000)
  {
    while (i < N)
    {
      scanf("%d / %d %s", &N1, &D1, &operador);
      getchar();
      scanf(" %d / %d", &N2, &D2);
      getchar();

      if (N1 >= 1 && N1 <= 1000 && N2 >= 1 && N2 <= 1000 && D1 >= 1 && D1 <= 1000 && D2 >= 1 && D2 <= 1000)
      {
        menu(N1, N2, D1, D2, operador, &num, &den);

        mdcr = maximoDivisorComum(den, num);
        if (mdcr <= 0)
          mdcr = -1 * mdcr;
        inserir(resposta, den, num, mdcr);
      }
      else
      {
        break;
      }
      i++;
    }
  }
  imprimir(resposta);

  return 0;
}
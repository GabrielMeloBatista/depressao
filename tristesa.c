#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maximoDivisorComum(int x, int y)
{
  if (y == 0)
  {
    return y;
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

int main()
{
  int N, N1, N2, D1, D2, menor, num, den;
  int i = 0;
  char operador;
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
        menor = maximoDivisorComum((num < 0 ? -num : num), den);
        printf("%d / %d = %d / %d\n", num, den, num / menor, (!num ? 1 : den / menor));
      }
      else
      {
        break;
      }
      i++;
    }
  }

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void soma(int N1, int N2, int D1, int D2){
	int Num, Den;
	//(N1*D2 + N2*D1) / (D1*D2)
	Num = N1*D2 + N2*D1;
	Den = D1*D2;
}

void subtracao(int N1, int N2, int D1, int D2){
	int Num, Den;
	//(N1*D2 - N2*D1) / (D1*D2)
	Num = N1*D2 - N2*D1;
	Den = D1*D2;
}

void multiplicacao(int N1, int N2, int D1, int D2){
	int Num, Den;
	//(N1*N2) / (D1*D2)
	Num = N1 * N2;
	Den = D1*D2;
}

void divisao(int N1, int N2, int D1, int D2){
	int Num, Den;
	//(N1*D2)/(N2*D1)
	Num = N1*D2;
	Den = N2*D1;
}

void menu(int N1, int N2, int D1, int D2, char operador){
	switch(operador){
		case '+':
			soma( N1,  N2,  D1,  D2);
			break;
			
		case '-':
			subtracao( N1,  N2,  D1,  D2);
			break;
			
		case '*':
			multiplicacao( N1,  N2,  D1,  D2);
			break;
			
		case '/':
			divisao( N1,  N2,  D1,  D2);
			break;
	}
}

int main(){
    int N, N1, N2, D1, D2;
	int i = 0;
	char operador;
	scanf("%d", &N);
	if(N >= 1 && N<= 10000){
	    while(i < N){
	    	scanf("%d", &N1);
	    	scanf("%d", &D1);
	    	scanf("%s", &operador);
	    	getchar();
	    	scanf("%d", &N2);
	    	scanf("%d", &D2);
	    	if(N1>= 1 && N1 <= 1000 && N2>= 1 && N2 <= 1000 && D1>= 1 && D1 <= 1000 && D2 >= 1 && D2 <= 1000){
	    		menu(N1, N2, D1, D2, operador);
			}
			else{
				break;
			}
	    	i++;
		}
	}
    
    return 0;
}
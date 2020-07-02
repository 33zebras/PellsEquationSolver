#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#pragma warning(disable:4996)

int x = 0, y = 0, D = 0, k = 0;
int resultR = 0, resultIr = 0;	//	결과를 저장할 변수	R = 유리수	 Ir = 무리수	(sqrt 안의 값이라고 생각할 것)

void calc(int x0, int y0, int k);
int fibonacci(int from, int to);
int detFib(int r, int ir);
int doExp(int base, int x);
void msgFirst();
void msgSolve1();

int main()
{
	msgFirst();
	redo:
	msgSolve1();
	
	
	printf("\n(^0^)/ 거듭제곱을 통해 다른 해도 구해볼까요?\n\n(^0^)/ 원하는 거듭제곱 k 값을 입력해주세요.\n\t(0 입력시 프로그램이 종료됩니다. -1 입력시 D값을 수정합니다.)\n");
	while (1)
	{
		printf("\n(^0^)/ D : %d, k : ", D);
		scanf("%d", &k);

		if (k == 0)
		{
			exit(0);
		}
		else if (k == -1)
		{
			printf("\n__________________________________________________________________________\n");
			printf("\n(^0^)/ D 값을 수정합니다!\n");
			goto redo;
		}
		else
			calc(x, y, k);
	}
	return 0;
}

void calc(int x0, int y0, int k)
{
	int tempR = 0, tempIr = 0, fib = 0, r = k, ir = 0;	// i == 유리수 개수, j = 무리수 개수, k = 전체 거듭제곱의 개수 ( 따라서 언제나 i + j = k )
	resultIr = resultR = 0;

	for (; r >= 0; r--, ir++)
	{
		fib = detFib(r, ir);
		printf("\n(~_~) 유리수는 %d 제곱, 무리수는 %d 제곱일 때 . . .", r, ir);
		tempR = doExp(x0, r);					// x0^r
		
		if (ir % 2 == 0)
		{
			tempR *= doExp(y0, ir);				// x0^r * y0^ir
			tempR *= doExp(D, ir / 2);			// x0^r * y0^ir * D^(ir/2)
			tempR *= fib;						// x0^r * y0^ir * D^(ir/2) * fib
			printf("\n(~_~) 유리수부 계산값 : %d", tempR);
			resultR += tempR;
		}
		else
		{
			tempR *= doExp(y0, ir);				// x0^r * y0^ir
			tempR *= doExp(D, (ir-1) / 2);			// x0^r * y0^ir * D^(ir/2)
			tempR *= fib;						// x0^r * y0^ir * D^(ir/2) * fib
			tempIr = tempR;
			printf("\n(~_~) 무리수부 계수 계산값 : %d", tempIr);
			resultIr += tempR;
		}
	}
	printf("\n\n(^0^)/ 해는 x : %d\ty : %d 입니다!\n", resultR, resultIr);
	if (resultR < 0 || resultIr < 0)
	{
		printf("\n(T^T)/ 결과가 아무리 봐도 이상하네요...\n\n(T^T)/ 너무 큰 k 값을 지정한 게 아닐까요?\n");
	}

	return;
}

int fibonacci(int input, int to)
{
	if (input <= 1)
		return 1;
	else if (input <= to)
		return input;
	else
		return input*fibonacci(input-1, to);
}

int detFib(int r, int ir)
{
	int fib = 0, temp1 = 0, temp2 = 0;
	if (r*ir == 0)									// 각 경우가 몇 번인지 조합과 팩토리얼로 구함
		fib = 1;
	else
	{
		if (r >= ir)
		{
			temp1 = r;
			temp2 = ir;
		}
		else
		{
			temp1 = ir;
			temp2 = r;
		}
		fib = fibonacci(k, temp1 + 1);
		fib /= fibonacci(temp2, 1);					// 각 경우는 fib 번 도출
	}

	return fib;
}

int doExp(int base, int x)
{
	if (base <= 1)
		return base;
	else if (x == 1)
		return base;
	else if (x == 0)
		return 1;
	else
		return base*doExp(base, x-1);
}

void msgFirst()
{
	printf("_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/\n");
	printf("_/_/_/_/\t\t\t\t\t\t\t_/_/_/_/\n");
	printf("_/_/_/_/\tx^2 - Dy^2 = 1 형태의 펠 방정식 계산기\t\t_/_/_/_/\n");
	printf("_/_/_/_/\t\t고통받던 수학과 친구를 위해\t\t_/_/_/_/\n");
	printf("_/_/_/_/\tstaticccast \t 2019.09.30. Ver1.00\t\t_/_/_/_/\n");
	printf("_/_/_/_/\t\t\t\t\t\t\t_/_/_/_/\n_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/\n");

	printf("\n\n");
	printf("(^0^)/ D 값을 지정하고 몇 제곱의 경우를 구할지 k 값을 통해 지정해주세요.\n");
	printf("__________________________________________________________________________\n");
	return;
}

void msgSolve1()
{
	int leftSide = 0, rightSide = 0; // 각각 편의상 x^2, Dy^2 + 1 값을 저장해둘 것.

	printf("\n(^0^)/ D 값을 입력해주세요 : ");
	scanf("%d", &D);
	if (D <= 1)
	{
		printf("\n(T^T)/ 예기치 못한 입력이 발견되었습니다.\n\n(T^T) 프로그램을 종료합니다.\n\n");
		exit(0);
	}

	printf("\n(^0^)/ x^2 - %dy^2 = 1 를 풀겠습니다!\n", D);
	printf("\n(^0^)/ 최소 자연수해를 구하는 중 . . .\n");

	do
	{
		if (x < 0 || y < 0)
		{
			printf("\n(T^T)/ 오버플로우 발생으로 프로그램을 종료합니다.\n\n(T^T)/ 계산 도중 int 범위를 벗어난 것 같으니 D 값을 다시 확인해주세요\n");
			exit(0);
		}
		if (x == 0)
			x = 1;
		if (y == 0)
			y = 1;

		if (leftSide > rightSide)
			y++;
		else
			x++;

		leftSide = x*x;
		rightSide = (D * y * y) + 1;

	} while (leftSide != rightSide);

	printf("\n(^0^)/ 최소 자연수해는 : x = %d,\t y = %d 입니다.\n", x, y);
}
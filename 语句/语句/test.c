#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

#define EXP 0.0000000001
int main()
{
	double a = 0.0, b = 0.0, c = 0.0;
	scanf("%lf%lf%lf", &a, &b, &c);
	if (a > -EXP && a < EXP)
	{
		printf("不是一元二次方程\n");
	}
	else
	{
		double disc = b * b - a * a*c;
		if (disc < 0)
		{
			printf("无解\n");
		}
		else if (disc > -EXP && disc < EXP)
		{
			printf("%f\n", -b / (2 * a));
		}
		else {
			printf("%f %f\n", (-b + sqrt(disc)) / (2 * a), (-b-sqrt(disc)) / (2 * a));
		}
	}
	return 0;
}
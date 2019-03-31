#include <stdio.h>
#include <math.h>

float dn;
//Функция
float Func(float x) {
	float fx = x * x * x + 4 * x - 3;
	return fx;
}
//Вторая производная функции
float ddFunc(float x) {
	float fx = 6 * x;
	return fx;
}
//Функция для посчёта площади трапеции на отрезке (y, y + dn)
float Int(float y) {
	float intg = (Func(y) + Func(y + dn)) * dn / 2;
	return intg;
}

int main() {
	char ch;
	do {
		double steps, a, b, sum, deriv;
		sum = 0;

		printf("Input a, b: ");
		scanf_s("%lf%lf", &a, &b);
		printf("Input steps: ");
		scanf_s("%lf", &steps);

		dn = (b - a) / steps;
		deriv = fabs(ddFunc(a));
		//Суммирование площадей трапеций
		for (int i = 0; i < steps; i++) {
			sum = sum + Int(a + i * dn);
			if (fabs(ddFunc(a + i * dn)) > deriv) {	//Нахождение максимальной второй производной
				deriv = fabs(ddFunc(a + i * dn));
			}
		}

		printf("Result: %f\nPrecision: %f", sum, deriv * dn * dn * (b - a) / 12);	//формула (deriv * dn * dn * (b - a) / 12) даёт оценку точности метода

		//Повтор программы
		printf("\nDo you wish to restart program? (y/n)\n");
		getchar();
		scanf_s("%c", &ch);
	} while (ch == 'y' || ch == 'Y');

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
double getNum(const double min, const double max) {
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min)*temp;
	return temp;
}

bool isCircle(const double x, const double y) {
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;
	const double f = pow(x - x_c, 2) + pow(y - y_c, 2) - pow(r, 2);
	if (f > 0.0)
		return false;
	else
		return true;
}

void main() {
	FILE *of = fopen("Circle.txt", "w");
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10000; i++) {
		double x = getNum(0.0, 1.0);
		double y = getNum(0.0, 1.0);
		if (isCircle(x, y) == true)
			fprintf(of, "%f, %f\n", x, y);
	}
	fclose(of);
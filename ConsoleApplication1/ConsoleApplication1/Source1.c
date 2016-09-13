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

bool isDumcircle(const double x, const double y) {
	const double x_c = 1.2;
	const double y_c = 0.5;
	const double r = 0.5;
	const double f = pow(y - y_c, 2) + 4 * pow(x - x_c, 6) - 4 * pow(x - x_c, 4);
	if (f > 0.0)
		return false;
	else
		return true;
}

void main() {
	FILE *of = fopen("dumCircle.txt", "w");
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10000; i++) {
		double x = getNum(0.0, 4.0);
		double y = getNum(0.0, 1.0);
		if (isDumcircle(x, y) == true)
			fprintf(of, "%f, %f\n", x, y);
	}
	fclose(of);
}
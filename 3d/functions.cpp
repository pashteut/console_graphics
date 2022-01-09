#include "functions.h"

int brightness(int n, int min, int max) {
	return fmax(fmin(n, max), min);
}
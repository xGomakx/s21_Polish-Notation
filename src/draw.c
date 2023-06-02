#include "draw.h"
void input(char *str) {
  char c = getchar();
  int i = 0;
  while (c != '\n') {
    str[i] = c;
    c = getchar();
    i++;
  }
  str[i] = c;
}

void make_points(char *str, double *data) {
  double dx = (4.0 * M_PI) / X_MAX;
  for (int i = 0; i < X_MAX; i++) {
    data[i] = stack_machine(str, i * dx);
  }
}

void normalize(double *data, int *a) {
  double dy = 2.0 / (Y_MAX - 1);
  for (int i = 0; i < X_MAX; i++) {
    if (isnan(data[i])) {
      a[i] = -1000;
    } else {
      a[i] = round((data[i] + 1) / dy);
    }
  }
}

void output(const int *arr) {
  for (int i = 0; i < Y_MAX; i++) {
    for (int j = 0; j < X_MAX; j++) {
      if (arr[j] == i) {
        printf("*");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

#include "graph.h"
int main() {
  char str[NMAX];
  char str_out[NMAX];
  str_out[0] = '\0';
  input(str);
  polish_notation(str, str_out);
  double *data = malloc(X_MAX * sizeof(double));
  int *out = malloc(X_MAX * sizeof(int));
  make_points(str_out, data);
  normalize(data, out);
  output(out);
  free(data);
  free(out);
}

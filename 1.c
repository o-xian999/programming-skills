#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// task 1.1
double double_random(void) {
  return random() % 10 / 10.0;
}

// task 1.2
int bit_random(void) {
  return random() % 2;
}

// task 1.3
void output_ten(void) {
  printf("[double_random, bit_random]\n");
  for (int i = 0; i < 10; i++) {
    printf("[%0.1f, %d]\n", double_random(), bit_random());
  }
}

int main(void) {
  srandom(1);
  output_ten();
  return 0;
}

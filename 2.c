#include <stdio.h>

int main(void) {
  // 各値段とサイズを定義
  char goods[6][100] = {"缶コーヒー", "ペットボトル", "バナナ", "りんご", "おにぎり", "パン"};
  int price[6] = {120, 130, 80, 100, 250, 185};
  int size[6] = {10, 12, 7, 9, 21, 16};

  int max_price = 0, max_size = 0, best_bit = 0;

  // 2^6通りの組み合わせを探索
  for (int bit = 0; bit < (1 << 6); bit++) {
    int total_price = 0, total_size = 0;
    for (int i = 0; i < 6; i++) {
      if (bit & (1 << i)) {
        total_price += price[i];
        total_size += size[i];
      }
    }
    // 容量が65以内になる組み合わせのうち、最大となる合計金額を更新していく
    if (total_size <= 65 && max_price < total_price) {
      max_price = total_price;
      max_size = total_size;
      best_bit = bit;
    }
  }

  printf("combination: {");
  for (int i = 0; i < 6; i++) {
    if (best_bit & (1 << i)) {
      printf("%s, ", goods[i]);
    }
  }
  printf("\b\b}\n");

  printf("max_price: %d\n", max_price);
  printf("max_size: %d\n", max_size);

  return 0;
}

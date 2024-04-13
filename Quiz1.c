#include <stdio.h>
void quiz(int* a, int* b) {
  int aBin[10] = {0};
  int bBin[10] = {0};
  // a변수
  printf("%d", *a);
  printf(" = ");
  for (int i = 9; i >= 0; i--) {
    int result = *a >> i & 1;
    if ((i + 1) % 4 == 0) {
      printf(" ");
    }

    aBin[i] = result;
    printf("%d", result);
  }
  printf("\n");

  //------------------//
  // b변수

  printf("%d", *b);
  printf(" = ");
  for (int i = 9; i >= 0; i--) {
    int result = *b >> i & 1;
    if ((i + 1) % 4 == 0) {
      printf(" ");
    }
    bBin[i] = result;
    printf("%d", result);
  }
  printf("\n");
  //-----------------------//
  for (int i = 9; i >= 0; i--) {
    if ((i + 1) % 4 == 0) {
      printf(" ");
    }

    printf("%d", aBin[i]);
  }

  printf(" AND ");

  for (int i = 9; i >= 0; i--) {
    if ((i + 1) % 4 == 0) {
      printf(" ");
    }

    printf("%d", bBin[i]);
  }
  printf(" = ");
  int resultAnd[10] = {0};
  int resultOr[10] = {0};
  for (int i = 9; i >= 0; i--) {
    if ((i + 1) % 4 == 0) {
      printf(" ");
    }

    resultAnd[i] = aBin[i] && bBin[i] == 1 ? 1 : 0;
    printf("%d", resultAnd[i]);
  }
  printf(" = ");

  // 이제 2진번 10진법 으로 변환

  int temp = 0;
  int bin = 1;

  for (int i = 0; i <= 9; i++) {
    temp += resultAnd[i] == 1 ? 1 * bin : 0;
    bin *= 2;
  }
  printf("%d", temp);

  printf("\n");

  for (int i = 9; i >= 0; i--) {
    if ((i + 1) % 4 == 0) {
      printf(" ");
    }

    printf("%d", aBin[i]);
  }

  printf(" OR ");

  for (int i = 9; i >= 0; i--) {
    if ((i + 1) % 4 == 0) {
      printf(" ");
    }

    printf("%d", bBin[i]);
  }

  printf(" = ");
  for (int i = 9; i >= 0; i--) {
    if ((i + 1) % 4 == 0) {
      printf(" ");
    }

    resultOr[i] = aBin[i] || bBin[i] ? 1 : 0;
    printf("%d", resultOr[i]);
  }

  printf(" = ");

  // 이제 2진번 10진법 으로 변환

  int mytemp = 0;
  int mybin = 1;

  for (int i = 0; i <= 9; i++) {
    mytemp += resultOr[i] == 1 ? 1 * mybin : 0;
    mybin *= 2;
  }
  printf("%d", mytemp);
}

// refactoring은 할일이 많아서....
void main() {
  int a;
  int b;
  scanf("%d%d", &a, &b);
  quiz(&a, &b);
}
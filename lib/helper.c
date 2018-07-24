void swap(int *num1, int *num2) {
  int temp;
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int less(int num1, int num2) {
  if (num1 < num2) {
    return 1;
  } else if (num1 > num2) {
    return -1;
  } else {
    return 0;
  }
}
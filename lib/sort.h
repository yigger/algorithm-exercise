int *chose_sort(int *array, int length);
int *bubble_sort(int *array, int length);
int *insert_sort(int *array, int length);
int *no_swap_insert_sort(int *array, int length);
int *shell_sort(int *array, int length);

// 归并排序
void sort(int *array, int start, int end);
void merge(int arr[], int l, int m, int r);
int *merge_sort(int *array, int length);

// 快排
void quicksort(int array[], int maxlen, int begin, int end);
void quick_sort(int *array, int length);
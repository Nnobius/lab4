#include <stdio.h>
#include <math.h>

int sum_array (int *mass, int count)
{
	if (count == 0){
		return 0;
	}
	return *mass + sum_array(mass + 1, count - 1);
}

int sum_array_iter (int sum, int *mass, int count)
{
	if (count == 0){
		return sum;
	}
	sum = sum + *mass;
	mass = mass + 1;
	count = count - 1;
	return sum_array_iter(sum, mass, count);	
}

int fibonachi (int num)
{
	if (num == 2 || num == 1 ) {
		return 1;
	}
	printf("num = %d, fibonachi = %d\n", num, fibonachi (num - 1) + fibonachi (num - 2));
	return fibonachi (num - 1) + fibonachi (num - 2);
}

int fib_iter (int first, int second, int num, int tmp, int count )
{
	if (count > num){
		return tmp;
	}
	if (num == 1 || num == 2){
		return 1;
	}
	tmp = first + second;
	first = second;
	second = tmp;
	count ++;
	return fib_iter(first, second, num, tmp, count);
}

int string (char *str, int sum) 
{
	if (*str == '\0') {
		return sum;
	}
	sum = sum + (*str - 48) * pow(10, strlen(str) - 1);
	str = str + 1;
	return string(str, sum);
}

int main() {
	int arr[] = {1,2,3,4};
	int sum;
	int fib, i = 5;
	int fibf = 1, fibs = 1, count = 3, t = 0, fib_result;
	char str[] = {"1234"};
	int sumstr = 0;
	
	sum = sum_array_iter (sum, arr, 4);
	fib_result = fib_iter (fibf, fibs, 5, t, count );
	
	printf("Сумма элементов массива(рекурсивный процесс): %d\n", sum_array (arr, 4));
	printf("Сумма элементов массива(итеративный процесс): %d\n", sum);
	printf("Число Фибоначчи(рекурсивный процесс): %d\n", fibonachi (i));
	printf("Число Фибоначчи(итеративный процесс): %d\n", fib_result);
	printf("Конвертированая строка: %d\n", string (str, sumstr));
	
	return 0;
}

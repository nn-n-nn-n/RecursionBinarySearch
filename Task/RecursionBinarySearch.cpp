// Task.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "Task.h"
#include "algorithm"

void NewArray(int* array, int middle)
{
	//int* newArray = new int[middle];
	for (int i = 0; i < middle; i++)
		array[i] = array[i];
	//return array;
}

void NewArray2(int* array, int middle, int size)
{
	//int* newArray = new int[middle];
	for (int i = size-1, j = 0; i > middle; i--, j++)
		array[j] = array[i];
	//return array;
}

int RecursionBinarySearch(int* array, int size, int target)
{
	if (array == nullptr || size < 1) return -1;
	//int index = 0;
	int right = size - 1;
	int middle = right / 2;
	if (target > array[middle])
	{
		NewArray2(array, middle,size);
		size /= 2;
	}
	else if (target <= array[middle])
	{
		NewArray(array, middle);
		size /= 2;
	}
	if (size >= 1)
	{

		RecursionBinarySearch(array, size, target);
	}
	if (array[right] == target) return right;
	else return -1;
}

/*
Создайте РЕКУРСИВНУЮ функцию, которая ищет в сортированном по возрастанию целочисленном массиве 
указанное число и возвращает индекс первого элемента, относительно начала массива, который равен 
заданному числу. Нумерация элементов начинается с 0.

1. Функция должна иметь имя RecursionBinarySearch
2. Функция в качестве параметров должна принимать следующее:
	- первый параметр - указатель на сортированный массив
	- второй параметр - количество элементов массива
	- третий параметр - искомое значение

3. Функция должна возвращать индекс первого элемента, относительно начала массива, который равен
	заданному числу. Если число не найдено, необходимо вернуть -1.
	Тип возвращаемого результата - int.

	!!!!! ВАЖНО !!!!!
	В данном файле разрешается разместить кроме кода требуемой функции - код любых других вспомогательных
	функций. Никакой функции main() в этом файле быть не должно.
	Если вы хотите испытать и отладить вашу функцию - пишите код в файле Example.cpp проекта Example данного решения
	Для этого задайте в качестве запускаемого проекта проект Example.

	ДЛЯ АВТОМАТИЧЕСКОГО ТЕСТИРОВАНИЯ  проверки правильности работы вашего задания - сделайте запукаемым проект
	Tests и запустите его. Если функция написана правильно - все тесты должны успешно выполниться
	(зеленый цвет в консоли). Если ваша функция работает некорректно - в консоли будут сообщения красным цветом
*/

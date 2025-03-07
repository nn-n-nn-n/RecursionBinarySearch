﻿// Task.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "Task.h"
#include "algorithm"

int RecursionTarget(int* array, int left, int right, int target) 
{
	int middle = left + (right - left) / 2;							// поиск середины массива

	if (array[middle] == target) 
	{
		while (array[middle] == target)								// поиск элемента, с которого начинаются повторяющиеся числа
			middle--;
		if (array[middle] != target)								// если middle перебрал слишком далеко влево
			middle++;												// возвращаем его, сдвигая middle вправо
		return middle;
	}
	if (middle > target)											// если искомое значение меньше середины
		return RecursionTarget(array, left, middle - 1, target);	// сдвигаем правую границу
	else if (middle < target)										// если искомое значение больше середины
			return RecursionTarget(array, middle + 1, right, target);	// сдвигаем левую границу
}

int RecursionBinarySearch(int* array, int size, int target)
{
	if (size <= 0 || size == 1 && array[0] != target || target < array[0] || target > size) return -1;	// перебор условий при которых возникают ошибки
	if (array[0] == target)
		return 0;													// если первый элемент - искомое значение
	if (size > 1)
		return RecursionTarget(array, 0, size - 1, target);			// вызов рекурсивной функции
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

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

struct Rect
{
	int x1;
	int y1;
	int width;
	int height;
};

int getper(Rect rectangle)
{
	return (rectangle.height + rectangle.width) * 2;
}

void input_file(Rect* mas, int& size)
{
	FILE* ft;
	if (fopen_s(&ft, "save.txt", "rt") != 0)
	{
		printf("Ошибка чтения!");
		exit(1);
	}
	else
	{
		fscanf_s(ft, "%d", &size);

		for (int i = 0; i < size; i++)
			fscanf_s(ft, "%d %d %d %d", &mas[i].x1, &mas[i].y1, &mas[i].width, &mas[i].height);
		fclose(ft);
	}
}

void output_file(Rect* mas, int size)
{
	FILE* f;

	if (fopen_s(&f, "save.txt", "w+") != 0)
	{
		printf("Ошибка записи!");
		exit(1);
	}
	else
	{
		fprintf_s(f, "%d\n", size);
		for (int i = 0; i < size; i++)
			fprintf_s(f, "%d %d %d %d\n", mas[i].x1, mas[i].y1, mas[i].width, mas[i].height);
		fclose(f);
	}
}

void selffill(Rect* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		do
		{
			system("cls");
			printf("Ввод %d Прямоугольника\nКоордината X верхнего левого угла = ", i);
			scanf_s("%d", &mas[i].x1);
			printf("Координата Y верхнего левого угла = ");
			scanf_s("%d", &mas[i].y1);
			printf("Ширина = ");
			scanf_s("%d", &mas[i].width);
			printf("Высота = ");
			scanf_s("%d", &mas[i].height);
		} while (mas[i].width <= 0 || mas[i].height <= 0);
	}
}

void printmas(Rect mas[], int size)
{
	system("cls");
	printf("Список прямоугольников:\n");
	for (int i = 0; i < size; i++)
	{
		printf("\nПрямоугольник №%d:\nВершины: (%d;%d);(%d;%d);(%d;%d);(%d;%d)\nПериметр= %d\n", i, mas[i].x1, mas[i].y1, mas[i].x1 + mas[i].width, mas[i].y1, mas[i].x1 + mas[i].width, mas[i].y1 + mas[i].height, mas[i].x1, mas[i].y1 + mas[i].height, getper(mas[i]));
	}
}

void choosetype(int& type)
{
	do
	{
		system("cls");
		printf("Способы ввода:\n1 - с клавиатуры\n2 - из файла\nВыбор : ");
		scanf_s("%d", &type);
	} while (type < 1 || type > 2);
}

void setsize(int& size)
{
	do
	{
		system("cls");
		printf("Введите количество прямоугольников = ");
		scanf_s("%d", &size);
	} while (size <= 0 || size > 100);
}

void switcher(Rect* mas, int& size, int type)
{
	switch (type)
	{
	case 1:
	{
		system("cls");
		selffill(mas, size);
		break;
	}
	case 2:
	{
		system("cls");
		input_file(mas, size);
		break;
	}
	default:
		break;
	}
}

bool mining(int a, int b)
{
	if (a <= b)
		return true;
	return false;
}

void getmin(Rect mas[], int size, int& min, int& index)
{
	for (int i = 0; i < size; i++)
	{
		int area = getper(mas[i]);
		if (mining(area, min))
		{
			min = area;
			index = i;
		}
	}
}

int main()
{
	system("chcp 1251 > nul");
	srand(time(NULL));

	int type = 0, size = 0, min = 10000000, index = 0;
	Rect mas[100];

	choosetype(type);

	if (type != 2)
		setsize(size);

	switcher(mas, size, type);

	printmas(mas, size);

	getmin(mas, size, min, index);

	printf("\nПериметр прямоугольника №%d минимален и равен %d\nВершины: (%d;%d);(%d;%d);(%d;%d);(%d;%d)", index, min, mas[index].x1, mas[index].y1, mas[index].x1 + mas[index].width, mas[index].y1, mas[index].x1 + mas[index].width, mas[index].y1 + mas[index].height, mas[index].x1, mas[index].y1 + mas[index].height);

	output_file(mas, size);

	return 0;
}
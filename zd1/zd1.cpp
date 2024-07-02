#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <locale.h>

typedef struct tochka
{
	double x;
	double y;
}Point;

typedef struct primoygl
{
	Point a;
	Point c;
}Rectangl;



Rectangl Vvod(Rectangl p)
{
	double c;
	printf("Введите первую точку\n");
	scanf("%lf %lf", &p.a.x, &p.a.y);
	printf("\n");
	printf("Введите вторую точку\n");
	scanf("%lf %lf", &p.c.x, &p.c.y);
	printf("\n");
	if (p.a.x > p.c.x) {
		c = p.a.x;
		p.a.x = p.a.x;
		p.a.x = c;
	}
	if (p.a.y > p.c.y) {
		c = p.a.y;
		p.a.y = p.c.y;
		p.c.y = c;
	}
	return p;
}

double Ploshad(Rectangl p)
{
	
	return sqrt(pow(p.c.x - p.a.x, 2) + pow(p.c.y - p.a.y, 2));
}

int proverka(Point o, Rectangl b)
{
	if ((o.y >= b.a.y) && (o.y <= b.c.y) && (o.x >= b.a.x) && (o.x <= b.c.x))
		return 1;
	else return 0;
}

 int proverochka(Rectangl p, Rectangl k)
 {
	 if (proverka(p.a, k) == 1 && proverka(p.c, k) == 1)
		 return 1;
	 else return 0;
 }

 Rectangl peresechenie(Rectangl p, Rectangl b)
 {
	 Rectangl c;
	 if (proverka(p.a, b) == 1 || proverka(p.c, b) == 1) {
		 if (p.a.x > b.a.x) c.a.x = p.a.x;
		 else  c.a.x = b.a.x;
		 if (p.a.y > b.a.y) c.a.y = p.a.y;
		 else c.a.y = b.a.y;
		 if (p.c.x < b.c.x) c.c.x = p.c.x;
		 else c.c.x = b.c.x;
		 if (p.c.y < b.c.y) c.c.y = p.c.y;
		 else c.c.y = b.c.y;
	 }
	 else printf("прямоугольники не пересекаются\n");
	 return c;
 }

 Rectangl povorot(Rectangl p)
 {
	 int l, h;
	 Point mid;
	 mid.x = (p.a.x + p.c.x) / 2;
	 mid.y = (p.a.y + p.c.y) / 2;
	 l = p.c.x - p.a.x;
	 h = p.c.y - p.a.y;
	 p.a.x = mid.x - l / 2;
	 p.c.x = mid.x + l / 2;
	 p.a.y = mid.y - h / 2;
	 p.c.y = mid.y + h / 2;
	 return p;
 }


 int main()
 {
	 Rectangl* a;
	 int count, k, n, i, j;
	 SetConsoleCP(1251);
	 SetConsoleOutputCP(1251);
	 printf("ВВедите количество прямоугольников\n");
	 scanf("%d", &count);
	 printf("\n");
	 a = (Rectangl*)malloc(sizeof(Rectangl) * (count));
	 for (i = 0; i < count; i++) {
		 a[i] = Vvod(a[i]);
	 }

	 k = -1;
	 n = 0;
	 for (i = 0; i < count - 1; i++)
		 for (j = i+1; j < count; j++)
		 {
			 if ((Ploshad(a[i]) < n || n == 0) && proverochka(a[i], a[j])==1) {
				 n = Ploshad(a[i]);
				 k = i;
			 }
			 if ((Ploshad(a[j]) < n || n == 0) && proverochka(a[j], a[i]) == 1) {
				 n = Ploshad(a[j]);
				 k = j;
			 }
		 }
	 if (k != -1)
		 printf("Прямоугольник %d имеет наименьшую площадь и содержит в себе один или болеее прямоугольников\n", (k + 1));

	 for (i = 0; i < count - 1; i++)
		 for (j = i+1; j < count; j++)
		 {
			 if (a[i].a.x == a[j].a.x && a[i].c.x == a[j].c.x && a[i].a.y == a[j].a.y && a[i].c.y == a[j].c.y) printf("Прямоугольники %d и %d равны с точночть до поворота угла\n", (i + 1), (j + 1));
			 a[i] = povorot(a[i]);
			 if (a[i].a.x == a[j].a.x && a[i].c.x == a[j].c.x && a[i].a.y == a[j].a.y && a[i].c.y == a[j].c.y) printf("Прямоугольники %d и %d равны с точночть до поворота угла\n", (i + 1), (j + 1));
		 }
	 system("pause");
 }
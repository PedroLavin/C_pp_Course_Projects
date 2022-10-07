// Project6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <vector>

class shape {
public:
	virtual ~shape() {};
	virtual double perimeter() = 0;
	virtual double area() = 0;
	virtual double surface_area() = 0;
	virtual double volume() = 0;
	virtual void info() = 0;
};

class two_d_shape  : public shape
{
public:
	virtual ~two_d_shape() {};
	virtual double perimeter()=0;
	virtual double area()=0;
	virtual void info() = 0;
};

class three_d_shape : public shape
{
public:
	virtual ~three_d_shape() {}
	virtual double surface_area() = 0;
	virtual double volume() = 0;
	virtual void info() = 0;
};

class cube : public three_d_shape
{
protected:
	double side;
public:
	cube(double side) : side{ side } {}
	~cube() {}
	double area() { return 0; }
	double perimeter() { return 0; }
	double volume() { return (pow(side, 3)); }
	double surface_area() { return 6 * side * side; }
	void info() { std::cout << std::setprecision(3) << "The area of the cube is " << surface_area() << " and its volume " << volume() << std::endl; }
};

class rectangle : public two_d_shape
{
protected:
	double long_side;
	double short_side;
public:
	rectangle(double l_side, double s_side) : long_side{ l_side }, short_side{ s_side } {}
	~rectangle(){}
	double perimeter() { return (2 * long_side) + (2 * short_side); }
	double area() { return (long_side * short_side); }
	double surface_area() { return 0; }
	double volume() { return 0; }
	void info() { std::cout << std::setprecision(3) << "The area of the rectangle is " << area() << " and its perimeter is " << perimeter() << std::endl; }
};

class triangle : public two_d_shape
{
protected:
	double side_a;
	double side_b;
	double side_c;
public:
	triangle(double side_a, double side_b, double side_c) : side_a{ side_a }, side_b{ side_b }, side_c{ side_c } {}
	~triangle(){}
	double perimeter() { return side_a + side_b + side_c; }
	double area() {
		double half_perimeter{ perimeter() / 2 };
		return pow(half_perimeter * (half_perimeter - side_a) * (half_perimeter - side_b) * (half_perimeter - side_c), 0.5); }
	double surface_area() { return 0; }
	double volume() { return 0; }
	void info() { std::cout << std::setprecision(3) << "The area of the triangle is " << area() << " and its perimeter is " << perimeter() << std::endl; }
};

class square : public two_d_shape
{
protected:
	double side;
public:
	square(double side) : side{ side } {}
	~square() {}
	double perimeter() { return (4 * side); }
	double area() { return (pow(side, 2)); }
	double surface_area() { return 0; }
	double volume() { return 0; }
	void info() { std::cout << std::setprecision(3) << "The area of the square is " << area() << " and its perimeter is " << perimeter() << std::endl; }
};

class circle : public two_d_shape
{
protected:
	double radius;
public:
	circle(double radius) : radius{ radius } {}
	~circle() {}
	double perimeter() { return 2 * M_PI * radius;}
	double area() { return (M_PI *  pow(radius, 2)); }
	double surface_area() { return 0; }
	double volume() { return 0; }
	void info() { std::cout << std::setprecision(3) << "The area of the circle is " << area() << " and its circumference is " << perimeter() << std::endl; }
};

class ellipse : public two_d_shape
{
protected:
	double long_radius;
	double short_radius;
public:
	ellipse(double long_radius, double short_radius) : long_radius{ long_radius }, short_radius{ short_radius } {}
	~ellipse() {}
	double perimeter() 
	{
		double l_plus_s_squared{ pow(long_radius + short_radius, 2) };
		double l_minus_s_squared{ pow(long_radius - short_radius, 2) };
		double square_factor{ pow((-3 * l_minus_s_squared / l_plus_s_squared) + 4, 0.5) + 10 };
		return (M_PI * (long_radius + short_radius) * ((3 * l_minus_s_squared) / ((l_plus_s_squared)*square_factor) + 1));
	}
	double area() { return (M_PI *  short_radius * long_radius); }
	double surface_area() { return 0; }
	double volume() { return 0; }
	void info() { std::cout << std::setprecision(3) << "The area of the ellipse is " << area() << " and its perimeter is " << perimeter() << std::endl; }
};

class cuboid : public three_d_shape
{
protected:
	double side_a;
	double side_b;
	double side_c;
public:
	cuboid(double side_a, double side_b, double side_c) : side_a{ side_a }, side_b{ side_b }, side_c{ side_c } {}
	~cuboid() {}
	double area() { return 0; }
	double perimeter() { return 0; }
	double surface_area() { return 2 * (side_a * side_b + side_a * side_c + side_b * side_c); }
	double volume() { return side_a * side_b * side_c; }
	void info() { std::cout << std::setprecision(3) << "The surface area of the cuboid is " << surface_area() << " and the volume is " << volume() << std::endl; }
};

class sphere : public three_d_shape
{
protected:
	double radius;
public:
	sphere(double radius) : radius{radius} {}
	~sphere() {}
	double area() { return 0; }
	double perimeter() { return 0; }
	double surface_area() { return 4 * M_PI * pow(radius, 2); }
	double volume() { return (4.0 / 3.0) * M_PI * pow(radius, 3); }
	void info() { std::cout << std::setprecision(3) << "The surface area of the sphere is " << surface_area() << " and the volume is " << volume() << std::endl; }
};

class ellipsoid : public three_d_shape
{
protected:
	double side_a;
	double side_b;
	double side_c;
public:
	ellipsoid(double side_a, double side_b, double side_c) : side_a{ side_a }, side_b{ side_b }, side_c{ side_c } {}
	~ellipsoid() {}
	double area() { return 0; }
	double perimeter() { return 0; }
	double surface_area() 
	{ 
		double a_times_b{ pow(side_a * side_b, 1.6) };
		double c_times_b{ pow(side_c * side_b, 1.6) };
		double a_times_c{ pow(side_a * side_c, 1.6) };
		return 4 * M_PI * pow((a_times_b + c_times_b + a_times_c) / 3, 1 / 1.6);
	}
	double volume() { return (4 / 3) * M_PI * side_a * side_b * side_c; }
	void info() { std::cout << std::setprecision(3) << "The surface area of the ellipsoid is " << surface_area() << " and the volume is " << volume() << std::endl; }
};

class prism : public two_d_shape
{
protected:
	double height;
	two_d_shape* figure_2;
public:
	prism(two_d_shape* figure, double height) :figure_2{ figure }, height { height } {}
	~prism() {}
	double area() { return 0; }
	double perimeter() { return 0; }
	double surface_area() { return 2 * (figure_2->area()) + (figure_2->perimeter() * height); }
	double volume() { return figure_2->area() * height; }
	void info() 
	{ 
		std::cout << std::setprecision(3) << "The surface area of the prism is " << surface_area() << " and the volume is " << volume() << std::endl; 
	}
};


int main()
{
	shape** shape_array = new shape*[10];
	shape_array[0] = new square(5);
	shape_array[1] = new rectangle(5, 2);
	shape_array[2] = new circle(1);
	shape_array[3] = new ellipse(1, 2);
	shape_array[4] = new cube(2);
	shape_array[5] = new cuboid(1, 2, 3);
	shape_array[6] = new ellipsoid(1, 2, 3);
	shape_array[7] = new sphere(1);
	shape_array[8] = new triangle(1, 1, 1);
	two_d_shape* sq = new square(1);
	shape_array[9] = new prism(sq, 5);

	for (int counter{}; counter < 10; counter++) {
		shape_array[counter]->info();
		delete [] shape_array[counter];
	}
	delete[] shape_array;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

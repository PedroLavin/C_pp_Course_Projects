// Project_4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <math.h>
#include <fstream>

class complex_number {

private :
    double real_part{};
    double imaginary_part{};

public :
    complex_number() = default;

    complex_number(double real, double imaginary) : real_part{ real }, imaginary_part{ imaginary } {}

    double get_real() const;
    double get_imaginary() const;
    double modulus() const;
    double argument() const;
    complex_number conjugate() const;
    complex_number operator+(const complex_number number_1) const;
    complex_number operator-(const complex_number number_1) const;
    complex_number operator*(const complex_number number_1) const;
    complex_number operator/(const complex_number number_1) const;
    friend std::ostream& operator<<(std::ostream& os, const complex_number& number);
    friend std::istream& operator>>(std::istream& is, complex_number& number);
    
};

complex_number complex_number::conjugate() const 
{
    return complex_number(real_part, imaginary_part * (-1));
}

double complex_number::modulus() const 
{
    double modulus{ };
    modulus = sqrt(pow(real_part, 2) + pow(imaginary_part, 2));

    return modulus;
}

double complex_number::argument() const 
{
    double argument{ };
    argument = atan(imaginary_part / real_part) * 180 / M_PI;

    return argument;
}

complex_number complex_number::operator+(const complex_number number_1) const 
{
    complex_number sum;
    double real{};
    double imaginary{};

    real = real_part + number_1.get_real();
    imaginary = imaginary_part + number_1.get_imaginary();

    sum = complex_number(real, imaginary);
    return sum;
}

complex_number complex_number::operator-(const complex_number number_1) const 
{
    complex_number substraction;
    double real{};
    double imaginary{};

    real = real_part - number_1.get_real();
    imaginary = imaginary_part - number_1.get_imaginary();

    substraction = complex_number(real, imaginary);
    return substraction;
}

complex_number complex_number::operator*(const complex_number number_1) const 
{
    complex_number multiplication;
    double real{};
    double imaginary{};

    real = real_part * number_1.get_real() - imaginary_part * number_1.get_imaginary();
    imaginary = real_part * number_1.get_imaginary() + imaginary_part * number_1.get_real();

    multiplication = complex_number(real, imaginary);
    return multiplication;
}

complex_number complex_number::operator/(const complex_number number_1) const 
{
    complex_number division;
    complex_number numerator(real_part, imaginary_part);
    complex_number multiplication_with_conjugate;
    double real{};
    double imaginary{};

    multiplication_with_conjugate = numerator * number_1.conjugate();
    real = multiplication_with_conjugate.get_real() / pow(number_1.modulus(), 2);
    imaginary = multiplication_with_conjugate.get_imaginary() / pow(number_1.modulus(), 2);

    division = complex_number(real, imaginary);

    return division;
}

double complex_number::get_real() const 
{
    return (real_part);
}

double complex_number::get_imaginary() const 
{
    return (imaginary_part);
}

std::ostream& operator<<(std::ostream& os, const complex_number& number) 
{
    std::string check_real_sign;
    std::string check_imaginary_sign;
    double real_number{number.get_real()};
    double imaginary_number{ number.get_imaginary()};

    if (real_number < 0) {
        check_real_sign = "-";
        real_number = real_number * -1;
    }
    else if (real_number == 0) {
        check_real_sign = "";
        real_number = 0;
    }
    else
        check_real_sign = "";
    if (imaginary_number < 0) {
        check_imaginary_sign = "-";
        imaginary_number = imaginary_number * -1;
    }

    else if (imaginary_number > 0)
        check_imaginary_sign = "+";
    else {
        imaginary_number = 0;
        check_imaginary_sign = "+";
    }
    os << check_real_sign << real_number << check_imaginary_sign << "i" << imaginary_number;
    return os;
}

std::istream& operator>>(std::istream& is, complex_number& number_complex) 
{
    double real{};
    double imag{};
    char sign;
    char i;
    
    is >> real;
    is >> sign;
    is >> i;
    is >> imag;
    if (sign == '-')
        number_complex = complex_number(real, imag * -1);
    else
        number_complex = complex_number(real, imag);
    return is;
}

int main() {
    std::cout.precision(3);

    complex_number comp;
    complex_number num; 

    std::cout << "Let's define the two complex numbers. The first one:" << std::endl;
    std::cin >> comp;
    std::cout << "Now, the second one: " << std::endl;
    std::cin >> num;
    std::cout << "The real part of the first complex number is: " << comp.get_real() << ", and the imaginary part is: " << comp.get_imaginary() << ".\n";
    std::cout << "The real part of the second complex number is: " << num.get_real() << ", and the imaginary part is: " << num.get_imaginary() << ".\n";
    std::cout << "The modulus of the first one is: " << comp.modulus() << std::endl;
    std::cout << "The modulus of the second one is: " << num.modulus() << std::endl;
    std::cout << "The argument of the first one is: " << comp.argument() << " degrees." << std::endl;
    std::cout << "The argument of the second one is: " << num.argument() << " degrees." << std::endl;
    std::cout << "The conjugate of the first one is: " << comp.conjugate() << std::endl;
    std::cout << "The conjugate of the second one is: " << num.conjugate() << std::endl;
    std::cout << "The sum is: " << comp + num << std::endl;
    std::cout << "The substraction is: " << comp - num << std::endl;
    std::cout << "The multiplication is: " << comp * num << std::endl;
    std::cout << "The division is: " << comp / num << std::endl;
}
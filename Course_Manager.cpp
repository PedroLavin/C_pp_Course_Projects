// Assignment_2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include<vector>
#include <math.h>
#include <iomanip>


int stoint(std::string a_string){
    //A function to convert from a string to a number

    int size{};
    int counter{};
    int number{};
    while (a_string[size] != '\0')
        size++;
    while (counter < size) {
        number = number + (a_string[counter] + '0');
        counter++;
    }
    return number;
}

int compare_strings(std::string string1, std::string string2) {
    //A function that compares two strings and returns 1 if the first one comes before alphabetically
    //and -1 if it is the opposite.
    size_t size{ string1.size() };
    int counter{};
    while (counter < size) {
        if (string1[counter] < string2[counter])
            return 1;
        else if (string1[counter] > string2[counter])
            return -1;
        else
            counter++;
    }
    return 1;
}

std::string itos(int number) {

    std::string my_string;
    std::stringstream ss;
    ss << number;
    ss >> my_string;
    return my_string;
}

class course {
    //A class is defined that describes a course, which has mark, code and title, and includes one method to print these data.
public:
    double course_mark;
    double course_code;
    std::string course_title;
public:
    course() = default;

    course(std::string mark, std::string code, std::string title) : course_mark{ std::stod(mark) }, course_code{ std::stod(code) }, course_title{ title }
    {}
    void print_data();
};

class course_manager {
    //Define a class that takes in a number of courses and can perform several methods with them.
    //It takes as input a vector containing all the courses.
public:
    std::vector <course> course_list;

public:
    course_manager() = default;

    course_manager(std::vector<course> list) : course_list(list)
    {}

    int size_of_file();
    double mean_of_marks();
    double standard_dev();
    double standard_error();
    void print_mean_and_error();
    void print_all_data();
    std::vector <course> print_by_year(int year);
    std::vector <course> sort_by_code();
    std::vector <course> sort_by_marks();
    std::vector <course> sort_by_title();


};

void course::print_data() {
    std::ostringstream output_stream;
    output_stream  << "PHYS " << course_code << " " << course_title;
    std::string output_filename{ output_stream.str() };
    std::cout << output_filename << std::endl;
}

int course_manager::size_of_file() {
    //This method calculates the size of the whole file: the number of courses.
    int counter{ 0 };
    for (auto course_it = course_list.begin(); course_it < course_list.end(); ++course_it)
        counter++;
    return counter;
}

double course_manager::mean_of_marks() {

    //This method calculates the mean of the marks of all the courses using a for loop over all the courses.

    int counter{ 0 };
    double total_sum{ 0 };

    for (auto course_it2 = course_list.begin(); course_it2 < course_list.end(); ++course_it2) {
        total_sum = total_sum + course_list[counter].course_mark;
        counter++;
    }
    return total_sum / counter;
}

double course_manager::standard_dev() {

    //This method calculates the standard deviation of all the courses.

    double mean{ course_manager::mean_of_marks() };
    int counter{ 0 };
    double sum{ 0.0 };
    for (auto course_it = course_list.begin(); course_it < course_list.end(); ++course_it) {
        sum = sum + pow(course_list[counter].course_mark - mean, 2);
        counter++;
    }
    sum = sqrt(sum / (counter - 1));
    return sum;
}

double course_manager::standard_error() {

    //This method calculates the standard error of all the courses.

    double mean{ mean_of_marks() };
    double std_dev{ standard_dev() };
    int size{ size_of_file() };
    return (std_dev / sqrt(size));
}

void course_manager::print_mean_and_error() {

   //This method prints the mean, the standard deviation and the standard error.

std::cout << "The mean of the courses is: " << /*std::setprecision(3) <<*/ mean_of_marks() << ". The standard deviation is: " << standard_dev() << ". The standard error is: " << standard_error() << std::endl;
}

std::vector <course> course_manager::print_by_year(int year) {

    //This method returns a vector of courses which have been filtered by the year they are coursed in.
    //This is done by comparing the first character of the code transformed to a string and the inputted year
    // and if it belongs, the entire course is added to the new vector.

    course_manager manager = course_manager();
    std::vector <course> vector_1;

    int counter{ 0 };
    for (auto course_it = course_list.begin(); course_it < course_list.end(); ++course_it) {
        if (std::to_string(course_list[counter].course_code)[0] == std::to_string(year)[0]) {
            manager.course_list.push_back(course_list[counter]);
            counter++;
        }
        else
            counter++;
    }
    vector_1 = manager.course_list;
    return vector_1;
}

void course_manager::print_all_data(){

    //This method iterates throughout the whole list of courses and prints the information of each of them.

    int counter{};
    for (auto course_it2 = course_list.begin(); course_it2 < course_list.end(); ++course_it2) {
        course_list[counter].print_data();
        counter++;
    }
}

std::vector <course> course_manager::sort_by_code() {

    //This method compares consecutive codes of courses and if the second one is lower than the first, 
    //the whole course is swapped. This happens until the list is sorted by code in ascending order.

    course_manager manager1 = course_manager();
    std::vector <course> vector1{ course_list };
    int exit_loop{};
    int size{ size_of_file() };
    do {
        int counter{ 0 };
        double dummy{};
        while (counter < size - 1) {
            if (vector1[counter].course_code < vector1[counter + 1].course_code) {
                counter++;
            }
            else {
                dummy = vector1[counter].course_mark;
                vector1[counter].course_mark = vector1[counter + 1].course_mark;
                vector1[counter + 1].course_mark = dummy;

                dummy = vector1[counter].course_code;
                vector1[counter].course_code = vector1[counter + 1].course_code;
                vector1[counter + 1].course_code = dummy;

                std::swap(vector1[counter].course_title, vector1[counter + 1].course_title);
                exit_loop++;
            }
        }
    } while (exit_loop != 0);
    return vector1;
}

std::vector <course> course_manager::sort_by_marks() {

    //This method performs the same as the previous method, but it compares the marks of each course.
    //It sorts the courses in ascending order of marks.

    course_manager manager1 = course_manager();
    std::vector <course> vector1{ course_list };
    int size{ size_of_file() };
    int exit_loop{};
    do {
        int counter{ 0 };
        double dummy{};
        exit_loop = 0;
        while (counter < size - 1) {
            if (vector1[counter].course_mark <= vector1[counter + 1].course_mark) {
                counter++;
            }
            else {
                dummy = vector1[counter].course_mark;
                vector1[counter].course_mark = vector1[counter + 1].course_mark;
                vector1[counter + 1].course_mark = dummy;

                dummy = vector1[counter].course_code;
                vector1[counter].course_code = vector1[counter + 1].course_code;
                vector1[counter + 1].course_code = dummy;

                std::swap(vector1[counter].course_title, vector1[counter + 1].course_title);
                exit_loop++;
            }
        }

    } while (exit_loop > 0);
    manager1.course_list = vector1;
    return vector1;
}

std::vector <course> course_manager::sort_by_title() {

    //This method sorts the courses in ascending order of titles, this is, the ones that come
    //first alphabetically will be first.

    course_manager manager1 = course_manager();
    std::vector <course> vector1{ course_list };
    int size{ size_of_file() };
    int exit_loop{};
    do {
        int counter{ 0 };
        double dummy{};
        exit_loop = 0;
        while (counter < size - 1) {
            if (compare_strings(vector1[counter].course_title, vector1[counter + 1].course_title) == 1) {
                counter++;
            }
            else {
                dummy = vector1[counter].course_mark;
                vector1[counter].course_mark = vector1[counter + 1].course_mark;
                vector1[counter + 1].course_mark = dummy;

                dummy = vector1[counter].course_code;
                vector1[counter].course_code = vector1[counter + 1].course_code;
                vector1[counter + 1].course_code = dummy;

                std::swap(vector1[counter].course_title, vector1[counter + 1].course_title);
                exit_loop++;
            }
        }

    } while (exit_loop > 0);
    manager1.course_list = vector1;
    return vector1;
}

int main() {
    std::string my_string;
    std::string your_file;
    std::vector <std::string> marks_vector;
    std::vector <std::string> codes_vector;
    std::vector <std::string> titles_vector;
    std::vector <course> course_vector;
    std::vector <std::string> courses;
    int counter2{};
    int counter3{};
    std::cout << "Please, input your desire file: " << std::endl;
    std::cin >> your_file;
    std::fstream my_file{ your_file + ".txt" };

    if (!my_file.good()) 
        std::cout << "The file could not be found or is in the incorrect format.";

    while (!my_file.eof()) {
        std::getline(my_file, my_string, ' ');
        marks_vector.push_back(my_string);

        std::getline(my_file, my_string, ' ');
        codes_vector.push_back(my_string);

        std::getline(my_file, my_string);
        titles_vector.push_back(my_string);
    }
    my_file.close();

    size_t size_of_course{ marks_vector.size() };

    for (int counter = 0; counter < size_of_course; ++counter) {
        titles_vector[counter] = titles_vector[counter].erase(0, 2);
        course_vector.push_back(course(marks_vector[counter], codes_vector[counter], titles_vector[counter]));
        std::ostringstream output_stream;
        output_stream << "PHYS " << codes_vector[counter] << " " << titles_vector[counter];
        std::string output_filename{ output_stream.str() };
        courses.push_back(output_filename);
    }

    course_manager course_manager_1 = course_manager(course_vector);

    //Number of methods in the file:

    int number_of_methods{};
    number_of_methods = course_manager_1.size_of_file();

    //To print information about all the courses, use the method print_all_data:
    course_manager_1.print_all_data();

    //Calculate the mean of the marks of all the courses:
    double mean_of_file{};
    mean_of_file = course_manager_1.mean_of_marks();

    //Calculate the standard deviation of the files:
    double standard_deviation{};
    standard_deviation = course_manager_1.standard_dev();

    //Calculate the standard error of the marks of the files:
    double standard_error{};
    standard_error = course_manager_1.standard_error();

    //To print all these data, use the method print_mean_and_error:
    course_manager_1.print_mean_and_error();

    //Create a course manager that only contains courses from a specific year:
    int year{ 1 };
    course_manager sort_year = course_manager(course_manager_1.print_by_year(year));

    //With this new course manager, the mean, standard deviation and error can be calculated using the appropriate method.
    //The following commented line would print the mean and erro of the courses filtered by year.
    
    //sort_year.print_mean_and_error();

    //The following method create new course manager sorting the given courses by marks, codes and titles:

    course_manager mark_sort = course_manager(course_manager_1.sort_by_marks());
    course_manager code_sort = course_manager(course_manager_1.sort_by_code());
    course_manager title_sort = course_manager(course_manager_1.sort_by_title());

    //With these methods, courses can be filtered from a particular year and sort that list by marks, codes or titles:
    //For instance:

    course_manager title_sort_year = course_manager_1.print_by_year(4);
    title_sort_year.print_mean_and_error();
    
    //The following lines are to print the data of the previous courses and the mean and error. 
    //It is under comments.

    //title_sort_year.print_all_data();
    //title_sort_year.print_mean_and_error();
}

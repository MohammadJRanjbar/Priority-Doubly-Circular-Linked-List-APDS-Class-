#ifndef aphw4_H
#define aphw4_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include<student.h>
#include<apds.h>
std::vector<Student> getData(const char* filename);
void show(std::vector<Student> student);
void show(const APDS& ap);
#endif
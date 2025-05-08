cmake_minimum_required(VERSION 3.28)
project(OOP)

set(CMAKE_CXX_STANDARD 11)

add_executable(app8-1
        homework/8/8-1/app8-1.cpp
        homework/8/8-1/myString.cpp
        homework/8/8-1/myString.h
        homework/8/8-1/Student.cpp
        homework/8/8-1/Student.h

)

add_executable(app8-2
        homework/8/8-2/app8-2.cpp
        homework/8/8-2/body/Person.cpp
        homework/8/8-2/header/Person.h
        homework/8/8-2/body/Stduent.cpp
        homework/8/8-2/header/Student.h
        homework/8/8-2/body/GraduateStudent.cpp
        homework/8/8-2/header/GraduateStudent.h
        homework/8/8-2/body/Teacher.cpp
        homework/8/8-2/header/Teacher.h
        homework/8/8-2/body/Tdate.cpp
        homework/8/8-2/header/Tdate.h
        homework/8/8-2/body/myString.cpp
)
add_executable(c11-1 lesson/class11/11-1/c11-1.cpp)
add_executable(c11-2 lesson/class11/11-2/c11-2.cpp)

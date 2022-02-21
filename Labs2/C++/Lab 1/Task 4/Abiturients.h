#pragma once

#include <cmath>
#include <string>
#include <istream>
#include <fstream>
#include <iostream>



class Abiturients
{
 
public:
    std::string name;
    std::string specialization;
    double avg_mark;
    int math, physics, russian;
    //std::string tmp_math, tmp_phys, tmp_rus;
    friend std::istream& operator>>(std::istream&, Abiturients&);
    

    //Abiturients(std::string name = "Ivanov Ivan", std::string spec = "Programmer", double avg_m = 9.2,
    //    )


};
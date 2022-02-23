#pragma once

#include <QtWidgets/QMainWindow>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <qfiledialog.h>


class Abiturients
{

public:
    std::string name;
    std::string specialization;
    double avg_mark;
    int math, physics, russian;
    int total_rate;
    //std::string tmp_math, tmp_phys, tmp_rus;
    friend std::istream& operator>>(std::istream&, Abiturients&);
    friend std::ostream& operator<<(std::ostream&, Abiturients&);
    //Abiturients* initializeAbit();

    //Abiturients(std::string name = "Ivanov Ivan", std::string spec = "Programmer", double avg_m = 9.2,
    //    )


};
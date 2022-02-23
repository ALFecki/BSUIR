
#include "Abiturients.h"


std::istream& operator>>(std::istream& oper, Abiturients& abitur)
{
    getline(oper, abitur.name);
    getline(oper, abitur.specialization);
    oper >> abitur.avg_mark;
    oper.ignore();
    oper >> abitur.math;
    oper.ignore();
    oper >> abitur.physics;
    oper.ignore();
    oper >> abitur.russian;
    oper.ignore();
    /*int marks_sum = 0, marks_num = 0;
    marks_num =  abitur.tmp_math.length() / 2 + 1;
    abitur.math = new int[marks_num];*/
    //for (int i = 0, j = 0; i < abitur.tmp_math.length(); i++)
    //{
    //    if (abitur.tmp_math[i] != 32)
    //    {
    //        if (abitur.tmp_math[i] == 48) continue;
    //        if (abitur.tmp_math[i + 1] != '\0' && abitur.tmp_math[i] == 49 && abitur.tmp_math[i + 1] == 48)
    //        {
    //            abitur.math[j] = 10;
    //            j++;
    //            continue;
    //        }
    //        abitur.math[j] = (int)abitur.tmp_math[i] - 48;
    //        marks_sum += abitur.math[j];
    //        j++;
    //    }
    //}
    //getline(oper, abitur.tmp_phys);
    //marks_num += abitur.tmp_phys.length() / 2 + 1;
    //abitur.physics = new int[abitur.tmp_phys.length() / 2 + 1];
    ////for (int i = 0, j = 0; i < abitur.tmp_phys.length(); i++)
    ////{
    ////    if (abitur.tmp_phys[i] != 32)
    ////    {
    ////        if (abitur.tmp_phys[i] == 48) continue;
    ////        if (abitur.tmp_phys[i + 1] != '\0' && abitur.tmp_phys[i] == 49 && abitur.tmp_phys[i + 1] == 48)
    ////        {
    ////            abitur.physics[j] = 10;
    ////            j++;
    ////            continue;
    ////        }
    ////        abitur.physics[j] = (int)abitur.tmp_phys[i] - 48;
    ////        marks_sum += abitur.physics[j];
    ////        j++;
    ////    }
    ////}
    //getline(oper, abitur.tmp_rus);
    //marks_num += abitur.tmp_rus.length() / 2 + 1;
    //abitur.russian = new int[abitur.tmp_rus.length() / 2 + 1];
    ////for (int i = 0, j = 0; i < abitur.tmp_rus.length(); i++)
    ////{
    ////    if (abitur.tmp_rus[i] != 32)
    ////    {
    ////        if (abitur.tmp_rus[i] == 48) continue;
    ////        if (abitur.tmp_rus[i + 1] != '\0' &&  abitur.tmp_rus[i] == 49 && abitur.tmp_rus[i + 1] == 48)
    ////        {
    ////            abitur.russian[j] = 10;
    ////            j++;
    ////            continue;
    ////        }
    ////        abitur.russian[j] = (int)abitur.tmp_rus[i] - 48;
    ////        marks_sum += abitur.russian[j];
    ////        j++;
    ////    }
    ////}
    //abitur.avg_mark = marks_sum / marks_num;
    return oper;
}

std::ostream& operator<<(std::ostream& out, Abiturients& abitur)
{
    out << "Name:" << abitur.name << std::endl;
    out << "Specialization: " << abitur.specialization << std::endl;
    out << "Average mark: " << abitur.avg_mark << std::endl;
    out << "Mathematics: " << abitur.math << std::endl;
    out << "Physics: " << abitur.physics << std::endl;
    out << "Russian: " << abitur.russian << std::endl;
    out << "=======================================================" << std::endl;
    return out;
}


//std::istream& operator<<(std::istream& oper, Abiturients& abitur)
//{
//    oper<< abitur.name;
//};














//Abiturients* AddMemory(Abiturients* abitur, int num_elements)
//{
//    if (num_elements == 0)
//    {
//        abitur = new Abiturients[num_elements + 1];
//    }
//    else
//    {
//        Abiturients* abitur_temp = new Abiturients[num_elements + 1];
//
//        for (int i = 0; i < num_elements; i++)
//        {
//            abitur_temp[i] = abitur[i];
//        }
//        delete[] abitur;
//        abitur = abitur_temp;
//    }
//    return abitur;
//}

//Abiturients* Abiturients::initializeAbit()
//{
//    QString filename = QFileDialog::getOpenFileName(this, tr("Open"), "C:/Users/AleXandR/Documents/BSUIR/Labs2/C++/Lab 1/Task 4",
//        tr("Text Files (*.txt)"));
//    std::ifstream file(filename.toStdString());
//
//    for (int i = 0; !file.eof(); i++)
//    {
//        this = AddMemory(this, i);
//        file >> this[i];
//        /*if (ui->comboBox->findText(QString::fromStdString(this[i].specialization)) == -1)
//        {
//            ui.comboBox->addItem(QString(QString::fromStdString(main_abitur[i].specialization)));
//        }*/
//    }
//    return this;
//}

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

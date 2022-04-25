#ifndef _EXTRA_H
#define _EXTRA_H

class Extra{

private:
    double time1;
    double time2;
    unsigned int score1;
    unsigned int score2;

public:

    Extra();

    double getTime1() const;
    void setTime1(double a);
    double getTime2() const;
    void setTime2(double a);

    unsigned int getScore1() const;
    void setScore1(unsigned int a);
    unsigned int getScore2() const;
    void setScore2(unsigned int a);

};

#endif // Extra.h

#include "Extra.h"
#include <iostream>
#include <cassert>
Extra::Extra()
{
    time1 = 0.2;
    time2 = 0.2;

    score1 = 0;
    score2 = 0;
}

double Extra::getTime1() const { return time1; }
void Extra::setTime1(double a) { time1=a; }

double Extra::getTime2() const { return time2; }
void Extra::setTime2(double a) { time2=a; }

unsigned int Extra::getScore1() const { return score1; }
void Extra::setScore1(unsigned int a) { score1=a; }

unsigned int Extra::getScore2() const { return score2; }
void Extra::setScore2(unsigned int a) { score2=a; }

void Extra::ETestRegression()
{
    Extra e;
    assert(e.score1==0);
    assert(e.score2==0);
    assert(e.time1==(0.2));
    assert(e.time2==(0.2));
}

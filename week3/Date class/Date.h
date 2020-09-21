#ifndef DATE_H
#define DATE_H

class Date
{
public:
    Date(int y = 0, int m = 0, int d = 0);
    void SetDate(int y, int m, int d);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    void Show() const;
    void NextDay();

private:
    int year, month, day;
};

#endif
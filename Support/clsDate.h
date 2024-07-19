#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include "clsString.h"

using namespace std ;

class clsDate {

private :

    short _Day ;
    short _Month ;
    short _Year ;
    short _Hour ;
    short _Minute ;
    short _Second ;

public :

    clsDate() {

        time_t t = time(0) ;
        tm *now = localtime(&t) ;

        _Day = now->tm_mday ;
        _Month = now->tm_mon + 1 ;
        _Year = now->tm_year + 1900 ;
        _Hour = now->tm_hour ;
        _Minute = now->tm_min ;
        _Second = now->tm_sec ;
    }

    clsDate(short Day , short Month , short Year) {

        _Day = Day ;
        _Month = Month ;
        _Year = Year ;
    }

    clsDate(short Day , short Month , short Year , short Hour , short Minute , short Second) {

        _Day = Day ;
        _Month = Month ;
        _Year = Year ;
        _Hour = Hour ;
        _Minute = Minute ;
        _Second = Second ;
    }

    clsDate(string sDate) {

        vector <string> vDate = clsString::Split(sDate , "/") ;

        _Day = stoi(vDate[0]) ;
        _Month = stoi(vDate[1]) ;
        _Year = stoi(vDate[2]) ;
        
    }

    clsDate(string sDate , string time) {

        vector <string> vDate = clsString::Split(sDate , "/") ;

        _Day = stoi(vDate[0]) ;
        _Month = stoi(vDate[1]) ;
        _Year = stoi(vDate[2]) ;

        vDate = clsString::Split(time , ":") ;

        _Hour = stoi(vDate[0]) ;
        _Minute = stoi(vDate[1]) ;
        _Second = stoi(vDate[2]) ;

    }

    clsDate(short DayOrderInYear , short Year) {

        clsDate Date1 = GetDayFromDayOrderInYear(DayOrderInYear , Year) ;
        
        _Day = Date1.Day() ;
        _Month = Date1.Month() ;
        _Year = Date1.Year() ;
    }

    void SetDay(short Day) {

        _Day = Day ;
    }

    short Day() {

        return _Day ;
    }

    void SetMonth(short Month) {

        _Month = Month ;
    }

    short Month() {

        return _Month ;
    }

    void SetYear(short Year) {

        _Year = Year ;
    }

    short Year() {

        return _Year ;
    }

    void SetHour(short Hour) {

        _Hour = Hour ;
    }

    short Hour() {

        return _Hour ;
    }

    void SetMinute(short Minute) {

        _Minute = Minute ;
    }

    short Minute() {

        return _Minute ;
    }

    void SetSecond(short Second) {

        _Second = Second ;
    }

    short Second() {

        return _Second ;
    }

    static clsDate GetSystemDate() {

        time_t t = time(0) ;
        tm * now = localtime(&t) ;
        short Day , Month , Year ;

        Day = now->tm_mday ;
        Month = now->tm_mon + 1 ;
        Year = now->tm_year + 1900 ;

        return clsDate(Day , Month , Year) ;
    }

    static clsDate GetSystemTime() {

        time_t t = time(0) ;
        tm * now = localtime(&t) ;
        short Day , Month , Year , Hour , Minute , Second ;

        Day = now->tm_mday ;
        Month = now->tm_mon + 1 ;
        Year = now->tm_year + 1900 ;
        Hour = now->tm_hour ;
        Minute = now->tm_min ;
        Second = now->tm_sec ;

        return clsDate(Day , Month , Year , Hour , Minute , Second) ;
    }

    static string DateToString(clsDate Date) {

        return to_string(Date.Day()) + "/" + to_string(Date.Month()) + "/" + to_string(Date.Year()) ; 
    }

    static string TimeToString(clsDate Date) {

        return to_string(Date.Day()) + "/" + to_string(Date.Month()) + "/" + to_string(Date.Year()) + " - " + 
        to_string(Date.Hour()) + ":" + to_string(Date.Minute()) + ":" + to_string(Date.Second()) ; 
    }

    string DateToString() {

        return DateToString(*this) ;
    }

    static bool IsLeapYear(short Year) {

        return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0)) ;
    }

    bool IsLeapYear() {

        return IsLeapYear(_Year) ;
    }

    static bool IsValidDate(clsDate Date) {

		if (Date.Month() < 1 || Date.Month () > 12)
			return false;


		short DaysInMonth = NumberOfDaysInMonth(Date.Month( ), Date.Year());

		if (Date.Day() > DaysInMonth)
			return false;

		return true;

	}

    bool IsValidDate() {

        return IsValidDate(*this) ;
    }

    static short NumberOfDaysInYear(short Year) {

        return (IsLeapYear(Year)) ? 366 : 365 ;
    }

    short NumberOfDaysInYear() {

        return NumberOfDaysInYear(_Year) ;
    }

    static int NumberOfHours(short Year) {

        return NumberOfDaysInYear(Year) * 24 ;
    }

    int NumberOfHours() {

        return NumberOfHours(_Year) ;
    }

    static int NumberOfMinutes(short Year) {

        return NumberOfHours(Year) * 60 ;
    }

    int NumberOfMinutes() {

        return NumberOfMinutes(_Year) ;
    }

    int NumberOfSeconds(short Year) {

        return NumberOfMinutes(Year) * 60 ;
    }

    int NumberOfSeconds() {

        return NumberOfSeconds(_Year) ;
    }

    void Print() {

        cout << DateToString() << endl ;
    }

    static short NumberOfDaysInMonth(short Year , short Month) {

        if (Month < 1 || Month > 12)
            return 0 ;
        
        short arrDays[] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31} ;

        return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arrDays[Month - 1] ;
    }

    short NumberOfDaysInMonth() {

        return NumberOfDaysInMonth(_Year , _Month) ;
    }

    static short NumberOfHoursInMonth(short Year , short Month) {

        return NumberOfDaysInMonth(Year , Month) * 24 ;
    }

    short NumberOfHoursInMonth() {

        return NumberOfHoursInMonth(_Year , _Month) ;
    }

    static int NumberOfMinutesInMonth(short Year , short Month) {

        return NumberOfHoursInMonth(Year , Month) * 60 ;
    }

    int NumberOfMinutesInMonth() {

        return NumberOfMinutesInMonth(_Year , _Month) ;
    }

    static int NumberOfSecondsInMonth(short Year , short Month) {

        return NumberOfMinutesInMonth(Year , Month) * 60 ;
    }

    int NumberOfSecondsInMonth() {

        return NumberOfSecondsInMonth(_Year , _Month) ;
    }

    static short DayOfWeekOrder(short Day , short Month , short Year) {

        short a , y , m ;

        a = (14 - Month) / 12 ;
        y = Year - a ;
        m = Month + (12 * a) - 2 ;

        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7 ;
    }

    short DayOfWeekOrder() {

        return DayOfWeekOrder(_Day , _Month , _Year) ;
    }

    static string DayToName(short Day , short Month , short Year) {

        string arrDays[] = {"Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat"} ;

        return  arrDays[DayOfWeekOrder(Day , Month , Year)] ;
    }

    string DayToName() {

        return DayToName(_Day , _Month , _Year) ;
    }

    static string MonthToName(short MonthNumber) {
    
        string Months[12] = {
        "Jan", "Feb", "Mar",
        "Apr", "May", "Jun",
        "Jul", "Aug", "Sep",
        "Oct", "Nov", "Dec"
        } ;

        return (Months[MonthNumber - 1]);
    }

    string MonthToName() {

        return MonthToName(_Month) ;
    }

    static void PrintMonthCalendar(short Month, short Year) {

        int current = DayOfWeekOrder(1, Month, Year);
        int NumberOfDays = NumberOfDaysInMonth(Month, Year);

        printf("\n _______________%s__________________\n\n",
        MonthToName(Month).c_str()) ;

        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        int i ;
        for (i = 0; i < current; i++)
    
            printf(" ") ;

        for (int j = 1; j <= NumberOfDays; j++) {
            printf("%5d", j);
        
            if (++i == 7) {
                i = 0;
                printf("\n");
            }
        }
    
        printf("\n ____________________________________\n\n");

    }

    void PrintMonthCalendar() {

        PrintMonthCalendar(_Month , _Year) ;
    }

    static void PrintYearCalendar(short Year) {

        cout << " ___________________________________________________\n" << endl ;
        cout << "\t\tCalendar - " << Year << " - " << endl ;
        cout << "\n ___________________________________________________\n" << endl ;

        for (short i = 1 ; i <= 12 ; i++)
            PrintMonthCalendar(Year , i) ;
    }

    void PrintYearCalendar() {

        PrintYearCalendar(_Year) ;
    }

    static short NumberOfDaysFromBeginingYear(short Year , short Month , short Day) {

        short Num = 0 ;

        for (short i = 1 ; i < Month ; i++) {

            Num += NumberOfDaysInMonth(Year , i) ;
        }

        Num += Day ;

        return Num ;
    }

    short NumberOfDaysFromBeginingYear() {

        return NumberOfDaysFromBeginingYear(_Year , _Month , _Day) ;
    }

    static clsDate GetDayFromDayOrderInYear(short DayOrdredInYear , short Year) {

        clsDate Date ;

        Date.SetYear(Year) ;
        short Remainder = DayOrdredInYear ;
        Date.SetMonth(1) ;
        short MonthDays = 0 ;

        while (true) {

            MonthDays = NumberOfDaysInMonth (Year , Date.Month()) ;

            if (Remainder > MonthDays) {

                Remainder -= MonthDays ;
                Date.SetMonth(Date.Month() + 1) ;
            }

            else {

                Date.SetDay(Remainder) ;
                break;
            }
        }

        return Date ;

    }

    void AddingDays(int Days) {

        int Reminder = NumberOfDaysFromBeginingYear(_Year , _Month , _Day) + Days ;

        short DaysInMonth = 0 ;

        while (true) {

            DaysInMonth = NumberOfDaysInMonth(_Year , _Month) ;

            if (Reminder > DaysInMonth) {

                Reminder -= DaysInMonth ;
                _Month++ ;

                if (_Month > 12) {
                
                    _Year++ ;
                    _Month = 1 ;
                }
            }

            else {

                _Day = Reminder ;
                break;
            }
        }
    }

    static short CalculateMyAgeInDays(clsDate DateOfBirth) {

        return DifferentDays(DateOfBirth , clsDate::GetSystemDate() , true) ;
    }

    static bool IsDate1BeforeDate2(clsDate Date1 , clsDate Date2) {

        return (Date1.Year() < Date2.Year()) ? true : ((Date1.Year() == Date2.Year()) ?
        (Date1.Month() < Date2.Month() ? true :
        (Date1.Month() == Date2.Month() ? Date1.Day() < Date2.Day() : false)) : false) ;
    }

    bool IsDate1BeforeDate2(clsDate Date2) {

        return IsDate1BeforeDate2(*this , Date2) ;
    }

    static bool IsDate1EqualToDate2(clsDate Date1 , clsDate Date2) {

    return (Date1.Year() == Date2.Year()) ? ((Date1.Month() == Date2.Month()) ? Date1.Day() == Date2.Day() : false) :
    false ;

    }

    bool IsDate1EqualToDate2(clsDate Date2) {

        return IsDate1EqualToDate2(*this , Date2) ;
    }

    static bool IsLastDayInMonth(clsDate Date) {

        return (NumberOfDaysInMonth(Date.Year() , Date.Month()) == Date.Day()) ? true : false ;
    }

    bool IsLastDayInMonth() {

        return IsLastDayInMonth(*this) ;
    }

    static bool IsLastMonthInYear(short Month) {

    return (Month == 12) ? true : false ;

    }

    bool IsLastMonthInYear() {

        return IsLastMonthInYear(_Month) ;
    }

    static clsDate AddingOneDay(clsDate &Date) {

        if (IsLastDayInMonth(Date)) {

            Date.SetDay(1)  ;

            if (IsLastMonthInYear(Date.Month())) {

                Date.SetMonth(1) ;
                Date.SetYear(Date.Year() + 1) ;
            }

            else 
                Date.SetMonth(Date.Month() + 1) ;
        }

        else
            Date.SetDay(Date.Day() + 1) ;
    
        return Date ;
        
}

    void AddingOneDay() {

        *this = AddingOneDay(*this) ;
    }

    static void SwapDates(clsDate &Date1 , clsDate &Date2) {

        clsDate Remainder ;

        Remainder.SetDay(Date1.Day()) ;
        Remainder.SetMonth(Date1.Month()) ;
        Remainder.SetYear(Date1.Year()) ;

        Date1.SetDay(Date2.Day()) ;
        Date1.SetMonth(Date2.Month()) ;
        Date1.SetYear(Date2.Year()) ;

        Date2.SetDay(Remainder.Day()) ;
        Date2.SetMonth(Remainder.Month()) ;
        Date2.SetYear(Remainder.Year()) ;
    }

    void SwapDates(clsDate &Date2) {

        SwapDates(*this , Date2) ;
    }


    static int DifferentDays(clsDate Date1 , clsDate Date2 , bool IncludeDay = false) {

        int Days = 0 ;
        short Swap = 1 ;

        if (!IsDate1BeforeDate2(Date1 , Date2)) {

            SwapDates(Date1 , Date2) ;
            Swap = -1 ;
        }

        while (IsDate1BeforeDate2(Date1 , Date2)) {

            Days++ ;
            Date1 = AddingOneDay(Date1) ;
        }

        return (IncludeDay) ? ++Days * Swap : Days * Swap ;
    }

    int DifferentDays(clsDate Date2) {

        return DifferentDays(*this , Date2) ;
    }

    static clsDate IncreasingDateByXDays(clsDate &Date , int Days) {

        for (int i = 1 ; i <= Days ; i++)
            Date = AddingOneDay(Date) ;
    
        return Date ;
    }

    void IncreasingDateByXDays(int Days) {

        *this = IncreasingDateByXDays(*this , Days) ;
    }

    static clsDate IncreasingDateByOneWeek(clsDate &Date) {

        for (int i = 1 ; i <= 7 ; i++)
            Date = AddingOneDay(Date) ;
    
        return Date ;
    }

    void IncreasingDateByOneWeek() {

        *this = IncreasingDateByOneWeek(*this) ;
    }

    static clsDate IncreasingDateByXWeek(clsDate &Date , short Weeks) {

        for (short i = 1 ; i <= Weeks ; i++)
            Date = IncreasingDateByOneWeek(Date) ;
    
        return Date ;
    }

    void IncreasingDateByXWeek(short Weeks) {

        *this = IncreasingDateByXWeek(*this , Weeks) ;
    }

    static clsDate IncreasingDateByOneMonth(clsDate &Date) {

        short NumberOfDays = NumberOfDaysInMonth(Date.Year() , Date.Month()) ;

        for (short i = 1 ; i <= NumberOfDays ; i++)
            Date = AddingOneDay(Date) ;
    
        return Date ;
    }

    void IncreasingDateByOneMonth() {

        *this = IncreasingDateByOneMonth(*this) ;
    }

    static clsDate IncreasingDateByXMonth(clsDate &Date , short Months) {

        for (short i = 1 ; i <= Months ; i++)
            Date = IncreasingDateByOneMonth(Date) ;
    
        return Date ;
    }

    void IncreasingDateByXMonth(short Months) {

        *this = IncreasingDateByXMonth(*this , Months) ;
    }

    static clsDate IncreasingDateByOneYear(clsDate &Date) {

        Date.SetYear(Date.Year() + 1) ;

        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29) {

            Date.SetDay(Date.Day() - 1) ;
            Date.AddingOneDay(Date) ;
        }
            

        return Date ;
    }

    void IncreasingDateByOneYear() {

        *this = IncreasingDateByOneYear(*this) ;
    }


    static clsDate IncreasingDateByXYears(clsDate &Date , short Year) {

        Date.SetYear(Date.Year() + Year) ;

        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29) {

            Date.SetDay(Date.Day() - 1) ;
            Date.AddingOneDay(Date) ;
        }

        return Date ;
    }

    void IncreasingDateByXYears(short Year) {

        *this = IncreasingDateByXYears(*this , Year) ;
    }

    static clsDate IncreasingDateByOneDecade(clsDate &Date) {

        Date.SetYear(Date.Year() + 10) ;
        
        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29) {

            Date.SetDay(Date.Day() - 1) ;
            Date.AddingOneDay(Date) ;
        }

        return Date ;
    }

    void IncreasingDateByOneDecade() {

        *this = IncreasingDateByOneDecade(*this) ;
    }

    static clsDate IncreasingDateByXDecades(clsDate &Date , short Decades) {
        
        Date.SetYear(Date.Year() + Decades * 10) ;

        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29) {

            Date.SetDay(Date.Day() - 1) ;
            Date.AddingOneDay(Date) ;
        }
        
        return Date ;

    }

    void IncreasingDateByXDecades(short Decades) {

        *this = IncreasingDateByXDecades(*this , Decades) ;
    }

    static clsDate IncreasingDateByOneCentury(clsDate &Date) {

        Date.SetYear(Date.Year() + 100) ;

        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29) {

            Date.SetDay(Date.Day() - 1) ;
            Date.AddingOneDay(Date) ;
        }

        return Date ;

    }

    void IncreasingDateByOneCentury() {

        *this = IncreasingDateByOneCentury(*this) ;
    }

    static clsDate IncreasingDateByOneMillennium(clsDate &Date) {

        Date.SetYear(Date.Year() + 1000) ;

        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29) {

            Date.SetDay(Date.Day() - 1) ;
            Date.AddingOneDay(Date) ;
        }

        return Date ;

    }

    void IncreasingDateByOneMillennium() {

        *this = IncreasingDateByOneMillennium(*this) ;
    }

    static clsDate DecreasingDateByOneDay(clsDate &Date) {

        if (Date.Day() == 1) {

            if (Date.Month() == 1) {

                Date.SetYear(Date.Year() - 1) ;
                Date.SetMonth(12) ;
                Date.SetDay(31) ;
            }
            else {
            
                Date.SetMonth(Date.Month() - 1) ;
                Date.SetDay(NumberOfDaysInMonth(Date.Year() , Date.Month())) ;
            }
        }
        else 
            Date.SetDay(Date.Day() - 1) ;
    
        return Date ;
    }

    void DecreasingDateByOneDay() {

        *this = DecreasingDateByOneDay(*this) ;
    }

    static clsDate DecreasingDateByXDays(clsDate &Date , int Days) {

        for (int i = 1 ; i <= Days ; i++) {

            Date = DecreasingDateByOneDay(Date) ;
        }

        return Date ;
    }

    void DecreasingDateByXDays(int Days) {

        *this = DecreasingDateByXDays(*this , Days) ;
    }

    static clsDate DecreasingDateByOneWeek(clsDate &Date) {

        for (short i = 1 ; i <= 7 ; i++) {

            Date = DecreasingDateByOneDay(Date) ;
        }

        return Date ;
    }

    void DecreasingDateByOneWeek() {

        *this = DecreasingDateByOneWeek(*this) ;
    }

    static clsDate DecreasingDateByXWeeks(clsDate &Date , short Weeks) {

        for (short i = 1 ; i <= Weeks ; i++) {

            Date = DecreasingDateByOneWeek(Date) ;
        }

        return Date ;
    }

    void DecreasingDateByXWeeks(short Weeks) {

        *this = DecreasingDateByXWeeks(*this , Weeks) ;
    }

    static clsDate DecreasingDateByOneMonth(clsDate& Date) {

        short NumberOfDays = NumberOfDaysInMonth(Date.Year() , Date.Month()) ;

        for (short i = 1 ; i < NumberOfDays ; i++) {

            Date = DecreasingDateByOneDay(Date) ;
        }

        return Date ;
    }

    void DecreasingDateByOneMonth() {

        *this = DecreasingDateByOneMonth(*this) ;
    }

    static clsDate DecreasingDateByXMonths(clsDate &Date , short Months) {

        for (short i = 1 ; i <= Months ; i++) {

            Date = DecreasingDateByOneMonth(Date) ;
        }

        return Date ;
    }

    void DecreasingDateByXMonths(short Months) {

        *this = DecreasingDateByXMonths(*this , Months) ;
    }

    static clsDate DecreasingDateByOneYear(clsDate &Date) {

        Date.SetYear(Date.Year() - 1) ;

        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29)
            Date.SetDay(Date.Day() - 1) ;

        return Date ;
    }

    void DecreasingDateByOneYear() {

        *this = DecreasingDateByOneYear(*this) ;
    }

    static clsDate DecreasingDateByXYears(clsDate &Date , short Year) {

        Date.SetYear(Date.Year() - Year) ;

        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29)
            Date.SetDay(Date.Day() - 1) ;

        return Date ;
    }

    void DecreasingDateByXYears(short Year) {

        *this = DecreasingDateByXYears(*this , Year) ;
    }

    static clsDate DecreasingDateByOneDecade(clsDate &Date) {

        Date.SetYear(Date.Year() - 10) ;

        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29)
            Date.SetDay(Date.Day() - 1) ;

        return Date ;
    }

    void DecreasingDateByOneDecade() {

        *this = DecreasingDateByOneDecade(*this) ;
    }

    static clsDate DecreasingDateByXDecades(clsDate &Date , short Decades) {

        Date.SetYear(Date.Year() - Decades * 10) ;

        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29)
            Date.SetDay(Date.Day() - 1) ;

        return Date ;
    }

    void DecreasingDateByXDecades(short Decades) {

        *this = DecreasingDateByXDecades(*this , Decades) ;
    }

    static clsDate DecreasingDateByOneCentury(clsDate &Date) {

        Date.SetYear(Date.Year() - 100) ;

        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29)
            Date.SetDay(Date.Day() - 1) ;

        return Date ;
    }

    void DecreasingDateByOneCentury() {

        *this = DecreasingDateByOneCentury(*this) ;
    }

    static clsDate DecreasingDateByOneMillennium(clsDate &Date) {

        Date.SetYear(Date.Year() - 1000) ;

        if (!IsLeapYear(Date.Year()) && Date.Month() == 2 && Date.Day() == 29)
            Date.SetDay(Date.Day() - 1) ;

        return Date ;
    }

    void DecreasingDateByOneMillennium() {

        *this = DecreasingDateByOneMillennium(*this) ;
    }

    
    static bool IsEndOfWeek(clsDate Date) {

        return DayOfWeekOrder(Date.Day() , Date.Month() , Date.Year()) == 6 ;
    }

    static short CalculateBusinessDays(clsDate DateFrom , clsDate DateTo) {

        short Days = 0 ;

        while (IsDate1BeforeDate2(DateFrom , DateTo)) {

            if (IsBussinessDay(DateFrom))   
                Days++ ;
            
            DateFrom = AddingOneDay(DateFrom) ;
        }

        return Days ;
    }

    bool IsEndOfWeek() {

        return IsEndOfWeek(*this) ;
    }

    static bool IsWeekend(clsDate Date) {

        short DayIndex = DayOfWeekOrder(Date.Day() , Date.Month() , Date.Year()) ;

        return (DayIndex == 5 || DayIndex == 6) ;
    }

    bool IsWeekend() {

        return IsWeekend(*this) ;
    }

    static bool IsBussinessDay(clsDate Date) {

        return !IsWeekend(Date) ;
    }

    bool IsBussinessDay() {

        return IsBussinessDay(*this) ;
    }

    static short DayUntilEndOfWeek(clsDate Date) {

        return 6 - DayOfWeekOrder(Date.Day() , Date.Month() , Date.Year()) ;
    }

    short DayUntilEndOfWeek() {

        return DayUntilEndOfWeek(*this) ;
    }

    static short DayUntilEndOfMonth(clsDate Date) {

        clsDate EndOfMonth ;

        EndOfMonth.SetDay(NumberOfDaysInMonth(Date.Year() , Date.Month())) ;
        EndOfMonth.SetMonth(Date.Month()) ;
        EndOfMonth.SetYear(Date.Year()) ;

        return DifferentDays(Date , EndOfMonth) ;
    }

    short DayUntilEndOfMonth() {

        return DayUntilEndOfMonth(*this) ;
    }

    static short DayUntilEndOfYear(clsDate Date) {

        clsDate EndOfYear ;

        EndOfYear.SetDay(31) ;
        EndOfYear.SetMonth(12) ;
        EndOfYear.SetYear(Date.Year()) ;

        return DifferentDays(Date , EndOfYear) ;
    }

    short DayUntilEndOfYear() {

        return DayUntilEndOfYear(*this) ;
    }

    static short ActucalVacationDays(clsDate Date1 , clsDate Date2) {

        return CalculateBusinessDays(Date1 , Date2) ;
    }

    short ActucalVacationDays(clsDate Date2) {

        return ActucalVacationDays(*this , Date2) ;
    }

    static clsDate ReturnDate(clsDate Date , short Days) {

        while (Days != 0) {

            if (IsBussinessDay(Date))
                Days-- ;
        
            Date = AddingOneDay(Date) ;
        }

        return Date ;
    }

    void ReturnDate(short Days) {

        *this = ReturnDate(*this , Days) ;
    }

    enum enCompareDates {Before = -1 , Equal = 0 , After = 1} ;

    static bool IsDate1AfterDate2(clsDate Date1 , clsDate Date2) {

        return !IsDate1BeforeDate2(Date1 , Date2) && !IsDate1EqualToDate2(Date1 , Date2) ;
    }

    bool IsDate1AfterDate2(clsDate Date2) {

        return IsDate1AfterDate2(*this , Date2) ;
    }

    static enCompareDates DateCompare(clsDate Date1 , clsDate Date2) {

        if (IsDate1BeforeDate2(Date1 , Date2))
            return enCompareDates::Before ;
    
        if (IsDate1EqualToDate2(Date1 , Date2))
            return enCompareDates::Equal ;
    
        return enCompareDates::After ;
    }

    enCompareDates DateCompare(clsDate Date2) {

        return DateCompare(*this , Date2) ;
    }


} ;
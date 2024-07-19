#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "clsDate.h"

using namespace std ;

class clsUtility {

public :

    template <typename T> static void Swap(T &a , T &b) {

        T h ;

        h = a ;
        a = b ;
        b = h ;
    }

    static void Srand() {

        srand((unsigned)time(NULL)) ;
    }

    static int RandomNumber(int From , int To) {

        return rand() % (To - From + 1) + From ;
    }

    static void Swap(clsDate &Date1 , clsDate &Date2) {

        clsDate::SwapDates(Date1 , Date2) ;
    }

    static bool IsEvenNumber(int Number) {

        return Number % 2 == 0 ;
    }

    static bool IsOddNumber(int Number) {

        return !IsEvenNumber(Number) ;
    }

    static bool IsPrimeNumber(int Number) {

        int M = round(Number / 2) ;

        for (int i = 2 ; i <= M ; i++) {

            if (Number % i == 0)
            
                return false ;
        }

        return true ;
    }

    static int ReverseNumber(int Num) {

        int remainder = 0 ;
        int R = 0 ;

        while (Num > 0) {

            remainder = Num % 10 ;
            Num = Num / 10 ;
            R = R * 10 + remainder ;
        }

        return R ;
    }

    short DigitFreqency(int Num , short Digit) {

        int remainder = 0 ;
        short Freqency = 0 ;

        while (Num > 0) {

            remainder = Num % 10 ;
            Num = Num / 10 ;
            if (remainder == Digit)
                Freqency++ ;
        }

        return Freqency ;
    }

    static bool IsPalindromeNumber(int Number) {

        return ReverseNumber(Number) == Number ;
    }

    static string EncryptionText(string Text , short EncryptionKey = 2) {

        for (int i = 0 ; i <= Text.length() ; i++) {

            Text[i] = char((int) Text[i] + EncryptionKey) ;
        }

        return Text ;
    }   

    static string DecryptionText(string Text , short EncryptionKey = 2) {

        for (int i = 0 ; i <= Text.length() ; i++) {

            Text[i] = char((int) Text[i] - EncryptionKey) ;
        }

        return Text ;
    }

    static bool GuessA3_LetterPassword(string Password) {

        string Word = "" ;
        int counter = 0 ;

        cout << endl ;

        for (int i = 65 ; i <= 90 ; i++) {

            for (int j = 65 ; j <= 90 ; j++) {

                for (int k = 65 ; k <= 90 ; k++) {

                    Word += char(i) ;
                    Word += char(j) ;
                    Word += char(k) ;

                    counter++ ;

                    cout << "Trial [" << counter << "] : " << Word << endl ;

                    if (Word == Password) {

                        cout << "\nPssaword is " << Word << endl ;
                        cout << "Found after " << counter << " Trial(s)" << endl ;
                        return true;
                    }

                    Word = "" ;
                }
            }
        }
    
        return false ;
    }

    enum enCharType {SmallLetter = 1 , CapitalLetter = 2 , Digit = 3 , SpecialCharacter = 4 , MixChars = 5} ;

    static char GetRandomCharacter(enCharType CharType) {

        if (CharType == MixChars)
        {
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch(CharType) {

            case enCharType::SmallLetter :
                return char(RandomNumber(97 , 122)) ; 
                break;
        
            case enCharType::CapitalLetter :
                return char(RandomNumber(65 , 90)) ;
                break;
           
            case enCharType::Digit :
                return char(RandomNumber(48 , 57)) ;
                break;
            
            case enCharType::SpecialCharacter :
                return char(RandomNumber(33 , 47)) ;
                break;
        
        }
    }

    static string GenerateWord(enCharType CharType , short Lenght) {

        string Word  ;

        for (int i = 1 ; i <= Lenght ; i++) {

            Word = Word + GetRandomCharacter(CharType) ;
        }

        return Word ;
    } 

    static string GenerateKey(enCharType CharType = CapitalLetter) {

        string Key = "";


        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);


        return Key;
    }

    template <typename T> static void PrintArray(T M[] , short arrLength) {

        for (short i = 0 ; i < arrLength ; i++)
            cout << M[i] << "\t" ;
    }

    static void FillArrayWithRandomNumbers(int M[] , short arrLength , int From , int To) {

        for (short i = 0 ; i < arrLength ; i++)
            M[i] = RandomNumber(From , To) ;
    }

    static void FillArrayWithRandomWords(string arr[], int arrLength, enCharType CharType, short Wordlength) {
        
        for (int i = 0; i < arrLength; i++)
            
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[], int arrLength, enCharType CharType) {
        
        for (int i = 0; i < arrLength; i++)
            
            arr[i] = GenerateKey(CharType);
    }

    static void ShuffleArray(int arr[], int arrLength) {

        for (int i = 0; i < arrLength; i++)
            
            Swap <int> (arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);

    }

    static void ShuffleArray(string arr[], int arrLength) {

        for (int i = 0; i < arrLength; i++)
            
            Swap <string> (arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);

    }

    static string Tabs(short NumberOfTabs) {
        
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++) {
            
            t = t + "\t";
            cout << t;
        }
        
        return t;

    }

    static string NumberToText(int Num) {

        if (Num == 0) {

            return "" ;
        }

        if (Num >= 1 && Num <= 19) {

            string arr[] = {"" , "One" , "Two" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine" ,
            "Ten" , "Eleven" , "Twelve" , "Thirteen" , "Fourteen" , "Fifteen" , "Sixteen" , "Seventeen" ,
            "Eighteen" , "Nineteen"} ;

            return arr[Num] + " " ;
        }

        if (Num >= 20 && Num <= 99) {

            string arr[] = {"" , "" , "Twenty" ,  "Thirty" , "Fourty" , "Fifty" , "Sixty" , "Seventy" ,
            "Eighty" , "Ninety"} ;

            return arr[Num / 10] + " " + NumberToText(Num % 10) + " " ;
        }

        if (Num >= 100 && Num <= 199) {

            return "One Hundred " + NumberToText(Num % 100) ;
        }

        if (Num >= 200 && Num <= 999) {

            return NumberToText(Num / 100) + "Hundreds " + NumberToText(Num % 100) ; 
        }

        if (Num >= 1000 && Num <= 1999) {

            return "One Thousand " + NumberToText(Num % 1000) ;
        }

        if (Num >= 2000 && Num <= 9999) {

            return NumberToText(Num / 1000) + "Thousands " + NumberToText(Num % 1000) ;
        }

        if (Num >= 10000 && Num <= 19999) {

            return "One Million " + NumberToText(Num % 10000) ;
        }      

        if (Num >= 20000 && Num <= 99999) {

            return NumberToText(Num / 10000) + "Millions " + NumberToText(Num % 10000) ;
        }

        if (Num >= 100000 && Num <= 199999) {

            return "One Billion " + NumberToText(Num % 100000) ;
        }

        if (Num >= 200000 && Num <= 999999) {

            return NumberToText(Num / 100000) + "Billions " + NumberToText(Num % 100000) ;
        }

        else 

            return "This The Limit of Program : 999999" ;
    }

} ;
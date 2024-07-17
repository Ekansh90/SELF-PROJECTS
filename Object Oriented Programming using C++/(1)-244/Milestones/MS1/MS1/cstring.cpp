/*/////////////////////////////////////////////////////////////////////////
                         Milestone - 1
Full Name  : Ekansh
Email      : ekansh@myseneca.ca
Student ID#: 167454214
Section    : OOP 244 -NAA

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

/*
#include "cstring.h"

namespace sdds {

    // DONE -> 1.Copies the srouce character string into the destination
    void strCpy(char* des, const char* src)
    {
        // determining src ( The lenght of string we will be overwriting to desc )

        int srcLen = strLen(src);
        int i = 0;
        for (; i < srcLen; i++)
        {
            des[i] = src[i];
        }

        des[i] = '\0';
    }

    // DONE : 2.Copies the source character string into the destination upto "len"
          // characters. The destination will be null terminated only if the number
          // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len)
    {
        //int srcLen = strLen(src);

        int i = 0;
        for (i = 0; i < len; i++)
        {
            des[i] = src[i];


        }

        des[i] = '\0';

    }


    // 3. Compares two C-strings
         // returns 0 i thare the same
         // return > 0 if s1 > s2
         // return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2)
    {
        // finding length of both strings ; 
        int s1_Len = strLen(s1);
        int s2_Len = strLen(s2);

        int i;

        // stores string compare result
        int j = 0;


        for (i = 0; (i < s1_Len || i < s2_Len); i++)
        {
            if (s1[i] == s2[i])
            {
                j = 0;
            }

            else if (s1[i] > s2[i])
            {

                return j = 1;
            }

            else if (s1[i] < s2[i])
            {

                return j = -1;
            }
        }
        return j;
    }

    // 4 . returns 0 i thare the same
        // return > 0 if s1 > s2
        // return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len)
    {

        int i;

        // stores string compare result
        int j = 0;


        for (i = 0; i < len; i++)
        {
            if (s1[i] == s2[i])
            {
                j = 0;
            }

            else if (s1[i] > s2[i])
            {

                return j = 1;
            }

            else if (s1[i] < s2[i])
            {

                return j = -1;
            }
        }
        return j;
    }



    // DONE -> 5.  returns the lenght of the C-string in characters
    int strLen(const char* s)
    {
        int i = 0;

        // Running a for loop until it finds a null terminator 

        //CHANGES MADE HERE , REVERT BACK
        for (; s[i] != '\0' && s != nullptr; i++)
        {
            ;
        }
        return i;
    }

    // 6. returns the address of first occurance of "str2" in "str1"
         // returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2)
    {
        // finding length of both strings ; 
        int str1_Len = strLen(str1);
        int str2_Len = strLen(str2);

        int index = 0;


        // counter which checks if the elements of str2 are consecutively stored in str1
        int checkMatch = 0;

        //tempIndex to go to only next value after matching and not comparing from the start
        int tempIndex = 0;

        // 1. Checking if str2 exists in str1

        for (int j = 0; (j < str2_Len) && (checkMatch != str2_Len); j++)
        {
            for (int i = tempIndex; i < str1_Len && (checkMatch != str2_Len); i++)
            {
                if (str2[j] == str1[i])
                {
                    checkMatch++;
                    j++; //
                    tempIndex = i + 1;
                }

            }
        }

        // 2. Now finding the address of 1st element 
        if (checkMatch == str2_Len)
        {

            int flag = 0;

            for (int i = 0; i < str1_Len && flag != 1; i++)
            {
                for (int j = 0; j < str2_Len && flag != 1; )
                {
                    if (str1[i] == str2[j])
                    {
                        flag = 1;
                        index = i;
                    }

                    else
                    {
                        j++;
                    }
                }

            }


            return &str1[index];

        }

        else
        {
            return nullptr;
        }


    }

    // DONE -> 7. Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src)
    {
        // finding length of both strings ; to find the index where the null terminator is stored
        int s1_Len = strLen(des);
        int s2_Len = strLen(src);

        int i, j;
        for (i = s1_Len, j = 0; i < ((s1_Len + s2_Len)); i++, j++)
        {
            des[i] = src[j];

        }

        des[(s1_Len + s2_Len)] = '\0';

    }

}
*/
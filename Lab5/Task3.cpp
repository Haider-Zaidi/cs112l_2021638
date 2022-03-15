#include<iostream>
using namespace std;

class stringType{

public:

    stringType()
    {
        first = " ";
        second = " ";
    }

    stringType(string str1, string str2)
    {
        first = str1;
        second = str2;
    }

    void setValues(string str1, string str2)
    {
        first = str1;
        second = str2;
    }

    void printValues()
    {
        cout << "First String: " << first << endl;
        cout << "Second String: " << second << endl;
    }

    int maxLength()
    {
        int fLen = 0;
        for (int i = 0; first[i] != '\0'; i++)
        {
            fLen++;
        }
        
        int sLen = 0;
        for (int i = 0; second[i] != '\0'; i++)
        {
            sLen++;
        }

        if(fLen > sLen)
        {
            return fLen;
        }
        else{
            return sLen;
        }
    }

    int compare(string s1, string s2)
    {
        int counter = 0;
        int wordLen;
        wordLen = maxLength();

        for (int i = 0; i < wordLen; i++)
        {
            if(int(s1[i]) == int(s2[i]))
            {
                counter++;
            }
        }
        
        if(wordLen == counter)
        {
            return 1;
        }
        else{
            return 0;
        }
        
    }    

    void copy(string source, string destination)
    {
        int wordLen;
        wordLen = maxLength();

        for (int i = 0; i < wordLen; i++)
        {
            destination[i] = source[i];
            
        }
            cout << destination;
    }

    string concatenate(string s1, string s2)
    {
        return s1+s2;
    }

    int searchWord(string word)
    {
        int counter1 = 0;
        int counter2 = 0;
        int wordLen;
        wordLen = maxLength();

        for (int i = 0; i < wordLen; i++)
        {
            if(int(first[i]) == int(word[i]))
            {
                counter1++;
            }

            if(int(second[i]) == int(word[i]))
            {
                counter2++;
            }
            
        }
        
        if(wordLen == counter1 || wordLen == counter2)
        {
            return 1;
        }
        else{
            return 0;
        }
    }

    int searchChar(char ch)
    {
        int wordLen;
        wordLen = maxLength();

        for (int i = 0; i < wordLen; i++)
        {
            if(int(first[i]) == int(ch))
            {
                return 1;
            }

            if(int(second[i]) == int(ch))
            {
                return 1;
            }

        }

        return 0;
    }

    ~stringType(){}

private:
    string first;
    string second;
};

int main()
{
    stringType t1("string1", "string2");
    // t1.setValues("Lab", "Task");
    // t1.printValues();
    // cout << t1.maxLength();
    // cout << t1.compare("haider", "haider");
    // t1.copy("Lab", "Task");
    cout << t1.concatenate("Lab", "Task");
    //cout << t1.searchWord("Task");
    // cout << t1.searchChar('k');

    return 0;
}
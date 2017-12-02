#include <iostream>

using namespace std;

int main()
{
    string s = "";

    while(cin >> s)
    {
        //Ìæ»»×Ö·û'\'
        string s1 = "";
        for(int i = 0; i < s.length(); i++)
        {
            if( s[i] == '\\')
                s[i] = '/';
        }

        //µÃµ½¹æ¸ñ×Ö·û´®
        bool slash = false;
        bool error = false;
        int point = 0;
        int indexSlash = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '/')
            {
                if(!slash)
                {
                    indexSlash ++;
                    s1 += s[i];
                    slash = true;
                }
                point = 0;
            }
            else if(s[i] == '.')
            {
                if(++point == 2)
                {
                    if(indexSlash < 1 ||(indexSlash == 1 && s1 == "/"))
                    {
                        error = true;
                        cout << "Value Error" << endl;
                        break;
                    }
                    else
                    {
                        int index_1 = s1.rfind('/', s1.length());
                        int index_2 = s1.rfind('/', index_1 - 1);
                        s1.erase(index_2 + 1, index_1 - index_2);
                        indexSlash --;
                    }
                    slash = true;
                }
            }
            else if(s[i] != '/' &&s[i] != '.')
            {
                s1 += s[i];
                point = 0;
                slash = false;
            }
        }

        if(!error)
        {
            if(s[0] != '/' && s1[0] == '/')
            {
                s1 = s1.erase(0,1);
            }

            if(s1 != "/" && s1[s1.length()-1] == '/')
            {
                s1 = s1.erase(s1.length()-1,1);
            }
            cout << s1 << endl;
        }
    }
    return 0;
}

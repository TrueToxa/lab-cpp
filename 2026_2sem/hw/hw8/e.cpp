#include <iostream>
using namespace std;

bool chek(char st, char end, char ch)
{
    int flag = 1;
    while (ch != '\n' && ch != '\0')
    {
        if (ch == end)
        {
            flag--;
            if (flag<0) {
                return false;
            }
        }
        else if (ch == st)
        {
            flag++;
        }
        else
        {
            switch (ch)
            {
            case '(':
                if (!chek('(', ')', getchar()))
                    return false;
                break;
            case '[':
                if (!chek('[', ']', getchar()))
                    return false;
                break;
            case '{':
                if (!chek('{', '}', getchar()))
                    return false;
                break;
            case '<':
                if (!chek('<', '>', getchar()))
                    return false;
                break;
            default:
                return false;
            }
        }
        ch = getchar();
    }
    return (flag == 0);;
}

int main()
{
    char ch = getchar();
    bool flag = false;

    switch (ch)
    {
    case '\n':
    case '\0':
        flag = true;
        break;
    case '(':
        flag = chek('(', ')', getchar());
        break;
    case '[':
        flag = chek('[', ']', getchar());
        break;
    case '{':
        flag = chek('{', '}', getchar());
        break;
    case '<':
        flag = chek('<', '>', getchar());
        break;
    }

    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
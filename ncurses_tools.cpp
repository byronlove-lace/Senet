#include "ncurses_tools.h"

int percentile_to_position(int max, float percent)
{
        float position = ((float)max / 100.00) * percent;

        return (int)round(position);
}

size_t longest_string(vector <const char *> strVect)
{
        size_t longestStr = 0;

        for (size_t i = 0; i < strVect.size(); ++i) 
        {
                if (strlen(strVect[i]) > longestStr)
                        longestStr = strlen(strVect[i]);
        }

        return longestStr;
}

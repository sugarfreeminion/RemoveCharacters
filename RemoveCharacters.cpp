/************************************************************************
 * Author:          sugarfreeoh
 * Date:            12 March 2016
 * Description:     Write a program which removes specific characters
 *                  from a string.
 ************************************************************************/

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            string inputString;
            string charsToRemove;

            size_t delLocation = 0;
            
            unsigned int index = 0;
            unsigned int charIndex = 0;

            delLocation = line.find(',');

            inputString = line.substr(0,delLocation);
            charsToRemove = line.substr(delLocation+2,line.size()-delLocation-2);

            //cout << "Input: " << inputString << endl;
            //cout << "Chars: " << charsToRemove << endl;

            while(charIndex < charsToRemove.size())
            {
                while((index = inputString.find(charsToRemove[charIndex])) < inputString.size())
                {
                    inputString.erase(index,1);
                }

                ++charIndex;
            }

            if(inputString.size() == 1 && inputString[0] == ' ')
            {
                inputString = "";
            }

            cout << inputString << endl;
        }

        inputFile.close();
    }

    return 0;
}

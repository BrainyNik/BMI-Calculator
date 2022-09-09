#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

/**
 *  This function will calculate the BMI of a person on supplying weight and height from a txt file
 *  First parameter is the weight of the person in Kg
 *  Second parameter os the height of the person in meter.
 */
double getBMI(double weight, double height)
{
    return weight / (height * height);
}

void filterTeensWithBMI(string source_file, string dest_file)
{
    ifstream fin(source_file); // fin is the source file object.
    ofstream fout(dest_file);  // fout is the destination file object.
    // ----- please read the entire problem statement above before you start.  You code must meet each of the
    // requirements.
    // first read the first line that contains the  number of records in the source file:
    int numRec = 0;
    fin >> numRec;
    int no_underweight = 0;
    string blank;
    getline(fin, blank); // *** reading the new line character at the end to move the file object at the beginning of
                         // the second line, this is required as the file object will be before the newline claracter of the
                         // first line after reading that number of records, we need to move that file object to the second
                         // line by reading that newline at the end of the first line.

    // ----- write your code after this line. You will need a loop to iterate for numRec times
    // declare a variable to hold the count of underweight teens, initialize that with 0
    for (int i = 1; i <= numRec; ++i)
    {
        // read next line from input file using std::getline
        // parse the line, get the age weigh and height. You may use istringstream as I used in the video
        // if the age is teen age, calculate the BMI and then find the appropriate comment and
        // finally write the record as instructed into the dest_file using fout. Remember, you will only
        // require to write the records of teen agers. Also do not forget to count the underweight teen agers
        
        // Getting each line one by one in the string::line
        string line;
        getline(fin, line);
        
        // getting name from the crrent line and storing it in name variable 
        istringstream iss1(line);
        string name;
        getline(iss1, name, '$');

        // getting age from line converting it to the int
        string temp_age;
        getline(iss1, temp_age, '$');
        int age = stoi(temp_age);

        // getting weight from line converting it to the double
        string temp_weight;
        getline(iss1, temp_weight, '$');
        double weight = stod(temp_weight);

        // getting height from line converting it to the double
        string temp_height;
        getline(iss1, temp_height, '$');
        double height = stod(temp_height);

        // calculating BMI of entity if he/she is a teenager only
        if (age >= 13 && age <= 19)
        {
            double bmi = getBMI(weight, height);
            string comment;
            if (bmi < 18.5)
            {
                comment = "Underweight";
                no_underweight = no_underweight + 1;
            }
            else if (bmi >= 18.5 && bmi < 25.0)
            {
                comment = "Normal";
            }
            else if (bmi >= 25.0 && bmi < 30.0)
            {
                comment = "Overweight";
            }
            else
            {
                comment = "Obase";
            }

            fout << name << "#" << age << "#" << setprecision(2) << fixed << bmi << "#" << comment << endl;
        }

    } // end of for loop

    // write the count of underweight teen agers and then write a newline at the end.
    fout << no_underweight << endl;

 
    fin.close();
    fout.close();
}

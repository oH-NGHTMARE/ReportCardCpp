#include <iostream>
#include <vector>
#include <string>

using namespace std;

// HELP TEXT FUNCTION
void helpMod()
{
    cout << "\n\nYou will enter the grade calculator if you press G or g" << endl;
    cout << "1. Then, you will be asked to enter the number of students ";
    cout << "(integer value only) that you are going to enter grades for." << endl;

    cout << "2. If you enter any other character (other than integer), you must ";
    cout << "you must prompt the user to enter a valid integer number only." << endl;

    cout << "3. The calculator asks you for the names of the students (if you enter 3 in in the step 1, ";
    cout << "the loop will run for 3 times ... taking 3 student names)." << endl;

    cout << "4. The program will start asking for the individual scores ";
    cout << "(physics, chemistry and math in our case)." << endl;

    cout << "5. Finally, it will print a report card with scores and the grade (calculated). ";
    cout << "I have programmed to give A, B, C and F grades only. You are free to use other grading scales as well.\n\n" << endl;
}
int calculationsMod(string person, int a, int b, int c)
{
    // ADDES VALUE INTO INTEGER FOR LATER USE
    int iTotal = a + b + c;

    cout << "\n***************************\n" << endl;
    cout << "  **** Report Card ****" << endl;
    cout << "\n***************************\n" << endl;
    cout << "Name of student: " << person << endl;
    cout << " Physics: " << a << "/100" << endl;
    cout << " Chemistry: " << b << "/100" << endl;
    cout << " Math: " << c << "/100" << endl;
    cout << " Total: " << iTotal << "/300" << endl;

    if (iTotal/3 >= 90)
    {
        cout << " Your letter grade: A" << endl;
    } else if (iTotal/3 >= 80)
    {
        cout << " Your letter grade: B" << endl;
    } else if (iTotal/3 >= 70)
    {
        cout << " Your letter grade: C" << endl;
    } else
    {
        cout << " Your letter grade: F" << endl;
    }

    cout << "\n*** End of report card ***" << endl;
    cout << "*** THANK YOU ***\n\n" << endl;
    return iTotal;
}
int gradeMod()
{
    int iNum; // USED FOR ABSOLUTE INDEXING
    string name; // STORES NAME
    vector<string> sStudentCount; // VECTOR FOR NAMES

    cout << " *** Welcome to the grade calculator ***" << endl;
    cout << " Enter the total number of students in your class: ";
    cin >> iNum;

    // LOOPS THROUGH AMOUNT OF STUDENTS
    for (int i = 1; i < (iNum + 1); i++) {
        cout << "Please enter student #" << i << " name: ";
        cin >> name;
        // ADDS NAMES TO VECTOR
        sStudentCount.push_back(name);
    }

    // STORES COURSE GRADES
    int iPhy;
    int iChem;
    int iMath;
    vector<int> v; // STORES VECTOR OF GRADES

    for (int i = 0; i < iNum; i++) {
        cout << "\n\nPlease enter " << sStudentCount[i] << " Physics score(out of 100 points): ";
        cin >> iPhy;
        cout << "Please enter " << sStudentCount[i] << " Chemistry score(out of 100 points): ";
        cin >> iChem;
        cout << "Please enter " << sStudentCount[i] << " Math score(out of 100 points): ";
        cin >> iMath;

        // STORES GRADES IN VECTOR FOR SLICING
        v.push_back(iPhy);
        v.push_back(iChem);
        v.push_back(iMath);
    }
    // RUNS GRADE CALCULATIONS FUNCTION BASED OFF ABSOLUTE PAIRED INDEXING IN iNUM
    for (int i = 0; i < iNum; i++) {
        if (i == 0) {
            calculationsMod(sStudentCount[i], v[0], v[1], v[2]);
        } else
        {
            // SOME MATH FOR EVERY 3 INDEXES BASED OF A RECURSION IF ITS BEEN RAN ALREADY
            calculationsMod(sStudentCount[i], v[i*3], v[(i*3)+1], v[(i*3)+2]);
        }
    }
    return iNum;
}

int main()
{
    // APP RUNTIME LOOP
    bool loop = true;
    char c_g;

    while (loop) {
        cout << "Press G to enter grade calculator" << endl;
        cout << "Press H for help" << endl;
        cout << "(Press e to exit) Please enter your option: ";

        cin >> c_g;

        if (c_g == 'e' || c_g == 'E') {
            loop = false;
        } else if (c_g == 'H' || c_g == 'h')
        {
            helpMod();
        } else if (c_g == 'g' || c_g == 'G')
        {
            gradeMod();
        } else
        {
            cout << "Not a valid number / value" << endl;
            cout << "Please enter a valid positive integer number only" << endl;
        }
    }
    return 0;
}

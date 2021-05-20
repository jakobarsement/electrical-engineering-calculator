/*      Electrical Engineering Program

This program was written at Richard Design Services to solve tedious tasks
that would otherwise cost hours of sifting through textbooks, performing
calculations, and testing existing design values. It was inspired
by the refusal of our mentors to give us access to the existing software that
they used for these calculations. It has not been optimized, and was a quick
solution to our immediate concerns. Upon further usage, this program can be
changed to be more comprehensive and user-friendly.
*/

#include "iostream"
#include "iomanip"
#include "string"
#include "cmath"
using namespace std;

void motorAmps3();
void voltageDrop();
void motorHp();

const double PI = 3.14159265;

string x;


// main() contains the primary while-loop that prompts the user
//to input their desires. call on other functions.
int  main()
{
    do
    {
    cout << "*****Whatcha need?*****\n\n";
    getline(cin, x);

    if(x == "motor amps"||x == "motor amps ")
        {
            int phase;
            cout << "\n\nPhase: ";
            cin  >> phase;

            if(phase == 3)
                motorAmps3();

            /*
            if(phase == 1)
            {
                MotorAmps1();
            }
            */
            else {cout << "Not programmed for that...";}
        }
    if(x == "voltage drop")
        voltageDrop();

    } while(true);


}

// motorAmps() calculates the given motor's usage of amperes based on
//the input values of horsepower, voltage, the power factor and efficiency.
//it also prints an NEC table that was frequently used during the RDS
//internship
void motorAmps3()
{
    double horse, volts, pf, effic, RLA, FLA;

    cout << "\n\nHorsepower: ";
    cin  >> horse;

    cout << "\n\nVoltage: ";
    cin  >> volts;

    cout << "\n\nPower Factor: ";
    cin  >> pf;

    cout << "\n\nEfficiency: ";
    cin  >> effic;

    if(horse == 0 || volts == 0)
    {
        cout << "Check your inputs and try again.\n\n";
    }
    while(pf > 1 || effic > 1)
    {
        cout << "\n\nPower Factor and Efficiency should be less than 1...";
        motorAmps3();
    }

    RLA = ((horse*746)/(volts*effic*pf*1.73));
    FLA = ((horse*746*0.722543352)/(volts));           //

    cout << "\n\nRLA: " << RLA;
    cout << "\n\nFLA: " << FLA;
    cout << "\n\n\n";
    cout << endl << endl;

{
    cout << setw(5) << "Horsepower" << setw(5) << "115V" << setw(5) << "200V"
    << setw(5) << "208V"<< setw(5) << "230V"<< setw(5) << "460V"<< setw(5) << "575V"
    << setw(6) << "2300V" << setw(5) << endl << endl;

    cout << setw(5) << "1/2" << setw(10) << "4.4" << setw(5) << "2.5"<< setw(5) << "2.4"
    << setw(5) << "2.2" << setw(5) << "1.1" << setw(5) << "0.9" << setw(5) << "---" << endl;

    cout << setw(5) << "3/4" << setw(10) << "6.4" << setw(5) << "3.7"<< setw(5) << "3.5"
    << setw(5) << "3.2" << setw(5) << "1.6" << setw(5) << "1.3" << setw(5) << "---" << endl;

    cout << setw(5) << "1" << setw(10) << "8.4" << setw(5) << "4.8"<< setw(5) << "4.6"
    << setw(5) << "4.2" << setw(5) << "2.1" << setw(5) << "1.7" << setw(5) << "---" << endl;

    cout << setw(5) << "2" << setw(10) << "13.6" << setw(5) << "7.8"<< setw(5) << "7.5"
    << setw(5) << "6.8" << setw(5) << "3.4" << setw(5) << "2.7" << setw(5) << "---" << endl;

    cout << setw(5) << "5" << setw(10) << "---" << setw(5) << "17.5"<< setw(5) << "16.7"
    << setw(5) << "15.2" << setw(5) << "7.6" << setw(5) << "6.1" << setw(5) << "---" << endl;

    cout << setw(5) << "10" << setw(10) << "---" << setw(5) << "32.2"<< setw(5) << "30.8"
    << setw(5) << "28" << setw(5) << "14" << setw(5) << "11" << setw(5) << "---" << endl;

    cout << setw(5) << "50" << setw(10) << "---" << setw(5) << "150"<< setw(5) << "143"
    << setw(5) << "130" << setw(5) << "65" << setw(5) << "52" << setw(5) << "---" << endl;

    cout << setw(5) << "75" << setw(10) << "---" << setw(5) << "221"<< setw(5) << "211"
    << setw(5) << "192" << setw(5) << "96" << setw(5) << "77" << setw(5) << "20" << endl;

    cout << setw(5) << "200" << setw(10) << "-" << setw(5) << "552"<< setw(5) << "528"
    << setw(5) << "480" << setw(5) << "240" << setw(5) << "192" << setw(5) << "49" << endl;

    //cout << setw(5) << "200" << setw(10) << "-" << setw(5) << "552"<< setw(5) << "528"
    //<< setw(5) << "480" << setw(5) << "240" << setw(5) << "192" << setw(5) << "49" << endl;

}
}

// voltageDrop() calculates voltage drop using feet or meters, material
//properties, length from source to load, wire size in kcmils or awg,
//voltage, and amperes.
void voltageDrop()
{
    string material, lunits, wsize, wunits, awgSize;
    double length, p, k, crossarea, drop, amps, volts, percent;
    int kcmils;

    cout << "\n\nLength to Load: ";
    cin  >> length;

    cout << "\n\nUnits(m or ft): ";
    cin  >> lunits;

    if (lunits == "meters"||lunits == "m"||lunits == "meter")  {length = length*3.28084;}
    while(lunits != "meters" &&lunits!= "meter"&&lunits != "m" //check for appropriate distance units
          &&lunits != "ft" &&lunits != "feet")
    {
        cout << "\n\nNot programmed for that...";
        voltageDrop();
    }

    cout << "\n\nConductor Material: ";
    cin  >> material;
    if(material == "copper")    {p = 0.0000000172; k = 12.88;}
    //else if(material == "silver")    {p = 0.0000000160;}
    else if(material == "aluminum"||"aluminium")    {p = 0.0000000160; k = 21.2;}
    //else if(material == "silicon")    {p = 0.0023;}
    while(material != "copper" &&material!= "aluminum"  //check for correct material entry
          &&material != "aluminium")
    {
        cout << "\n\nNot programmed for that...";
        voltageDrop();
    }
    cout << "(K-Factor: " << k << ")";

    cout <<"\n\n\nWire Area in kcmil or AWG: ";
    cin  >> wunits;
    if(wunits == "awg"||wunits == "AWG")                          //convert awg to kcmil
    {
        cout << "\n\nWire Size: ";
        cin  >> awgSize;

        if(awgSize == "0000"||awgSize == "4/0")    {kcmils = 211592;}
        else if(awgSize == "000"||awgSize == "3/0")    {kcmils = 167800;}
        else if(awgSize == "00"||awgSize == "2/0")    {kcmils = 133072;}
        else if(awgSize == "0"||awgSize == "1/0")    {kcmils = 105531;}
        else if(awgSize == "1")     {kcmils = 83690;}
        else if(awgSize == "2")     {kcmils = 66369;}
        else if(awgSize == "3")     {kcmils = 52633;}
        else if(awgSize == "4")     {kcmils = 41740;}
        else if(awgSize == "5")     {kcmils = 33101;}
        else if(awgSize == "6")     {kcmils = 26251;}
        else if(awgSize == "7")     {kcmils = 20818;}
        else if(awgSize == "8")     {kcmils = 16509;}
        else if(awgSize == "9")     {kcmils = 13092;}
        else if(awgSize == "10")    {kcmils = 10383;}
        else if(awgSize == "11")    {kcmils = 8234;}
        else if(awgSize == "12")    {kcmils = 6530;}
        else if(awgSize == "13")    {kcmils = 5178;}
        else if(awgSize == "14")    {kcmils = 4107;}
        else if(awgSize == "15")    {kcmils = 3257;}
        else if(awgSize == "16")    {kcmils = 2583;}
        else if(awgSize == "17")    {kcmils = 2048;}
        else if(awgSize == "20")    {kcmils = 1022;}
        else if(awgSize == "21")    {kcmils = 810;}
        else if(awgSize == "22")    {kcmils = 642;}
        else if(awgSize == "23")    {kcmils = 510;}
        else if(awgSize == "24")    {kcmils = 404;}
        else if(awgSize == "25")    {kcmils = 320;}
    }
    if(wunits == "kcmil"||wunits == "kcmils")
    {
        cout << "\n\nWire Size(" << wunits << "): ";       //get cross area measurements
        cin  >> kcmils;
    }

    while(wunits != "awg" &&wunits!= "kcmil"                //check for appropriate sizing units
          &&wunits != "AWG"&&wunits != "kcmils")
    {
        cout << "\n\nNot programmed for that...";
        voltageDrop();
    }

    cout << "\n\nAmperes: ";                                //calculate amps
    cin  >> amps;

    cout << "\n\nVoltage: ";                                //calculate volts
    cin  >> volts;

    drop = (1.732*length*k*amps/kcmils);
    percent = drop/volts;


    cout << "\n\nVoltage Dropped: " << drop << endl << endl;
    cout << "\n\nPercent Dropped: " << percent*100 << endl << endl;
    cout << "\n\nlength " << length << "\n\nk " << k << "\n\namps " << amps << "\n\nkcmils " << kcmils
         << "\n\nwunits " << wunits;
}

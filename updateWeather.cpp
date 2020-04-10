#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

bool getForecast(const string& file, vector<string> days);
bool writeForecast(const string& file, const string& fullForecast);

int main() {
    // create vector of days in the week and initilize csv file name
    vector<string> days = {"Monday","Tuesday","Wednessday","Thursday","Friday","Saturday","Sunday"};
    string file = "weather.csv";

    // INSTRUCTIONS
    cout << "Weather Forcast Backdrop Generator" << endl;
    cout << "For each day of the week you will be prompted for 'Forcast', 'High', and 'Low'" << endl;
    cout << "For Forcast, type 'sun','cloud','partcloud','rain','lightning', or 'snow'" << endl;
    cout << "For High and Low, type an integer between -50 and 150 (this is in Farenheight)" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    // Call function and check for return error
    if(getForecast(file, days)){
        // If no error, call python script
        cout << "Data collected, backdrop will be generated!" << endl;
        system("python3 weather.py");
    } else {
        cout << "Error: data issue, please run again" << endl;
    }

    return 0;
}

/* Functon getForecast takes in file name and vector of days in the week
* Function gets user input for forcast, high, and low temp for the week
* Creates an output string which it sends to function writeForecast
* Returns true if no error encountered
*/
bool getForecast(const string& file, vector<string> days) {
    string fullForecast;
    string forecast;
    string forecastInput;
    int high;
    int low;
    for(const auto & day : days){
        // get user input for forecast
        cout << day << ":" << endl;
        cout << "  Forecast: ";
        cin >> forecastInput;

        // reset string forecast and make all lowercase
        forecast = "";
        for(char j : forecastInput){
            forecast += tolower(j);
        }

        // input validation for forecast
        while (forecast!="sun" && forecast!="cloud" && forecast!="partcloud" && forecast!="rain" && forecast!="lightning" && forecast!="snow"){
            // if invalid, prompt again
            cout << "  Please only enter the above options for Forcast" << endl;
            cout << "  Forecast: ";
            cin >> forecastInput;

            // reset string and make all lowercase
            forecast = "";
            for(char j : forecastInput){
                forecast += tolower(j);
            }
        }

        // get user input for high temp
        cout << "  High: ";
        cin >> high;
        high = int(high);

        // input validation
        while (high > 150 || high < -50){
            cout << "  Please only enter an int within -50 to 150 range" << endl;
            cout << "  High: ";
            cin >> high;
        }

        // get user input for low temp
        cout << "  Low: ";
        cin >> low;

        // input validation
        while (low > 150 || low < -50){
            cout << "  Please only enter an int within -50 to 150 range" << endl;
            cout << "  Low: ";
            cin >> low;
        }

        // update fullForecast
        fullForecast += forecast + "," + to_string(high) + "," + to_string(low) + "\n";
    }

    // call writeForcast to write fullForecast to desired csv file
    if (writeForecast(file, fullForecast)) {
        return true;
    } else{
        cout << "Error: could not write to file" << endl;
        return false;
    }
}

/* writeForecast function takes in file name and fullForecast string
* Function writes fullForecast to desired file
* If no error, returns true, if error returns false
*/
bool writeForecast(const string& file, const string& fullForecast) {
    ofstream outFile(file);
    // if file valid, write to file then close and return true
    if (outFile) {
        outFile << fullForecast << endl;
        outFile.close();
        return true;
    }
    outFile.close();
    return false;
}



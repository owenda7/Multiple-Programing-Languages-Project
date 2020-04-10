#include <fstream>
#include <iostream>
#include <list>
using namespace std;

bool getForecast(string file, list<string> days);
bool writeForecast(string file, string fullForcast);
void clearFile(string filename);


int main() {

    list<string> days = {"Monday","Tuesday","Wednessday","Thursday","Friday","Saturday","Sunday"};
    string file = "weather.csv";

    cout << "Weather Forcast Backdrop Generator" << endl;
    cout << "For each day of the week you will be prompted for 'Forcast', 'High', and 'Low'" << endl;
    cout << "For Forcast, type 'sun','cloud','partcloud','rain','lightning', or 'snow'" << endl;
    cout << "For High and Low, type an integer between -50 and 150 (this is in Farenheight)" << endl;
    if(getForecast(file, days)){
        cout << "Data collected, backdrop will be generated!" << endl;
    } else {
        cout << "Error: data issue, please run again" << endl;
        clearFile(file);
    }

    return 0;
}

bool getForecast(string file, list<string> days) {
    string fullForecast = "";
    string forecast;
    int high;
    int low;
    for(int i = 0; i < days.size(); i++){
        cout << days.at(i) << ":" << endl;
        cout << "  Forecast: ";
        getline(cin, forecast);
        tolower(forecast)
        while (forecast!="sun" && forecast!="cloud" && forecast!="partcloud" && forecast!="rain" && forecast!="lightning" && forecast!="snow"){
            cout << "  Please only enter the above options for Forcast" << endl;
            cout << "  Forecast: ";
            getline(cin, forecast);
            forecast.lower();
        }
        cout << "  High: ";
        cin >> high;
        while (high > 150 && high << -50){
            cout << "  Please only enter an int within -50 to 150 range" << endl;
            cout << "  High: ";
            cin >> high;
        }
        cout << "  Low: ";
        cin >> low;
        while (low > 150 && low << -50){
            cout << "  Please only enter an int within -50 to 150 range" << endl;
            cout << "  Low: ";
            cin >> low;
        }
        fullForcast += forecast + to_string(high) + to_string(low);
    }

    if (writeForecast(file, forecast, high, low)){
        return true;
    } else{
        cout << "Error: could not write to file" << endl;
        return false;
    }
}

bool writeForcast(string file, string fullForcast) {
    ofstream outFile(file)
    if (outFile) {
        outFile << fullForcast << endl;
        outFile.close();
        return true;
    }
    outFile.close();
    return false;
}

void clearFile(string filename) {
    ofstream outFile(filename);
    outFile.close();
}


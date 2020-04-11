# OA-Final-Project-MPL

For the MPL portion of the final project, I chose to write a program 
to generate the backdrop for a news weather report. To do this, I used
c++ to gather user input and write the user input to a csv file. The c++ 
program then calls the corresponding python program that uses the csv file
to generate the backdrop for the newscast using the PIL image library. 

![Final backdrop generated](exampleresult.png)

<h3> Instructions for use: </h3>

* Compile and run updateWeather.cpp
* For each day of the week you will be prompted for 'Forecast', 'High', and 'Low'
* For Forecast, type 'sun', 'cloud', 'partcloud', 'rain', 'lightning', or 'snow'
* For High and Low, type an integer between -50 and 150 (this is in Farenheight)
* Image will appear in preview and a copy will be saved in the given directory as final.png
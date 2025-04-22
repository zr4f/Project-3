Our project only had 2 people, as one person dropped the class from the 3 person group, so we were allowed to use a C++ library function to create one of the data structures and the other one was made from scratch.

# Climate Data - Temperature and Precipitation Analysis

### Getting Started
To use the repository, clone the repository and open it in CLion.

#### Selecting Weather Station
Our Code has default acess to the Cape Canaveral Station data from 2013-04-17 to 2025-04-16, but can be applied to any area's weather station.

Go to [this website](https://mesonet.agron.iastate.edu/request/download.phtml?network=FL_ASOS#) and selected what weather station you would like to use and what dates you would like the application to access. Click on the Air Temperature (F) and 1 hour Precipation (in) under the Select from Available Data drop down and export the data as a ".csv" file.

When you open CLion replace the original "XMR.csv" with the new data in the same location as the original.

If you named your file something other than the default you will need to update line 16 of the main.cpp changing "src/XMR.csv" to "src/(your file name here).csv"

You will now be able to use your data. Remember you will only have access to the days of data you exported from the website.

### Running the Program
Run the main.cpp file and the program will execute in the terminal. 

The first 3 options will return the maximum and minimum temperature and the maximum 1 hour precipipation from all your data.
The last three will accept a date range to find the maximum and minimum temperature and maximum precipitation. 
#### Input Rules for Date Range
Input the dates in YYYY-MM-DD and make sure to type the "-". The dates must exist on a calendar. Additionally, the first date must be before the second date chronologically. 
So 2023-05-04 followed by 2023-04-05 would not produce an output.

### Thank you for using our program!

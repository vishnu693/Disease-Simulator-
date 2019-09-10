#include <iostream>
#include <vector> // for 2D vector 
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <string>
#include <cstdlib>

using namespace std;

// A function to print out each day's update
void printChart(vector<vector<char> > table, int day )
{
    cout<<endl;
    cout<<"DAY "<< day<<endl; // Printing the graph

    // Loops the 2-d vector to print the values
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++)
        {
            cout << table[i][j]<< " ";
        }
        cout<<endl;

    }
}



int main()
{
    // Request and connect to input file
    ifstream in;
    char input_file[30];
    cout << "Please input the input file name \n"; // get the file name
    cin >> input_file;

    in.open(input_file); // connect to the input file and test
    if(in.fail())
    {
        cout << "Input file opening failed. \n";
        exit(EXIT_FAILURE); // exit if cannot open file
    }



    // Reading in the input dat and storing he values in variables
    for(int i =0; i< 10; i++)
    {
        char c;
        in >> c;

    }

    int threshold;
    in >> threshold;

    for(int i =0; i< 17; i++)
    {
        char c;
        in >> c;
        //cout<< c <<endl;
    }
    int period;
    in >> period;

    for(int i =0; i< 8; i++)
    {
        char c;
        in >> c;
    }
    int display;
    in >> display;


    vector<vector<char> > chart; // 2d vector of an object to store the data

    // Read in the values for the graph
    string aa;
    getline(in,aa);
    while(!in.eof())
    {
        vector <char> row; // get values and store each row in a vector
        string line;
        getline(in,line);
        for(int i =0; i < line.length(); i = i+2)
        {
            row.push_back(line[i]);

        }
        if(row.size() != 0) {
            chart.push_back(row); // add the vector to the 2d vector
        }
    }

    //create a 2-d vector to store the days remining infected
    int length = chart.size();
    int nums[length][length];

    for(int i = 0; i<length; i++)
    {
        for(int j=0; j<length; j++)
        {
            nums[i][j] =0;
        }
    }


    //Seting the infected days remaining initially based on the initial input value
    for (int i = 0; i < chart.size(); i++)
    {
        for (int j = 0; j < chart[i].size(); j++)
        {
            char temp = (chart[i][j]);
            if(temp == 's' || temp  == 'S')
            {
                nums[i][j] = 0;
            }
            else if(temp  == 'i' || temp  == 'I')
            {
                nums[i][j] = period;
            }
            else if(temp  == 'r' || temp == 'R')
            {
                nums[i][j] = 0;
            }
            else if(temp  == 'v' || temp  == 'V')
            {
                nums[i][j] = 0;
            }
        }
    }



    //Print out the initial graph from
    cout<<"DAY 0"<<endl; // Printing the graph


    for (int i = 0; i < chart.size(); i++) {
        for (int j = 0; j < chart[i].size(); j++)
        {
            cout << chart[i][j]<< " ";
        }
        cout<<endl;
    }




    //Variables that store the required cretiria
    int peakDay =0;
    int peakValue =0;
    bool end = true;
    int dayCount =0;

    //Keeps running the program till the program meets its criteria
    while(end == true)
    {
        dayCount++;
        vector<vector<char> > chart_new; // emperory 2d vector to store the changes
        chart_new = chart;

        for (int i = 0; i < chart.size(); i++)
        {
            for (int j = 0; j < chart[i].size(); j++)
            {
                char temp = (chart[i][j]);

                // finds if an element is susepable and see if will get infected
                if(temp == 's' || temp  == 'S')
                {
                    int counter =0;

                    //checks the top left position
                    if( i!= 0 )
                    {
                        if( j!=0 )
                        {

                            if (chart[i-1][j-1] == 'i')
                            {
                                counter++;
                            }
                        }
                        else
                        {
                            //cout << chart[i-1][length-1]<<endl;
                            if (chart[i-1][length-1] == 'i')
                            {
                                counter++;
                            }
                        }
                    }

                    //checks the top position
                    if( i!=0)
                    {
                        if (chart[i-1][j] == 'i')
                        {
                            counter++;
                        }
                    }

                    //checks the top right position
                    if( i!= 0 )
                    {
                        if( j!= length-1 )
                        {

                            if (chart[i-1][j+1] == 'i')
                            {
                                counter++;
                            }
                        }
                        else
                        {
                            if (chart[0][j+1] == 'i')
                            {
                                counter++;
                            }
                        }
                    }

                    //checks the left position

                    if(j!= 0)
                    {
                        if (chart[i][j-1] == 'i')
                        {
                            counter++;
                        }
                    }
                    else
                    {
                        if (chart[i][length-1] == 'i')
                        {
                            counter++;
                        }
                    }


                    //cheks the right position

                    if( j!= length-1)
                    {
                        if (chart[i][j+1] == 'i')
                        {
                            counter++;
                        }
                    }
                    else
                    {
                        if (chart[i][0] == 'i')
                        {
                            counter++;
                        }
                    }


                    // chcks the bottom left position

                    if(i != length-1)
                    {
                        if( j!=0 )
                        {

                            if (chart[i+1][j-1] == 'i')
                            {
                                counter++;
                            }
                        }
                        else
                        {
                            //cout << chart[i-1][length-1]<<endl;
                            if (chart[i+1][length-1] == 'i')
                            {
                                counter++;
                            }
                        }
                    }

                    // checks the bottom right position

                    if( i!= length-1 )
                    {
                        if( j!= length-1 )
                        {

                            if (chart[i+1][j+1] == 'i')
                            {
                                counter++;
                            }
                        }
                        else
                        {
                            if (chart[i+1][0] == 'i')
                            {
                                counter++;
                            }
                        }
                    }

                    // checks the bottom position

                    if( i!= length-1)
                    {
                        if (chart[i+1][j] == 'i')
                        {
                            counter++;
                        }
                    }

                    //Checks if there are enough agets to infect the person
                    if(counter >= threshold)
                    {
                        chart_new[i][j] = 'i';
                        nums[i][j] = period+1;
                    }
                }



            }
        }


        //saving all the changes to the actual vector
        chart = chart_new;


        // decrease the number of days left as a round passes
        for (int i = 0; i < chart.size(); i++) {
            for (int j = 0; j < chart[i].size(); j++)
            {
                if(nums[i][j] != 0)
                {
                    nums[i][j] = nums[i][j] -1;
                }
            }

        }

        // check and change the status of a reovered
        for (int i = 0; i < chart.size(); i++) {
            for (int j = 0; j < chart[i].size(); j++)
            {
                if(nums[i][j] == 0 && chart[i][j] == 'i')
                {
                    chart[i][j] = 'r';
                }
            }
        }

        //print out the days based on the display requirements
        if(dayCount % display == 0)
        {
            printChart(chart, dayCount);
        }



        //Goes through the code and counts the number of each type of status
        int counts [4]= {0,0,0,0};
        for (int i = 0; i < chart.size(); i++)
        {
            for (int j = 0; j < chart[i].size(); j++)
            {
                char temp = (chart[i][j]);
                if(temp == 's' || temp  == 'S')
                {
                    counts[0]++;
                }
                else if(temp  == 'i' || temp  == 'I')
                {
                    counts[1]++;
                }
                else if(temp  == 'r' || temp == 'R')
                {
                    counts[2]++;
                }
                else if(temp  == 'v' || temp  == 'V')
                {
                    counts[3]++;
                }
            }
        }


        //ends the loop if thee are no infected left (program requirement)
        if(counts[1] == 0)

        {
            break;
        }

        //keeps track of the peak vlaue
        if(peakValue <= counts[1])
        {
            peakValue = counts[1];
            peakDay =dayCount;
        }


    }


    //Goes through the code and counts the number of each type of status at the final state

    int count [4]= {0,0,0,0};
    for (int i = 0; i < chart.size(); i++)
    {
        for (int j = 0; j < chart[i].size(); j++)
        {
            char temp = (chart[i][j]);
            if(temp == 's' || temp  == 'S')
            {
                count[0]++;
            }
            else if(temp  == 'i' || temp  == 'I')
            {
                count[1]++;
            }
            else if(temp  == 'r' || temp == 'R')
            {
                count[2]++;
            }
            else if(temp  == 'v' || temp  == 'V')
            {
                count[3]++;
            }
        }
    }

    //prints the last day even if the end day doesent follow the display patteren
    if(dayCount % display != 0)
    {
        printChart(chart, dayCount);
    }

    // Printing the data collected at the last day
    cout<<endl;
    cout<<"Outbreak Ends: Day " <<dayCount<<endl;
    cout<< "Peak Day: Day " << peakDay<<endl;
    cout <<"S: " <<count[0]<<endl;
    cout <<"I: " <<count[1]<<endl;
    cout <<"R: " <<count[2]<<endl;
    cout <<"V: " <<count[3]<<endl;
    cout<<endl;

    return 0;
}




// Team Members: Sarah Villegas, Ali Fenton, Chanel Aquin
// Date Created: 30 October 2015
// Description: Evaluating Structural Strength
/*
    In order to calculate whether or not the coupons data are acceptable, 
    we multiply each standard deviation by the design factor (S = 2) and
    subtract that value from its respective mean value.
    If this number is greater 16000, then it is within three standrd deviations.
    
        Formula: [Mean - (Standard Deviation * 2)] > 16000?
        
    1) Steel: 18846 - (1190.77 * 2) == 16465.36 > 16000 ==> Acceptable coupon
    2) Graphite: 18581.4 - (945.878 * 2) == 16689.644 > 16000 ==> Acceptable coupon
*/

#include <iostream> // cin, cout
#include <fstream>  // file IO
#include <cmath>    // sqrt(), pow
#include <iomanip>  // setw()
#include <cstdlib>  // exit()
using namespace std;


void printArray(int ary[], int num);
double mean(int ary[], int n);
int maxValue(ofstream& sendfile, int ary[], int num); 
int minValue(ofstream& sendfile, int ary[], int num);
double variance(int ary[],double avg, int count);
double standardDeviation(int var);


//*********************************
int main()
{
    const int SIZE = 20;
    
    int 
        stl[SIZE] = {0},
        gph[SIZE] = {0},
        value,
        steelAryCount = 0,
        graphiteAryCount = 0;
        
   int 
        maxSteel = 0, 
        maxGph = 0, 
        minSteel = 0, 
        minGph = 0;
    
    double 
        averageSteel,
        averageGraphite,
        varianceSteel,
        varianceGraphite,
        stdDevSteel,
        stdDevGraphite;
    
    // create input/output files
    ifstream fsteel, fgraphite;
    ofstream fout;
    
    // open files
    fsteel.open("data1.txt");
    fgraphite.open("data2.txt");
    fout.open("results.txt");
    
    // exit program if files do not exist
    if (fsteel.fail() || fgraphite.fail() || fout.fail())
    {
        cout << "Error: Files do not exist.";
        exit(1);
    }
    
    // read data from file data1.txt to array stl[]
    while (fsteel >> value)
    {
        stl[steelAryCount] = value; // input values into stl[] 
        steelAryCount++;
    }
    
    // read data from file data2.txt to array gph[]
    while (fgraphite >> value)
    {
        gph[graphiteAryCount] = value;  // input values into gph[]
        graphiteAryCount++;
    }     
    
    // close files
    fsteel.close();
    fgraphite.close();
    
    
    // call functions and print results to output file
    
    fout << "Team Members: Sarah Villegas, Ali Fenton, Chanel Aquino" << endl << endl;
    
    averageSteel =  mean(stl, steelAryCount);
    averageGraphite = mean(gph, graphiteAryCount);
    maxSteel = maxValue(fout, stl, steelAryCount); 
    maxGph = maxValue(fout, gph, steelAryCount);
    minSteel = minValue(fout, stl, steelAryCount);
    minGph = minValue(fout, gph, graphiteAryCount);
    varianceSteel = variance(stl, averageSteel, steelAryCount);
    stdDevSteel = standardDeviation(varianceSteel);
    varianceGraphite = variance(gph, averageGraphite, graphiteAryCount);
    stdDevGraphite = standardDeviation(varianceGraphite);
    
    const int WIDTH = 30;
    fout 
        << setw(WIDTH * 2)<< "Steel" << setw(WIDTH) << "Graphite" << endl
        <<  setw(WIDTH) << "Mean" << setw(WIDTH) << averageSteel << setw(WIDTH) << averageGraphite << endl
        <<  setw(WIDTH) << "Maximum" << setw(WIDTH) << maxSteel <<  setw(WIDTH) << maxGph << endl
        <<  setw(WIDTH) << "Minimum" << setw(WIDTH) << minSteel << setw(WIDTH) << minGph << endl
        <<  setw(WIDTH) << "Variance" << setw(WIDTH) << varianceSteel << setw(WIDTH) << varianceGraphite << endl
        <<  setw(WIDTH) << "Standard Deviation" << setw(WIDTH) << stdDevSteel << setw(WIDTH) << stdDevGraphite << endl;
    
    fout.close();
    return 0;
}

//*********************************
void printArray(int ary[], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << ary[i] << " " << endl;
    }
    
}

//*********************************
double mean(int ary[], int n)
{

    double sum = 0, finalMean; 
    for(int i = 0; i < n; i++){
    
        sum += ary[i]; 
    }
    
    finalMean = sum / n;

    return finalMean; 
}

//*********************************
int maxValue(ofstream& sendfile, int ary[], int num)
{
    int maxNum = 0;
    for(int i = 0; i < num; i++){
        if(ary[i] > maxNum){
            maxNum = ary[i];
        }
    }
    return maxNum;
}

//*********************************
int minValue(ofstream& sendfile, int ary[], int num)
{
    int minNum = 50000;
    for(int i = 0; i < num; i++){
        if( minNum > ary[i]){
            minNum = ary[i];
        }
    }
    return  minNum;
}

//*******************************
double variance(int ary[],double avg, int count)
{
    double sum = 0.0;
    
    for(int i = 0; i < count; i++)
    {
        sum += pow( (ary[i] - avg), 2);
    }
    
    double var = sum / count;
    
    return var;
}

//*******************************
double standardDeviation(int var)
{
    double stdDv = sqrt(var);
    
    return stdDv;
}














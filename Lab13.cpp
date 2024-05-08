//Author:  Beatriz Ceschin Antunes
//Class:   CMPSC 121
//Lab 13
//Purpose: Program reads a txt file with candidates' names, then generates random number of votes for each candidate 
// listed on the txt file and displays the results. 
//Sources of logic assistance: N/A

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// defining constant that sets size of arrays
const int CAPACITY = 25;

// function prototypes
bool readFile(string c[], int& size);
void getVotes(int v[], int size);
void calculatePercents(int v[], double p[], int size);
void displayResults(string c[], int v[], double p[], int size);

int main() {

    // declaring arrays 
    string candidates[CAPACITY];
    int votes[CAPACITY];
    double percents[CAPACITY];

    int size = CAPACITY;

    // makes sure there have been no errors opening the file
    if (!readFile(candidates, size)) {
        return 1;
    }

    // fills the votes array with random numbers
    getVotes(votes, size);

    // fills percentage array with calculated precentages of the total of votes
    calculatePercents(votes, percents, size);

    // show voting results
    displayResults(candidates, votes, percents, size);

    return 0;
}

// function reads candidates.txt file, displays error if anything goes wrong
bool readFile(string c[], int& size)
{
    ifstream infile("C:/CMPSC121/experiments/Lab13/Lab13/candidates.txt");
    if (!infile) {
        cout << "Error opening file." << endl;
        return false;
    }

    size = 0;
    
    // reads file until end
    while (size < CAPACITY && getline(infile, c[size])) {
        size++;
    }

    // closes file
    infile.close();
    return true;
}

// function generates random numbers between 1500 and 25000 to fill the votes array
void getVotes(int v[], int size)
{
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed); // seeds random number generator

    // loop fills the votes array with randomly generated numbers
    for (int i = 0; i < size; i++) {
        v[i] = rand() % 23501 + 1500; // Random number between 1500 and 25000
    }
}

// function determines number of votes and calculates the percentage for each candidate to fill the percents array
void calculatePercents(int v[], double p[], int size)
{
    // calculates total of votes
    int totalVotes = 0;
    for (int i = 0; i < size; i++) {
        totalVotes += v[i];
    }

    // calculates percentages
    for (int i = 0; i < size; i++) {
        p[i] = (static_cast<double>(v[i]) / totalVotes) * 100.0;
    }
}

// displays voting results to user
void displayResults(string c[], int v[], double p[], int size)
{
    // displays header
    cout << setw(15) << left << "Candidate";
    cout << setw(15) << left << "Votes";
    cout << setw(15) << left << "Percent" << endl;

    // help keep track of winner
    int winnerIndex = 0;
    int maxVotes = v[0];

    for (int i = 0; i < size; i++)
    {
        cout << setw(15) << left << c[i]; // displays candidates' names
        cout << setw(15) << left << v[i]; // displays number of votes
        cout << setprecision(1) << fixed;
        cout << p[i] << "%" << endl; // displays percentage 

        // compares results to declare a winner
        if (v[i] > maxVotes) 
        {
            maxVotes = v[i];
            winnerIndex = i;
        }
    }
    
    // displays winner
    cout << endl << "The winner is " << c[winnerIndex] << " with " << v[winnerIndex] << " votes!" << endl;
}

/*
Execution Sample:
#1
Candidate      Votes          Percent
Rubio          24208          10.4%
Bush           12646          5.4%
Christie       10309          4.4%
Paul           2484           1.1%
O'Malley       8781           3.8%
Cruz           13493          5.8%
Clinton        7888           3.4%
Trump          6842           2.9%
Kasich         23995          10.3%
Sanders        9307           4.0%
Carson         2997           1.3%
Gilmore        21184          9.1%
Fiorina        17812          7.6%
Santorum       17951          7.7%
Huckabee       5467           2.3%
Graham         24895          10.7%
Jindal         3130           1.3%
Walker         4406           1.9%
Perry          15470          6.6%

The winner is Graham with 24895 votes!

#2
Candidate      Votes          Percent
Rubio          24349          9.2%
Bush           16076          6.1%
Christie       15538          5.9%
Paul           21398          8.1%
O'Malley       2823           1.1%
Cruz           18502          7.0%
Clinton        10651          4.0%
Trump          12041          4.6%
Kasich         13097          5.0%
Sanders        7084           2.7%
Carson         20138          7.6%
Gilmore        23078          8.7%
Fiorina        19511          7.4%
Santorum       8547           3.2%
Huckabee       9458           3.6%
Graham         16769          6.4%
Jindal         9424           3.6%
Walker         10258          3.9%
Perry          5154           2.0%

The winner is Rubio with 24349 votes!

#3
Candidate      Votes          Percent
Rubio          24463          9.8%
Bush           8321           3.3%
Christie       18192          7.3%
Paul           11646          4.6%
O'Malley       3385           1.4%
Cruz           24866          9.9%
Clinton        21283          8.5%
Trump          7891           3.2%
Kasich         10446          4.2%
Sanders        12011          4.8%
Carson         14961          6.0%
Gilmore        24620          9.8%
Fiorina        7940           3.2%
Santorum       7111           2.8%
Huckabee       9019           3.6%
Graham         10277          4.1%
Jindal         7048           2.8%
Walker         23282          9.3%
Perry          3693           1.5%

The winner is Cruz with 24866 votes!
*/

// This code outputs 2D matrix from input file. The input file is a batch of lines, with the first line in the file defining the size of the matrix
// Created in 2019 August 29.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <algorithm>
#include <limits>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
     int linenum=0; 
     string line;
     string pirma; 

     stringstream ss;
     int eil, stu;
     double val;


     ifstream inputfile;
     ofstream outputfile;
     
	cout << " Enter input file name : \n";
	string inpname; 
	cin >> inpname;
	//inpname = "Cu111ax_pot.txt";

	inputfile.open(inpname);
	//cin >> inputfile;

	if(!inputfile) {
        std::cout<<"Couldn't open the file"<<std::endl; //checks for input
        exit(1); }

	cout << " Enter output file name: \n";
	string outnam;
	//outnam = "Cu111ax_pot-out.txt";
	cin >> outnam;
	outputfile.open(outnam);
	


     getline(inputfile,pirma);				// pirmos eilutes rezas
     ss << pirma;					// skriptas paima pirma eilute kaip teksta
     while (!ss.eof()) { 				// ir vercia i 2 integer
        ss >> eil >> stu; 
     }
     cout << " Matrix " << eil << " x " << stu << endl;



	// novi bullshit
	const size_t N = eil;
	string** array = new string*[N];
	for (size_t i=0; i<N; ++i)
		array[i] = new string[N];
	for (size_t i=0; i<N; ++i)
	{	//for (size_t j=0; j<N; ++j)
		for (size_t j=0; j<stu; ++j)
		{
			array[i][j]={};
		}
	}


     while (!inputfile.eof())  	//skaito iki end of file
     {
	        for(int i = 0; i < stu; i++) //ciklas nuskaityti ir uzpildyti verciu masyva
        	{
			for (int j=0; j < eil; j++)
			{
				inputfile >> array[i][j]; // buvo ji, dabar taip pat, kaip ir root faile
				linenum++;
			}
		
        	}

     }// End While
	inputfile.close();	//uzdarom input

	cout << " Total number of lines " << linenum/2 << "\n"; //kazkodel dvigubai daugiau eiluciu parodo

	 
	// ciklas isvesti i nauja faila matricele
	for (int k=0; k<eil; k++)
		{ for (int l=0; l<stu; l++)
			{ 
			outputfile << array[k][l] << "\t\n"[l == stu-1]; }
     		}

     	//ciklas isvesciai i ekrana
		for (int i = 0; i < eil; i++) 
    		{ 
      			  for (int j = 0; j < stu; j++) 
        			{ 
         		  		cout << "Element at x[" << i 
               		  		<< "][" << j << "]: "; 
            				cout << array[i][j]<<endl; 
        			} 
		}
     outputfile.close();
     return 0;
}



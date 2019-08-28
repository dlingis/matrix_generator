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

     //fstream input;

     ifstream inputfile;
     ofstream outputfile;
     
     //inputfile.open("test.txt"); 	//opens input file
	cout << " Enter input file name : \n";
	string inpname; 
	cin >> inpname;



	inputfile.open(inpname);
	//cin >> inputfile;

	if(!inputfile) {
        std::cout<<"Couldn't open the file"<<std::endl; //checks for input
        exit(1); }

	cout << " Enter output file name: \n";
	string outnam;
	cin >> outnam;



     getline(inputfile,pirma);				// pirmos eilutes rezas
     ss << pirma;					// skriptas paima pirma eilute kaip teksta
     while (!ss.eof()) { 				// ir vercia i 2 integer
        ss >> eil >> stu; 
     }
     cout << " Matrix " << eil << " x " << stu << endl;

     string array[eil][stu] = {};			//kuriamas 2D masyvas vertems

     while (!inputfile.eof())  	//skaito iki end of file
     {
	        for(int i = 0; i < stu; i++) //ciklas nuskaityti ir uzpildyti verciu masyva
        	{
			for (int j=0; j < eil; j++)
			{
				inputfile >> array[j][i];
				linenum++;
			}
		
        	}

     }// End While
	inputfile.close();	//uzdarom input

	cout << " Total number of lines " << linenum/2 << "\n"; //kazkodel dvigubai daugiau eiluciu parodo

	 outputfile.open(outnam);
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



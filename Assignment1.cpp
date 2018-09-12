#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int countSubstring(const std::string& str, const std::string& sub) // function to count occurences of bigram
{
    if (sub.length() == 0)
    {
       return 0;
    }

    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
     offset = str.find(sub, offset + sub.length())) //search onward from the previous point in the substring it was found
    {
        count++;
    }
    return count;
}

int main(int argc, char* argv[])
{
  if(argc == 1)
  {
    cout << "No File inputted." << endl;
  }
                                                      //checking arcg c for num of arguments
  if(argc > 2)
  {
    cout << "Too many arguments." << endl;
  }
  else if(argc == 2)
    {
      bool cont = false;                              //variable to keep track of user input later
      int A=0, C=0, T=0, G=0;
      int AA=0, AC=0, AT=0, AG=0, CA=0, CC=0, CT=0, CG=0, TA=0,         //if argc = 2 will start to process file
          TC=0, TT=0, TG=0, GA=0, GC=0, GT=0, GG = 0;
      int totalNuc = 0;
      int totalBigram = 0;
      int numlines = 0;
      int totalLength = 0;
      string filename = "";
      ifstream file;
      double mean, variance, deviation;

      while(true)
      {
        if(cont == false)
        {
          filename = argv[1];                        //if cont is false it will execut ethe command line arg if true it will ask the user for a file
        }
        else
        {
          cout << "Enter the file name.";
          cin >> filename;
        }

        file.open(filename);
        string line;

        while(getline(file, line))
        {
          if(line.empty())
          {
            continue;
          }

          transform(line.begin(), line.end(), line.begin(), ::toupper);    //changing the characters in the file to uppercase

          for(int i = 0; i < line.size(); i++)                             //looping each line to count each char
          {
              if(line.at(i) == 'A')
              {
                A+=1;
              }
              if(line.at(i) == 'C')
              {
                C+=1;
              }
              if(line.at(i) == 'T')
              {
                T+=1;
              }
              if(line.at(i) == 'G')
              {
                G+=1;
              }
          }
          AA += countSubstring(line, "AA");
          AT += countSubstring(line, "AT");
          AG += countSubstring(line, "AG");
          AC += countSubstring(line, "AC");
          TA += countSubstring(line, "TA");
          TT += countSubstring(line, "TT");
          TG += countSubstring(line, "TG");
          TC += countSubstring(line, "TC");
          GA += countSubstring(line, "GA");
          GT += countSubstring(line, "GT");
          GG += countSubstring(line, "GG");
          GC += countSubstring(line, "GC");
          CA += countSubstring(line, "CA");
          CT += countSubstring(line, "CT");
          CG += countSubstring(line, "CG");
          CC += countSubstring(line, "CC");

          numlines += 1;
          totalLength += line.size()-1;
        }

        file.close();
        totalLength ++;
        mean = totalLength / numlines;

        totalNuc = float(A+T+G+C);
        totalBigram = float(AA+AC+AT+AG+CA+CC+CT+CG+TA+TC+TT+TG+GA+GC+GT+GG);
        cout << "A probability: "<< (float(A)/totalNuc) << endl;
        cout << "T probability: "<< (float(T)/totalNuc) << endl;
        cout << "G probability: "<< (float(G)/totalNuc) << endl;
        cout << "C probability: "<< (float(C)/totalNuc) << endl;
        cout << endl;
        cout << "AA probability: "<< (float(AA)/totalBigram) << endl;
        cout << "AT probability: "<< (float(AT)/totalBigram) << endl;
        cout << "AG probability: "<< (float(AG)/totalBigram) << endl;
        cout << "AC probability: "<< (float(AC)/totalBigram) << endl;

        cout << "TA probability: "<< (float(TA)/totalBigram) << endl;
        cout << "TT probability: "<< (float(TT)/totalBigram) << endl;
        cout << "TG probability: "<< (float(TG)/totalBigram) << endl;
        cout << "TC probability: "<< (float(TC)/totalBigram) << endl;

        cout << "GA probability: "<< (float(GA)/totalBigram) << endl;
        cout << "GT probability: "<< (float(GT)/totalBigram) << endl;
        cout << "GC probability: "<< (float(GC)/totalBigram) << endl;
        cout << "GG probability: "<< (float(GG)/totalBigram) << endl;

        cout << "CA probability: "<< (float(CA)/totalBigram) << endl;
        cout << "CT probability: "<< (float(CT)/totalBigram) << endl;
        cout << "CG probability: "<< (float(CG)/totalBigram) << endl;
        cout << "CC probability: "<< (float(CC)/totalBigram) << endl;
        cout << endl;

        file.open(filename);                                            //re-reading the file to calculate the variance

        while(getline(file, line))
        {
          variance += pow(line.size() - mean, 2);
        }

        file.close();

        variance = variance / numlines;
        deviation = sqrt(variance);
        ofstream JadynGonzalez;
        JadynGonzalez.open("JadynGonzalez.txt");

        if(cont == false)
        {
          JadynGonzalez << "Jadyn Gonzalez\t\t 2290329\n\n" <<endl;
          JadynGonzalez << "A probability: "<< (float(A)/totalNuc) << endl;
          JadynGonzalez << "T probability: "<< (float(T)/totalNuc) << endl;
          JadynGonzalez << "G probability: "<< (float(G)/totalNuc) << endl;
          JadynGonzalez << "C probability: "<< (float(C)/totalNuc) << endl;
          JadynGonzalez << endl;
          JadynGonzalez << "AA probability: "<< (float(AA)/totalBigram) << endl;
          JadynGonzalez << "AT probability: "<< (float(AT)/totalBigram) << endl;
          JadynGonzalez << "AG probability: "<< (float(AG)/totalBigram) << endl;
          JadynGonzalez << "AC probability: "<< (float(AC)/totalBigram) << endl;
          JadynGonzalez << "TA probability: "<< (float(TA)/totalBigram) << endl;
          JadynGonzalez << "TT probability: "<< (float(TT)/totalBigram) << endl;
          JadynGonzalez << "TG probability: "<< (float(TG)/totalBigram) << endl;
          JadynGonzalez << "TC probability: "<< (float(TC)/totalBigram) << endl;
          JadynGonzalez << "GA probability: "<< (float(GA)/totalBigram) << endl;
          JadynGonzalez << "GT probability: "<< (float(GT)/totalBigram) << endl;
          JadynGonzalez << "GC probability: "<< (float(GC)/totalBigram) << endl;
          JadynGonzalez << "GG probability: "<< (float(GG)/totalBigram) << endl;
          JadynGonzalez << "CA probability: "<< (float(CA)/totalBigram) << endl;
          JadynGonzalez << "CT probability: "<< (float(CT)/totalBigram) << endl;
          JadynGonzalez << "CG probability: "<< (float(CG)/totalBigram) << endl;
          JadynGonzalez << "CC probability: "<< (float(CC)/totalBigram) << endl;
          JadynGonzalez << endl;
          JadynGonzalez << "The sum is " << totalLength << endl;
          JadynGonzalez << "The number of lines is " << numlines << endl;
          JadynGonzalez << "The mean is " << mean << endl;
          JadynGonzalez << "The variance is " << variance << endl;
          JadynGonzalez << "The Standard Deviation is: " << deviation << endl;
          JadynGonzalez << endl;
        }
        else
        {
          JadynGonzalez << "A probability: "<< (float(A)/totalNuc) << endl;
          JadynGonzalez << "T probability: "<< (float(T)/totalNuc) << endl;
          JadynGonzalez << "G probability: "<< (float(G)/totalNuc) << endl;
          JadynGonzalez << "C probability: "<< (float(C)/totalNuc) << endl;
          JadynGonzalez << endl;
          JadynGonzalez << "AA probability: "<< (float(AA)/totalBigram) << endl;
          JadynGonzalez << "AT probability: "<< (float(AT)/totalBigram) << endl;
          JadynGonzalez << "AG probability: "<< (float(AG)/totalBigram) << endl;
          JadynGonzalez << "AC probability: "<< (float(AC)/totalBigram) << endl;
          JadynGonzalez << "TA probability: "<< (float(TA)/totalBigram) << endl;
          JadynGonzalez << "TT probability: "<< (float(TT)/totalBigram) << endl;
          JadynGonzalez << "TG probability: "<< (float(TG)/totalBigram) << endl;
          JadynGonzalez << "TC probability: "<< (float(TC)/totalBigram) << endl;
          JadynGonzalez << "GA probability: "<< (float(GA)/totalBigram) << endl;
          JadynGonzalez << "GT probability: "<< (float(GT)/totalBigram) << endl;
          JadynGonzalez << "GC probability: "<< (float(GC)/totalBigram) << endl;
          JadynGonzalez << "GG probability: "<< (float(GG)/totalBigram) << endl;
          JadynGonzalez << "CA probability: "<< (float(CA)/totalBigram) << endl;
          JadynGonzalez << "CT probability: "<< (float(CT)/totalBigram) << endl;
          JadynGonzalez << "CG probability: "<< (float(CG)/totalBigram) << endl;
          JadynGonzalez << "CC probability: "<< (float(CC)/totalBigram) << endl;
          JadynGonzalez << endl;
          JadynGonzalez << "The sum is " << totalLength << endl;
          JadynGonzalez << "The number of lines is " << numlines << endl;
          JadynGonzalez << "The mean is " << mean << endl;
          JadynGonzalez << "The variance is " << variance << endl;
          JadynGonzalez << "The Standard Deviation is: " << deviation << endl;
          JadynGonzalez << endl;
        }

        double a = rand() % 2; //random variables from [0-1)??
        double b = rand() % 2;
        double PI = 3.14;

        double E = sqrt(-2 * log(a)) * cos(2 * PI * b); //Standard Gaussian with mean 0 and variance 1
        double D = (deviation * E) + mean;
        cout << "Gaussian " << D << endl;
        char cmd;
        cout << "Do you want to enter another file? (y/n)" << endl;
        cin >> cmd;
        if(cmd == 'n' || cmd == 'N')
        {
        cont = false;
         for(int i = 0; i < 50; i++)
          {
            for(int j = 0; j < D; j++)
            {
              int n = rand() % 5 + 1;
              switch(n)
              {
                case 1:
                  JadynGonzalez << "A";
                case 2:
                  JadynGonzalez << "T";
                case 3:
                  JadynGonzalez << "C";
                case 4:
                  JadynGonzalez << "G";
              }
            }
            JadynGonzalez << endl;
          }
          cout << "ending program.";
          JadynGonzalez.close();
          break;
        }
        else if(cmd == 'y' || cmd == 'Y')                                                             // updating cont to continue or exit the loop
        {
        cont = true;
         for(int i = 0; i < 50; i++)
          {
            for(int j = 0; j < D; j++)
            {
              int m = rand() % 5 + 1;
              switch(m)
              {
                case 1:
                  JadynGonzalez << "A";
                case 2:
                  JadynGonzalez << "T";
                case 3:
                  JadynGonzalez << "C";
                case 4:
                  JadynGonzalez << "G";
              }
            }
            JadynGonzalez << endl;
          }
        cont = true;
        JadynGonzalez.close();
      }

    }
    return 0;
  }
}

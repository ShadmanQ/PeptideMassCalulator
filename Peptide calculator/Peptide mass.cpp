/*
Calculates the molar mass of a peptide.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct peptide
{
char id;
string threelet;
string name;
double mass;
};

void LoadPeptides(vector <peptide>& x);
void capitalize (string& g);

int main()
{

vector <peptide> PepVector;
LoadPeptides(PepVector);
cout << "please enter your sequence"<<endl;

string sequence;
cin >> sequence;
capitalize(sequence);
double totalmass = 0;
cout << "The sequence you entered has "<< sequence.length()<<" amino acid(s). Is this correct?(type y or n)" << endl;
char confirm;
cin >> confirm;
{
    cout << "This peptide has the fololowing amino acid(s)";
    for (int i = 0; i < sequence.length(); i++)
    {
        for (int j = 0; j < PepVector.size(); j++)
        {
            if (sequence[i] == PepVector[j].id)
            {
                cout << PepVector[j].name<< " ";
                totalmass += PepVector[j].mass;
            }
        }
    }
    cout << endl;
}

double water_weight = (18.01528)*(sequence.length()-1);
totalmass-=water_weight;
cout <<"The molar mass of this peptide is "<<totalmass<<" g/mol"<<
endl;
system("PAUSE");
return 0;
}
void LoadPeptides(vector <peptide>& x)
{
 char temp_id;
 string temp_3let;
 string temp_name;
 double temp_mass;
 ifstream Pepfile;
 Pepfile.open("Peptide.txt");
  while (Pepfile >> temp_id >> temp_3let >> temp_name >> temp_mass)
    {
     peptide temptide;
     temptide.id = temp_id;
     temptide.threelet = temp_3let;
     temptide.name = temp_name;
     temptide.mass = temp_mass;
     x.push_back(temptide);
    }
}

void capitalize (string& g)
{
    for (int i = 0; i < g.length(); i++)
    {
        g[i] =  char(toupper(g[i]));
    }
}

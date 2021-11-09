#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<istream>

using namespace std;

int main()
{
    char para[1000], word[100];

	printf("Enter the paragraph:  ");

	cin.getline(para, 1000);             // used to read a string or a line from input stream.

	int iteration = 0;
	int i=0;

	while (para[iteration]!= '\0'){     // denotes the end of string

		cout<<para[iteration];

		if (isspace(para[iteration]))
		{
			cout <<"\n";
		}
	word[i] = para[iteration];
	i++;
	iteration++;
}

return 0;

}



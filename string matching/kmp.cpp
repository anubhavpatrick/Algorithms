/* http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/ */
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char pattern[]="nanna";
	char text[]="nanna is great programmer. You must take nanna seriously. nanna is best";
	int lcs[]={0,0,1,1,2};//Needs to be computed manually
	int i,j,len_pattern=strlen(pattern),len_text=strlen(text);
	i=0;//Starting index of text
	j=0;//Starting index of pattern
	while(i<len_text)
	{
		if(pattern[j]==text[i])
		{
			i++;
			j++;
			if(j==len_pattern)
			{
				cout<<"Pattern found at starting at index "<<(i-j)<<endl;
				j>=0?j=lcs[j-1]:j=0;
			}
		}
		else
		{
			if(j>0)
			j=lcs[j-1];
			else
			{
				j=0;
				i++;
			}
		}

	}
	return 0;
}
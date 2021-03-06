// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/crossword-puzzle-official/ojquestion


// Code:-

#include <bits/stdc++.h>
using namespace std;
bool isfithorzontally(char* crossword, string curWord, int row, int col){
	  if (col + curWord.length() >10)
	{
		return false;
	}

	for (int i = 0; i < curWord.length(); i++)
	{   
	  
		if (*(crossword + row * 10 + col + i) == '-' || *(crossword + row * 10 + col + i) == curWord[i])
		{
			continue;
		}else{
		    	return false;
		}
	}
	if (col + curWord.length() == 10 || *(crossword + row * 10 + col +curWord.length()) == '+')
	{
	return true;
	}
	else
	{
		return false;
	}
	
	return true;
}
bool isfitvertically(char* crossword, string curWord, int row, int col)
{	
    if (row + curWord.length()> 10)
	{  
   
		return false;
	}


	for (int i = 0; i < curWord.length(); i++)
	{   	
	    
		if (*(crossword + (row+i) * 10 + col) == '-' || *(crossword + (row+i) * 10 + col ) == curWord[i])
		{    continue;
		
		}else{
		    	return false;
		}
	}
	 if (row + curWord.length() == 10 || *(crossword + (row + curWord.length()) * 10 + col) == '+')
	{
		return true;
	}
	else
	{
		return false;
	}
	
	return true;
}
void placethiswordhorizontaly(char* crossword, string curWord, int row, int col, bool visited[])
{

	for (int i = 0; i < curWord.length(); i++)
	{
		if (*(crossword + row * 10 + col + i) == '-')
		{
			*(crossword + row * 10 + col + i) = curWord[i];
			visited[i] = true;
		}
		else
		{
			visited[i] = false;
		}
	}
	return;
}
void placethiswordvertically(char* crossword, string curWord, int row, int col, bool visited[])
{

	for (int i = 0; i < curWord.length(); i++)
	{
		if (*(crossword + (row + i) * 10 + col) == '-')
		{
			*(crossword + (row + i) * 10 + col) = curWord[i];
			visited[i] = true;
		}
		else
		{
			visited[i] = false;
		}
	}
	return;
}
void unplacethiswordhorizontaly(char* crossword, string curWord, int row, int col, bool visited[])
{
	for (int i = 0; i < curWord.length(); i++)
	{
		if (visited[i] == true)
		{
			*(crossword + row * 10 + col + i) = '-';
		}
	}
}
void unplacethiswordvertically(char* crossword, string curWord, int row, int col, bool visited[])
{
	for (int i = 0; i < curWord.length(); i++)
	{
		if (visited[i] == true)
		{
			*(crossword + (row + i) * 10 + col) = '-';
		}
	}
}

void crosswordSolver(char *crossword, string words[], int widx, int sizeofwords)
{
	if (widx == sizeofwords)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << *(crossword + i * 10 + j);
			}
			cout << endl;
		}
		return;
	}
		string curWord = words[widx];
		         
   
	for (int row = 0; row < 10; row++)
	{
		for (int col = 0; col < 10; col++)
		{   
		    
		
			if (*(crossword + row * 10 + col) == '-' || *(crossword + row * 10 + col) == curWord[0])
			{   
			    
				if (isfithorzontally((char *)crossword, curWord, row, col) == true)
				{    
					bool visited[curWord.length()];
					placethiswordhorizontaly((char *)crossword, curWord, row, col, visited);
					crosswordSolver((char *)crossword, words, widx + 1, sizeofwords);
					unplacethiswordhorizontaly((char *)crossword, curWord, row, col, visited);
				}
               
               
				if (isfitvertically((char *)crossword, curWord, row, col) == true)
				{   
					bool visited[curWord.length()];
					placethiswordvertically((char *)crossword, curWord, row, col, visited);
					crosswordSolver((char *)crossword, words, widx + 1, sizeofwords);
					unplacethiswordvertically((char *)crossword, curWord, row, col, visited);
				}
			}
			
		}
	
	}
}
	int main()
	{
		char crossword[10][10];
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cin >> crossword[i][j];
			}
		}
		
		
		int n;
		cin >> n;
		string words[n];
		for (int i = 0; i < n; i++)
		{
			cin >> words[i];
		
		}
		crosswordSolver((char *)crossword, words, 0, n);
	}

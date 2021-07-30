/*
This is the Brute Force method of solving the problem using HashMap.

Approach : For solving the problem we first have to find out all the distinct characters present in the string. 
This can be done using a HashMap. The next thing is to generate all the possible substrings. This follows by checking 
whether a substring generated has all the required characters(stored in the hash_map) or not. If yes, then compare its 
length with the minimum substring length which follows the above constraints, found till now.
HashMap: HashMap is a part of Java’s collection since Java 1.2. 
It provides the basic implementation of the Map interface of Java. It stores the data in (Key, Value) pairs. 
To access a value one must know its key. HashMap is known as HashMap because it uses a technique called Hashing. 
Hashing is a technique of converting a large String to small String that represents the same String. A shorter value 
helps in indexing and faster searches. HashSet also uses HashMap internally. 
It internally uses a link list to store key-value pairs already explained in HashSet in detail and further articles. 

Time Complexity: O(N^2). 
This time is required to generate all possible sub-strings of a string of length “N”.

Space Complexity: O(N). 
As a hash_map has been used of size N.

Here we have used Sliding Window technique to arrive at the solution. This technique shows how a nested for loop in few 
problems can be converted to single for loop and hence reducing the time complexity.

EFFICIENT Approach: Basically a window of characters is maintained by using two pointers namely start and end. 
These start and end pointers can be used to shrink and increase the size of window respectively. 
Whenever the window contains all characters of given string, the window is shrinked from left side to remove extra 
characters and then its length is compared with the smallest window found so far. 
If in the present window, no more characters can be deleted then we start increasing the size of the window using 
the end until all the distinct characters present in the string are also there in the window. Finally, find the minimum 
size of each window.

Time Complexity: O(N). 
As the string is traversed using two pointers only once.

Space Complexity: O(N). 
As a hash_map is used of size N

WE USED:

erase function is used to erase elements from the unordered_map. 
There are three type of erase functions supported by unordered_map of which we used
erasing by key: It takes a key as a parameter and erases the key and value.
Syntax
unordered_map.erase(const key);

*/

#include<bits/stdc++.h> //OPTIONAL
#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#include <unordered_map>

using namespace std;

int findSubString(string str,int l,unordered_map<int,int> m,int distinct)
{
	
	
	int min_len=INT_MAX,count=0,key;
	
	//creating a sliding window of size 0
	int window_start=0;
	int window_end=0;
	
	int win_length;
	
	//traverse the string
	
	//window start ko string ke start pe rakh diya hai and ab window end vaha hoga jaha pe saare distinct characters aa jayenege
	for(int i=0;i<l;i++)
	{
		key=(int)str[i];
		//if current character is present in the map then map me vo key erase karo taaki agar duplicate character aaye
		//to usko vaapis count na kare and increase our count (count<distinct)
		if(m.find(key)!=m.end())
		{
			m.erase(key);
			count++;
		}
		
		//jaha count distinct elements ke barabar pohocha vaha par window end karo and us window ki length nikalo
		//and simpultaneously minimum length bhi nikalo
		if(count==distinct)
		{
			window_end=i;
			win_length=window_end-window_start;
			min_len=min(min_len,win_length);
			
			//ab ek ek karke elements window se bahar nikaalte jaao 
			window_start++;
		}
	}
	
return min_len;	
}

int main()
{
	string str = "aabcbcdbca";
	int l=str.length();
	int key,value,frequency=1,distinct=0;
	
	//creating a map to store all distinct character
	unordered_map<int,int> m;
	
	//Saari unique values insert karo map me
    for(int i=0;i<l;)
    {
    	key=(int)str[i];
    	value=frequency; 
    	
    	// if map is empty or Key is not present, insert key and the value with frequency 1
    	if (m.find(key)==m.end())
    	{
    		//pair(mapping) bnaye
    		m.insert(make_pair(key,value));
    		distinct++;
    		i++;
		}
		// Key is already present to aage badho
		else if(m.find(key)!=m.end())
		{
			i++;
		}
	}
	
    cout << "Smallest window containing all distinct characters is: "<< findSubString(str,l,m,distinct);
	
	return 0;
}

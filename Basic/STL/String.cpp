1)
String has a substring function without iterators, just indices:
//s.substr(start,length) or s.substr(start)

string s = "hello";
string
s1 = s.substr(0, 3), // "hel"
s2 = s.substr(1, 3), // "ell"
s3 = s.substr(0, s.length()-1), "hell"
s4 = s.substr(1); // "ello"

Beware of (s.length()-1) on empty string because s.length() is unsigned and unsigned(0) – 1 is definitely not what you are expecting!
 /*
 stoi do not accept empty string
 */
  
2)function: 
        a) Check      - isalpha(), isdigit(), isalnum(), isupper(), islower(), lexicographical_compare(p.begin(), p.end(), s.begin(), s.end());
	b) Transform  - toupper(), tolower()
		
3)int i=s.find(' ') //Not " "
  0->48 and 9->57 ascii of numbers
  a-z == 97-122
  A-Z=65-90
  space = 32
  
4)Stable sort -- //The order of equal elements is guaranteed to be preserved in stable_sort.
  
5)string str; 
	// Input with spaces
	getline(cin,str);

6)//  replace(a, b, str)  replaces b characters from a index by str 
    str6.replace(2, 7, "ese are test"); 

    if (str6.find(str4) != string::npos) 
        cout << "str4 found in str6 at " << str6.find(str4) 
             << " pos" << endl; 
    else
        cout << "str4 not found in str6" << endl; 

7)string replaceBlankWith20(string str) 
  { 
    string replaceby = "%20"; 
    int n = 0; 
  
    // loop till all space are replaced 
    while ((n = str.find(" ", n)) != string::npos ) 
    { 
        str.replace(n, 1, replaceby); 
        n += replaceby.length(); 
    } 
    return str; 
  } 

8) Finding Occurence of a character
    string str = "geeksforgeeks a computer science"; 
    char c = 'g'; 
  
    // Find first occurrence of 'g' 
    size_t found = str.find(c); 
    if (found != string::npos) 
        cout << "First occurrence is " << found << endl; 
  
    // Find next occurrence of 'g' 
    found = str.find(c, found+1); 
    if (found != string::npos) 
        cout << "Next occurrence is " << found << endl; 
  
9)Permutation of string
     void permute(string str) 
     { 
    // Sort the string in lexicographically 
    // ascennding order 
    sort(str.begin(), str.end()); 
  
    // Keep printing next permutation while there 
    // is next permutation 
    do { 
       cout << str << endl; 
    } while (next_permutation(str.begin(), str.end())); 
    } 

10) String and Int
	(i)string to int 
		int i = stoi(s);
	(ii)int to string
		string s = to_string(i);
	Remember:
		a) int p = s[i]-'0'; //Single digit conversion
		b) comparison -> s[i]=='c' // Not Double quotes
		c) replacing -> s[i] = 'c'
		d) use Double quotes for adding/comapring more than one char (String literal) -> s+="1234"; //Not s+='1234'
		e) stoi do not accept empty string

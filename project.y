%{
	#include <stdio.h>
	#include <iostream>
	#include <string>
	#include <map>
	using namespace std;
	#include "y.tab.h"
	extern FILE *yyin;
	extern int yylex();
	void yyerror(string s);
	
	extern int linenum;
	bool errorFlag=false;
	int isTab=-1;
	#include <vector>
	#include <algorithm>
	vector<int> ss;
	vector<bool> ssCond;
	vector<int> ssWhat; // 1=if, 2=elif, 3=else
	map<string,int>varType; // 1=int 2=float 3=string
	map<string,string>stringVars;
	map<string,string>intVars;
	map<string,string>floatVars;
	
	int lastSt;
	


	
%}

%union
{
	int number;
	char * str;
}

%token PRINTF PERCENTINT
%token<str> IFST ELIFST ELSEST COMMA EQUAL SEMICOLON COLON OPS CPS COMPARISON MATH OP CP IDENTIFIER TAB QUOTE INT FLOAT
%type<str> program statement if_block elif_block else_block assignment_block expression value assignment expquote valuequote
%type<number> tab_block
 
%%

start:
	program
	{
		
		cout << "void main()\n{"<<endl;
		
		map<string, string>::iterator it;
		
		if(!intVars.empty())
		{
			cout<<"\tint ";
			for ( it = intVars.begin(); it != prev(intVars.end()); it++ )
			{
				cout << it->first << "_int,";
			}
			cout << it->first << "_int";
			cout << ";" << endl;
		}
		
		if(!floatVars.empty())
		{
			cout<<"\tfloat ";
			for ( it = floatVars.begin(); it != prev(floatVars.end()); it++ )
			{
				cout << it->first << "_flt,";
			}
			cout << it->first << "_flt";
			cout << ";" << endl;
		}
		
		if(!stringVars.empty())
		{
			cout<<"\tstring ";
			for ( it = stringVars.begin(); it != prev(stringVars.end()); it++ )
			{
				cout << it->first << "_str,";
			}
			cout << it->first << "_str";
			cout << ";" << endl;
		}
		cout<<endl;
		
		cout<<$1;
		cout <<"}"<<endl;
		cout << endl;
	}
	
program:
	statement 
	{
		if(lastSt==1 | lastSt==2 | lastSt==3)
		{
			cout << "error in line " << linenum-1 << ": at least one line should be inside if/elif/else block" << endl;
			exit(1);
		}
		$$=strdup($1);
	}
	|
	statement program 
	{
		string combined=string($1)+string($2);
		$$=strdup(combined.c_str());
	}
    ;

statement:
	if_block { $$=strdup($1); linenum++; lastSt=1;}
	|
	elif_block { $$=strdup($1); linenum++; lastSt=2;}
	|
	else_block { $$=strdup($1); linenum++; lastSt=3; }
	|
	assignment_block {$$=strdup($1); linenum++; lastSt=4; }
	;
	
if_block:
	IFST TAB expression COMPARISON expression COLON //a>=b
	{
		
		string tempp=$3;
		char tempChar=tempp[0];
		string tempStr(1, tempChar);
		int tempType=varType[ tempStr ];  
		
		for(int i=1; i<tempp.length(); i++)
		{
			if(tempp[i]!='*' && tempp[i]!='/' && tempp[i]!='-' && tempp[i]!='+')
			{
				char tempChar=tempp[i];
				string tempStr(1, tempChar);
				int tempType2=varType[ tempStr ];
				
				if(tempType==1 && tempType2==2)
				{
					tempType=2;
				}
				else if( (tempType==1 && tempType2==3) | (tempType==2 && tempType2==3) | (tempType==3 && tempType2==1) | (tempType==3 && tempType2==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		string tempp2=$5;
		char tempChar2=tempp2[0];
		string tempStr2(1, tempChar2);
		int tempTypeB=varType[ tempStr2 ];  
		
		for(int i=1; i<tempp2.length(); i++)
		{
			if(tempp2[i]!='*' && tempp2[i]!='/' && tempp2[i]!='-' && tempp2[i]!='+')
			{
				char tempChar2=tempp2[i];
				string tempStr2(1, tempChar2);
				int tempType3=varType[ tempStr2 ];
				
				if(tempTypeB==1 && tempType3==2)
				{
					tempTypeB=2;
				}
				else if( (tempTypeB==1 && tempType3==3) | (tempTypeB==2 && tempType3==3) | (tempTypeB==3 && tempType3==1) | (tempTypeB==3 && tempType3==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		if( (tempType==3 && tempTypeB==1) | (tempType==3 && tempTypeB==2) | (tempType==1 && tempTypeB==3) | (tempType==2 && tempTypeB==3) )
		{
			cout << "comparison type mismatch in line " << linenum << endl;
			exit(1);
		}

		if(ss.empty())
		{		
		
			isTab=1;
			string combined = "\t" + string($1) + "(" + " " + string($3) + " " + string($4) + " " + string($5) + " " + ")" + "\n" + "\t" + "{" + "\n";
			$$=strdup(combined.c_str());
	
			ss.push_back(0);
			ssCond.push_back(false);
			ssWhat.push_back(1);
		}
		else if(ss.size()>=1 && ssCond.back()==true)
		{
			string ssCurl;
			
			while(!ss.empty())
			{
				string ssNumCurl(ss.back(), '\t');
				ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
				
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
			}
			
			isTab=1;
			string combined = ssCurl + "\t" + string($1) + "(" + " " + string($3) + " " + string($4) + " " + string($5) + " " + ")" + "\n" + "\t" + "{" + "\n";
			$$=strdup(combined.c_str());
		
			ss.push_back(0);
			ssCond.push_back(false);
			ssWhat.push_back(1);
		}
		else if(ss.size()>=1 && ssCond.back()==false)
		{
			cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
			exit(1);
		}
		else
		{
			cout << "if/else inconsistency at line: "<< linenum << endl;
			exit(1);
		}

	}
	|
	tab_block IFST TAB expression COMPARISON expression COLON //	a>=b
	{
		
		string tempp=$4;
		char tempChar=tempp[0];
		string tempStr(1, tempChar);
		int tempType=varType[ tempStr ];  
		
		for(int i=1; i<tempp.length(); i++)
		{
			if(tempp[i]!='*' && tempp[i]!='/' && tempp[i]!='-' && tempp[i]!='+')
			{
				char tempChar=tempp[i];
				string tempStr(1, tempChar);
				int tempType2=varType[ tempStr ];
				
				if(tempType==1 && tempType2==2)
				{
					tempType=2;
				}
				else if( (tempType==1 && tempType2==3) | (tempType==2 && tempType2==3) | (tempType==3 && tempType2==1) | (tempType==3 && tempType2==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		string tempp2=$6;
		char tempChar2=tempp2[0];
		string tempStr2(1, tempChar2);
		int tempTypeB=varType[ tempStr2 ];  
		
		for(int i=1; i<tempp2.length(); i++)
		{
			if(tempp2[i]!='*' && tempp2[i]!='/' && tempp2[i]!='-' && tempp2[i]!='+')
			{
				char tempChar2=tempp2[i];
				string tempStr2(1, tempChar2);
				int tempType3=varType[ tempStr2 ];
				
				if(tempTypeB==1 && tempType3==2)
				{
					tempTypeB=2;
				}
				else if( (tempTypeB==1 && tempType3==3) | (tempTypeB==2 && tempType3==3) | (tempTypeB==3 && tempType3==1) | (tempTypeB==3 && tempType3==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		if( (tempType==3 && tempTypeB==1) | (tempType==3 && tempTypeB==2) | (tempType==1 && tempTypeB==3) | (tempType==2 && tempTypeB==3) )
		{
			cout << "comparison type mismatch in line " << linenum << endl;
			exit(1);
		}
			
		if (isTab == -1 || $1 > isTab)
		{
			cout << "tab inconsistency in line "<< linenum << endl;
			exit(1);
		}
		else
		{

			
			if( (ss.size()!=0) && ssCond.back()==false && $1==ss.back()+1 )
			{
				ssCond.back()=true;
				
				ss.push_back($1);
				ssCond.push_back(false);
				ssWhat.push_back(1);
				
				isTab=$1+1; 
				string stuff($1, '\t');
				string combined = "\t" + stuff + string($2) + "(" + " " +string($4)  +" " + string($5) + " " + string($6) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
				$$=strdup(combined.c_str());
			}
			else if( (ss.size()!=0) && ssCond.back()==true && $1==ss.back()+1 )
			{
				ss.push_back($1);
				ssCond.push_back(false);
				ssWhat.push_back(1);
				
				isTab=$1+1;
				string stuff($1, '\t');
				string combined = "\t" + stuff + string($2) + "(" + " " +string($4)  +" " + string($5) + " " + string($6) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
				$$=strdup(combined.c_str());
				
			}
			else if( (ss.size()!=0) && ssCond.back()==true && $1==ss.back() )
			{	
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				ss.push_back($1);
				ssCond.push_back(false);
				ssWhat.push_back(1);
				
				isTab=$1+1;
				string stuff($1, '\t');
				string combined = "\t" + stuff + string($2) + "(" + " " +string($4)  +" " + string($5) + " " + string($6) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
				$$=strdup(combined.c_str());
			}
			else if( (ss.size()!=0) && ssCond.back()==true && $1<ss.back() )
			{
				
				while( $1!=ss.back() ) 
				{
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
				}
				
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				ss.push_back($1);
				ssCond.push_back(false);
				ssWhat.push_back(1);
				
				isTab=$1+1;
				string stuff($1, '\t');
				string combined  = "\t" + stuff + string($2) + "(" + " " +string($4) + " " + string($5) + " " + string($6) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
				$$=strdup(combined.c_str());
				
			}
			else if( ss.size()!=0 && ssCond.back()==false )
			{
				cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
				exit(1);
			}
			else
			{
				cout << "if/else inconsistency at line: "<< linenum << endl;
				exit(1);
			}
		}
	}
	;

elif_block:
	ELIFST TAB expression COMPARISON expression COLON //a>=b
	{	
	
		string tempp=$3;
		char tempChar=tempp[0];
		string tempStr(1, tempChar);
		int tempType=varType[ tempStr ];  
		
		for(int i=1; i<tempp.length(); i++)
		{
			if(tempp[i]!='*' && tempp[i]!='/' && tempp[i]!='-' && tempp[i]!='+')
			{
				char tempChar=tempp[i];
				string tempStr(1, tempChar);
				int tempType2=varType[ tempStr ];
				
				if(tempType==1 && tempType2==2)
				{
					tempType=2;
				}
				else if( (tempType==1 && tempType2==3) | (tempType==2 && tempType2==3) | (tempType==3 && tempType2==1) | (tempType==3 && tempType2==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		string tempp2=$5;
		char tempChar2=tempp2[0];
		string tempStr2(1, tempChar2);
		int tempTypeB=varType[ tempStr2 ];  
		
		for(int i=1; i<tempp2.length(); i++)
		{
			if(tempp2[i]!='*' && tempp2[i]!='/' && tempp2[i]!='-' && tempp2[i]!='+')
			{
				char tempChar2=tempp2[i];
				string tempStr2(1, tempChar2);
				int tempType3=varType[ tempStr2 ];
				
				if(tempTypeB==1 && tempType3==2)
				{
					tempTypeB=2;
				}
				else if( (tempTypeB==1 && tempType3==3) | (tempTypeB==2 && tempType3==3) | (tempTypeB==3 && tempType3==1) | (tempTypeB==3 && tempType3==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		if( (tempType==3 && tempTypeB==1) | (tempType==3 && tempTypeB==2) | (tempType==1 && tempTypeB==3) | (tempType==2 && tempTypeB==3) )
		{
			cout << "comparison type mismatch in line " << linenum << endl;
			exit(1);
		}
			
		if( ss.size()>=1 && ssWhat.front()==1 && ssCond.back()==true )
		{
			string ssCurl;
			
			while(!ss.empty())
			{
				string ssNumCurl(ss.back(), '\t');
				ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
				
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
			}
			
			isTab=1;
			string combined = ssCurl  + "\t" + string("else if") + " " + "(" + " " + string($3) + " " + string($4) + " " + string($5) + " " + ")" + "\n" + "\t" + "{" + "\n";
			$$=strdup(combined.c_str());
			
			ss.push_back(0);
			ssCond.push_back(false);
			ssWhat.push_back(2);
		}
		else if( ss.size()==0 )
		{
			cout << "elif without if in line " << linenum << endl;
			exit(1);
		}
		else if( ss.size()>=1 && ssWhat.back()==3 )
		{
			cout << "elif after else in line " << linenum << endl;
			exit(1);
		}
		else if( ss.size()>=1 && ssCond.back()==false )
		{
			cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
			exit(1);
		}
		else
		{
			cout << "if/else inconsistency at line: "<< linenum << endl;
			exit(1);
		}
	}
	|
	tab_block ELIFST TAB expression COMPARISON expression COLON //	a>=b
	{
		
		string tempp=$4;
		char tempChar=tempp[0];
		string tempStr(1, tempChar);
		int tempType=varType[ tempStr ];  
		
		for(int i=1; i<tempp.length(); i++)
		{
			if(tempp[i]!='*' && tempp[i]!='/' && tempp[i]!='-' && tempp[i]!='+')
			{
				char tempChar=tempp[i];
				string tempStr(1, tempChar);
				int tempType2=varType[ tempStr ];
				
				if(tempType==1 && tempType2==2)
				{
					tempType=2;
				}
				else if( (tempType==1 && tempType2==3) | (tempType==2 && tempType2==3) | (tempType==3 && tempType2==1) | (tempType==3 && tempType2==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		string tempp2=$6;
		char tempChar2=tempp2[0];
		string tempStr2(1, tempChar2);
		int tempTypeB=varType[ tempStr2 ];  
		
		for(int i=1; i<tempp2.length(); i++)
		{
			if(tempp2[i]!='*' && tempp2[i]!='/' && tempp2[i]!='-' && tempp2[i]!='+')
			{
				char tempChar2=tempp2[i];
				string tempStr2(1, tempChar2);
				int tempType3=varType[ tempStr2 ];
				
				if(tempTypeB==1 && tempType3==2)
				{
					tempTypeB=2;
				}
				else if( (tempTypeB==1 && tempType3==3) | (tempTypeB==2 && tempType3==3) | (tempTypeB==3 && tempType3==1) | (tempTypeB==3 && tempType3==2) )
				{
					cout << "type mismatch in line " << linenum << endl;
					exit(1);
				}
			}
		}
		
		if( (tempType==3 && tempTypeB==1) | (tempType==3 && tempTypeB==2) | (tempType==1 && tempTypeB==3) | (tempType==2 && tempTypeB==3) )
		{
			cout << "comparison type mismatch in line " << linenum << endl;
			exit(1);
		}
	
		if (isTab == -1 || $1 > isTab)
		{
			cout << "tab inconsistency in line "<< linenum << endl;
			exit(1);
		}
		else
		{
			if( (ss.size()!=0) && ssCond.back()==true && $1==ss.back() )
			{
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				ss.push_back($1);
				ssCond.push_back(false);
				ssWhat.push_back(2);
				
				isTab=$1+1;
				string stuff($1, '\t');
				string combined = stuff + "\t" +  string("}") + "\n" + "\t" + stuff + string("else if") + " " + "(" + " " +string($4) + " " + string($5) + " " + string($6) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
				$$=strdup(combined.c_str());
			}
			else if( (ss.size()!=0) && ssCond.back()==true && $1<ss.back() )
			{
				while($1!=ss.back())
				{
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
				}
				if(ssWhat.back()==1)
				{
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
					
					ss.push_back($1);
					ssCond.push_back(false);
					ssWhat.push_back(2);
					
					isTab=$1+1;
					string stuff($1, '\t');
					string combined=stuff + "\t" +  string("}") + "\n" + "\t" + stuff + string("else if") + " " + "(" + " " +string($4) + " " + string($5) + " " + string($6) + " " + ")" + "\n" + stuff + "\t" + "{" + "\n";
					$$=strdup(combined.c_str());
				}
				else
				{
					cout << "if/else inconsistency at line: "<< linenum << endl;
					exit(1);
				}
				
				
			}
			else if( ss.size()==0 )
			{
				cout << "elif without if in line " << linenum << endl;
				exit(1);
			}
			else if( ss.size()!=0 && ssWhat.back()==3 )
			{
				cout << "elif after else in line " << linenum << endl;
				exit(1);
			}
			else if(ss.size()!=0 && ssCond.back()==false)
			{
				cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
				exit(1);
			}
			else if( ss.size()!=0 && $1>ss.back() )
			{
				cout << "elif without if in line " << linenum << endl;
				exit(1);
			}
			else
			{
				cout << "if/else inconsistency at line: "<< linenum << endl;
				exit(1);
			}
		}
	}
	;


else_block:
	ELSEST COLON //a>=b
	{
		if( ss.size()>=1 && (ssWhat.front()==1 || ssWhat.front()==2 ) && ssCond.back()==true )
		{
			string ssCurl;
			
			while(!ss.empty())
			{
				string ssNumCurl(ss.back(), '\t');
				ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
				
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
			}
			
			isTab=1;
			string combined= ssCurl + "\t"  + string($1) + "\n" + "\t" + "{" + "\n";
			$$=strdup(combined.c_str());
			
			ss.push_back(0);
			ssCond.push_back(false);
			ssWhat.push_back(3);
		}
		else if( ss.size()==0 )
		{
			cout << "else without if in line " << linenum << endl;
			exit(1);
		}
		else if( ss.size()>=1 && ssCond.back()==false )
		{
			cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
			exit(1);
		}
		else
		{
			cout << "if/else inconsistency at line: "<< linenum << endl;
			exit(1);
		}
	}
	|
	tab_block ELSEST COLON
	{
		if (isTab == -1 || $1 > isTab)
		{
			cout << "tab inconsistency in line "<< linenum << endl;
			exit(1);
		}
		else
		{
			if( (ss.size()!=0) && ssCond.back()==true && $1==ss.back() )
			{
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				ss.push_back($1);
				ssCond.push_back(false);
				ssWhat.push_back(3);
				
				isTab=$1+1;
				string stuff($1, '\t');
				string combined= stuff+ "\t" + string("}") + "\n" + "\t" + stuff + string($2) + "\n" + stuff + "\t" + "{" + "\n";
				$$=strdup(combined.c_str());
			}
			else if( (ss.size()!=0) && ssCond.back()==true && $1<ss.back() )
			{
				while($1!=ss.back())
				{
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
				}
				if(ssWhat.back()==1)
				{
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
					
					ss.push_back($1);
					ssCond.push_back(false);
					ssWhat.push_back(3);
					
					isTab=$1+1;
					string stuff($1, '\t');
					string combined=stuff+ "\t" + string("}") + "\n" + "\t" + stuff + string($2) + "\n" + stuff + "\t" + "{" + "\n";
					$$=strdup(combined.c_str());
				}
				else
				{
					cout << "if/else inconsistency at line: "<< linenum << endl;
					exit(1);
				}
				
				
			}
			else if(ss.size()==0)
			{
				cout << "else without if in line " << linenum << endl;
				exit(1);
			}
			else if( ss.size()!=0 && ssCond.back()==false )
			{
				cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
				exit(1);
			}
			else if( ss.size()!=0 && $1>ss.back() )
			{
				cout << "else without if in line " << linenum << endl;
				exit(1);
			}
			else
			{
				cout << "if/else inconsistency at line: "<< linenum << endl;
				exit(1);
			}
		}
	}
	;

assignment_block:
	assignment //x=..
	{
		if(ss.empty())
		{
			isTab=0;
			string combined= "\t" + string($1) + "\n";
			$$=strdup(combined.c_str());
		}
		else if( !ss.empty() && ssCond.back()==true )
		{
			string ssCurl;
			
			while( !ss.empty() ) 
			{
				string ssNumCurl(ss.back(), '\t');
				ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
			
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
			}
			
			ss.pop_back();
			ssCond.pop_back();
			ssWhat.pop_back();
			
			isTab=0;
			string combined = ssCurl + "\t" + string($1) + "\n";
			$$=strdup(combined.c_str());
		}
		else if( !ss.empty() && ssCond.back()==false )
		{
			cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
			exit(1);
		}
		else
		{
			cout << "if/else inconsistency at line: "<< linenum << endl;
			exit(1);
		}

	}
	|
	tab_block assignment //	x=..
	{
		if (isTab == -1 || $1 > isTab)
		{
			cout << "tab inconsistency in line "<< linenum << endl;
			exit(1);
		}
		else
		{
			if( (ss.size()!=0) && ssCond.back()==false && $1==ss.back()+1 )
			{
				ssCond.back()=true;
				
				string stuff($1, '\t');
				string combined= "\t" + stuff + string($2) + "\n";
				$$=strdup(combined.c_str());
				
			}
			else if( (ss.size()!=0) && ssCond.back()==true && $1==ss.back()+1 )
			{
				string stuff($1, '\t');
				string combined= "\t" + stuff + string($2) + "\n";
				$$=strdup(combined.c_str());
			}
			else if( (ss.size()!=0) && ssCond.back()==true && $1==ss.back() ) 
			{
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				string stuff($1, '\t');
				string combined = stuff+ "\t" + string("}") + "\n"+ "\t" + stuff + string($2) + "\n";
				$$=strdup(combined.c_str());
				
			}
			else if( (ss.size()!=0) && ssCond.back()==true && $1<ss.back() )
			{	
				string ssCurl;
				
				while( $1!=ss.back() ) 
				{
					string ssNumCurl(ss.back(), '\t');
					ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
				
					ss.pop_back();
					ssCond.pop_back();
					ssWhat.pop_back();
				}
				string ssNumCurl(ss.back(), '\t');
				ssCurl = ssCurl + (ssNumCurl + "\t" + string("}") + "\n");
				
				ss.pop_back();
				ssCond.pop_back();
				ssWhat.pop_back();
				
				string stuff($1, '\t');
				string combined = ssCurl + "\t" + stuff + string($2) + "\n";
				$$=strdup(combined.c_str());
				
			}
			else if( ss.size()!=0 && ssCond.back()==false )
			{
				cout << "error in line " << linenum << ": at least one line should be inside if/elif/else block" << endl;
				exit(1);
			}
			else
			{
				cout << "if/else inconsistency at line: "<< linenum << endl;
				exit(1);
			}
		}
	}
	;

assignment:
	IDENTIFIER EQUAL INT
	{
		varType[string($1)]=1;
		intVars[string($1)]=$3;
		
		string combined= string($1)+string("_int")+" "+string($2)+" "+string($3)+";";
		$$=strdup(combined.c_str());
	}
	|
	IDENTIFIER EQUAL FLOAT
	{
		varType[string($1)]=2;
		floatVars[string($1)]=$3;
		
		string combined=string($1)+string("_flt")+" "+string($2)+" "+string($3)+";";
		$$=strdup(combined.c_str());
	}
	|
	IDENTIFIER EQUAL IDENTIFIER
	{
		
		if( varType.find(string($3))==varType.end() )
		{
			cout<<"Line "<<linenum<<": variable "<<$3<<" is not declared\n";
			exit(1);
		}
			
		if( varType[string($3)]==1 )
		{
			varType[string($1)]=1;
			intVars[string($1)]=$3;
			
			string combined=string($1)+string("_int")+" "+string($2)+" "+string($3)+string("_int")+";";
			$$=strdup(combined.c_str());
		}
		else if( varType[string($3)]==2 )
		{
			varType[string($1)]=2;
			floatVars[string($1)]=$3;
			
			string combined=string($1)+string("_flt")+" "+string($2)+" "+string($3)+string("_flt")+";";
			$$=strdup(combined.c_str());
		}
		else if( varType[string($3)]==3 )
		{
			varType[string($1)]=3;
			stringVars[string($1)]=$3;
			
			string combined=string($1)+string("_str")+" "+string($2)+" "+string($3)+string("_str")+";";
			$$=strdup(combined.c_str());
		}

	}
	|
	IDENTIFIER EQUAL expression
	{
		string tempp=$3;
		string tempStr;
		int i=0;
		if(tempp[0]=='-')
		{
			i=1;
			while( i<tempp.length() && tempp[i]!='+' && tempp[i]!='-' && tempp[i]!='/' && tempp[i]!='*' )
			{
				tempStr=tempStr+tempp[i];
				i++;
			}
		}
		else
		{
			i=0;
			while( i<tempp.length() && tempp[i]!='+' && tempp[i]!='-' && tempp[i]!='/' && tempp[i]!='*' )
			{
				tempStr=tempStr+tempp[i];
				i++;
			}
		}	
		
		int tempType=0;
		if( isalpha(tempStr[0]) )
		{	
			tempStr=tempStr.erase(tempStr.size()-5);
			tempType = varType[ string(tempStr) ];
		}
		else if( isdigit(tempStr[0]) )
		{
			float num=stof(tempStr);
			if( int(num)-num < 0 )
			{
				tempType=2;
			}
			else if( int(num)-num == 0 )
			{
				tempType=1;
			}
		}
	
		for(int j=i+1; j<tempp.length(); j++)
		{
			int k=j;
			string tempStr2;
			while( k<tempp.length() && tempp[k]!='+' && tempp[k]!='-' && tempp[k]!='/' && tempp[k]!='*')
			{
				tempStr2=tempStr2+tempp[k];
				k++;
			}
			j=k;
			
			int tempType2=0;
			if( isalpha(tempStr2[1]) )
			{
				if(tempStr2.find("_int") != string::npos) {tempType2=1;}
				if(tempStr2.find("_flt") != string::npos) {tempType2=2;}
				if(tempStr2.find("_str") != string::npos) {tempType2=3;}
			}
			else if( isdigit(tempStr2[1]) )
			{
				float num=stof(tempStr2);
				if( int(num)-num < 0 )
				{
					tempType2=2;
				}
				else if( int(num)-num == 0 )
				{
					tempType2=1;
				}
			}
			
			if( (tempType==1 && tempType2==3) | (tempType==2 && tempType2==3) | (tempType==3 && tempType2==1) | (tempType==3 && tempType2==2) )
			{
				cout << "type mismatch in line " << linenum << endl;
				exit(1);
			}
			else if( tempType==2 && (tempType2==1 | tempType2==2) )
			{
				tempType=2;
			}
			else if( tempType==1 && tempType2==2 )
			{
				tempType=2;
			}
			else if( tempType==1 && tempType2==1 )
			{
				tempType=1;
			}
		}

		
		varType[ string($1) ] = tempType;
		if(tempType==1)
		{	
			intVars[string($1)]=$3;
			string combined = string($1)+string("_int") + " " + string($2) + " " + string($3) + ";";
			$$=strdup(combined.c_str());
		}
		else if(tempType==2)
		{
			floatVars[string($1)]=$3;
			string combined = string($1)+string("_flt") + " " + string($2) + " " + string($3) + ";";
			$$=strdup(combined.c_str());
		}
		else if(tempType==3)
		{
			stringVars[string($1)]=$3;
			string combined = string($1)+string("_str") + " " + string($2) + " " + string($3) + ";";
			$$=strdup(combined.c_str());
		}
		
		
		
	}
	|
	IDENTIFIER EQUAL QUOTE expquote QUOTE
	{
		varType[string($1)]=3;
		string cmbd = string($3)+string($4)+string($5);
		stringVars[string($1)]=cmbd;
		
		string combined=string($1)+ "_flt" +" "+string($2)+" "+string($3)+string($4)+string($5)+";";
		$$=strdup(combined.c_str());
	}
    ;

expression:
	value
	{
		$$=$1;
	}
	|
	expression MATH value 
	{		
		string combined=string($1)+" "+string($2)+" "+string($3);
		$$=strdup(combined.c_str());
	}
	;

value:
	INT
	{
		$$=strdup($1);
	}
	|
	FLOAT
	{

		$$=strdup($1);
	}
	|
	IDENTIFIER
	{

		if( varType.find(string($1))==varType.end() )
		{
			cout<<"Line "<<linenum<<": variable "<<$1<<" is not declared\n";
			exit(1);
		}
		
		if( varType[string($1)]==1 )
		{

			string combined=string($1)+string("_int");
			$$=strdup(combined.c_str());
		}
		else if( varType[string($1)]==2 )
		{

			string combined=string($1)+string("_flt");
			$$=strdup(combined.c_str());
		}
		else if( varType[string($1)]==3 )
		{

			string combined=string($1)+string("_str");
			$$=strdup(combined.c_str());
		}
	}
	|
	OP expression CP
	{
		string combined="("+string($2)+")";
		$$=strdup(combined.c_str());
	}
	;
	

//no decleariton checking for "..." quoted calls
expquote:
	valuequote
	{
		$$=$1;
	}
	|
	expquote MATH valuequote 
	{
		string combined=string($1)+string($2)+string($3);
		$$=strdup(combined.c_str());
	}
	;

valuequote:
	INT
	{
		$$=strdup($1);
	}
	|
	FLOAT
	{
		$$=strdup($1);
	}
	|
	IDENTIFIER
	{
		$$=strdup($1);
	}
	|
	OP expquote CP
	{
		string combined="("+string($2)+")";
		$$=strdup(combined.c_str());
	}
	;



tab_block:
	TAB {$$=1;}
	|
	tab_block TAB {$$=$1+1;}
	;
	




%%
void yyerror(string s){
	cerr<<"Syntax Error at line: "<<linenum<<endl;
	errorFlag=true;
}


int yywrap(){
	return 1;
}
int main(int argc, char *argv[])
{
    /* Call the lexer, then quit. */
    yyin=fopen(argv[1],"r");
    yyparse();
    fclose(yyin);
	

    return 0;
}

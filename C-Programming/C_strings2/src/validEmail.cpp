/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>
int findlen1(char *s)
{
	int n = 0;
	while (s[n]) {
		n++;
	}
	return n;
}

int isValidEmail(char *email)
{
	
	if (findlen1(email) > 254)
		return 0;



	char *name=(char*)malloc(sizeof(char*)*30);
	
	
	int i = 0,flag=1,k=0,count=0;


//creating hashtable for allowed inputs

	//char *hashtable = (char*)calloc(128,sizeof(char));
	/*for (i = 0; i < 128; i++)
	hashtable[i] = '0';
	for (int i = 48; i < 57; i++)
	{
	hashtable[i] = '1';
	}
	hashtable[32] = '1';
	for (int i = 64; i <=90; i++)
	{
	hashtable[i] = '1';
	}
	for (int i = 97; i <= 122; i++)
	{
	hashtable[i] = '1';
	}
	hashtable[95] = '1';
	hashtable[127] = 0;
	printf("%s", hashtable);*/




	char hashtable[128] = "0000000000000000000000000000000010000000000001101111111110000000111111111111111111111111111000010111111111111111111111111110000";

	int bouy,front=0;
	int namelength = 0,validAtTheRate=0,flagdot=0,validDot=0;

	int email_frontcheck = 0;
	int flag2 = 1, flag3 = 1, flag5 = 0, flag7=1,rear = 0;
	// variable email is in form of "name something@domain.server"
	
	
	while (email[i])
	{
		//for invalid characters
		 if (hashtable[email[i]] == 48)
			      return 0;
		 
		 flag5 = 0;

		//storing name
		if (flag){
			
			if (email[i] == 32)
			{
				name[i] = 0;
				flag = 0;
				namelength = i;
			}
			else
			{
				name[i] = email[i];
				i++;
			}
			continue;
		}
		


		//frontcheck
		if (flag2)
		{
			while (email[i] == 32)
			{
				i++;
			}

			if (email[i] == 45 || email[i] == 46 || email[i] == 95)
					return 0;
			flag2 = 0;
			bouy = i;

			}
		

		//name check
		
		if (flag3)
		{
			while (name[k] == email[i] - 32 || name[k] == email[i] + 32 || name[k] == email[i])
			{
				

				hashtable[32] = '0';  //making space invalid after a character


				if (hashtable[email[i]] == 48)
					return 0;
				flag5 = 1;
				
		
				
				k++;
				i++;
			}
			if (k >=1  && k < namelength)  //preventing double increamenting of i in while loop
				i--;
		}
        
		if (flag7)
		if (k == namelength)//name found
		{
			// in front
			if (bouy + k == i)
				front = 1;
			//in rear
			if (email[i] == '@')
				rear = 1;

			

			//else found in middle
			flag3 = 0; 
			//preventing while loop for name execution again
			flag7 = 0;
		}
		else
			k = 0;
	       
		  

	      if (email[i] == '@')
			 {
				 if (validAtTheRate)  //if @ occured twice
					 return 0;

				validAtTheRate = 1;
				flagdot = 1;
				
			 }

		  if (flagdot && email[i] == '.')
		  {
			  validDot = 1;
			  hashtable[32] = '1'; //making space valid after @ . text
			 
		  }

		  i++;
	
}
		
	
	if ((front || rear) && validDot)
		return 2;

	if (validDot)
		return 1;



	return 0;
}

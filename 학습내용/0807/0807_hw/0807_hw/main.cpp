#include <iostream>

using namespace std;

//let it go ���?
int main()
{
	char lyrics[1024 *10] = "The snow glows white on the mountain tonight\
		Not a footprint to be seen\
		A kingdom of isolation\
		And it looks like I'm the queen\
		The wind is howling like this swirling storm inside\
		Couldn't keep it in, heaven knows I've tried\
		Don't let them in, don't let them see\
		Be the good girl you always have to be\
		Conceal, don't feel, don't let them know\
		Well, now they know\
		Let it go, let it go\
		Can't hold it back anymore\
		Let it go, let it go\
		Turn away and slam the door\
		I don't care what they're going to say\
		Let the storm rage on\
		The cold never bothered me anyway\
		Let it go, let it go\
		Can't hold it back anymore\
		Let it go, let it go\
		Turn away and slam the door\
		Let it go(go, go, go go, go go, go go, go, go, go go)\
		Let it go\
		Let it go\
		Let it go\
		It's funny��";

	char* szFind = lyrics;
	int iCount = 0;
	while (true)
	{
		szFind = strstr(szFind, "Let it go");
		iCount++;

		if (szFind == NULL)
			break;

		szFind++; 
	}

	char* szFind2 = lyrics;
	while (true)
	{
		szFind2 = strstr(szFind2, "let it go");
		iCount++;

		if (szFind2 == NULL)
			break;

		szFind2++;
	}


	cout << iCount << endl;
	system("pause");

	return 0;
}
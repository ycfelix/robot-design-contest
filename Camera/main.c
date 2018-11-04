/*
 * main.c
 *
 *  Created on: 2018¦~11¤ë4¤é
 *      Author: yauch
 */

void StraightenLine(int Image[][], int Row, int Col)
{

}

void CalculateSlope(int Image[][], int Row, int Col)
{

}

int CalculateAngle(int Image[][], int Row, int Col)
{

	//dummy statement
	return 0;
}

int main()
{

	/*here are some samples, the Row, Col will not be this small,
	*
	*	for real competition, it will be around 40 rows and 80 columns
	* 	So don't try to hard code the size
	*/
	{
		//do one of your testings here
		int Image[][]=
		{
				{0,0,1,0,0,0},
				{0,0,1,1,0,0},
				{0,0,1,0,0,0},
				{1,1,1,1,1,1},
				{0,1,1,0,0,0}
		};

	}

	{
		//do one of your testings here
		int Image[][]=
		{
				{0,0,1,0,0,0},
				{0,0,0,0,0,0},
				{0,0,1,0,0,0},
				{1,1,1,1,1,1},
				{0,0,1,0,0,0}
		};

	}


	{
		//do one of your testings here
		int Image[][]=
		{
				{0,0,1,0,0,0},
				{0,0,1,0,0,0},
				{0,0,1,0,0,0},
				{1,1,0,1,1,1},
				{0,0,1,0,0,0}
		};

	}



	return 0;
}



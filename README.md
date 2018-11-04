2018 internal competition
=======================
Thrower robots software design and implementation


# Camera Algorithm
Please complete the following algorithm

* Prerequisite: 2D-array, Looping

* A `2D-array` is like 2d-coordinate system, for example,<br>
in a coordinate system, (0,1) means the point x=0, y=1,<br>
a 2D array(Named `Coordinate`) representation will be `Coordinate[1][0]`, The general form is Coordinate[y][x],<br>
meaning the point `(x,y)` on a coordinate system.

* Here is given a 2D array consists of 0 and 1 only, and here are some instructions for you to complete.<br>
SampleArray:

{<br>
{0,0,1,0,0,0},<br>
{0,0,1,0,0,0},<br>
{0,0,1,0,0,0},<br>
{1,1,1,1,1,1},<br>
{0,0,1,0,0,0}<br>
}

This is a 2D array(Named `SampleArray`) consist of 5 Row and 6 Col,<br>
To access the element, <br>

SampleArray[0][0], which means 1st Row, 1rd element, and this element is `0`<br>
SampleArray[0][1], which means 1st Row, 2rd element, and this element is `0`<br>
SampleArray[0][2], which means 1st Row, 3rd element, and this element is `1`<br>

eg: you can do sth like, `int Element=SampleArray[0][2];` and Element is equal to 1 now<br>
`SampleArray[0][2]=3;`and SampleArray[0][2] is 3 now, but Element is kept equal to 1<br>

* Note: For now, we will handle 1 or 0 horizontal line and 1 or 0 vertical line only, but we will probably<br>
need to handle 0-2 vertical lines and 0-2 horizontal lines in the competition

--------------------------
* 1 `void StraightenLine(int Image[][], int Row, int Col);`
 * This Function should correct the content of the Image array<br>
 Input parameter:`Image[][]` is the Image 2d-array consists of 0 and 1 only<br>
 Input parameter:`Row` is the total number of rows in the array<br>
 Input parameter:`Col` is the total number of columns in the array<br>
 
 Sample Input/Output:<br>
 Image[][]=
{<br>
{0,0,1,0,0,0},<br>
{0,0,1,1,0,0},<br>
{0,0,1,0,0,0},<br>
{1,1,1,1,1,1},<br>
{0,1,1,0,0,0}<br>
}

`Row`=5 `Col`=6<br>
Your task is to remove unnecessary 1's in the array<br>

Sample Output: After the function, the array should be:<br>
{<br>
{0,0,1,0,0,0},<br>
{0,0,1,0,0,0},<br>
{0,0,1,0,0,0},<br>
{1,1,1,1,1,1},<br>
{0,0,1,0,0,0}<br>
}

* Note that the Col and Row is not fixed, the sample is simply for reference, the array may have diagonal lines<br>
--------------------------
 * 2 `void CalculateSlope(int Image[][], int Row, int Col);`
 Given an array of strightened 1 and 0, Calculate the slope of the lines and print it on the console<br>
Sample:<br>
{<br>
{0,0,1,0,0,0},<br>
{0,0,1,0,0,0},<br>
{0,0,1,0,0,0},<br>
{1,1,1,1,1,1},<br>
{0,0,1,0,0,0}<br>
}
 
Output: 1 , 0

--------------------------
 * 3 `int CalculateAngle(int Image[][], int Row, int Col);`
 Given an array of strightened 1 and 0, Calculate the Angle of rotation, <br>
Sample:<br>
{<br>
{0,0,1,0,0},<br>
{0,0,1,0,0},<br>
{0,0,1,0,0},<br>
{1,1,1,1,1},<br>
{0,0,1,0,0}<br>
}
 
Output: 0

Sample:
{<br>
{1,0,0,0,1},<br>
{0,1,0,1,0},<br>
{0,0,1,0,0},<br>
{0,1,0,1,0},<br>
{1,0,0,0,1}<br>
}
 
Output: 45

--------------------------


Task List(Not in order):
--------------------------
* Set up `debug Mode`
  * Monitor motor velocity/angle
  * Monitor camera input

* Design auto-mode algorithm
  * detect the position of robots
  * movement condition
  * Rack lifting mechanism
  * Ball throwing mechanism

* Code enhancement
  * reduce complexity
  
* Flow chart
  * draw a flow chart to show the sequence of robot movement
  
* Sensor testing
  * Camera
    * test performace at distance at 8cm
    * Image processing to black&white
    * Transfer the image to 2d array of 1 and 0
  
  * Ultrasonic
    * Test the distance and sensitivity on different surface
    * Write library to do I/O to the sensor
   
   * Line tracking
     * Tune the sensitivity (3/11/2018 update: 3~5cm for best sensitivity)
     * Write library to do I/O to the sensor  (3/11/2018 update: Done and tested)
    


Map used in the competition
---------------------------
![image](https://github.com/ycfelix/RobotDesignContest/blob/master/rules10th-24.jpg)

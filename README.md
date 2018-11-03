2018 internal competition
=======================
Thrower robots software design and implementation


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

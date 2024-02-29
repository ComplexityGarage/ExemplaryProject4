# Communication Based on Muscle Contraction
# Authors 
- Hanna Nowak
- Mikołaj Pocheć
# Description of the project 
This project aims to utilize technology of electrode-based muscle contraction detection to form a basic form of communication with partially paralyzed people.
# Science and tech used 
The project was built with:
- Arduino Uno,
- EMG analogue sensor (SEN0240) with amplifier,
- servomechanism,
- LED diode.

In general, detecting muscle contraction involves placing three electrodes (MID, END and REF) in specific places. As name suggests, MID electrode should be placed in the middle of muscle of interest, END electrode is placed in direction of the muscle and REF (reference) electrode placement depends on specific muscle, but most often it is placed somewhere else than the muscle.

A device that implements the description above is e.g. DFRobot Gravity analogue EMG sensor shown below:
![dfrobot](https://github.com/ComplexityGarage/ExemplaryProject4/assets/86022023/78845ea4-7286-4cdb-b9a1-3f83f1af4bf9)
Three of the electrodes are placed in the direction of a muscle. The complete circuit is shown below.

![circuit](https://github.com/ComplexityGarage/ExemplaryProject4/assets/86022023/e43ae1e7-e508-43a6-a1de-3684a254e199)

The gathered signal is rather noisy and not very useful, therefore manufacturer shared [a simple library](https://codeload.github.com/yuyouliang/EMG_Filter/zip/master) for data filtering and some [examplary programs](https://wiki.dfrobot.com/Analog_EMG_Sensor_by_OYMotion_SKU_SEN0240) (which were in fact used in this project).

The original code mentioned above requires adjusting threshold manually (by editing code). As it is not very comfortable, we implemented an automatic calibration activated by pressing a button. A simple algorithm of setting a threshold to ~80% of the maximum value of a 10 second signal sample works very well for our applications.

An useful feature of a circuit above is a LED diode signalizing calibration process.

# State of the art 
At the current stage, we managed to implement gesture detection (gesture means contraction of corresponding muscle) and it works suprisingly well. If placed in the right spot, the device is able to differentiate between an intentional muscle contraction and false-positives. Implemented automatic calibration not only allows to use the device at different muscles and by different people, but also allows to detect a strenght of later detected gestures. 

The processed signal looks like this:
![image](https://github.com/ComplexityGarage/ExemplaryProject4/assets/86022023/cebb7f23-a20c-40f7-a8b6-77f09920d3c6)
    Gesture detection is based on setting (in our case - by an automatic calibration) some threshold. Signal below that point is just cut off. Function `getEMGCount` is responsible for deciding whether detected signal can be indeed considered a muscle contraction.

To suggest possible usage of our project, we added a support for servomechanism. 
The idea is that for each successful gesture detection, servomechanism rotates by a constant angle, (e.g. $45^\circ$). It is not hard to imagine the situation, in which this mechanism enables partially paralyzed people to communicate in a simple way. Say we have a circle with four general answers and the disabled person can move their finger. In this situation, we establish a simple form of communication, in which such a person can choose from number of answers, or even choose letters from the alphabet.

# What next?
Unfortunately, our project is not perfect. This fact is directly tied to the used technology. The EMG sensor we use is a rather simple device and it is not as reliable, as we imagine it for a real usage. 

Therefore, the next step could be to build sensor with reusable electrodes (they could be placed on a tightening strap) ourselves. This could be much cheaper and allow us to use multiple detection devices to establish more advanced forms of communication or even to control more complex devices than servomechanism used here. We think that five of such devices could be enough to build a simple artifitial hand for example.

# Sources

https://codeload.github.com/yuyouliang/EMG_Filter/zip/master
https://wiki.dfrobot.com/Analog_EMG_Sensor_by_OYMotion_SKU_SEN0240

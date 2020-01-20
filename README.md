# EMILA
Electromyography Muscular Interface Limb Assist - An Investigation into Robotic Prosthetics 

## Project Description
Project EMILA is a cursory investigation into robotic prosthetics. 
This project essentially gathers EMG data from EMG sensors and has it interpreted by a machine learning classifier to perform a previously mapped gesture. 
Much of robotic prosthetics technology is still in its infancy and this project was made to learn more about this growing field and where this technology stands today. 

## Project Requirements
As this project was made for my ENGR 478 (Design with Microprocessors) class. 

A few hard requirements were stated and are as follows:
- Must use a PSOC microcontroller
- Feature real time components
- Feature multitasking events
- Host GUI
- Feature at least two interrupt routines at varying priorities
- Interaction with sensors / Some Data Acquisition 

## Materials and Equipment
These were some of the major components used in this build:
- PSOC 5LP ($10)
- Robot arm kit ($52)
- MyoWare EMG Sensor ($38)
- Shaving cream + Razor ($5)

## Methodology
Now when it came to the methodology, the approach was split into following three major sections.

Data Collection:
- Here the PSOC was the vital component and allowed for EMG sampling
- This consisted of starting the UART protocol and opening a serial port
- From here, the EMG sensor was connected to the PSOC's Analog pins for sensor data acquisition 
- The analog values were retrieved and converted via the SAR_ADC function block 
- Concurrently, an interrupt service routine (ISR) was made consisting of a hardware timer to sample data for 5 seconds 
- This converted value was transmitted out thanks to the UART protocol to the PC for data visualization and storage

Machine Learning:
- Here the PC was the vital component and allowed for machine learning to take place
- A simple convolutional neural network (CNN) was trained on the data collected to differentiate between a clench and spidey hands gesture 
- The CNN leveraged transfer learning and frozen layers from the VGG16 model to achieve a test accuracy of 92.8571% and a Fscore of [0.85714286 0.95238095] for clench and spidey gestures respectively
- This proved to be more than adequate to demonstrate the project's core idea 

Robot Arm:
- Here the robot arm was the vital component that allowed for the gestures to be demonstrated
- Once the machine learning classifier detected a gesture, it would move the servo motors of each individual finger to the premapped gesture
- Another ISR was made to verify the accuracy of the machine learning classifier to continually improve the CNN by recording more data (not implemented)
- Once the gesture, was performed the servo motors would reset to a neutral position

## Limitations 
While this project was successful in demonstrating the fundamentals, investigating robotic prostethics and building a successful demo; there are still some limitations such as:
- For ease of proof of concept, the data acquisition was limited to a discrete set of time. With more time and resources, it would be far more valuable to able to implement a sliding window capture for the classifier to perform gesture recognition for continously transmitted data
- Due to time constraints, the number of gestures were limited to two simple movements. While more time could have been taken to map a whole variety of gestures, an investigation into a more novel way of training the classifier should be explored. 
- Due to GPU limitations, the gesture recognition speed is bottlenecked due to the fact that the classifier was running on an anaconda GPU enabled virtual environment. Once it ran outside this environment, speed improvements were noticeably faster. With an addition of a dedicated TPU, speed improvments may further increase. 

## Demo 
Below is the beta demo video of the final project. The significant time delay is NOT present when running outside of the Anaconda virtual environment.

![BetaDemo](https://i.imgur.com/9XwtNuN.mp4)

## Media 
In the below link you may find videos and pictures detailing the project.

https://photos.google.com/share/AF1QipMtgHSae3AMFFn_HSqIvlHlRMEjb5AUE4gdvErBo0U595-0e7dV38DIKtpDdVbgsg?key=T1oxTWtsSHplUlBmQVlWRWFpUGl0N1I3SjBXY1B3



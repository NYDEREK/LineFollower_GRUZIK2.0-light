
<h1 align="center">GRUZIK2.0: Line follower robot </h1>
<div align="center">
  
<img alt="Static Badge" src="https://img.shields.io/badge/uC-STM32F103C8T6-lime"> <img alt="Static Badge" src="https://img.shields.io/badge/Platform-STM32cubeIDE-darkcyan"> <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/NYDEREK/LineFollower_GRUZIK2.0-light"> <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/NYDEREK/LineFollower_GRUZIK2.0-light"> 

</div>

> **GRUZIK2.0 is simple light `74g` construction made for "line follower light" competition. Robot has bluetooth communication with app on smartphone. GRUZIK2.0 uses digital sensor insted of analog.**

  
![image](https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/0cd45245-ee79-4929-86ba-0e2f9b55157a)

<img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/fe5838ad-ae66-4651-823d-7fa049178016" width="200"/> <img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/e688352e-b9cf-4387-a83c-95ce9aeba8c7" width="200"/> 
## Hardware

> **Simple light construction(74g) let's robot to achive high speed on the track.** 
> `PCB's` **ware designed in KiCAD 7.0 and manufactured by JLCPCB. Rims were 3D printed with PETG for Kysosho "mini z" tires.** 
> **Light** `dualsky 150mAh battery` **gives enough current (max 30C) without adding to much weight (10g).** 
> `Pololu 2211 motor (10:1)` **with max current 1.6A per one require the use of two separate TB6612FNG motor drivers with connected channels (max 2A per Dirver).**
> `HC-05` **bluetooth module gives communication range up to 10m.** 
> **Fast ARM microcontroller** `STM32F103C8T6` **(max 72MHz) gives a lot of software capabilities.** 
* uC - STM32F103C8T6
* drivers - TB6612FNG
* sensor - 8x KTIR0711S
* battery - 150mAh LiPo dualski
* wheels - kyosho mini z
* motors - Pololu 2211
* bluetooth - HC-05
## 📱Bluetooth app📱

> **It's simple Bluetooth app created with MIT app inventor.App Starts and Stops robot, allows you to send data in the `terminal`, slow down or accelerate on any section of the route using `Time mode`, the `Modes` pad is responsible for quickly adapting the speed and accuracy of the robot to the route using modes and the application also displays the battery charge status**

<img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/99308187-04be-49ce-bf4d-46ec42ed3cef" width="200"/>

  
  


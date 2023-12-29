# GRUZIK2.0: Line Follower Robot

<div align="center">

![Microcontroller](https://img.shields.io/badge/uC-STM32F103C8T6-lime) ![Platform](https://img.shields.io/badge/Platform-STM32cubeIDE-darkcyan) ![Repo Size](https://img.shields.io/github/repo-size/NYDEREK/LineFollower_GRUZIK2.0-light) ![Top Language](https://img.shields.io/github/languages/top/NYDEREK/LineFollower_GRUZIK2.0-light)

</div>

> **GRUZIK2.0 is a lightweight construction (74g) designed for the "Line Follower Light" competition. The robot features Bluetooth communication with a smartphone app and uses a digital sensor instead of analog.**

![GRUZIK2.0](https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/0cd45245-ee79-4929-86ba-0e2f9b55157a)

<div align="center">
  <img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/fe5838ad-ae66-4651-823d-7fa049178016" width="200"/>
  <img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/e688352e-b9cf-4387-a83c-95ce9aeba8c7" width="200"/>
</div>

## Hardware

> **The simple lightweight construction (74g) allows the robot to achieve high speed on the track.**
> **PCBs were designed in KiCAD 7.0 and manufactured by JLCPCB. The rims were 3D printed with PETG for Kyosho "Mini Z" tires.**
> **The light dualsky 150mAh battery provides enough current (max 30C) without adding too much weight (10g).**
> **The Pololu 2211 motor (10:1) with max current 1.6A per one requires the use of two separate TB6612FNG motor drivers with connected channels (max 2A per driver).**
> **The HC-05 Bluetooth module gives communication range up to 10m.**
> **The fast ARM microcontroller STM32F103C8T6 (max 72MHz) provides a lot of software capabilities.**

- uC - STM32F103C8T6
- drivers - TB6612FNG
- sensor - 8x KTIR0711S
- battery - 150mAh LiPo dualsky
- wheels - Kyosho Mini Z
- motors - Pololu 2211
- Bluetooth - HC-05

## 📱Bluetooth App 📱

> **It's a simple Bluetooth app created with MIT App Inventor. The app starts and stops the robot, allows you to send data in the terminal, slow down or accelerate on any section of the route using Time mode. The Modes pad is responsible for quickly adapting the speed and accuracy of the robot to the route using modes, and the application also displays the battery charge status.**

<div align="center">
  <img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/99308187-04be-49ce-bf4d-46ec42ed3cef" width="200"/>
</div>

## ⏱Time mode⏱
> **Time mode is function that provides you to slow down or accelerate on any section of the route by choosing:**
> 
>  `mode_1` **- mode for entire route**
> 
> `mode_2` **- mode for time section on route**
> 
> `Start_time` **- time from start to mode change**
> 
> `Change_time` **- Duration of mode_2**

<img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/f31179b3-dcbc-4551-86c7-9655d86f9fea" width="180"/><img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/6e4534ce-c543-4864-8fb3-f4f834b6377c" width="670"/>

<h1 align="center">GRUZIK2.0: Line Follower Robot</h1>

<div align="center">

![Microcontroller](https://img.shields.io/badge/uC-STM32F103C8T6-white) ![Platform](https://img.shields.io/badge/Platform-STM32cubeIDE-darkcyan) ![Repo Size](https://img.shields.io/github/repo-size/NYDEREK/LineFollower_GRUZIK2.0-light) ![Top Language](https://img.shields.io/github/languages/top/NYDEREK/LineFollower_GRUZIK2.0-light)

<i>Loved the project? Please consider giving a Star ⭐️</i>

</div>

> **GRUZIK2.0 is a lightweight construction (74g) designed for the "Line Follower Light" competition. The robot features Bluetooth communication with a smartphone app and uses a digital sensor instead of analog.**



<div align="center">
  <img src="https://github.com/user-attachments/assets/0fdffd6d-9023-4386-b539-104f9b9ba9c4" width="700"/>
</div>

<div align="center">
  <img src="https://github.com/user-attachments/assets/7fa3e891-3858-4886-a66f-cda7b4732d12" width="200"/>
  <img src="https://github.com/user-attachments/assets/800418eb-de7f-4ffd-9bcf-28b1dca531c5" width="200"/>
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
- motors - Pololu 3071
- Bluetooth - HC-05

<div align="center">
  <img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/09fbbeaa-abc1-43ac-baea-b56389da5343" width="400"/>
  <img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/a5f2fef5-a88e-447f-a070-cfea2200bb3b" width="400"/>
</div>

## 📱Bluetooth App 📱

> **It's a simple Bluetooth app created with MIT App Inventor. The app starts and stops the robot, allows you to send data in the terminal, slow down or accelerate on any section of the route using Time mode. The Modes pad is responsible for quickly adapting the speed and accuracy of the robot to the route using modes, and the application also displays the battery charge status.**

<div align="center">
  <img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/99308187-04be-49ce-bf4d-46ec42ed3cef" width="200"/>
</div>

## ⏱Time Mode⏱
> **Time Mode is a feature that allows you to slow down or speed up any section of your route by selecting:**
>
> `mode_1` **- mode for the entire route**
>
> `mode_2` **- time section mode on the route**
>
> `Start_time` **- time from start to mode change**
>
> `Change_time` **- Mode_2 duration**

<img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/f31179b3-dcbc-4551-86c7-9655d86f9fea" width="195"/><img src="https://github.com/NYDEREK/LineFollower_GRUZIK2.0-light/assets/112076828/6e4534ce-c543-4864-8fb3-f4f834b6377c" width="630"/>

## 💥What's next💥
> <i>**In the future, I aspire for my robot to autonomously identify sharp edges along its path and enhance its efficiency by seamlessly adjusting modes both before and after encountering them.**<i>

## Credits

> <i>**I implemented the PD controller in my project, drawing inspiration from Bilal Kabas' repository available at - https://github.com/sametoguten/STM32-Line-Follower-with-PID with MIT License - [MIT License](LICENSE)**<i>

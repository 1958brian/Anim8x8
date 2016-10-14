# Anim8x8
This was adapted from an Adafruit trinket project that I found online

Arduino based 8x8 LED matrix animation

Animate a 8x8 LED module using an Arduino (tested with the UNO and Mini Pro)

MatrixAnimate.ino is the main Arduino sketch

There are 3 header (.h) files that contain the animation data

anim.h - regular speed animation
anim2.h - faster animation
anim3.h - includes data to control the brightness (intensity) of each animation frame

The LED control (LedControl.h) library for Arduino is required

The module requires +5v and ground and connections:
  CS (connects to Arduino pin 10)
  CLK (connects to Arduino pin 11)
  DIN (connects to Arduino pin 12)
  
  

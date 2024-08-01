# STM32F030F4 Bare metal programming

![Pipeline Status](https://github.com/nemocazin/stm32f030f4-bare-metal-programming/actions/workflows/ci.yml/badge.svg)

![Code Coverage](https://codecov.io/github/nemocazin/stm32f030f4-bare-metal-programming/graph/badge.svg?token=GVIVAL2Y8H)](https://codecov.io/github/nemocazin/stm32f030f4-bare-metal-programming)

## Table of content

 * [General project information](#general-project-information)
 * [Electronic board design](#electronic-board-design)
 * [Embedded programming and test design](#embedded-programming-and-test-design)
 * [Contact](#contact)

## General project information

This product was developed as part of a fourth-year project in the Embedded Systems program at Polytech Lille with an another student. It consisted in designing an electronic board to measure temperature and store the values in an EPROM-type memory. We had to create the board and the programming ourselves, __in a context of mass production__. As a result, we had to work as if we were in a company, meaning we had to carry out all the design stages of a product. 

__This project is focused on the test and maintenance part of the project__. Whether we were testing the physical board or the programming part, we had to do our best to ensure that the board worked in spite of the environment and all its constraints.

The project is therefore divided in __two parts__ : the physical part with the electronic board, and the programming part with the embedded program and the tests carried out on it.

## Electronic board design

This part consists of designing the electronic board. The purpose of this board is to __measure temperature and store measured values in an EPROM-type memory__. We were then asked to design certain components, such as the temperature sensor. 

We then designed the board on Kicad-6 and drew up the schematic and routing. In the end, the board was designed on Polytech Lille's site, from manufacturing to soldering.

We also carried out tests on the board to see how it performed in certain types of environment. 

The board design files can be found in the _"PCB"_ folder of the current directory.

## Embedded programming and test design

The programming of the card was mainly __carried out in the C programming language and using bare metal programming__.

We also used the _"check.h"_ library to carry out unit tests and ensure the proper functioning of our code.

Nucleo boards were available to transfer our file to our microcontroller

## Contact

Created by [@nemocazin] & Antoine Cegarra
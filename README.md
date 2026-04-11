# Water Tank PID Control System

A PID-based control system for regulating water level and temperature using **MATLAB, Simulink, and Arduino**.

---

## 📁 Project Structure

```

water-tank-pid-control-system/
│
├── src/
│   ├── Arduino Code Without PID/
│   │   └── Water_Tank_Control_System_Without_PID.ino
│   │
│   ├── MATLAB and Simulink with PID/
│   │   ├── Water_Level_Control.m
│   │   ├── Water_Level_Control.slx
│   │   ├── Heat_Control.m
│   │   └── Heat_Control.slx
│
├── media/
│   ├── images
│   ├── results
│
├── Presentation/
│   └── project presentation files
│
└── README.md

````


## Project Overview

This project implements a real-time feedback control system to maintain stable **water level** and **temperature** in a tank.

The complete workflow included:
- mathematical modeling in **MATLAB**
- controller design and simulation in **Simulink**
- hardware implementation using **Arduino**

The project contains two control subsystems:
- **Water Level Control**
- **Heat Control**

---

## Features

- Real-time PID control for water level
- PID-based temperature control
- MATLAB/Simulink system modeling and simulation
- Arduino-based hardware implementation
- Sensor integration and actuator control
- System response analysis including overshoot, settling time, and stability

---

## 🛠️ Hardware Components

- **Arduino Uno**
- **Two Water Tanks**
  - One tank acts as a **source reservoir** for the pump
  - The second tank is the **controlled tank**, where water level and temperature are measured and regulated

- **12V Ultra-Quiet DC Water Pump**
  - Transfers water from the source tank to the controlled tank

- **1/4 inch Valve**
  - Used to regulate or control water flow

- **L298N H-Bridge Motor Driver**
  - Controls the operation of the water pump

- **HC-SR04 Ultrasonic Sensor**
  - Measures the water level in the controlled tank

- **6 × Power Resistors (27Ω, 7W each)**
  - Connected to form a **resistive heating element**
  - Used as the **heat source** for temperature control

- **DS18B20 Temperature Sensor**
  - Measures water temperature in the controlled tank

- **16x2 LCD Display (Blue)**
  - Displays real-time temperature and water level

- **Potentiometer**
  - Adjusts LCD contrast

- **Relay Module**
  - Controls ON/OFF switching of the heating element

---

## System Architecture

### Water Level Control

The water level loop uses:
- **Sensor:** HC-SR04 ultrasonic sensor
- **Actuator:** 12V water pump through L298N driver

The water level plant is modeled as:

$$G(s) =\frac{R}{(R A s + 1)}$$

Where:
- $$R = 0.2778$$
- $$A = 198$$

### Heat Control

The temperature loop uses:
- **Sensor:** DS18B20
- **Actuator:** **Resistance heating element** switched through a relay

The thermal plant is modeled as:

$$G(s) = \frac{R_{T}}{(R_{T} C s + 1)}$$

Where:
- $$R_{T} = 1.339$$
- $$C = 10460$$

---

## PID Controllers

### Water Level PID Parameters

From `Water_Level_Control.m`:



- $$K_{p} = 49.92$$
- $$K_{i} = 3.451$$
- $$K_{d} = 38.88$$
- $$N = 100$$

$$

### Temperature PID Parameters

From `Heat_Control.m`:

- $$K_{p} = 612.4$$
- $$K_{i} = 6.638$$
- $$K_{d} = 1837$$
- $$N = 100$$

---

## Control Strategy

The system uses closed-loop feedback control:

1. Sensors measure the actual water level and temperature
2. The measured values are compared with desired setpoints
3. PID controllers compute corrective control actions
4. The pump and heating element are driven to reduce error

### Water Level Control Logic
- The ultrasonic sensor measures tank level
- The level PID controller adjusts the pump control signal
- The pump is driven through the L298N module

### Heat Control Logic
- The DS18B20 measures the water temperature
- The temperature PID controller regulates heating
- The **resistance heating element** acts as the heat source
- Since the heater is switched using a relay, the practical implementation is relay-based control rather than continuous analog actuation

---

## MATLAB and Simulink Files

### Water Level Control Files
- `Water_Level_Control.m`
- `Water_Level_Control.slx`

### Heat Control Files
- `Heat_Control.m`
- `Heat_Control.slx`

---

## How to Run the MATLAB and Simulink Models

## Important Note

The Simulink models depend on variables defined in the MATLAB scripts.

You must run the `.m` file first so the required parameters are loaded into the MATLAB workspace before opening or running the `.slx` file.

If you open the Simulink file directly without running the corresponding MATLAB script first, the model may fail because parameters such as `R`, `A`, `C`, `R_T`, `Kp`, `Ki`, `Kd`, and `N` are not yet defined in the workspace.

---

### Run Water Level Control

```matlab
cd 'src/MATLAB and Simulink with PID'
Water_Level_Control
open('Water_Level_Control.slx')
```

This initializes the water level parameters in the MATLAB workspace, including:

```matlab
R = 0.2778;
A = 198;

Kp = 49.92;
Ki = 3.451;
Kd = 38.88;
N  = 100;
```

---

### Run Heat Control

```matlab
cd 'src/MATLAB and Simulink with PID'
Heat_Control
open('Heat_Control.slx')
```

This initializes the temperature control parameters in the MATLAB workspace, including:

```matlab
RT = 1.339;
C  = 10460;

Kp = 612.4;
Ki = 6.638;
Kd = 1837;
N  = 100;
```

> Note: In some files or screenshots, the thermal resistance is written as `R_T`. In MATLAB scripts it may appear as `RT`.

---

## Arduino Implementation

The hardware implementation was carried out using Arduino with real sensors and actuators.

### Inputs
- Water level from the HC-SR04 ultrasonic sensor
- Temperature from the DS18B20 sensor

### Outputs
- Pump control through the L298N driver
- Heating control through a relay connected to the **resistance heating element**
- LCD display for real-time system monitoring

The Arduino stage was used for real-world testing after modeling and simulation in MATLAB/Simulink.

---

## What I Did

- Modeled the water level system in MATLAB
- Modeled the thermal system in MATLAB
- Designed PID controllers for both subsystems
- Simulated the system in Simulink
- Tuned controller parameters for level and temperature regulation
- Implemented the control system on Arduino hardware
- Integrated sensors, pump, LCD, relay, and heating resistance
- Evaluated system response and stability

---

## Technologies

- MATLAB
- Simulink
- Arduino
- Embedded C/C++
- PID Control
- Control Systems

---

## Screenshots

- Water level Simulink model
- Heat control Simulink model
- Schematic diagram
- MATLAB parameter files
- System response plots if available

---

## Contact

If you have any questions, feel free to contact me:

- **Phone:** +201028325749
- **Email:** a.mohamed822000@gmail.com
- **LinkedIn:** [Abdelrahman Mohamed Hamad](https://www.linkedin.com/in/abdelrahman-mohamed-a1956b247/)

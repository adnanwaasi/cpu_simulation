# CPU Scheduling Simulation

## Overview
This project simulates various CPU scheduling algorithms. CPU scheduling is a fundamental concept in operating systems, where the CPU decides the order in which processes are executed. This simulation helps visualize and understand how different scheduling algorithms work.

## Features
- Implementation of multiple CPU scheduling algorithms.
- Comparison of scheduling performance metrics such as turnaround time, waiting time, and response time.
- Easy-to-run simulation with clear outputs.

## Algorithms Implemented
- First-Come, First-Served (FCFS)
- Shortest Job Next (SJN)
- Priority Scheduling
- Round Robin (RR)

## Prerequisites
- A C++ compiler (e.g., `g++`)
- Linux environment (recommended)

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/adnanwaasi/cpu_simulation.git
   ```
2. Navigate to the project directory:
   ```bash
   cd cpu_simulation
   ```
3. Compile the code:
   ```bash
   g++ main.cpp -o cpu_simulation
   ```
4. Run the simulation:
   ```bash
   ./cpu_simulation
   ```

## File Structure
- `main.cpp`: Contains the main logic for the simulation.
- `priority/`: Directory for priority scheduling-related code.
- `run.sh`: Script to automate the build and run process.
- `README.md`: Project documentation.
- `what_i_learnt.txt`: Notes and learnings from the project.

## What I Learned
This project provided insights into:
- The working of various CPU scheduling algorithms.
- Writing modular and efficient C++ code.
- Debugging and testing scheduling logic.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Author
- **Adnan Waasi**

Feel free to contribute to this project by submitting issues or pull requests!
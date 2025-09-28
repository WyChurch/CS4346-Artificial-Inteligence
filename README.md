# CS 4346 Project 1 – Expert System for Mental Health Diagnosis & Treatment

## Overview
This project is an **Expert System** built for **CS 4346 (Artificial Intelligence)**.  
It uses a **Backward Chaining (BC)** engine to determine the diagnosis based on user-provided symptoms, and then applies **Forward Chaining (FC)** to recommend treatments based on the diagnosis.  

- **Backward Chaining (BC)** → works from goals (disorders) backward to symptoms.  
- **Forward Chaining (FC)** → works from facts (diagnosis) forward to treatments.  
- **Rules File** → all disorder diagnosis rules and treatment rules are stored in `EXPERT SYSTEM RULES.cpp` and parsed automatically at runtime.  
- **Parser** → `ExpertSystemParser` reads and stores all rules dynamically. 

### How to compile the backwards chaining
g++ -o expert_system Project1-jdr357.cpp ExpertSystemParser.cpp
./expert_system
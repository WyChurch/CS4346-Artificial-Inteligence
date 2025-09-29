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

## File Structure
├── Project1-jdr357.cpp # Main driver program (Backward & Forward chaining)
├── ExpertSystemParser.cpp # Parser implementation
├── ExpertSystemParser.h # Parser header
├── EXPERT SYSTEM RULES.cpp # Knowledge base (diagnosis + treatment rules)
├── README.md # This file

## Running the Program
=== BACKWARD CHAINING EXPERT SYSTEM ===
Initializing data structures...
Successfully loaded XX rules.

=== AVAILABLE DISORDERS FOR DIAGNOSIS ===
1. BIPOLAR DISORDER
2. DISSOCIATIVE IDENTITY DISORDER
3. DYSTHYMIA
4. GENERALIZED ANXIETY DISORDER
5. MAJOR DEPRESSIVE DISORDER
6. PANIC DISORDER WITH AGORAPHOBIA
7. SCHIZO-AFFECTIVE DISORDER
8. SCHIZOPHRENIA

Enter the disorder you want to test (e.g., 'BIPOLAR DISORDER'):

Example Run (DYSTHYMIA)

Enter DYSTHYMIA.

The system will ask symptom questions (sadness, loss_of_interest, etc.).

Once enough conditions are satisfied, BC derives:

=== FINAL RESULT ===
SUCCESS: diagnosis = DYSTHYMIA

=== FORWARD CHAINING RESULTS ===
 - treatment = SSRIs_SNRIs
 - treatment = Tricyclics
 - treatment = Psychotherapy
 - treatment = Cognitive_Behavioral_Therapy
 - treatment = Long_term_coping_strategies
 - treatment = Supportive_Therapy

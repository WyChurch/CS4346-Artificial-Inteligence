//------DIAGNOSIS-------

// SCHIZOPHRENIA

//RULE 10
IF hallucinations = true
AND delusions = true
AND disorganized_speech = true
THEN diagnosis = SCHIZOPHRENIA

//RULE 20
IF hallucinations = true 
AND paranoia = true 
AND unusual_motor_behavior = true
THEN diagnosis = SCHIZOPHRENIA

//RULE 30
IF delusions = true 
AND disorganized_behavior = true
AND paranoia = true
THEN diagnosis = SCHIZOPHRENIA

// MAJOR DEPRESSIVE DISORDER

//RULE 40
IF anxiety = true
AND sadness = true
AND guilt = true
THEN diagnosis = MAJOR DEPRESSIVE DISORDER

//RULE 50
IF anxiety = true
AND sadness = true
AND altered_sleep = true
THEN diagnosis = MAJOR DEPRESSIVE DISORDER

//RULE 60
IF sadness = true
AND guilt = true
AND weight_gain = true
THEN diagnosis = MAJOR DEPRESSIVE DISORDER

// PANIC DISORDER WITH AGORAPHOBIA

//RULE 70
IF anxiety = true
AND sadness = true
AND guilt = true
AND helplessness = true
THEN diagnosis = PANIC DISORDER WITH AGORAPHOBIA

//RULE 80
IF anxiety = true
AND panic_attacks = true
AND fear_trapped = true
AND helplessness = true
THEN diagnosis = PANIC DISORDER WITH AGORAPHOBIA

// BIPOLAR DISORDER

//RULE 90
IF confused_thinking = true
AND agitated = true
AND manic_episodes = true
AND delusions = true
THEN diagnosis = BIPOLAR DISORDER

//RULE 100
IF confused_thinking = true
AND agitated = true
AND distractable = true
AND mood_swings = true
THEN diagnosis = BIPOLAR DISORDER

//RULE 110
IF confused_thinking = true
AND agitated = true
AND psychosis = true
AND anxiety = true
THEN diagnosis = BIPOLAR DISORDER


// GENERALIZED ANXIETY DISORDER

//RULE 120
IF anxiety = true
AND sadness = true
AND guilt = true
AND helplessness = true
THEN diagnosis = GENERALIZED ANXIETY DISORDER

//RULE 130
IF overthinking = true
AND Indecisiveness = true
AND constant_worry = true
AND fast_heart_rate = true
THEN diagnosis = GENERALIZED ANXIETY DISORDER

//RULE 140
IF sadness = true
AND guilt = true
AND panic_attacks = true
AND hyper_vigilance = true
THEN diagnosis = GENERALIZED ANXIETY DISORDER

// SCHIZO-AFFECTIVE DISORDER

//RULE 150
IF confused_thinking = true
AND sleeplessness = true
AND paranoia = true
THEN diagnosis = SCHIZO-AFFECTIVE DISORDER

//RULE 160
IF confused_thinking = true
AND compulsory_talkativeness = true
AND unstable_emotions = true
THEN diagnosis = SCHIZO-AFFECTIVE DISORDER

//RULE 170
IF confused_thinking = true
AND agitated = true
AND distractable = true
THEN diagnosis = SCHIZO-AFFECTIVE DISORDER

// DISSOCIATIVE IDENTITY DISORDER

//RULE 180
IF memory_loss = true
AND blurred_identity = true
THEN diagnosis = DISSOCIATIVE IDENTITY DISORDER

//RULE 190
IF memory_loss = true
AND coping_difficulty = true
AND sense_of_unreality = true
THEN diagnosis = DISSOCIATIVE IDENTITY DISORDER

//RULE 200
IF severe_stress = true
AND coping_difficulty = true
AND depression = true
AND anxiety = true
THEN diagnosis = DISSOCIATIVE IDENTITY DISORDER

// DYSTHYMIA

//RULE 210
IF sadness = true
AND loss_of_interest = true
AND lack_of_energy = true
THEN diagnosis = DYSTHYMIA

//RULE 220
IF low_self_esteem = true
AND no_focus = true
AND hopelessness = true
THEN diagnosis = DYSTHYMIA

//RULE 230
IF depressive_episodes = true
AND quickly_annoyed = true
AND no_appetite = true
THEN diagnosis = DYSTHYMIA

// -------TREATMENT-------

//SCHIZOPHRENIA

//RULE 240
IF diagnosis = SCHIZOPHRENIA AND treatment_needed = true
THEN treatment = Antipsychotics_Aripiprazole_Olanzapine

//RULE 241
IF diagnosis = SCHIZOPHRENIA AND treatment_needed = true
THEN treatment = Individual_Therapy

//RULE 242
IF diagnosis = SCHIZOPHRENIA AND treatment_needed = true
THEN treatment = Family_Therapy

//RULE 243
IF diagnosis = SCHIZOPHRENIA AND treatment_needed = true
THEN treatment = Social_Skills_Therapy

//MAJOR DEPRESSIVE DISORDER

//RULE 250
IF diagnosis = MAJOR DEPRESSIVE DISORDER AND treatment_needed = true
THEN treatment = SSRIs_SNRIs

//RULE 251
IF diagnosis = MAJOR DEPRESSIVE DISORDER AND treatment_needed = true
THEN treatment = Tricyclics

//RULE 252
IF diagnosis = MAJOR DEPRESSIVE DISORDER AND treatment_needed = true
THEN treatment = Psychotherapy

//RULE 253
IF diagnosis = MAJOR DEPRESSIVE DISORDER AND treatment_needed = true
THEN treatment = Interpersonal_Therapy

//RULE 254
IF diagnosis = MAJOR DEPRESSIVE DISORDER AND treatment_needed = true
THEN treatment = Exercise

//RULE 255
IF diagnosis = MAJOR DEPRESSIVE DISORDER AND treatment_needed = true
THEN treatment = Sleep_hygiene

//PANIC DISORDER WITH AGORAPHOBIA

//RULE 260
IF diagnosis = PANIC DISORDER WITH AGORAPHOBIA AND treatment_needed = true
THEN treatment = Antidepressants

//RULE 261
IF diagnosis = PANIC DISORDER WITH AGORAPHOBIA AND treatment_needed = true
THEN treatment = Anti_anxiety_medicine

//RULE 262
IF diagnosis = PANIC DISORDER WITH AGORAPHOBIA AND treatment_needed = true
THEN treatment = Psychotherapy

//RULE 263
IF diagnosis = PANIC DISORDER WITH AGORAPHOBIA AND treatment_needed = true
THEN treatment = Calming_skills

//RULE 264
IF diagnosis = PANIC DISORDER WITH AGORAPHOBIA AND treatment_needed = true
THEN treatment = Gradual_exposure

//BIPOLAR DISORDER

//RULE 270
IF diagnosis = BIPOLAR DISORDER AND treatment_needed = true
THEN treatment = Mood_stabilizers

//RULE 271
IF diagnosis = BIPOLAR DISORDER AND treatment_needed = true
THEN treatment = Antidepressants_Antipsychotics

//RULE 272
IF diagnosis = BIPOLAR DISORDER AND treatment_needed = true
THEN treatment = Cognitive_Behavioral_Therapy

//RULE 273
IF diagnosis = BIPOLAR DISORDER AND treatment_needed = true
THEN treatment = Psychoeducation

//RULE 274
IF diagnosis = BIPOLAR DISORDER AND treatment_needed = true
THEN treatment = Regular_sleep

//RULE 275
IF diagnosis = BIPOLAR DISORDER AND treatment_needed = true
THEN treatment = Support_systems

//GENERALIZED ANXIETY DISORDER

//RULE 280
IF diagnosis = GENERALIZEDANXIETYDISORDER
AND treatment_needed = true
THEN treatment = SSRIs_SNRIs

//RULE 281
IF diagnosis = GENERALIZEDANXIETYDISORDER
AND treatment_needed = true
THEN treatment = Buspirone

//RULE 282
IF diagnosis = GENERALIZEDANXIETYDISORDER
AND treatment_needed = true
THEN treatment = Stress_reduction_techniques

//RULE 283
IF diagnosis = GENERALIZEDANXIETYDISORDER
AND treatment_needed = true
THEN treatment = CBT

//RULE 284
IF diagnosis = GENERALIZEDANXIETYDISORDER
AND treatment_needed = true
THEN treatment = Relaxation_Therapy

//SCHIZO-AFFECTIVE DISORDER

//RULE 290
IF diagnosis = SCHIZO-AFFECTIVE DISORDER AND treatment_needed = true
THEN treatment = Antipsychotics_Paliperidone

//RULE 291
IF diagnosis = SCHIZO-AFFECTIVE DISORDER AND treatment_needed = true
THEN treatment = Individual_Therapy

//RULE 292
IF diagnosis = SCHIZO-AFFECTIVE DISORDER AND treatment_needed = true
THEN treatment = Family_Therapy

//RULE 293
IF diagnosis = SCHIZO-AFFECTIVE DISORDER AND treatment_needed = true
THEN treatment = Social_Skills_Therapy

//DISSOCIATIVE IDENTITY DISORDER

//RULE 300
IF diagnosis = DISSOCIATIVE IDENTITY DISORDER AND treatment_needed = true
THEN treatment = Psychotherapy

//RULE 301
IF diagnosis = DISSOCIATIVE IDENTITY DISORDER AND treatment_needed = true
THEN treatment = Family_Therapy

//RULE 302
IF diagnosis = DISSOCIATIVE IDENTITY DISORDER AND treatment_needed = true
THEN treatment = Hypnotherapy

//RULE 303
IF diagnosis = DISSOCIATIVE IDENTITY DISORDER AND treatment_needed = true
THEN treatment = Antidepressants_if_Depression

//RULE 304
IF diagnosis = DISSOCIATIVE IDENTITY DISORDER AND treatment_needed = true
THEN treatment = Anti_anxiety_if_Anxiety

//DYSTHYMIA

//RULE 310
IF diagnosis = DYSTHYMIA AND treatment_needed = true
THEN treatment = SSRIs_SNRIs

//RULE 311
IF diagnosis = DYSTHYMIA AND treatment_needed = true
THEN treatment = Tricyclics

//RULE 312
IF diagnosis = DYSTHYMIA AND treatment_needed = true
THEN treatment = Psychotherapy

//RULE 313
IF diagnosis = DYSTHYMIA AND treatment_needed = true
THEN treatment = Cognitive_Behavioral_Therapy

//RULE 314
IF diagnosis = DYSTHYMIA AND treatment_needed = true
THEN treatment = Long_term_coping_strategies

//RULE 315
IF diagnosis = DYSTHYMIA AND treatment_needed = true
THEN treatment = Supportive_Therapy

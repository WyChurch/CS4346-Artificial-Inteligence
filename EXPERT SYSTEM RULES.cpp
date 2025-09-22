//SCHIZOPHRENIA

//RULE 10
IF hallucinations = true
AND delusions = true
AND disorganized_speech = true
THEN diagnosis = Schizophrenia

//RULE 20
IF hallucinations = true 
AND paranoia = true 
AND unusual_motor_behavior = true
THEN diagnosis = Schizophrenia

//RULE 30
IF delusions = true 
AND disorganized_behavior = true
AND paranoia = true
THEN diagnosis = Schizophrenia

//MAJOR DEPRESSIVE DISORDER

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

//PANIC DISORDER WITH AGORAPHOBIA

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

//BIPOLAR DISORDER

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

//GENERALIZED ANXIETY DISORDER

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

//SCHIZO-AFFECTIVE DISORDER

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

//DISSOCIATIVE IDENTITY DISORDER

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

//DYSTHYMIA

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

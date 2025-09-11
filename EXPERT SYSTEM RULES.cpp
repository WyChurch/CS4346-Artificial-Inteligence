//SCHIZOPHRENIA

//RULE 1
IF hallucinations = true 
AND delusions = true 
AND disorganized_speech = true
THEN diagnosis = Schizophrenia

//RULE 2
IF hallucinations = true 
AND paranoia = true 
AND unusual_motor_behavior = true
THEN diagnosis = Schizophrenia

//RULE 3
IF delusions = true 
AND disorganized_behavior = true
THEN diagnosis = Schizophrenia

//MAJOR DEPRESSIVE DISORDER

//RULE 1
IF anxiety = true
AND sadness = true
AND guilt = true
THEN diagosis = MAJOR DEPRESSIVE DISORDER

//RULE 2
IF anxiety = true
AND sadness = true
AND altered_sleep = true
THEN diagosis = MAJOR DEPRESSIVE DISORDER

//RULE 3
IF anxiety = true
AND sadness = true
AND weight_gain = true
THEN diagosis = MAJOR DEPRESSIVE DISORDER

//PANIC DISORDER WITH AGORAPHOBIA

//rule 1
IF anxiety = true
AND sadness = true
AND guilt = true
AND helplessnes = true
THEN diagosis = PANIC DISORDER WITH AGORAPHOBIA

//rule 2
IF anxiety = true
AND sadness = true
AND guilt = true
AND helplessnes = true
AND panic_attacks = true
THEN diagosis = PANIC DISORDER WITH AGORAPHOBIA

//3
IF anxiety = true
AND sadness = true
AND guilt = true
AND helplessnes = true
AND fear_trapped = true
THEN diagosis = PANIC DISORDER WITH AGORAPHOBIA

//BIPOLAR DISORDER

//RULE 1
IF confused_thinking = true
AND agitated = true
AND manic_episodes = true
AND delusions = true
THEN diagosis = BIPOLAR DISORDER

//RULE 2
IF confused_thinking = true
AND agitated = true
AND distractable = true
AND mood_swings = true
THEN diagosis = BIPOLAR DISORDER

//RULE 3

IF confused_thinking = true
AND agitated = true
AND psychosis = true
AND anxiety = true
THEN diagosis = BIPOLAR DISORDER

//GENERALIZED ANXIETY DISORDER

//RULE 1
IF anxiety = true
AND sadness = true
AND guilt = true
AND helplessness = true
THEN diagnosis = GENERALIZED ANXIETY DISORDER

//RULE 2
IF overthinking = true
AND Indecisiveness = true
AND constant_worry = true
AND fast_heart_rate = true
THEN diagnosis = GENERALIZED ANXIETY DISORDER

//RULE 3
IF sadness = true
AND guilt = true
AND panic_attacks = true
AND hyper_vigilance = true
THEN diagnosis = GENERALIZED ANXIETY DISORDER

//SCHIZO-AFFECTIVE DISORDER

//RULE 1
IF confused_thinking = true
AND sleeplessness = true
AND paranoia = true
THEN diagnosis = SCHIZO-AFFECTIVE DISORDER

//RULE 2
IF confused_thinking = true
AND compulsory_talkativeness = true
AND unstable_emotions = true
THEN diagnosis = SCHIZO-AFFECTIVE DISORDER

//RULE 3 
IF confused_thinking = true
AND agitated = true
AND distractable = true
THEN diagnosis = SCHIZO-AFFECTIVE DISORDER

//DISSOCIATIVE IDENTITY DISORDER

//RULE 1
IF memory_loss = true
AND blurred_identity = true
THEN diagnosis = DISSOCIATIVE IDENTITY DISORDER

//RULE 2
IF memory_loss = true
AND coping_difficulty = true
AND sense_of_unreality = true
THEN diagnosis = DISSOCIATIVE IDENTITY DISORDER

//RULE 3 
IF severe_stress = true
AND coping_difficulty = true
AND depression = true
AND anxiety = true
THEN diagnosis = DISSOCIATIVE IDENTITY DISORDER

//DYSTHYMIA

//RULE 1
IF sadness = true
AND loss_of_interest = true
AND lack_of_energy = true
THEN diagnosis  = DYSTHYMIA

//RULE 2
IF low_self_esteem = true
AND no_focus = true
AND hopelessness = true
THEN diagnosis = true

//RULE 3
IF depressive_episodes = true
AND quickly_annoyed = true
AND no_appetite = true
THEN diagnosis = true

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include "ExpertSystemParser.h"
using namespace std;

// Global data structures for backward chaining
vector<string> variableList;           // Variable List
vector<string> conclusionList;        // Conclusion List  
vector<string> clauseVariableList;    // Clause Variable List (44 elements)
map<string, string> derivedGlobalVariables; // Derived Global Variable List
ExpertSystemParser ruleParser;         // Rule parser instance

// Function prototypes
int search_con(string variable);
int rule_to_clause(int Ri);
void update_VL(int Ci);
bool validate_Ri(int Ri, string& conclusion);
void Process(string variable);
void displayAvailableDisorders();
void ProcessDisorder(const string& disorderName, const vector<int>& disorderRules, ExpertSystemParser& ruleParser);

// Global variable to track which rules have been tried
static int lastTriedRuleIndex = -1;

// search_con function - finds matching variable in conclusion list
int search_con(string variable) {
    cout << "Searching for variable '" << variable << "' in conclusion list..." << endl;
    
    // Parse rules from file if not already done
    if (ruleParser.getRuleCount() == 0) {
        ruleParser.parseRulesFromFile("EXPERT SYSTEM RULES.cpp");
    }
    
    // Search through all rules to find variable in conclusion
    for (int i = lastTriedRuleIndex + 1; i < ruleParser.getRuleCount(); i++) {
        RuleData rule = ruleParser.getRuleByIndex(i);
        if (rule.isActive && rule.ruleText.find("THEN") != string::npos) {
            // Extract conclusion part
            size_t thenPos = rule.ruleText.find("THEN");
            if (thenPos != string::npos) {
                string conclusion = rule.ruleText.substr(thenPos + 4);
                // Clean up conclusion
                conclusion.erase(remove(conclusion.begin(), conclusion.end(), ' '), conclusion.end());
                
                // Check if variable matches conclusion
                if (conclusion.find(variable) != string::npos) {
                    cout << "Found variable '" << variable << "' in rule " << rule.ruleNumber << endl;
                    lastTriedRuleIndex = i;
                    return rule.ruleNumber;
                }
            }
        }
    }
    
    cout << "Variable '" << variable << "' not found in remaining rules." << endl;
    return -1; // Not found
}

// rule_to_clause function - converts rule number to clause number
// (Function is already defined in ExpertSystemParser.cpp)

// update_VL function - asks questions and instantiates variables
void update_VL(int Ci) {
    cout << "Updating Variable List starting from clause " << Ci << "..." << endl;
    
    // Get the rule corresponding to this clause
    int Ri = (Ci - 1) / 44 * 10 + 10; // Reverse calculation
    RuleData rule = ruleParser.getRuleByNumber(Ri);
    
    if (rule.ruleNumber == 0) {
        cout << "No rule found for clause " << Ci << endl;
        return;
    }
    
    // Extract variables from IF clause
    if (rule.ruleText.find("IF") != string::npos) {
        size_t ifPos = rule.ruleText.find("IF");
        size_t thenPos = rule.ruleText.find("THEN");
        
        if (ifPos != string::npos && thenPos != string::npos) {
            string ifClause = rule.ruleText.substr(ifPos + 2, thenPos - ifPos - 2);
            
            // Parse variables from IF clause
            vector<string> variables;
            
            // Split by AND/OR and extract variables
            string current = ifClause;
            size_t pos = 0;
            
            while (pos < current.length()) {
                // Find next AND or OR
                size_t andPos = current.find("AND", pos);
                size_t orPos = current.find("OR", pos);
                size_t nextPos = min(andPos, orPos);
                
                if (nextPos == string::npos) {
                    nextPos = current.length();
                }
                
                string segment = current.substr(pos, nextPos - pos);
                
                // Extract variable from segment
                size_t eqPos = segment.find("=");
                if (eqPos != string::npos) {
                    string varName = segment.substr(0, eqPos);
                    // Clean up variable name
                    varName.erase(remove(varName.begin(), varName.end(), ' '), varName.end());
                    if (!varName.empty()) {
                        variables.push_back(varName);
                    }
                }
                
                if (nextPos == current.length()) break;
                pos = nextPos + 3; // Skip "AND" or "OR"
            }
            
            // Ask questions for each variable
            for (const string& var : variables) {
                if (derivedGlobalVariables.find(var) == derivedGlobalVariables.end()) {
                    cout << "Is " << var << " true or false? (t/f): ";
                    char answer;
                    cin >> answer;
                    
                    string value = (answer == 't' || answer == 'T') ? "true" : "false";
                    derivedGlobalVariables[var] = value;
                    cout << "Set " << var << " = " << value << endl;
                } else {
                    cout << var << " already set to " << derivedGlobalVariables[var] << endl;
                }
            }
        }
    }
}

// validate_Ri function - checks if rule conditions are satisfied
bool validate_Ri(int Ri, string& conclusion) {
    cout << "Validating rule " << Ri << "..." << endl;
    
    RuleData rule = ruleParser.getRuleByNumber(Ri);
    if (rule.ruleNumber == 0) {
        cout << "Rule " << Ri << " not found." << endl;
        return false;
    }
    
    // Extract IF clause
    if (rule.ruleText.find("IF") != string::npos) {
        size_t ifPos = rule.ruleText.find("IF");
        size_t thenPos = rule.ruleText.find("THEN");
        
        if (ifPos != string::npos && thenPos != string::npos) {
            string ifClause = rule.ruleText.substr(ifPos + 2, thenPos - ifPos - 2);
            string thenClause = rule.ruleText.substr(thenPos + 4);
            
            // Parse and validate conditions
            vector<string> conditions;
            
            // Split by AND/OR and extract conditions
            string current = ifClause;
            size_t pos = 0;
            
            while (pos < current.length()) {
                // Find next AND or OR
                size_t andPos = current.find("AND", pos);
                size_t orPos = current.find("OR", pos);
                size_t nextPos = min(andPos, orPos);
                
                if (nextPos == string::npos) {
                    nextPos = current.length();
                }
                
                string segment = current.substr(pos, nextPos - pos);
                
                // Clean up segment
                segment.erase(remove(segment.begin(), segment.end(), ' '), segment.end());
                if (!segment.empty() && segment.find("=") != string::npos) {
                    conditions.push_back(segment);
                }
                
                if (nextPos == current.length()) break;
                pos = nextPos + 3; // Skip "AND" or "OR"
            }
            
            // Check if all conditions are satisfied
            bool allSatisfied = true;
            for (const string& condition : conditions) {
                size_t eqPos = condition.find("=");
                if (eqPos != string::npos) {
                    string varName = condition.substr(0, eqPos);
                    string expectedValue = condition.substr(eqPos + 1);
                    
                    // Clean up expected value (remove newlines, spaces)
                    expectedValue.erase(remove(expectedValue.begin(), expectedValue.end(), '\n'), expectedValue.end());
                    expectedValue.erase(remove(expectedValue.begin(), expectedValue.end(), '\r'), expectedValue.end());
                    expectedValue.erase(remove(expectedValue.begin(), expectedValue.end(), ' '), expectedValue.end());
                    
                    if (derivedGlobalVariables.find(varName) != derivedGlobalVariables.end()) {
                        string actualValue = derivedGlobalVariables[varName];
                        if (actualValue != expectedValue) {
                            cout << "Condition " << condition << " not satisfied (expected '" 
                                 << expectedValue << "', got '" << actualValue << "')" << endl;
                            allSatisfied = false;
                            break;
                        } else {
                            cout << "Condition " << condition << " satisfied!" << endl;
                        }
                    } else {
                        cout << "Variable " << varName << " not found in derived variables." << endl;
                        allSatisfied = false;
                        break;
                    }
                }
            }
            
            if (allSatisfied) {
                // Extract conclusion
                size_t diagPos = thenClause.find("diagnosis =");
                if (diagPos != string::npos) {
                    conclusion = thenClause.substr(diagPos + 11);
                    // Clean up conclusion
                    conclusion.erase(remove(conclusion.begin(), conclusion.end(), ' '), conclusion.end());
                    cout << "Rule " << Ri << " validated. Conclusion: " << conclusion << endl;
                    return true;
                }
            }
        }
    }
    
    cout << "Rule " << Ri << " validation failed." << endl;
    return false;
}

// Process function - main backward chaining logic
void Process(string variable) {
    cout << "\n=== PROCESSING VARIABLE: " << variable << " ===" << endl;
    
    // Reset rule index for new variable
    lastTriedRuleIndex = -1;
    
    // Check if variable is already derived
    if (derivedGlobalVariables.find(variable) != derivedGlobalVariables.end()) {
        cout << "Variable '" << variable << "' already derived: " 
             << derivedGlobalVariables[variable] << endl;
        return;
    }
    
    int maxAttempts = 10; // Prevent infinite loops
    int attempts = 0;
    
    while (attempts < maxAttempts) {
        attempts++;
        cout << "\n--- Attempt " << attempts << " ---" << endl;
        
        // Search for variable in conclusion list
        int Ri = search_con(variable);
        if (Ri == -1) {
            cout << "Cannot find rule for variable '" << variable << "'" << endl;
            break;
        }
        
        // Convert rule number to clause number
        int Ci = rule_to_clause(Ri);
        
        // Update variable list
        update_VL(Ci);
        
        // Validate rule
        string conclusion = "";
        if (validate_Ri(Ri, conclusion)) {
            // Rule validated, save conclusion
            derivedGlobalVariables[variable] = conclusion;
            cout << "SUCCESS: " << variable << " = " << conclusion << endl;
            return;
        } else {
            cout << "Rule validation failed, trying next rule..." << endl;
            continue;
        }
    }
    
    cout << "Could not determine value for variable '" << variable << "'" << endl;
}

// Function to display all available disorders
void displayAvailableDisorders() {
    cout << "\n=== AVAILABLE DISORDERS FOR DIAGNOSIS ===" << endl;
    cout << "==========================================" << endl;
    
    // Parse rules from file if not already done
    if (ruleParser.getRuleCount() == 0) {
        ruleParser.parseRulesFromFile("EXPERT SYSTEM RULES.cpp");
    }
    
    set<string> disorders;
    
    // Extract all unique disorders from rules
    for (int i = 0; i < ruleParser.getRuleCount(); i++) {
        RuleData rule = ruleParser.getRuleByIndex(i);
        if (rule.isActive && rule.ruleText.find("THEN") != string::npos) {
            // Extract conclusion part
            size_t thenPos = rule.ruleText.find("THEN");
            if (thenPos != string::npos) {
                string conclusion = rule.ruleText.substr(thenPos + 4);
                // Clean up conclusion
                conclusion.erase(remove(conclusion.begin(), conclusion.end(), ' '), conclusion.end());
                
                // Extract disorder name
                if (conclusion.find("diagnosis=") != string::npos) {
                    string disorder = conclusion.substr(conclusion.find("diagnosis=") + 9);
                    // Clean up any extra characters and spaces
                    disorder.erase(remove(disorder.begin(), disorder.end(), '='), disorder.end());
                    disorder.erase(remove(disorder.begin(), disorder.end(), ' '), disorder.end());
                    // Remove any comment markers
                    size_t commentPos = disorder.find("//");
                    if (commentPos != string::npos) {
                        disorder = disorder.substr(0, commentPos);
                    }
                    disorders.insert(disorder);
                }
            }
        }
    }
    
    // Display disorders in a nice format
    int count = 1;
    for (const string& disorder : disorders) {
        cout << count << ". " << disorder << endl;
        count++;
    }
    
    cout << "\nTotal disorders available: " << disorders.size() << endl;
    cout << "==========================================" << endl;
}

// New function to process a specific disorder
void ProcessDisorder(const string& disorderName, const vector<int>& disorderRules, ExpertSystemParser& ruleParser) {
    cout << "\n=== TESTING " << disorderName << " ===" << endl;
    
    // Try each rule for this disorder
    for (int ruleNum : disorderRules) {
        cout << "\n--- Testing Rule " << ruleNum << " ---" << endl;
        
        // Get the rule
        RuleData rule = ruleParser.getRuleByNumber(ruleNum);
        if (!rule.isActive) {
            cout << "Rule " << ruleNum << " not found or inactive." << endl;
            continue;
        }
        
        // Extract variables from the IF clause
        vector<string> variables;
        size_t ifPos = rule.ruleText.find("IF");
        size_t thenPos = rule.ruleText.find("THEN");
        
        if (ifPos != string::npos && thenPos != string::npos) {
            string ifClause = rule.ruleText.substr(ifPos + 2, thenPos - ifPos - 2);
            
            // Parse variables from IF clause
            size_t pos = 0;
            while (pos < ifClause.length()) {
                size_t nextPos = ifClause.find("AND", pos);
                if (nextPos == string::npos) {
                    nextPos = ifClause.length();
                }
                
                string segment = ifClause.substr(pos, nextPos - pos);
                
                // Extract variable from segment
                size_t eqPos = segment.find("=");
                if (eqPos != string::npos) {
                    string varName = segment.substr(0, eqPos);
                    // Clean up variable name
                    varName.erase(remove(varName.begin(), varName.end(), ' '), varName.end());
                    if (!varName.empty()) {
                        variables.push_back(varName);
                    }
                }
                
                if (nextPos == ifClause.length()) break;
                pos = nextPos + 3; // Skip "AND"
            }
        }
        
        // Ask questions for each variable
        bool allSatisfied = true;
        for (const string& var : variables) {
            if (derivedGlobalVariables.find(var) == derivedGlobalVariables.end()) {
                cout << "Is " << var << " true or false? (t/f): ";
                char answer;
                cin >> answer;
                
                string value = (answer == 't' || answer == 'T') ? "true" : "false";
                derivedGlobalVariables[var] = value;
                cout << "Set " << var << " = " << value << endl;
            }
        }
        
        // Validate the rule
        string conclusion;
        if (validate_Ri(ruleNum, conclusion)) {
            cout << "SUCCESS: Rule " << ruleNum << " validated!" << endl;
            cout << "Diagnosis: " << conclusion << endl;
            return; // Stop after first successful rule
        } else {
            cout << "Rule " << ruleNum << " validation failed." << endl;
        }
    }
    
    cout << "No rules for " << disorderName << " were satisfied." << endl;
}

// ======================= FORWARD CHAINING =======================

// data structures for FC
vector<string> FC_DerivedConclusions;     // derived conclusion list
queue<string> FC_GlobalConclusionQueue;   // global conclusion variable queue

// search_cvl: find clause number for a given variable
double search_cvl(string variable) {
    if (ruleParser.getRuleCount() == 0) {
        ruleParser.parseRulesFromFile("EXPERT SYSTEM RULES.cpp");
    }

    for (int i = 0; i < ruleParser.getRuleCount(); i++) {
        RuleData rule = ruleParser.getRuleByIndex(i);
        if (!rule.isActive) continue;

        if (rule.ruleText.find("THEN") != string::npos) {
            size_t thenPos = rule.ruleText.find("THEN");
            string thenClause = rule.ruleText.substr(thenPos + 4);
            thenClause.erase(remove(thenClause.begin(), thenClause.end(), ' '), thenClause.end());

            // Look for variable on LHS of THEN
            size_t eqPos = thenClause.find('=');
            if (eqPos != string::npos) {
                string varName = thenClause.substr(0, eqPos);
                if (varName == variable) {
                    return (i * 4) + 1;  // Clause numbers start at 1
                }
            }
        }
    }
    return -1; // not found
}

// clause_to_rule: convert Clause number -> Rule number
int clause_to_rule(int Ci) {
    // Rules are numbered in steps of 10 (10, 20, 30…)
    int Ri = ((Ci - 1) / 4 + 1) * 10;
    return Ri;
}

// update_VL: instantiate variables from clause
int update_VL(int Ci) {
    int Ri = clause_to_rule(Ci);
    RuleData rule = ruleParser.getRuleByNumber(Ri);
    if (rule.ruleNumber == 0) return -1;

    // extract IF part
    size_t ifPos = rule.ruleText.find("IF");
    size_t thenPos = rule.ruleText.find("THEN");
    if (ifPos == string::npos || thenPos == string::npos) return -1;

    string ifClause = rule.ruleText.substr(ifPos + 2, thenPos - ifPos - 2);

    // split by AND
    stringstream ss(ifClause);
    string segment;
    while (getline(ss, segment, 'A')) { // crude split on "AND"
        size_t eqPos = segment.find('=');
        if (eqPos != string::npos) {
            string varName = segment.substr(0, eqPos);
            string expectedValue = segment.substr(eqPos + 1);

            // cleanup
            varName.erase(remove(varName.begin(), varName.end(), ' '), varName.end());
            expectedValue.erase(remove(expectedValue.begin(), expectedValue.end(), ' '), expectedValue.end());

            // ask if not already known
            if (derivedGlobalVariables.find(varName) == derivedGlobalVariables.end()) {
                cout << "Is " << varName << " = " << expectedValue << "? (t/f): ";
                char ans;
                cin >> ans;
                string val = (ans == 't' || ans == 'T') ? expectedValue : "false";
                derivedGlobalVariables[varName] = val;
            }
        }
    }
    return 0;
}

// validate_Ri: check if IF-part of rule Ri is satisfied
int validate_Ri(int Ri) {
    RuleData rule = ruleParser.getRuleByNumber(Ri);
    if (rule.ruleNumber == 0) return 0;

    size_t ifPos = rule.ruleText.find("IF");
    size_t thenPos = rule.ruleText.find("THEN");
    if (ifPos == string::npos || thenPos == string::npos) return 0;

    string ifClause = rule.ruleText.substr(ifPos + 2, thenPos - ifPos - 2);
    string thenClause = rule.ruleText.substr(thenPos + 4);

    // parse IF conditions
    stringstream ss(ifClause);
    string cond;
    while (getline(ss, cond, 'A')) { // split on "AND"
        size_t eqPos = cond.find('=');
        if (eqPos != string::npos) {
            string varName = cond.substr(0, eqPos);
            string expectedValue = cond.substr(eqPos + 1);
            varName.erase(remove(varName.begin(), varName.end(), ' '), varName.end());
            expectedValue.erase(remove(expectedValue.begin(), expectedValue.end(), ' '), expectedValue.end());

            if (derivedGlobalVariables.find(varName) == derivedGlobalVariables.end() ||
                derivedGlobalVariables[varName] != expectedValue) {
                return 0; // condition not satisfied
            }
        }
    }

    // IF satisfied then add conclusion
    size_t eqPos = thenClause.find('=');
    if (eqPos != string::npos) {
        string conclVar = thenClause.substr(0, eqPos);
        string conclVal = thenClause.substr(eqPos + 1);
        conclVar.erase(remove(conclVar.begin(), conclVar.end(), ' '), conclVar.end());
        conclVal.erase(remove(conclVal.begin(), conclVal.end(), ' '), conclVal.end());

        string conclusionStr = conclVar + " = " + conclVal;
        FC_DerivedConclusions.push_back(conclusionStr);
        FC_GlobalConclusionQueue.push(conclVar);
        derivedGlobalVariables[conclVar] = conclVal;
    }
    return 1;
}

// process: perform FC step for a variable
void process(string variable) {
    double Ci = search_cvl(variable);
    if (Ci == -1) return;

    update_VL((int)Ci);
    int Ri = clause_to_rule((int)Ci);
    validate_Ri(Ri);
}

// FC_main: driver
void FC_main(string startVar) {
    process(startVar);

    while (!FC_GlobalConclusionQueue.empty()) {
        string nextVar = FC_GlobalConclusionQueue.front();
        FC_GlobalConclusionQueue.pop();
        process(nextVar);
    }

    cout << "\n=== FORWARD CHAINING RESULTS ===\n";
    for (auto& concl : FC_DerivedConclusions) {
        cout << " - " << concl << endl;
    }
}
// ======================= END FORWARD CHAINING =======================

//  main function
int main() {
    cout << "=== BACKWARD CHAINING EXPERT SYSTEM ===" << endl;
    
    // Initialize data structures
    cout << "Initializing data structures..." << endl;
    
    // Parse rules from file
    if (!ruleParser.parseRulesFromFile("EXPERT SYSTEM RULES.cpp")) {
        cout << "Failed to parse rules from file!" << endl;
        return 1;
    }
    
    cout << "Successfully loaded " << ruleParser.getRuleCount() << " rules." << endl;
    
    // Display available disorders
    displayAvailableDisorders();
    
    // Ask user to select a specific disorder to test
    string selectedDisorder;
    cout << "\nEnter the disorder you want to test (e.g., 'BIPOLAR DISORDER'): ";
    cin.ignore(); // Clear the input buffer
    getline(cin, selectedDisorder);
    
    // Convert to uppercase for comparison
    transform(selectedDisorder.begin(), selectedDisorder.end(), selectedDisorder.begin(), ::toupper);
    
    // Find rules for the selected disorder
    vector<int> disorderRules;
    for (int i = 0; i < ruleParser.getRuleCount(); i++) {
        RuleData rule = ruleParser.getRuleByIndex(i);
        if (rule.isActive && rule.ruleText.find("THEN") != string::npos) {
            // Extract the conclusion part
            size_t thenPos = rule.ruleText.find("THEN");
            if (thenPos != string::npos) {
                string conclusion = rule.ruleText.substr(thenPos + 4);
                // Check if the conclusion contains the selected disorder
                if (conclusion.find(selectedDisorder) != string::npos) {
                    disorderRules.push_back(rule.ruleNumber);
                    cout << "Found rule " << rule.ruleNumber << " for " << selectedDisorder << endl;
                }
            }
        }
    }
    
    if (disorderRules.empty()) {
        cout << "No rules found for disorder: " << selectedDisorder << endl;
        cout << "Available disorders:" << endl;
        displayAvailableDisorders();
        return 1;
    }
    
    cout << "\nFound " << disorderRules.size() << " rule(s) for " << selectedDisorder << endl;
    cout << "Rule numbers: ";
    for (int ruleNum : disorderRules) {
        cout << ruleNum << " ";
    }
    cout << endl;
    
    // Process only the selected disorder
    ProcessDisorder(selectedDisorder, disorderRules, ruleParser);
    
if (derivedGlobalVariables.find("diagnosis") != derivedGlobalVariables.end() && 
    !derivedGlobalVariables["diagnosis"].empty()) {
    cout << "\n=== FINAL RESULT ===" << endl;
    cout << "SUCCESS: diagnosis = " << derivedGlobalVariables["diagnosis"] << endl;

    // Run Forward Chaining starting from diagnosis
    FC_main("diagnosis");
} else {
    cout << "\n=== FINAL RESULT ===" << endl;
    cout << "FAILURE: Could not determine diagnosis for " << selectedDisorder << endl;
}


    
    // Display all derived variables
    cout << "\n=== ALL DERIVED VARIABLES ===" << endl;
    for (const auto& pair : derivedGlobalVariables) {
        cout << pair.first << " = " << pair.second << endl;
    }
    
    return 0;
}

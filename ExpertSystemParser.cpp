#include "ExpertSystemParser.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Constructor
ExpertSystemParser::ExpertSystemParser() {
    ruleCount = 0;
    nextRuleNumber = 10;
}

// Parse rules from file
bool ExpertSystemParser::parseRulesFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return false;
    }
    
    string line;
    string currentCategory = "";
    string currentRule = "";
    int currentRuleNumber = 0;
    bool inRule = false;
    
    while (getline(file, line)) {
        // Skip empty lines
        if (line.empty()) continue;
        
        // Check for category headers (only if not currently parsing a rule)
        if (!inRule && line.find("//") == 0 && line.find("RULE") == string::npos && line.find("=") == string::npos) {
            currentCategory = line.substr(2); // Remove "//"
            // Clean up category name
            size_t pos = currentCategory.find_last_not_of(" \t\r\n");
            if (pos != string::npos) {
                currentCategory = currentCategory.substr(0, pos + 1);
            }
            continue;
        }
        
        // Check for rule number comments
        if (line.find("//RULE") != string::npos) {
            // If we were already in a rule, complete it first
            if (inRule && !currentRule.empty()) {
                rules[ruleCount].ruleText = currentRule;
                rules[ruleCount].isActive = true;
                rules[ruleCount].ruleNumber = currentRuleNumber;
                rules[ruleCount].category = currentCategory;
                ruleCount++;
            }
            
            // Extract rule number
            size_t pos = line.find("RULE");
            if (pos != string::npos) {
                string numberStr = line.substr(pos + 4);
                currentRuleNumber = stoi(numberStr);
                inRule = true;
                currentRule = "";
            }
            continue;
        }
        
        // If in a rule, collect the rule text
        if (inRule) {
            if (line.find("IF") != string::npos) {
                currentRule = line;
            } else if (line.find("AND") != string::npos || line.find("OR") != string::npos) {
                currentRule += " " + line;
            } else if (line.find("THEN") != string::npos) {
                currentRule += " " + line;
                // Rule is complete, add it to our array
                rules[ruleCount].ruleText = currentRule;
                rules[ruleCount].isActive = true;
                rules[ruleCount].ruleNumber = currentRuleNumber;
                rules[ruleCount].category = currentCategory;
                ruleCount++;
                inRule = false;
                currentRule = "";
                // Stop processing this line and move to next
                continue;
            } else if (!line.empty() && line.find("//") == string::npos && line.find("IF") == string::npos) {
                // This is a continuation line (like IF on next line)
                // But only if it's not a comment line
                if (line.find("//") == string::npos) {
                    currentRule += " " + line;
                }
            }
        }
    }
    
    // Complete the last rule if we were still in one
    if (inRule && !currentRule.empty()) {
        rules[ruleCount].ruleText = currentRule;
        rules[ruleCount].isActive = true;
        rules[ruleCount].ruleNumber = currentRuleNumber;
        rules[ruleCount].category = currentCategory;
        ruleCount++;
    }
    
    file.close();
    return true;
}

// Get rule by index
RuleData ExpertSystemParser::getRuleByIndex(int index) {
    if (index >= 0 && index < ruleCount) {
        return rules[index];
    }
    return RuleData{"", false, "", 0};
}

// Get rule by number
RuleData ExpertSystemParser::getRuleByNumber(int ruleNumber) {
    for (int i = 0; i < ruleCount; i++) {
        if (rules[i].ruleNumber == ruleNumber) {
            return rules[i];
        }
    }
    return RuleData{"", false, "", 0};
}

// Get rule count
int ExpertSystemParser::getRuleCount() const {
    return ruleCount;
}

// Display all rules
void ExpertSystemParser::displayRules() {
    cout << "Total rules loaded: " << ruleCount << endl;
    for (int i = 0; i < ruleCount; i++) {
        cout << "Rule " << rules[i].ruleNumber << " (" << rules[i].category << "): " 
             << rules[i].ruleText << " [Active: " << (rules[i].isActive ? "Yes" : "No") << "]" << endl;
    }
}

// Display rules by category
void ExpertSystemParser::displayRulesByCategory(const string& category) {
    cout << "Rules for category: " << category << endl;
    for (int i = 0; i < ruleCount; i++) {
        if (rules[i].category == category) {
            cout << "Rule " << rules[i].ruleNumber << ": " << rules[i].ruleText << endl;
        }
    }
}

// Add a new rule manually
void ExpertSystemParser::addRule(string ruleText, string category) {
    if (ruleCount < 44) {
        rules[ruleCount].ruleText = ruleText;
        rules[ruleCount].isActive = true;
        rules[ruleCount].ruleNumber = nextRuleNumber;
        rules[ruleCount].category = category;
        ruleCount++;
        nextRuleNumber += 10;
    }
}

// Set next rule number
void ExpertSystemParser::setNextRuleNumber(int number) {
    nextRuleNumber = number;
}

// Rule to clause conversion function
int rule_to_clause(int Ri) {
    // Formula for rule numbers like 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230
    // CLAUSE NUMBER (Ci) = 4 * (RULE NUMBER / 10 - 1) + 1
    return 4 * (Ri / 10 - 1) + 1;
}

// Test function to demonstrate usage
void demonstrateExpertSystemParsing() {
    ExpertSystemParser parser;
    
    cout << "=== EXPERT SYSTEM PARSER DEMONSTRATION ===" << endl;
    
    // Parse rules from file
    if (parser.parseRulesFromFile("EXPERT SYSTEM RULES.cpp")) {
        cout << "Successfully loaded " << parser.getRuleCount() << " rules." << endl;
        
        // Display all rules
        cout << "\n=== ALL RULES ===" << endl;
        parser.displayRules();
        
        // Test rule_to_clause function
        cout << "\n=== RULE TO CLAUSE CONVERSION ===" << endl;
        for (int i = 0; i < parser.getRuleCount(); i++) {
            RuleData rule = parser.getRuleByIndex(i);
            int clauseNumber = rule_to_clause(rule.ruleNumber);
            cout << "Rule " << rule.ruleNumber << " -> Clause " << clauseNumber << endl;
        }
        
    } else {
        cout << "Failed to parse rules from file!" << endl;
    }
}
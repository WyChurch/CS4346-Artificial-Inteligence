#ifndef EXPERT_SYSTEM_PARSER_H
#define EXPERT_SYSTEM_PARSER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Structure to hold rule information (matches your 44-element array requirement)
struct RuleData {
    string ruleText;    // String part of the pair
    bool isActive;      // Boolean part of the pair
    string category;
    int ruleNumber;     // Keep rule number for rule_to_clause function
};

// Enhanced automated rule management
class ExpertSystemParser {
private:
    RuleData rules[500]; // Increased to accommodate all rules
    int ruleCount;
    int nextRuleNumber;
    
public:
    ExpertSystemParser();
    
    // Parse rules from your EXPERT SYSTEM RULES.cpp file
    bool parseRulesFromFile(const string& filename);
    
    // Get rule by index
    RuleData getRuleByIndex(int index);
    
    // Get rule by rule number
    RuleData getRuleByNumber(int ruleNumber);
    
    // Display all rules
    void displayRules();
    
    // Display rules by category
    void displayRulesByCategory(const string& category);
    
    // Get total rule count
    int getRuleCount() const;
    
    // Get rules by category
    vector<RuleData> getRulesByCategory(string category);
    
    // Add rule manually (useful for dynamic rule addition)
    void addRule(string ruleText, string category);
    
    // Set next rule number (useful for custom numbering)
    void setNextRuleNumber(int number);
};


// Function to demonstrate parsing from your expert system file
void demonstrateExpertSystemParsing();

#endif // EXPERT_SYSTEM_PARSER_H

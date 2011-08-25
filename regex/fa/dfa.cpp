#include <vector>
#include <map>
#include <string>

#include "dfa.h"
#include "state.h"

void DiscreteFiniteAutomaton::setLanguage(const std::vector<char>& language) {
  
  for (std::vector<char>::const_iterator iter  = language.begin(),
                                     int index = 1;
                                         language.end() != iter;
                                         ++iter, ++index) {
    d_languageTokenMap.insert(std::pair<char,int>(*iter, index));
  }
}

bool DiscreteFiniteAutomaton::evaluate(const std::string& input) {
  return false;
}

State *DiscreteFiniteAutomaton::getState(const std::string& name) {
  return NULL;
}

void DiscreteFiniteAutomaton::printTransitionTable() {
}

void insertState(const State **state) {
}

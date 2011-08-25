#ifndef __INCLUDED_DFA_H
#define __INCLUDED_DFA_H

#include "automaton.h"
#include "state.h"

namespace fa {

class DiscreteFiniteAutomaton: public Automaton {
// Contains the implementation of a discrete finite automaton.
// Inherits from the abstract Automaton class which defines what an automaton
// should do.
  public:
    DiscreteFiniteAutomaton(const std::string& name)
    :Automaton(name) { }
    
    virtual void setLanguage(const std::vector<char>& language);
      // Implementation of the abstract setLanguage().
    virtual bool evaluate(const std::string& input);
      // Implementation of the abstract evaluate(). 
    virtual State *getState(const std::string& name);
      // Implementation of the abstract getState().
    virtual void printTransitionTable();
      // Implementation of the abstract printTransitionTable().
    virtual void insertState(const State **state);
      // Implementation of the abstract insertState(). 
};
}
#endif

/* 
 * Contains the implementation of a discrete finite automaton.
 * Inherits from the abstract Automaton class which defines what an automaton
 * should do.
 */
#ifndef __INCLUDED_DFA_H
#define __INCLUDED_DFA_H

#include "automaton.h"
#include "state.h"

namespace fa {

class DiscreteFiniteAutomaton: public Automaton {
  public:
    DiscreteFiniteAutomaton(const std::string& name)
    :Automaton(name) { }
    
    virtual void setLanguage(const std::vector<char>& language);
    virtual bool evaluate(const std::string& input);
    virtual State *getState(const std::string& name);
    virtual void printTransitionTable();
    virtual void insertState(const State **state);
};
}
#endif

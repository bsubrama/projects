#ifndef __INCLUDED_AUTOMATON_H
#define __INCLUDED_AUTOMATON_H

#include <string>
#include <vector>
#include <map>

#include "state.h"

namespace fa {

class Automaton {
  //Abstract automaton class. defines the interface exposed by all the automata
  //implemented.
  public:
    Automaton(const std::string& name)
    :d_name(name) {}

    virtual void setLanguage(const std::vector<char>& language) = 0;
      // Set the language understood by the automaton to the be characters in
      // the specified 'language'. 
    virtual bool evaluate(const std::string& input) = 0;
      // Evaluate the specified 'input' using the current transition table and
      // return 'true' if a final state was reached, and 'false' otherwise. 
    virtual State *getState(const std::string& name) = 0;
      // Returns a State* to the State object in the FA with the specified
      // 'name', if present. Otherwise, returns a NULL pointer. 
    virtual void printTransitionTable(std::ostream& os) = 0;
      // Prints the transition table as used by the automaton to specified
      // output stream 'os'. 
    virtual void insertState(const State **state) = 0;
      // Insert the specified '*state' into the list of states maintained by the
      // FA. 
  private:
    std::string          d_name;
      // The name of the automaton. 
    std::map<char, int>  d_languageTokenMap;
      // A mapping between the language tokens and the internal tokens used by
      // the FA. Use of separate internal tokens allows for greater flexibility
      // over using only the tokens provided in the language. 
    std::vector<State *> d_states;
      // A list of the states in the FA. 
};
}
#endif

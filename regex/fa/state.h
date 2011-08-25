#ifndef __INCLUDED_STATE_H
#define __INCLUDED_STATE_H

#include <string>
#include <map>

namespace fa {

class State {
  // Contains the implementation of a state. A state represents a 'name',
  // a flag indicating whether it is a final state, and a mapping between an
  // integer and a State * indicating the outgoing links. 
  public:
    State(const std::string& name, bool isFinal = false) {
      // Constructs a State object with specified 'name' and, if specified, with
      // the specified 'isFinal' state. 
      d_name = name;
      d_isFinal = isFinal;
    }

    void addTransition(int tokenId, const State **destination) {
      // Adds the transition from the current state to the specified
      // '*destination' state upon encountering symbol represented by specified
      // 'tokenId'. 
      d_transitions.insert(std::pair<int, State *>(tokenId,
                                                   *destination));
    }

    void removeTransition(int tokenId) {
      // Removes the transition upon encountering symbol represented by
      // specified 'tokenId' from the transition table. 
      if (d_transitions.find(tokenId) != d_transitions.end()) {
        d_transitions.erase(tokenId);
      }
    }

    State *getNextState(int tokenId) {
      // Gets the state reached from the current state upon encountering the
      // symbol represented by 'tokenId' in the input, if a transition exists.
      // Otherwise, NULL is returned. 
      if (d_transitions.find(tokenId) != d_transitions.end()) {
        return d_transitions[tokenId];
      }

      return NULL;
    }

    bool isFinal() {
      // Simple getter for d_isFinal. 
      return d_isFinal;
    }

    bool name() {
      // Simple getter for d_name. 
      return d_name;
    }

  private:
    std::map<int, State *>   d_transitions;
    // Contains a mapping between tokens that are expected in the input from the
    // current state, and the State to transition to upon encountering such a
    // token. 
    std::string              d_name;
    // The name of the State. 
    bool                     d_isFinal;
    // Whether the state is a Final state, or a non-Final state. 
};
}
#endif

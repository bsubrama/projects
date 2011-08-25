/*
 * Contains the implementation of a state. A state represents a 'name',
 * a flag indicating whether it is a final state, and a mapping between an
 * integer and a State * indicating the outgoing links. 
 */
#ifndef __INCLUDED_STATE_H
#define __INCLUDED_STATE_H

#include <string>

namespace fa {

class State {
	public:
		State(const std::string& name, bool final = false) {
			d_name = name;
			d_final = final;
		}

		void addTransition(int tokenId, const State **destination) {
			d_transitions.insert(std::pair<int, State *>(tokenId,
																									 *destination));
		}

		void removeTransition(int tokenId) {
			if (d_transitions.find(tokenId) != d_transitions.end()) {
				d_transitions.erase(tokenId);
			}
		}

		State *getNextState(int tokenId) {
			if (d_transitions.find(tokenId) != d_transitions.end()) {
				return d_transitions[tokenId];
			}

			return NULL;
		}

		bool isFinal() {
			return d_final;
		}

		bool name() {
			return d_name;
		}

	private:
		std::map<int, State *> 	d_transitions;
		std::string 						d_name;
		bool 										d_isFinal;

};
}
#endif

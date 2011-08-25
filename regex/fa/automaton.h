/* 
 * Abstract automaton class. defines the interface exposed by all the automata
 * implemented.
 */
#ifndef __INCLUDED_AUTOMATON_H
#define __INCLUDED_AUTOMATON_H

#include <string>
#include <vector>
#include <map>

#include <state.h>

namespace fa {

class Automaton {
	public:
		Automaton(const std::string& name,
							const std::vector<char>& language);
		
		virtual bool evaluate(const std::string& input) = 0;
		virtual State *getState(const std::string& name) = 0;
		virtual void printTransitionTable() = 0;
		virtual void insertState(const State **state) = 0;
	private:
		std::string 				d_name;
		std::map<char, int> d_languageTokenMap;
};
}
#endif

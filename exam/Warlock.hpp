#include <iostream>
#include "Spellbook.hpp"

class Warlock {
	private: 
		std::string _name;
		std::string _title;
		Spellbook _book;
		Warlock();
		Warlock(Warlock const & ref);
		Warlock & operator= (Warlock const & ref);

}

for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it) {
		delete it->second;
	}

for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _Spellbook.end(); ++it) {
	delete it->second;
}
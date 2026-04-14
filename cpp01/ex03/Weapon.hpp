#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;

	public:
		const std::string& getType(void) const;
		void setType(std::string newType);

		Weapon(std::string type);
		~Weapon();
};

#endif

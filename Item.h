#pragma once

#include <string>

class Item {
public:
	Item() = default;
	virtual ~Item() = default;

	virtual void description() const;
	virtual void use();

	int id;
	int uses;
	int damage;
	std::string name;
};

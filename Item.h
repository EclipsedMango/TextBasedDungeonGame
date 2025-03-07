#pragma once

#include <string>

class Item {
public:
	Item() = default;
	virtual ~Item() = default;

	virtual void Description() const;
	virtual void Use();

	int id;
	int uses;
	int damage;
	std::string name;
};

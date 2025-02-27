#pragma once

class Item {
public:
	Item() = default;
	virtual ~Item() = default;

	virtual void description() const;
	virtual void use();

	int id;
};

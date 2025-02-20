#pragma once

class Item
{
public:
	Item() = default;
	~Item() = default;

	virtual void description() const;
	virtual void use();

private:

};

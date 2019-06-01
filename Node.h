#pragma once

template <typename T>

class Node
{
	T Value;
	Node *Previous;
public:
	T getValue() { return Value; }
	Node *getPrev() { return Previous; }
	void setValue(T op1) { Value = op1; }
	void setPrev(Node *op1) { Previous = op1; }
};

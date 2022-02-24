#include <iostream>


class Expression
{
public:
	virtual double evaluate() const = 0;
	virtual ~Expression() {};
};


class Number : public Expression
{
public:
	Number(double value_) : value(value_)  {};
	double evaluate () const
	{
		return value;
	}
	~Number() {};


private:
	double value;

};


class BinaryOperation : public Expression
{
public:
	BinaryOperation(Expression const* left_, char op, Expression const* right_)
		: left(left_), operation(op), right(right_) {}
	double evaluate() const
	{
		if (operation == '+')
		{
			return left->evaluate() + right->evaluate();
		}
		else if (operation == '-')
		{
			return left->evaluate() - right->evaluate();
		}
		else if (operation == '*')
		{
			return left->evaluate() * right->evaluate();
		}
		else return left->evaluate() / right->evaluate();
	}


	~BinaryOperation()
	{
		delete left;
		delete right;
	}

private:
	Expression const* left, const* right;
	char operation;
};

bool check_equals(Expression const* left, Expression const* right)
{
	return *(size_t**)left == *(size_t**)right;
}


int main()
{
	Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	Expression* expr = new BinaryOperation(new Number(3), '+', sube);
	std::cout << expr->evaluate() << std::endl;
	delete expr;
}
// eleven_standart.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <memory>
#include <vector>

class Move {
public: 
	Move() {
		std::cout << "Move()" << std::endl;
	}
	~Move() {
		std::cout << __FUNCTION__ << std::endl;
	};
	Move(const Move& copy) {
		std::cout << "Move(const Move& copy)" << std::endl;
	}
	Move(const Move&& copy) {
		std::cout << "Move(const Move&& copy)" << std::endl;
	}
	int m_member;
};

Move get() {
	std::cout << __FUNCTION__ << std::endl;
	Move el;
	return el;
}

Move getMove() {
	std::cout << __FUNCTION__ << std::endl;
	Move el;
	return std::move(el);
}

Move getStraight() {
	std::cout << __FUNCTION__ << std::endl;
	return Move();
}

Move getStraightMove() {
	std::cout << __FUNCTION__ << std::endl;
	return std::move(Move());
}

using t_vec_move = std::vector<Move>;

t_vec_move getVector() {
	std::cout << __FUNCTION__ << std::endl;
	t_vec_move v(3);
	return v;
}

t_vec_move getVectorMove() {
	std::cout << __FUNCTION__ << std::endl;
	t_vec_move v(3);
	return std::move(v);
}

void testSimple() {
	std::cout << "########### " << __FUNCTION__ << " ###########" << std::endl;

	{
		std::cout << "## get" << std::endl;
		auto el = get();
	}
	{
		std::cout << "## getMove" << std::endl;
		auto el = getMove();
	}

	{
		std::cout << "## std::move(get())" << std::endl;
		auto el = std::move(get());
	}

	{
		std::cout << "## std::move(getMove())" << std::endl;
		auto el = std::move(getMove());
	}
}

void testSimpleStraight() {
	std::cout << "########### " << __FUNCTION__ << " ###########" << std::endl;
	
	{
		std::cout << "## get" << std::endl;
		auto el = getStraight();
	}
	{
		std::cout << "## getMove" << std::endl;
		auto el = getStraightMove();
	}

	{
		std::cout << "## std::move(get())" << std::endl;
		auto el = std::move(getStraight());
	}

	{
		std::cout << "## std::move(getMove())" << std::endl;
		auto el = std::move(getStraightMove());
	}
}


void testVector() {
	std::cout << "########### " << __FUNCTION__ << " ###########" << std::endl;

	{
		std::cout << "## get" << std::endl;
		auto el = getVector();
	}
	{
		std::cout << "## getMove" << std::endl;
		auto el = getVectorMove();
	}

	{
		std::cout << "## std::move(get())" << std::endl;
		auto el = std::move(getVector());
	}

	{
		std::cout << "## std::move(getMove())" << std::endl;
		auto el = std::move(getVectorMove());
	}
}

void MoveTest() {
	std::cout << "########### ### " << __FUNCTION__ << " ### ###########" << std::endl;
	testSimple();
	testSimpleStraight();
	testVector();
}

int main()
{
	MoveTest();

	int a;
	std::cin >> a;
    return 0;
}


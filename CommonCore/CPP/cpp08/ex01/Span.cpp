#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N)
{
	numbers.reserve(N);
}

Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		numbers = other.numbers;
		maxSize = other.maxSize;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (numbers.size() >= maxSize)
		throw SpanFullException();
	numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = INT_MAX;
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw NotEnoughNumbersException();

	int min = *std::min_element(numbers.begin(), numbers.end());
	int max = *std::max_element(numbers.begin(), numbers.end());

	return max - min;
}
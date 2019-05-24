#pragma once

template<typename TElem>

class std::vector {

private:

	TElem* elements;
	int capacity;
	int length;

public:

	/*
	Dynamic vector constructor
	*/
	std::vector(int capacity = 10);
	/*
	Dynamic vector copy constructor
	*/
	std::vector(const std::vector& dynvect);
	/*
	Dynamic vector destructor
	*/
	~std::vector();

	/*
	Dynnamic vector [] operator
	*/
	TElem& operator[](int pos);
	/*
	Dynamic vector assignment operator
	*/
	std::vector<TElem>& operator=(const std::vector<TElem>& dynvect);
	/*
	Dynamic + operator that adds an element to the vector
	*/
	std::vector<TElem>& operator+(const TElem& element);

	/*
	Function that returns the array
	*/
	TElem* getAll();
	/*
	Funciton that adds an element to the vector
	*/
	void push_back(TElem TElem);
	/*
	Function that deletes an element from the vector
	*/
	void deleteTElem(int index);
	/*
	Function that returns the length of the vector
	*/
	int size() const;

private:
	/*
	Function that resizes the vector - used for the push_back function
	*/
	void resize(double factor = 2);

};

template<typename TElem>
inline std::vector<TElem>::std::vector(int capacity)
{
	this->length = 0;
	this->capacity = capacity;
	this->elements = new TElem[capacity];
}

template<typename TElem>
inline std::vector<TElem>::std::vector(const std::vector<TElem>& dynvect)
{
	this->length = dynvect.length;
	this->capacity = dynvect.capacity;
	this->elements = new TElem[capacity];
	for (int i = 0; i < this->length; i++) {
		this->elements[i] = dynvect.elements[i];
	}
}

template<typename TElem>
inline std::vector<TElem>::~std::vector()
{
	delete[] this->elements;
}

template<typename TElem>
inline TElem & std::vector<TElem>::operator[](int pos)
{
	return this->elements[pos];
}

template<typename TElem>
inline std::vector<TElem>& std::vector<TElem>::operator=(const std::vector<TElem>& dynvect)
{
	if (this == &dynvect) {
		return *this;
	}
	this->length = dynvect.length;
	this->capacity = dynvect.capacity;
	delete[] this->elements;
	for (int i = 0; i < this->length; i++) {
		this->elements[i] = dynvect.elements[i];
	}
	return *this;
}

template<typename TElem>
inline std::vector<TElem>& std::vector<TElem>::operator+(const TElem & element)
{
	this->push_back(element);
	return *this;
}

template<typename TElem>
inline TElem * std::vector<TElem>::getAll()
{
	return this->elements;
}

template<typename TElem>
inline void std::vector<TElem>::push_back(TElem element)
{
	if (this->length == this->capacity)
		this->resize();
	this->elements[this->length] = element;
	this->length++;
}

template<typename TElem>
inline void std::vector<TElem>::deleteTElem(int index)
{
	for (int i = index + 1; i < this->length; i++) {
		this->elements[i - 1] = this->elements[i];
	}
	this->length--;
}

template<typename TElem>
inline int std::vector<TElem>::size() const
{
	return this->length;
}

template <typename TElem>
void std::vector<TElem>::resize(double factor)
{
	this->capacity = (int)(factor * this->capacity);

	TElem* els = new TElem[this->capacity];
	for (int i = 0; i < this->length; i++)
		els[i] = this->elements[i];

	delete[] this->elements;
	this->elements = els;
}
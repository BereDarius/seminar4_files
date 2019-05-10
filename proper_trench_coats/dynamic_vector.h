#pragma once

template<typename TElem>

class DynamicVector {

private:

	TElem* elements;
	int capacity;
	int length;

public:

	/*
	Dynamic vector constructor
	*/
	DynamicVector(int capacity = 10);
	/*
	Dynamic vector copy constructor
	*/
	DynamicVector(const DynamicVector& dynvect);
	/*
	Dynamic vector destructor
	*/
	~DynamicVector();

	/*
	Dynnamic vector [] operator
	*/
	TElem& operator[](int pos);
	/*
	Dynamic vector assignment operator
	*/
	DynamicVector<TElem>& operator=(const DynamicVector<TElem>& dynvect);
	/*
	Dynamic + operator that adds an element to the vector
	*/
	DynamicVector<TElem>& operator+(const TElem& element);

	/*
	Function that returns the array
	*/
	TElem* getAll();
	/*
	Funciton that adds an element to the vector
	*/
	void addTElem(TElem TElem);
	/*
	Function that deletes an element from the vector
	*/
	void deleteTElem(int index);
	/*
	Function that returns the length of the vector
	*/
	int getLength() const;

private:
	/*
	Function that resizes the vector - used for the addTElem function
	*/
	void resize(double factor = 2);

};

template<typename TElem>
inline DynamicVector<TElem>::DynamicVector(int capacity)
{
	this->length = 0;
	this->capacity = capacity;
	this->elements = new TElem[capacity];
}

template<typename TElem>
inline DynamicVector<TElem>::DynamicVector(const DynamicVector<TElem>& dynvect)
{
	this->length = dynvect.length;
	this->capacity = dynvect.capacity;
	this->elements = new TElem[capacity];
	for (int i = 0; i < this->length; i++) {
		this->elements[i] = dynvect.elements[i];
	}
}

template<typename TElem>
inline DynamicVector<TElem>::~DynamicVector()
{
	delete[] this->elements;
}

template<typename TElem>
inline TElem & DynamicVector<TElem>::operator[](int pos)
{
	return this->elements[pos];
}

template<typename TElem>
inline DynamicVector<TElem>& DynamicVector<TElem>::operator=(const DynamicVector<TElem>& dynvect)
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
inline DynamicVector<TElem>& DynamicVector<TElem>::operator+(const TElem & element)
{
	this->addTElem(element);
	return *this;
}

template<typename TElem>
inline TElem * DynamicVector<TElem>::getAll()
{
	return this->elements;
}

template<typename TElem>
inline void DynamicVector<TElem>::addTElem(TElem element)
{
	if (this->length == this->capacity)
		this->resize();
	this->elements[this->length] = element;
	this->length++;
}

template<typename TElem>
inline void DynamicVector<TElem>::deleteTElem(int index)
{
	for (int i = index + 1; i < this->length; i++) {
		this->elements[i - 1] = this->elements[i];
	}
	this->length--;
}

template<typename TElem>
inline int DynamicVector<TElem>::getLength() const
{
	return this->length;
}

template <typename TElem>
void DynamicVector<TElem>::resize(double factor)
{
	this->capacity = (int)(factor * this->capacity);

	TElem* els = new TElem[this->capacity];
	for (int i = 0; i < this->length; i++)
		els[i] = this->elements[i];

	delete[] this->elements;
	this->elements = els;
}
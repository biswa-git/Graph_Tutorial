/*
#include <iostream>
using namespace std;
//--------------------------------------SHARED POINTER--------------------------------------

template <typename T>
class sharedPtr
{
public:
	sharedPtr();
	~sharedPtr();
	//sharedPtr(T*);
	sharedPtr(const sharedPtr<T>&);
	void operator =(const sharedPtr<T>&);
	T* operator ->();
	T& operator *();
	void clear();

	unsigned int GetReferenceCount();
private:
	T* dataPtr;
	unsigned int *refCount;
};

template <typename T>
sharedPtr<T>::sharedPtr() :dataPtr(nullptr)
{
	refCount = new unsigned int(0);
	this->dataPtr = new T();
	++(*refCount);
}

template <typename T>
sharedPtr<T>::~sharedPtr()
{
	--(*refCount);
	if (*refCount == 0)
	{
		cout << "ref count of address " << dataPtr << " is 0... deleting!" << endl;
		delete dataPtr;
	}
}

template<typename T>
sharedPtr<T>::sharedPtr(const sharedPtr<T>& copyPointer)
{
	dataPtr = copyPointer.dataPtr;
	refCount = copyPointer.refCount;
	++(*refCount);
}

template<typename T>
void sharedPtr<T>::operator=(const sharedPtr<T>& assignPointer)
{
	dataPtr = assignPointer.dataPtr;
	refCount = assignPointer.refCount;
	++(*refCount);
}

template<typename T>
T* sharedPtr<T>::operator->()
{
	return dataPtr;
}

template<typename T>
T& sharedPtr<T>::operator *()
{
	return *dataPtr;
}

template<typename T>
void sharedPtr<T>::clear()
{
	--(*refCount);
	if (*refCount == 0)
	{
		cout << "ref count of address " << dataPtr << " is 0... deleting!" << endl;
		delete dataPtr;
	}
	dataPtr = nullptr;
}

template<typename T>
unsigned int sharedPtr<T>::GetReferenceCount()
{
	return *refCount;
}


int main(char* argc, char* argv[])
{
	sharedPtr<int> R1;
	sharedPtr<int> R2(R1);
	cout << R1.GetReferenceCount() << endl;
	cout << R2.GetReferenceCount() << endl;
	*R1 = 5;
	cout << *R2 << endl;
	R1.clear();
	R2.clear();


	cout << "exiting..." << endl;
	return 0;
}

//--------------------------------------SHARED POINTER--------------------------------------//
*/



//------------------------------------------------

#include <iostream>
#include <memory>
using namespace std;
weak_ptr<int> gw;

void observe()
{
	cout << "use_count == " << gw.use_count() << ": ";
	if (auto spt = gw.lock()) { // Has to be copied into a shared_ptr before usage
	cout << *spt << "\n";
	}
	else {
		cout << "gw is expired\n";
	}
}

int main()
{
	{
		auto sp = make_shared<int>(42);
		shared_ptr<int> sp2(sp);
		gw = sp;

		observe();
	}

	observe();
}

//------------------------------------------------

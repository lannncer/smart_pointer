/*************************************************************************
    > File Name: smart_pointer.h
    > Author: lancer 
 ************************************************************************/
#include <iostream>

using namespace std;


template <typename T>
class shared_pointer
{
public:
	shared_pointer(): m_pointer(nullptr){
		cout<<"hello constructor 1 !"<<endl;
		m_num = new int(0);
	};

	shared_pointer(T *x) : m_pointer(x){
		cout<<"hello constructor 2 !"<<endl;
		m_num = new int(1);
	}

	shared_pointer(const shared_pointer& x){
		cout<<"hello copy constructor !"<<endl;
		m_pointer = x.m_pointer;
		m_num = x.m_num;
		(*m_num)++;
	}

	shared_pointer& operator=(const shared_pointer& x){
		cout<<"copy assignment !"<<endl;
		(*m_num)--;
		if((*m_num) == 0){
			delete m_pointer;
			delete m_num;
		}
		m_pointer = x.m_pointer;
		m_num = x.m_num;
		(*m_num)++;
		return *this;
	}

	T& operator*(){
		return *(this->m_pointer);
	}

	T* operator->(){
		return this->m_pointer;
	}

	~shared_pointer(){
		cout<<"hello destructor ! "<<endl;
		(*m_num)--;
		if((*m_num) == 0){
			delete m_pointer;
			delete m_num;
		}
	}

	int useCount(){
		return *(this->m_num);
	}
	
	bool unique()
    {
        return *m_num == 1;
    }

private:
	T* m_pointer;
	int* m_num;
};


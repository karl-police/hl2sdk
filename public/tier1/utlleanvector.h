#ifndef UTLLEANVECTOR_H
#define UTLLEANVECTOR_H

#include "tier1/utlvector.h"


template< class T, class A = CUtlMemory<T> >
class CUtlLeanVector : public CUtlVector<T, A>
{
	typedef CUtlVector< T, CUtlMemory<T, int> > BaseClass;

public:
	CUtlLeanVector(int growSize = 0, int initSize = 0) : BaseClass(growSize, initSize) {};
};



template< class T, class A = CUtlMemory<T> >
class CUtlLeanVectorBase : public CUtlLeanVector<T, A>
{
	typedef CUtlVector< T, CUtlMemory<T, int> > BaseClass;

public:
	CUtlLeanVectorBase(int growSize = 0, int initSize = 0) : BaseClass(growSize, initSize) {};
};


template< class T, size_t MAX_SIZE >
class CUtlLeanVectorFixedGrowable : public CUtlLeanVectorBase<T, CUtlMemoryFixedGrowable<T, MAX_SIZE > >
{
	typedef CUtlLeanVectorBase< T, CUtlMemoryFixedGrowable<T, MAX_SIZE > > BaseClass;

public:
	CUtlLeanVectorFixedGrowable(int growSize = 0) : BaseClass(growSize, MAX_SIZE) {}
};

template<class T, class B, size_t MAX_SIZE>
class CUtlLeanVectorImpl
{

};


#endif // UTLLEANVECTOR_H
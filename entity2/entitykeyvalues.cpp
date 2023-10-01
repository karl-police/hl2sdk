#include "entity2/entitysystem.h"


struct CEntityKeyValues {
    CUtlLeanVectorFixedGrowable<unsigned int, 9u, short int> m_keyHashes;
    CUtlLeanVector<CEntityKeyValues::KeyValueInfo_t, short int> m_keyValues;
    CUtlScratchMemoryPool m_memoryPool;
    CEntityKeyValues::EntityComplexKeyListElem_t* m_pComplexKeys;
    int16 m_nRefCount;
    int16 m_nQueuedForSpawnCount;
    CUtlVector<EntityIOConnectionDescFat_t, CUtlMemory<EntityIOConnectionDescFat_t, int> > m_connectionDescs;
}


struct CEntityKeyValues::CIterator {
    const CEntityKeyValues* m_pKeyValues;
    int m_nIndex;
};

struct CEntityKeyValues::EntityComplexKeyListElem_t {
    IEntityKeyComplex* m_pKey;
    CEntityKeyValues::EntityComplexKeyListElem_t* m_pNext;
}

struct CEntityKeyValues::KeyValueInfo_t {
    CEntityVariant m_value;
    const char* m_pAttributeName;
};



// Functions

void CEntityKeyValues::CEntityKeyValues() { // Only commented things here are missing
    CUtlScratchMemoryPool* p_m_memoryPool;

    /*
    this->m_keyHashes._anon_0._anon_0.m_nCount = 0;
    this->m_keyHashes._anon_0._anon_0.m_nAllocated = 9;
    */

    p_m_memoryPool = &this->m_memoryPool;

    /*
    LOWORD(p_m_memoryPool[-1].m_pFirstBlock) = 0;
    WORD1(p_m_memoryPool[-1].m_pFirstBlock) = 0;
    */

    CUtlScratchMemoryPool::CUtlScratchMemoryPool(p_m_memoryPool, 512, nullptr, 0);
    this->m_connectionDescs.m_Size = 0;
    this->m_connectionDescs.m_Memory.m_pMemory = nullptr;
    this->m_connectionDescs.m_Memory.m_nAllocationCount = 0;
    this->m_connectionDescs.m_Memory.m_nGrowSize = 0;
    this->m_nRefCount = 0;
    this->m_nQueuedForSpawnCount = 0;
    this->m_pComplexKeys = nullptr;
}

void CEntityKeyValues::ReleaseAllComplexKeys()
{    
    for ( EntityComplexKeyListElem_t* i = m_pComplexKeys; i; i = i->m_pNext )
    {
        IEntityKeyComplex* pKey = i->m_pKey;
        while (pKey->m_nRef-- != 1)
        {
            i = i->m_pNext;            
            if (!i)
                m_pComplexKeys = nullptr; // 0LL      
            
            pKey = i->m_pKey; // (*m_pKey->_vptr_IEntityKeyComplex)(m_pKey)
        }
        
        pKey->vptr();
    }
}



void CEntityKeyValues::RemoveAllKeys() {
    CUtlLeanVectorFixedGrowableBase<unsigned int, 9u, short int>::IndexType_t m_nAllocated;
    CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int>::IndexType_t v2;
    CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int>::ElemType_t* m_pElements;
    CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int>::IndexType_t v4;
    CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int>::ElemType_t* v5;
    uint16 m_flags;

    
    // == WARNING ==
    // This "between" section is unclear and not fully complete



}



bool CEntityKeyValues::HasValue(const CEntityKeyValues* const this, EntityKeyId_t key) {

}






// CEntityKeyValues::Serialize


__int64 CEntityKeyValues::Unserialize(CUtlBuffer* const buf) {

}


// CEntityKeyValues::UnserializeKeys from world renderer

// more

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

void CEntityKeyValues::CEntityKeyValues() { // Only commented things here are missing - "MISSING_HELP"
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

void CEntityKeyValues::~CEntityKeyValues() {
    CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int>::IndexType_t m_nAllocated;
    CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int>::ElemType_t* m_pElements;
    CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int>::IndexType_t v4; // dx
    CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int>::ElemType_t* v5; // rax
    uint16 m_flags;
    CUtlLeanVectorFixedGrowableBase<unsigned int, 9u, short int>::IndexType_t v7;

    void(FASTCALL* v8)(_QWORD*, CUtlLeanVectorFixedGrowableBase<unsigned int, 9u, short int>::ElemType_t*);

    CEntityKeyValues::ReleaseAllComplexKeys(this);

    this->m_connectionDescs.m_Size = 0;
    
    if ( this->m_connectionDescs.m_Memory.m_nGrowSize & 0xC0000000) == 0 ) {
        CUtlMemory<EntityIOConnectionDescFat_t, int>::Purge(&this->m_connectionDescs.m_Memory);
    }

    CUtlScratchMemoryPool::~CUtlScratchMemoryPool(&this->m_memoryPool);

    // MISSING_HELP
    /* m_nAllocated = this->m_keyValues._anon_0.m_nAllocated;

    if (m_nAllocated) {
        m_pElements = this->m_keyValues._anon_0.m_pElements;
    }
    else {
        m_pElements = nullptr;
    }

    if (this->m_keyValues._anon_0.m_nCount > 0) {
        v4 = 0;

        while (this->m_keyValues._anon_0.m_nCount > v4) do {
            v5 = &m_pElements[v4];
            m_flags = v5->m_value.m_flags;
            if ((m_flags & 1) != 0) {
                v5->m_value.m_flags = m_flags & 0xFFFE;
                v5->m_value._anon_0.m_uint64 = nullptr;
                ++v4;
                v5->m_value.m_type = 0;
            }
        }

        m_nAllocated = this->m_keyValues._anon_0.m_nAllocated;
    }

    if (m_nAllocated > 0) {
        (*(void(__fastcall**)(_QWORD*, CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int>::ElemType_t*))(*g_pMemAlloc + 16LL))(
            g_pMemAlloc,
            this->m_keyValues._anon_0.m_pElements);
        this->m_keyValues._anon_0.m_pElements = nullptr;
    }

    v7 = this->m_keyHashes._anon_0._anon_0.m_nAllocated;
    this->m_keyValues._anon_0.m_nAllocated = 0;
    this->m_keyHashes._anon_0._anon_0.m_nCount = 0;

    if ((unsigned __int64)v7 > 9)
    {
        v8 = *(void(__fastcall**)(_QWORD*, CUtlLeanVectorFixedGrowableBase<unsigned int, 9u, short int>::ElemType_t*))(*g_pMemAlloc + 16LL);
        if (v7)
            v8(g_pMemAlloc, this->m_keyHashes._anon_0._anon_2.m_pElements);
        else
            v8(g_pMemAlloc, nullptr);
        this->m_keyHashes._anon_0._anon_0.m_nAllocated = 9;
    }
    else
    {
        this->m_keyHashes._anon_0._anon_0.m_nAllocated = 9;
    }*/
}

bool CEntityKeyValues::HasValue(EntityKeyId_t key) {
    int m_nCount;

    CUtlLeanVectorFixedGrowableBase<unsigned int, 9u, short int>::IndexType_t m_nAllocated;
    int64 v4;
    CUtlLeanVectorFixedGrowableBase<unsigned int, 9u, short int>::ElemType_t* m_pElements;
    CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int>::ElemType_t* v6;

    m_nCount = this->m_keyHashes._anon_0._anon_0.m_nCount;
    if (m_nCount <= 0) {
        return 0; // return false?
    }

    m_nAllocated = this->m_keyHashes._anon_0._anon_0.m_nAllocated;
    v4 = nullptr;

    // MISSING_HELP
    /*while (!m_nAllocated) {

        if ( *(DWORD*)(4 * v4) == key.m_nHashCode ) {
            if (this->m_keyValues._anon_0.m_nAllocated) {
                v6 = this->m_keyValues._anon_0.m_pElements;
            }
            else {
                v6 = nullptr;
            }

            return (v6[v4].m_pAttributeName == nullptr);
        }
    }*/

    // This never got called
    /*
    LABEL_6:
        if ( m_nCount <= (int)++v4 )
          return 0;
      }
      m_pElements = (CUtlLeanVectorFixedGrowableBase<unsigned int,9u,short int>::ElemType_t *)(&this->m_keyHashes._anon_0._anon_2.m_nAllocAllocated
                                                                                             + 1);
      if ( (unsigned __int64)m_nAllocated > 9 )
        m_pElements = this->m_keyHashes._anon_0._anon_2.m_pElements;
      if ( m_pElements[v4] != key.m_nHashCode )
        goto LABEL_6;
    */
}

void CEntityKeyValues::SetTargetNameForConnection(int nDesc, const char *pTargetName) {
    int64 v4;

    EntityIOConnectionDescFat_t* v5;

    int targetNameLen;
    int targetNameLen_2;

    int v9;

    char* m_pTargetName;
    size_t v11;
    char* v12;

    if (this->m_nQueuedForSpawnCount <= 0) {
        v4 = nDesc;
        v5 = &this->m_connectionDescs.m_Memory.m_pMemory[v4];

        if (pTargetName)
        {
            targetNameLen = strlen(pTargetName);

            v5->m_pTargetName = (char*)CUtlScratchMemoryPool::AllocAligned(
                CEntityVariantAllocator::sm_pMemoryPool,
                targetNameLen + 1,
                8 * (unsigned int)(targetNameLen + 1 >= 16) + 8);

            targetNameLen_2 = strlen(pTargetName);

            v9 = targetNameLen_2 + 1;
            m_pTargetName = this->m_connectionDescs.m_Memory.m_pMemory[v4].m_pTargetName;

            if (v9 < 0) {
                DebugBreak();
            }

            v11 = v9;
        }
        else
        {
            v12 = (char*)CUtlScratchMemoryPool::AllocAligned(CEntityVariantAllocator::sm_pMemoryPool, 1, 8);
            v11 = 1LL;
            v5->m_pTargetName = v12;
            m_pTargetName = this->m_connectionDescs.m_Memory.m_pMemory[v4].m_pTargetName;
        }

        memcpy(m_pTargetName, pTargetName, v11);
    }
}





// CEntityKeyValues::Serialize


__int64 CEntityKeyValues::Unserialize(CUtlBuffer* const buf) {

}


// CEntityKeyValues::UnserializeKeys from world renderer

// more

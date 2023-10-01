#include "entity2/entitysystem.h"

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
    CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int>::ElemType_t* m_pElements;
    uint16 m_flags;
}

// CEntityKeyValues::Serialize


__int64 CEntityKeyValues::Unserialize(CUtlBuffer* const buf) {

}


// CEntityKeyValues::UnserializeKeys from world renderer

// more

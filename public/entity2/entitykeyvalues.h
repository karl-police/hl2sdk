#ifndef ENTITYKEYVALUES_H
#define ENTITYKEYVALUES_H

#include "tier1/utlleanvector.h"
#include "entitysystem.h"
#include "variant.h"

class CEntityKeyValues {
public:
    struct KeyValueInfo_t {
        CEntityVariant m_value;
        const char* m_pAttributeName;
    };

    //CUtlLeanVectorFixedGrowable<unsigned int, 9u, short int> m_keyHashes;
    CUtlLeanVectorFixedGrowable<CEntityKeyValues, 9u> m_keyHashes;

    CUtlLeanVectorBase<CEntityKeyValues::KeyValueInfo_t, short int> m_keyValues;
    CUtlScratchMemoryPool m_memoryPool;
    CEntityKeyValues::EntityComplexKeyListElem_t* m_pComplexKeys;
    int16 m_nRefCount;
    int16 m_nQueuedForSpawnCount;
    CUtlVector<EntityIOConnectionDescFat_t, CUtlMemory<EntityIOConnectionDescFat_t, int> > m_connectionDescs;

    struct CIterator {
        const CEntityKeyValues* m_pKeyValues;
        int m_nIndex;
    };

    struct EntityComplexKeyListElem_t {
        IEntityKeyComplex* m_pKey;
        CEntityKeyValues::EntityComplexKeyListElem_t* m_pNext;
    };
};


#endif // ENTITYKEYVALUES_H
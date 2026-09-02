#pragma once

#include "TextIP_ByteArray_to_CharPointer_Serialization_Model.hpp"
#include "Serialization.hpp"

#if defined(pankey_Log) && (defined(IPSerialization_Log) || defined(pankey_Global_Log) || defined(pankey_Support_Serialization_Log))
	#include "Logger_status.hpp"
	#define IPSerializationLog(status,method,mns) pankey_Log(status,"IPSerialization",method,mns)
#else
	#define IPSerializationLog(status,method,mns)
#endif

namespace pankey{

	namespace Support{

		namespace Serialization{

			using IPSerialization = Serialization<TextIP_ByteArray_to_CharPointer_Serialization_Model>;
		}

	}

}
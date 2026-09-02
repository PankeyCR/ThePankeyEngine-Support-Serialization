#pragma once

#include "Text_ByteArray_to_CharPointer_Serialization_Model.hpp"
#include "Serialization.hpp"

#if defined(pankey_Log) && (defined(TextMessage_Log) || defined(pankey_Global_Log) || defined(pankey_Support_Serialization_Log))
	#include "Logger_status.hpp"
	#define TextMessageLog(status,method,mns) pankey_Log(status,"TextMessage",method,mns)
#else
	#define TextMessageLog(status,method,mns)
#endif

namespace pankey{

	namespace Support{

		namespace Serialization{

			using TextMessage = Serialization<Text_ByteArray_to_CharPointer_Serialization_Model>;
		}

	}

}
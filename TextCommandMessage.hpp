#pragma once

#include "Text_ByteArray_to_CharCommands_Serialization_Model.hpp"
#include "Serialization.hpp"

#if defined(pankey_Log) && (defined(TextCommandMessage_Log) || defined(pankey_Global_Log) || defined(pankey_Support_Serialization_Log))
	#include "Logger_status.hpp"
	#define TextCommandMessageLog(status,method,mns) pankey_Log(status,"TextCommandMessage",method,mns)
#else
	#define TextCommandMessageLog(status,method,mns)
#endif

namespace pankey{

	namespace Support{

		namespace Serialization{

			using TextCommandMessage = Serialization<Text_ByteArray_to_CharCommands_Serialization_Model>;
			
		}

	}

}
#pragma once

#include "ArrayPointerHelper.hpp"
#include "to_CharArray_CharPointer.hpp"
#include "to_CharPointer_ByteArray.hpp"
#include "CharCommands.hpp"

namespace pankey{

	namespace Support{

		namespace Serialization{

			struct Text_ByteArray_to_CharCommands_Serialization_Model{
				using SERIALIZATION_TYPE = Text_ByteArray_to_CharCommands_Serialization_Model;

				using SERIALIZE_TYPE = pankey::Type::Array::ByteArray;
				using DESERIALIZE_TYPE = pankey::Type::Array::CharCommands;

				using SERIALIZE_MODEL = Text_ByteArray_to_CharCommands_Serialization_Model;
				using DESERIALIZE_MODEL = Text_ByteArray_to_CharCommands_Serialization_Model;
			};

			template<class SERIALIZATION, class DESERIALIZE>
			pankey::Type::Array::ByteArray serializeObject(const Text_ByteArray_to_CharCommands_Serialization_Model& a_model, SERIALIZATION& a_state, const DESERIALIZE& a_value){
				pankey::Type::Array::ByteArray i_data;
				for(int x = 0; x < a_value.length(); x++){
					pankey::Utility::Test::CharPointer i_command = a_value.get(x);
					pankey::Type::Array::ByteArray i_command_data = pankey::Type::Array::toByteArray(i_command);
					i_data.add(i_command_data);
				}
				return i_data;
			}

			template<class SERIALIZATION, class SERIALIZE>
			pankey::Type::Array::CharCommands deserializeObject(const Text_ByteArray_to_CharCommands_Serialization_Model& a_model, SERIALIZATION& a_state, const SERIALIZE& a_value){
				pankey::Type::Array::CharArray i_array = pankey::DataStructure::Array::toArrayPointer<CharArrayModel>(a_value);
				auto i_split = pankey::DataStructure::Array::split<pankey::Type::Array::CharArrayModel>(i_array, ' ');

				pankey::Type::Array::CharCommands i_commands;
				for(int x = 0; x < i_split.length(); x++){
					pankey::Utility::Test::CharPointer i_command = pankey::Type::Array::toCharPointer(i_split.get(x));
					i_commands.add(i_command);
				}
				return i_commands;
			}

		}

	}

}
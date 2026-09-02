#pragma once

#include "ArrayPointer.hpp"
#include "CharPointer.hpp"
#include "ByteArray.hpp"
#include "to_CharPointer_ByteArray.hpp"


namespace pankey{

	namespace Support{

		namespace Serialization{

			struct Text_ByteArray_to_CharPointer_Serialization_Model{
				using SERIALIZATION_TYPE = Text_ByteArray_to_CharPointer_Serialization_Model;

				using SERIALIZE_TYPE = pankey::Type::Array::ByteArray;
				using DESERIALIZE_TYPE = pankey::Utility::Test::CharPointer;

				using SERIALIZE_MODEL = Text_ByteArray_to_CharPointer_Serialization_Model;
				using DESERIALIZE_MODEL = Text_ByteArray_to_CharPointer_Serialization_Model;
			};

			template<class SERIALIZATION, class DESERIALIZE>
			pankey::Type::Array::ByteArray serializeObject(const Text_ByteArray_to_CharPointer_Serialization_Model& a_model, SERIALIZATION& a_state, const DESERIALIZE& a_value){
				pankey::Type::Array::ByteArray i_data = pankey::Type::Array::toByteArray(a_value);
				return i_data;
			}

			template<class SERIALIZATION, class SERIALIZE>
			pankey::Utility::Test::CharPointer deserializeObject(const Text_ByteArray_to_CharPointer_Serialization_Model& a_model, SERIALIZATION& a_state, const SERIALIZE& a_value){
				return pankey::Type::Array::toCharPointer(a_value);
			}

		}

	}

}
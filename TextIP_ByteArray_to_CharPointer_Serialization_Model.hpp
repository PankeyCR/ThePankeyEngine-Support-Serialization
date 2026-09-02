#pragma once

#include "ArrayPointer.hpp"
#include "CharPointer.hpp"
#include "CharArrayPrimitive.hpp"
#include "to_CharArray_CharPointer.hpp"
#include "ArrayPointerHelper.hpp"
#include "ByteArray.hpp"


namespace pankey{

	namespace Support{

		namespace Serialization{

			struct TextIP_ByteArray_to_CharPointer_Serialization_Model{
				using SERIALIZATION_TYPE = TextIP_ByteArray_to_CharPointer_Serialization_Model;

				using SERIALIZE_TYPE = pankey::Type::Array::ByteArray;
				using DESERIALIZE_TYPE = pankey::Utility::Test::CharPointer;

				using SERIALIZE_MODEL = TextIP_ByteArray_to_CharPointer_Serialization_Model;
				using DESERIALIZE_MODEL = TextIP_ByteArray_to_CharPointer_Serialization_Model;
			};

			template<class S, class V>
			pankey::Type::Array::ByteArray serializeObject(const TextIP_ByteArray_to_CharPointer_Serialization_Model& a_model, S& a_state, const V& a_value){
				pankey::Type::Array::CharArray i_array = pankey::Type::Array::toCharArray(a_value);
				auto i_split = pankey::DataStructure::Array::split(i_array, '.');
  				pankey::Type::Array::ByteArray i_data = 
					pankey::DataStructure::Array::createArrayPointer<pankey::Type::Array::ByteArrayModel>(
																		pankey::Type::Array::toInt(i_split.get(0)), 
																		pankey::Type::Array::toInt(i_split.get(1)), 
																		pankey::Type::Array::toInt(i_split.get(2)), 
																		pankey::Type::Array::toInt(i_split.get(3)));
				return i_data;
			}

			template<class S, class V>
			pankey::Utility::Test::CharPointer deserializeObject(const TextIP_ByteArray_to_CharPointer_Serialization_Model& a_model, S& a_state, const V& a_value){
				if(a_value.length() != 4){
					return pankey::Utility::Test::CharPointer();
				}
				pankey::Type::Array::CharArray i_array;
				i_array.add(pankey::Type::Array::toCharArray((int)a_value.get(0)));
				i_array.add('.');
				i_array.add(pankey::Type::Array::toCharArray((int)a_value.get(1)));
				i_array.add('.');
				i_array.add(pankey::Type::Array::toCharArray((int)a_value.get(2)));
				i_array.add('.');
				i_array.add(pankey::Type::Array::toCharArray((int)a_value.get(3)));
				return pankey::Type::Array::toCharPointer(i_array);
			}

		}

	}

}
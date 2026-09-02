#pragma once

#if defined(pankey_Log) && (defined(Serialization_Log) || defined(pankey_Global_Log) || defined(pankey_Support_Serialization_Log))
	#include "Logger_status.hpp"
	#define SerializationLog(status,method,mns) pankey_Log(status,"Serialization",method,mns)
#else
	#define SerializationLog(status,method,mns)
#endif

namespace pankey{

	namespace Support{

		namespace Serialization{

			template<class Policy>
			class Serialization{
				public:
					using SERIALIZATION_TYPE = typename Policy::SERIALIZATION_TYPE;

					using SERIALIZE_TYPE = typename Policy::SERIALIZE_TYPE;
					using DESERIALIZE_TYPE = typename Policy::DESERIALIZE_TYPE;

					using SERIALIZE_MODEL = typename Policy::SERIALIZE_MODEL;
					using DESERIALIZE_MODEL = typename Policy::DESERIALIZE_MODEL;

					Serialization(const SERIALIZE_TYPE& a_data): m_data(a_data){
						SerializationLog(pankey_Log_StartMethod, "Contructor", "const SERIALIZE_TYPE&");
						SerializationLog(pankey_Log_EndMethod, "Contructor", "");
					}

					Serialization(const DESERIALIZE_TYPE& a_object): m_object(a_object){
						SerializationLog(pankey_Log_StartMethod, "Contructor", "const DESERIALIZE_TYPE&");
						SerializationLog(pankey_Log_EndMethod, "Contructor", "");
					}

					Serialization(const Serialization& a_Serialization): m_data(a_Serialization.m_data), m_object(a_Serialization.m_object){
						SerializationLog(pankey_Log_StartMethod, "Contructor", "const Serialization&");
						SerializationLog(pankey_Log_EndMethod, "Contructor", "");
					}

					virtual ~Serialization(){
						SerializationLog(pankey_Log_StartMethod, "Destructor", "");
						SerializationLog(pankey_Log_EndMethod, "Destructor", "");
					}

					static SERIALIZE_TYPE serialize(const DESERIALIZE_TYPE& a_object){
						SerializationLog(pankey_Log_StartMethod, "s_serialize", "const DESERIALIZE_TYPE&");
						SERIALIZE_TYPE i_data = serializeObject(SERIALIZE_MODEL(), m_serialization, a_object);
						SerializationLog(pankey_Log_EndMethod, "s_serialize", "");
						return i_data;
					}

					static DESERIALIZE_TYPE deserialize(const SERIALIZE_TYPE& a_data){
						SerializationLog(pankey_Log_StartMethod, "s_deserialize", "const SERIALIZE_TYPE&");
						DESERIALIZE_TYPE i_object = deserializeObject(DESERIALIZE_MODEL(), m_serialization, a_data);
						SerializationLog(pankey_Log_EndMethod, "s_deserialize", "");
						return i_object;
					}

					SERIALIZE_TYPE serialize() const {
						SerializationLog(pankey_Log_StartMethod, "serialize", "const");
						SERIALIZE_TYPE i_data = serializeObject(SERIALIZE_MODEL(), m_serialization, m_object);
						SerializationLog(pankey_Log_EndMethod, "serialize", "");
						return i_data;
					}

					DESERIALIZE_TYPE deserialize() const {
						SerializationLog(pankey_Log_StartMethod, "deserialize", "const");
						DESERIALIZE_TYPE i_object = deserializeObject(DESERIALIZE_MODEL(), m_serialization, m_data);
						SerializationLog(pankey_Log_EndMethod, "deserialize", "");
						return i_object;
					}
					
					bool operator==(const DESERIALIZE_TYPE& a_object) const {
						return deserialize() == a_object;
					}
					
					bool operator!=(const DESERIALIZE_TYPE& a_object) const {
						return deserialize() != a_object;
					}
					
				protected:
					SERIALIZE_TYPE m_data;
					DESERIALIZE_TYPE m_object;

					static SERIALIZATION_TYPE m_serialization;
			};

			template<class Policy>
			typename Serialization<Policy>::SERIALIZATION_TYPE Serialization<Policy>::m_serialization;

		}

	}

}
CXX_FLAGS=\
-I../third_party/cereal/include/ \
-I../data_types/ltensor/ \
-I../data_types/essi_data_type/ \
-I../src/ \
-I../utils/ \
-std=c++11 -Wall 

Files=\
../data_types/essi_data_type/MovableObject.cpp \
../data_types/essi_data_type/Vector.cpp \
../data_types/essi_data_type/Matrix.cpp \
../data_types/essi_data_type/ID.cpp \
../data_types/essi_data_type/Message.cpp \
../data_types/essi_data_type/ChannelAddress.cpp \
../data_types/essi_data_type/nDarray.cpp \
../data_types/essi_data_type/FEM_ObjectBroker.cpp \
../src/Serialization_Channel.cpp \
../src/Serialization_input_Channel.cpp \
../src/Serialization_output_Channel.cpp 

test_channel: test_channel.cpp $(Files)
	g++ -o test_channel.out test_channel.cpp $(CXX_FLAGS) $(Files)


clean:
	rm -f test_channel
	rm -f essi.serial
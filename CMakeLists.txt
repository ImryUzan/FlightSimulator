cmake_minimum_required(VERSION 3.13)
project(simulator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(simulator main.cpp LexerClass.cpp LexerClass.h Command.h openDataServerCommand.cpp openDataServerCommand.h Expression.h BinaryExpression.cpp BinaryExpression.h Plus.cpp Plus.h Minus.cpp Minus.h Div.h Div.cpp Mult.cpp Mult.h Num.cpp Num.h ShutingYard.cpp ShutingYard.h Negative.cpp Negative.h DefineVarCommand.h DefineVarCommand.cpp DataReaderServer.h DataReaderServer.cpp ParamsToUpdate.h ParamsToUpdate.cpp Parser.h Parser.cpp CommandExpression.h CommandExpression.cpp Connect.h Connect.cpp DataClient.cpp DataClient.h EqualCommand.h EqualCommand.cpp)
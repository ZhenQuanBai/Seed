@echo off

..\Plugins\Protobuf\bin\protoc.exe --proto_path=..\Proto --cpp_out=..\Source\Seed\PbFiles Test.proto

pause
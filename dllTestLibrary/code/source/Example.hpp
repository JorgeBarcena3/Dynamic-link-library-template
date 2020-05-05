#pragma once
#define EXAMPLE_API __declspec(dllexport)

/*
* Testeamos que la dll este funcionando perfectamente
*/
extern "C" EXAMPLE_API const char * test();
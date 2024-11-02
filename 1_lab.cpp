#include  <iostream>
//#include  <intrin.h> //для NOP
using namespace std;

int nTwin=1;			//глобальная переменная
namespace TwinSpace{ int nTwin=2;}	//переменная объявлена в локальном пространстве TwinSpace

int main()
{

 //**********************************************************
	//Задание 1. Работа с отладчиком. Базовые типы данных. Выполняя программу по шагам, 
	//следите за значениями переменных и интерпретируйте результат (помните, что 
	//количество байт, отводимых под int, системо-зависимо).
	//Обратите внимание на разную интерпретацию отладчиком signed и unsigned целых типов 
	//данных, а также на внутреннее представление отрицательных целых чисел.

	
	char cByte = 'A'; // Присваивает char 'А' с кодом в ASCII 65
	cByte    = 0x42; // Присваивает char 'B' в шестнадцатеричном коде с код в ASCII 66 
	cByte    = 66; // Присваивает char 'B' в соответсвии с ASCII-кодом
	cByte    = -1; // Не существующий символ   

	unsigned char ucByte = 0x41; // Присваивает char 'A' в шестнадцатеричном коде с код в ASCII 66
	ucByte   = 'B'; // Присваивает char 'B'
	ucByte   =	-1; // -1 меняется на 255 так как невозможно присваивать отрицательные значения

	int iInt =  0xffffffff; // из-за выхода за пределы диапазона присваивается значение равное -1

	unsigned int uiInt = 0xffffffff; // Присваивается 4294967295

	float fFloat = 1.f;  // Присваивается 1 с типом данных float
	double dDouble = 1.; // Присваивается 1 с типом данных double

	// Выполните фрагмент, приведенный далее. В комментариях отразите,
	// что реально заносится в переменную. Объясните разницу между этим 
	// значением и инициализатором.

	double d = 0.1234567890123456789123456789; // у double диапозон знаков после запятой 15-17 значение и все дальнейшие знаки программа округлила
	float  f = 0.1234567890123456789123456789; // у float диапозон знаков после запятой 6-9 значений

	d	=	1.; // присваевается значение 1, так как после . значение равно 0
	d	=	0.999999999999999999999999999999999; // присваевается значение 1, так как количество знаков после запятой превышает
	// диапозон возможных значений у типа double
	
	// В комментариях напишите результат, возвращаемый оператором sizeof для
	// переменной типа wchar_t (ее размер)
	wchar_t cw = L'Ф';
	size_t n = sizeof(cw); // 2 байта


// **************************************************************
	//Задание 2a. Неявное приведение типов данных.
	//Объясните разницу результата при выполнении (1) и (2):
	//Покажите явно (напишите в коде) преобразования, которые неявно выполняет компилятор

	iInt=1;
	double dDouble1=iInt/3;		// (1) результат равен 0
	// double dDouble2 = static_cast<double>(iInt / 3.);
	// присваевается значение с типом int и из-за этого то что должно было быть за знаком отбрасывается
	double dDouble2=iInt/3.;	// (2) результат равен 0.33333333333333331
	// double dDouble2 = static_cast<double>(iInt) / 3.;
	// при делении на значение с типом double результат также приводится к этому типу


	// Ассоциативность операторов.
	// Синтаксис языка C допускает "цепочечное" присваивание
	// (как в строках (1) и (2)). Посмотрев результаты выполнения строк (1) и (2)
	// (значения переменных dDouble, fFloat, nInt, sShort, cByte), определите порядок 
	// выполения присваиваний при цепочечной записи и объясните результат.
	// Расставте скобки, явно определяющие порядок выполнения, как это сделал бы компилятор.
	// Объясните (в комментариях) предупреждения (warnings) компилятора.

	short sShort;
	(dDouble=(fFloat=(iInt=(sShort=(cByte=(3.3/3))))));			// (1)
	// warning C4244 : '=' : conversion from 'double' to 'char', possible loss of data
	// у double и float разный объем занимаемой памяти
    // double 8 байт, float - 4 байт.
	// warning C4244: '=' : conversion from 'int' to 'float', possible loss of data
	// у int и float так же разный объем занимаемой памяти
	
	(cByte=(sShort=(iInt=(fFloat=(dDouble=(3.3/3))))));			// (2)
	// warning C4244: '=' : conversion from 'double' to 'float', possible loss of data
	// у double и float разный объем занимаемой памяти 
	// warning C4244: '=' : conversion from 'float' to 'int', possible loss of data
	// у int и float разный объем занимаемой памяти
	// warning C4244: '=' : conversion from 'short' to 'char', possible loss of data
	// у short и char разный объем занимаемой памяти. short 2 байт, char - 1 байт 

	//ниже Вам дан пример "небрежного" использования неявного приведения типов, что может 
	// привести к нежелательным результатам - объясните (в комментариях), к каким?
	// Напишите явно преобразования, которые неявно выполняет компилятор

	iInt	=	257;
	cByte	=	iInt; // в 2сс значение 257 - это 000100000001. так как char может содержать в себе только 1 байт информации,
	// то часть значений теряется и присваевается только 00000001

	unsigned char cN1=255, cN2=2, cSum;
	cSum = cN1 + cN2; // в 2сс максимум допустимого значения равен 255
	// в ходе операции сложения получается 257, что в 2сс равно 000100000001
	// 0001 теряется, остаётся 00000001

	//Сравните предыдущую строчку с приведенной ниже. Объясните (в комментариях),
	//почему в следующей строке не происходит выход за разрядную сетку
	// Напишите явно преобразования, которые неявно выполняет компилятор
	int iSum = cN1+cN2; // в результате значение с типом данных int

	//Напишите, почему при сложении одинаковых значений (одинаковых в двоичной системе) 
	// в строках (1) и (2) получаются разные результаты
	// Напишите явно преобразования, которые неявно выполняет компилятор и объясните,
	// что при этом происходит
	char c1=0xff, c2=2;
	unsigned char uc1=0xff, uc2=2;
	int iSum1= c1 + c2;   //(1) Результат равен 1, так как переменные с типом данных char и значениями -1 и 2 в сумме дают 1
	int iSum2= uc1 + uc2; //(2) значение переменной uc1 равно 255. в результате 255 + 2 = 257


	
// ***********************************************************
	//Задание 2b. Явное приведение типов данных.
	//Проинтерпретируйте результат (значения переменной dDouble) в строке (3)
	// Напишите явно преобразования, которые неявно выполняет компилятор
	int nTmp=100, nn=3;
	dDouble=3.3 + nTmp / nn; // (3) первым выполняется действие деления переменных nTmp и nn в результате получается значение равное 33.
	// nTmp, nn имеют тип данных int -> дробная часть убирается.
	// следующее действие 3.3 + 33, тип double. результат - 36.3

	//Получите результат без потери точности с помощью оператора явного
	//приведения типа
//	double dDouble3=...		// (4)
	double dDouble3 = static_cast<double>(nTmp) / nn + 3.3;

	return 0;
}
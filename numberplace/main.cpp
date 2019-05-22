// numberplace.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "main.h"
#include "NumberPlace.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

void PrintJson(NumberPlace &p_numpla)
{
	wcout << "{" << endl;
	wcout << "\t\"List\": [" << endl;
	([&]() {
		size_t l_counter = 0;

		wcout << "\t\t";
		for (auto l_value : p_numpla.GetCellList()) {
			wcout << l_value;
			if (l_counter != p_numpla.GetCellList().size() - 1) {
				wcout << ",";
			} else {
				wcout << endl;
			}
			l_counter++;
		}
	})();
	wcout << "\t]" << endl;
	wcout << "}" << endl;
}

int main()
{
	do {
		NumberPlace l_numberPlace;
		l_numberPlace.Create();
		vector<size_t> l_list = l_numberPlace.GetCellList();

		//l_numberPlace.PrintCellList();
		PrintJson(l_numberPlace);
	} while (getchar() != 'e');

	return 0;
}

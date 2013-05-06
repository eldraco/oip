/*
	Copyright 2008 Utah State University    

	This file is part of OIP.

    OIP is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OIP is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OIP.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "iptree.h"

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int i, j;
	iptree t;
	for (i = 0; i < 256; i++)
	{
		for (j = 0; j < 256; j++)
		{
			t.add((i << 16) | j);
		}
	}
	iptree::iterator p = t.begin();
	for (i = 0; i < 256 && p != t.end(); ++i)
	{
		for (j = 0; j < 256 && p != t.end(); j++, ++p)
		{
			if (p->label != ((i << 16) | j))
				cout << p->label << " != " << ((i << 16) | j) << endl;
		}
		if (t.getcount(i << 16, 16) != 256)
			cout << "count of " << (i << 16) << " is wrong\n";
	}
	if (i != 256 || j != 256)
		cout << "Not enough items in tree\n";
			
	return 0;
}

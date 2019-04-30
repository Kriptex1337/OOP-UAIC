#include <iostream>

using namespace std;

#define ABC class
#define AAA public
#define INIT(nume_var) nume_var(0)
#define CREATE(nume_var)\
	void Set_##nume_var(int val)\
	{\
		nume_var = val;\
	}\
\
	int Get_##nume_var()\
	{\
		return nume_var;\
	}
#define AFISEAZA(param) cout << param << ' ';
#define CAT_TIMP(conditie) while (conditie){
#define X_DIN_T t.Get_x()
#define ESTE_DIFERIT_DE !=
#define Y_DIN_T t.Get_y()
#define MAI_MARE_DECAT >
#define MINUS -
#define DACA(conditie, actiuneIf, actiuneElse)\
	if (conditie)\
		actiuneIf;\
	else\
		actiuneElse;
#define SFARSIT_CAT_TIMP }


ABC Test
{
	int x,y,z;
AAA:
	Test() : INIT(x), INIT(y), INIT(z) {}
	CREATE(x);
	CREATE(y);
	CREATE(z);
};

int main()
{
	Test t;
	t.Set_x(18);
	t.Set_y(24);
	AFISEAZA(t.Get_x() + t.Get_y());
	CAT_TIMP(X_DIN_T ESTE_DIFERIT_DE Y_DIN_T)
		DACA(X_DIN_T MAI_MARE_DECAT Y_DIN_T, t.Set_x(X_DIN_T MINUS Y_DIN_T), t.Set_y(Y_DIN_T MINUS X_DIN_T));
	SFARSIT_CAT_TIMP
	AFISEAZA(X_DIN_T);
	return 0;
}

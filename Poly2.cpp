#include <iostream>
using namespace std;

struct poly 
{
    int coeff;
    int pow_val;
    poly* next;
};

class add 
{
    poly *poly1, *poly2, *poly3;
	public:
    add() { poly1 = poly2 = poly3 = NULL; }
    void addpoly();
    void display();
};

void add::addpoly()
{
    int i, p,q,c;
    poly *newl = NULL, *end = NULL;
    cout << "Enter highest power for x\n in 1st polynomial"; 
	cin >> p;
	cout << "Enter highest power for x\n in 2nd polynomial"; 
	cin>>q;
	c=max(p,q);
    cout << "\nFirst Polynomial\n"; for (i = p; i >= 0; i--) {
        newl = new poly;
        newl->pow_val = p;
        cout << "Enter Co-efficient for degree" << i << ":: "; cin >> newl->coeff;
        newl->next = NULL;
        if (poly1 == NULL)
            poly1 = newl;
        else
            end->next = newl;
        end = newl;
    }


    cout << "\n\nSecond Polynomial\n"; end = NULL; for (i = q; i >= 0; i--) {
        newl = new poly;
        newl->pow_val = q;
        cout << "Enter Co-efficient for degree" << i << ":: "; cin >> newl->coeff;
        newl->next = NULL;
        if (poly2 == NULL)
            poly2 = newl;
        else
            end->next = newl;
        end = newl;
    }

    poly *p1 = poly1, *q1 = poly2;
    end = NULL;
    while (p1 != NULL && q1 != NULL) 
	{
        if (p1->pow_val == q1->pow_val) {
            newl = new poly;
            newl->pow_val=c--;
            newl->coeff = p1->coeff + q1->coeff;
            newl->next = NULL;
            if (poly3 == NULL)
                poly3 = newl;
            else
                end->next = newl;
            end = newl;
        }
        p1 = p1->next;
        q1 = q1->next;
    }
}

void add::display()
{
    poly* t = poly3;
    cout << "\n\nAnswer after addition is : ";
    while (t != NULL) {
        cout.setf(ios::showpos);
        cout << t->coeff;
        cout.unsetf(ios::showpos);
        cout << "X" << t->pow_val;
        t = t->next;
    }
}
int main()
{
    add obj;
    obj.addpoly();
    obj.display();
}

